// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <exception>

// [1, 1, 1]
// [1, 1, 1]
// [1, 1, 1]
// [1, 1, 1]
// x Matrix m();
// + Matrix m(4,3);
// + Matrix m2(m);

class MatrixMultException : public std::exception
{

};

class MatrixPlusException : public std::exception
{
    
};
class MatrixMinusException : public std::exception
{
    
};
class MatrixIndexException : public std::exception
{
    
};
class MatrixCinException : public std::exception
{
    
};
class MatrixCoutException : public std::exception
{
    
};

class Matrix
{
private:
    int m_rows;
    int m_cols;
    Matrix() = delete; // no need for the default constuctor
    int** mat;
    std::vector<int> matrix;
public:
    Matrix(const int& rows, const int& cols);
    Matrix(const Matrix& other);
    ~Matrix();
    int*& operator[](const int& index) const;
    void operator=(const Matrix& other);
    Matrix  operator -() const;
    Matrix  operator -(const Matrix& other) const;
    Matrix  operator +(const Matrix& other) const;
    Matrix  operator *(const Matrix& other) const;
    Matrix  operator *(const int& num) const;
    int getMatrixRows() const { return m_rows; }
    int getMatrixCols() const { return m_cols; }

    friend  Matrix operator *(const int& num, const Matrix& m)
    {
        Matrix tmp(m); // Matrix tmp(m.getMatrixRows(), m.getMatrixCols());
        for (size_t i = 0; i < m.getMatrixRows(); i++)
        {
            for (size_t j = 0; j < m.getMatrixCols(); j++)
            {
                tmp[i][j] = m[i][j] * num;
            }
        }
        return tmp;
        // return (num * m);
    }


    friend Matrix operator +(const int& num, const Matrix& m)
    {
        Matrix tmp(m); // Matrix tmp(m.getMatrixRows(), m.getMatrixCols());
        for (size_t i = 0; i < m.getMatrixRows(); i++)
        {
            for (size_t j = 0; j < m.getMatrixCols(); j++)
            {
                tmp[i][j] = m[i][j] + num;
            }
        }
        return tmp;
        // return (num + m);
    }

    friend std::istream& operator>>(std::istream& in, Matrix& m) 
    {
        std::cout << "Enter elements of matrix:\n";
        for (size_t i = 0; i < m.m_rows; i++)
        {
            for (size_t j = 0; j < m.m_cols; j++)
            {
                std::cout << "Matrix[" << i << "][" << j << "] = ";
                in >> m[i][j];
            }
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) 
    {
        try
        {
            for (int i = 0; i < m.m_rows; ++i) 
            {
                for (int j = 0; j < m.m_cols; ++j) 
                {
                    os << m.mat[i][j] << "\t";
                }
                os << '\n';
            }
        }
        catch(const MatrixCoutException& mce)
        {
            std::cerr << mce.what() << '\n';
            // throw -1;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(...)
        {
            std::cerr << "..." << '\n';
        }
        

        return os;
    }


};

//constructor of class Matrix
Matrix::Matrix(const int& n_rows, const int& n_cols)
{
    m_rows = n_rows;
    m_cols = n_cols;
    mat = new int* [m_cols];        // **mat -> *mat[0] + *mat[1] + *mat[2]
    assert(mat); // <=> if (nullptr)       //   |
    for (int i = 0; i < m_rows; i++)     //    \/
    {
        mat[i] = new int[m_cols]; // 0x0000 0x0004 0x0008 | 0x000C 0x0010 0x0014 | 0x0018 0x001C 0x0020 | 0x0024 0x0028 0x002C | cccccc 
        assert(mat[i]);
    }
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            mat[i][j] = 0;
        }
    }
}

//copy constructor
Matrix::Matrix(const Matrix& other)  
{
    m_cols = other.m_cols;
    m_rows = other.m_rows;
    mat = new int* [other.m_rows];
    assert(mat);
    for (int i = 0; i < other.m_rows; i++)
    {
        mat[i] = new int[other.m_cols];
        assert(mat[i]);
    }
    for (int i = 0; i < other.m_rows; i++)
    {
        for (int j = 0; j < other.m_cols; j++)
        {
            mat[i][j] = other[i][j];
        }
    }
}

