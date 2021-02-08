// algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//
//int main()
//{
//    int height = 10;
//    for (size_t i = 1; i <= height; ++i)
//    {
//        for (size_t spaces = (height - i); spaces > 0; spaces--)
//        {
//            std::cout << " ";
//        }
//        for (size_t hash = 1; hash <= i; ++hash)
//        {
//            std::cout << "#";
//        }
//
//        std::cout << "\n";
//    }
//}

#include <iostream>

int main() {
    int height = 10; // INPUT DATA
    const int roofHeight = height / 2;
    const int wallHeight = height - roofHeight;
    // roof
    for (size_t i = roofHeight; i > 0; --i)
    {
        for (size_t j = 0; j < i; ++j)
        {
            std::cout << " ";
        }
        std::cout << "/";
        for (size_t j = roofHeight; j - i > 0; --j)
        {
            std::cout << "  ";
        }
        std::cout << "\\" << std::endl;
    }
    // wall
    const int doubleWallWidth = 2;
    int buildingWidth = roofHeight * 2;
    for (size_t i = 0; i < buildingWidth + doubleWallWidth; ++i) // 0, 1, 2, .... 11
    {
        std::cout << "-";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < wallHeight; ++i)
    {
        std::cout << "|";
        for (size_t j = 0; j < buildingWidth; j++) // spaces
        {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }
    for (size_t i = 0; i < buildingWidth + doubleWallWidth; ++i)
    {
        std::cout << "-";
    }
    //int a = 5;
    //int b = 4;
    //std::cout << a++ << std::endl;  // 5
    //std::cout << ++b << std::endl;  // 5
    //std::cout << a << std::endl;    // 6

    return 0;
}



/*
simple version
      /\
     /  \
    /    \
   /      \
  /        \
 ------------
 |          |
 |          |
 |          |
 |          |
 |          |
 |__________|

    /\
   /  \
  /    \
 /------\
/ |    | \
  |    |
  |    |
  |____|

      /\
     /  \ ___
    /    \| |
   /      \ |
  /        \|
 /----------\
/|          |\
 |          |
 |          |
 |          |
 |__________|
*/