// overloading operator []
int*& Matrix::operator [](const int& index) const  
{
    return  mat[index];
}

// overloading operator =
void Matrix::operator=(const Matrix& other)   
{
    assert(mat != other.mat && m_cols == other.m_cols && m_rows == other.m_rows);
    // if (mat != other.mat && m_cols == other.m_cols && m_rows == other.m_rows)
    // {
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_cols; j++)
            {
                mat[i][j] = other.mat[i][j];
            }
        }
    // }
}

// overloading operator -
Matrix  Matrix::operator-()const   
{
    Matrix temp(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            temp.mat[i][j] = mat[i][j] * -1;
        }
    }
        
    return temp;
}

//add 2 matrix
Matrix  Matrix::operator +(const Matrix& other)const  
{
    Matrix temp(m_rows, m_cols);
    assert(m_rows != other.m_rows || m_cols != other.m_cols);
    if (m_rows != other.m_rows || m_cols != other.m_cols)
    {
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_cols; j++)
            {
                temp.mat[i][j] = mat[i][j];
            }
        }
            
        return temp;
    }
    else
    {
        for (int i = 0; i < m_rows; i++)
            for (int j = 0; j < m_cols; j++)
                temp.mat[i][j] += other.mat[i][j] + mat[i][j];
    }
    return temp;
}

//multiplay matrix on the right
Matrix  Matrix::operator *(const Matrix& other)const   
{
    if (m_cols != other.m_rows)
    {
        Matrix temp(m_cols, m_rows);
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_cols; j++)
            {
                temp.mat[i][j] = mat[i][j];
            }
        }
        return temp;
    }
    else
    {
//  A (3,3)   x  B(3,2) = C (3,2)
// [1, 1, 1]     [1, 1]     [3, 3]
// [1, 1, 1]  x  [1, 1] =   [1, 1]
// [1, 1, 1]     [1, 1]     [1, 1]



        Matrix temp(m_cols, other.m_rows);
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < other.m_cols; j++)
            {
                for (int k = 0; k < m_cols; k++)
                {
                    temp[i][j] += mat[i][k] * other.mat[i][j];
                }
            }
        }
            
        return temp;
    }

}

//multiplay with number
Matrix  Matrix::operator *(const int& num)const   
{
    Matrix temp(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            temp.mat[i][j] = mat[i][j] * num;
        }
    }
        
    return temp;
}
//matrix subtraction
Matrix  Matrix::operator -(const Matrix& other)const  
{
    Matrix temp(m_rows, m_cols);
    if (m_rows != other.m_rows || m_cols != other.m_cols)
    {
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_cols; j++)
            {
                temp.mat[i][j] = mat[i][j];
            }
        }
        return temp;
    }
    else
    {
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_cols; j++)
            {
                temp.mat[i][j] += mat[i][j] - other.mat[i][j];
            }
        }
    }
    return temp;
}

//destrucor 
Matrix::~Matrix()
{
    // delete the memory allocated to the array here
    for (int i = 0; i < m_rows; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;

}

void mul_to_3(Matrix& m)
{
    for (int i = 0; i < m.getMatrixRows(); i++)
    {
        for (int j = 0; j < m.getMatrixCols(); j++)
        {
            if ((m[i][j] < 0) && (m[i][j] % 2 != 0))
            {
                m[i][j] = m[i][j] * 3;
            }
        }
    }
}

int main()
{
    Matrix m(2, 2);
    //m[0][0] = 2;
    //m[1][1] = 2;

    try
    {
        std::cin >> m;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    mul_to_3(m);
    try
    {
        std::cout << m << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    //m = m;
    const Matrix s = -m;
    std::cout << m << std::endl << s << std::endl;
    m = s+2 * -m * m * 2 - s;
    std::cout << m << std::endl << s << std::endl;
    std::cout << s[1][1] << std::endl;

    return 0 ; 
}


