#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <vector>
#include <cassert>

// change to c++ format
// move algorithm (encrypt) to function
// propose and discuss (decrypt) function
// input our function to class

class Caesar
{
private:
    std::string m_origin_text;
    std::string m_cipher_text;
    int m_length{ 0 };
    int m_key { 0 };

public:
    Caesar();
    // Caesar(std::string text);
    // Caesar(int key);
    // Caesar(std::string text, int key);

    void encryption();
    std::string ecrypt();

    void decryption();
    std::string decrypt(int key);

    std::string getOriginText();
    std::string getCipherText();

    int getKey();
    void setIntegerKey(std::string str);
    void setOriginText(std::string str);
    void setCipherText(std::string str);
    bool isCorrectKey();

    

    // check for equal between decrypt text and original
    bool isDecrypt(); 

    // look for all versions of Encrypted text
    // index of vector is equal for index of key
    std::vector<std::string> bruteforce(std::string encrypted_text); 
    int bruteforce_key(std::string encrypted_text, std::string original_text);

    // using inside at function std::vector<std::pair<std::string, int> > 
    std::pair<std::string, int> findOriginalText(); 
};


Caesar::Caesar()
{
    std::cout << "What kind of text do you want to enter:\n\t1. Encrypted\n\t2.Decrypted\n";
    int number = get_int("Enter a version (1/2): ");
    assert(number == 1 || number == 2);
    if (number == 1)
    {
        setCipherText("Enter an encrypted text: ");

        setIntegerKey("Enter a key: ");
        assert(m_key > 0 && m_key < 26);
    }
    else if (number == 2)
    {
        setOriginText("Enter an origin text: ");

        setIntegerKey("Enter a key: ");
        assert(m_key > 0 && m_key < 26);
    }
    
}
// Caesar::Caesar(std::string text)
// {}
// Caesar::Caesar(int key)
// {}
// Caesar::Caesar(std::string text, int key)
// {}

void Caesar::encryption()
{
    if (!m_origin_text.empty())
    {
        for (int i = 0, n = m_origin_text.length(); i < n; i++)
        {
            if (isalpha(m_origin_text[i]))
            {
                if (isupper(m_origin_text[i]))
                {
                    m_origin_text[i] = m_origin_text[i] - 65;
                    m_cipher_text += (m_origin_text[i] + m_key) % 26 + 65;
                    std::cout << m_cipher_text[i]; //printf("%c", ciphertext[i]);
                }
                else if (islower(m_origin_text[i]))
                {
                    m_origin_text[i] -= 97;
                    m_cipher_text += (m_origin_text[i] + m_key) % 26 + 97;
                    std::cout << m_cipher_text[i]; //printf("%c", ciphertext[i]);
                }
            }
            else if (isdigit(m_origin_text[i]))
            {
                m_origin_text[i] -= 48;
                m_cipher_text += (m_origin_text[i] + m_key) % 10 + 48;
                std::cout << m_cipher_text[i]; //printf("%c", ciphertext[i]);
            }
            else 
            {
                m_cipher_text += m_origin_text[i];
                std::cout << m_cipher_text[i]; //printf("%c", ciphertext[i]);
            }
        }
    }
    else
    {
        // ... exception
    }
}
std::string Caesar::ecrypt()
{
        for (int i = 0, n = m_origin_text.length(); i < n; i++)
    {
        if (isalpha(m_origin_text[i]))
        {
            if (isupper(m_origin_text[i]))
            {
                m_origin_text[i] = m_origin_text[i] - 65;
                m_cipher_text += (m_origin_text[i] + m_key) % 26 + 65;
                //std::cout << ciphertext[i]; //printf("%c", ciphertext[i]);
            }
            else if (islower(m_origin_text[i]))
            {
                m_origin_text[i] -= 97;
                m_cipher_text += (m_origin_text[i] + m_key) % 26 + 97;
                //std::cout << ciphertext[i]; //printf("%c", ciphertext[i]);
            }
        }
        else if (isdigit(m_origin_text[i]))
        {
            m_origin_text[i] -= 48;
            m_cipher_text += (m_origin_text[i] + m_key) % 10 + 48;
            //std::cout << ciphertext[i]; //printf("%c", ciphertext[i]);
        }
        else 
        {
            m_cipher_text += m_origin_text[i];
            //std::cout << ciphertext[i]; //printf("%c", ciphertext[i]);
        }
    }
    return m_cipher_text;
}

void Caesar::decryption()
{
    if (!m_cipher_text.empty())
    {
        for (int i = 0, n = m_cipher_text.length(); i < n; i++)
        {
            if (isalpha(m_cipher_text[i]))
            {
                if (isupper(m_cipher_text[i]))
                {
                    m_cipher_text[i] = m_cipher_text[i] - 65;
                    m_origin_text += (m_cipher_text[i] - m_key) % 26 + 65;
                    std::cout << m_origin_text[i]; //printf("%c", ciphertext[i]);
                }
                else if (islower(m_cipher_text[i]))
                {
                    m_cipher_text[i] -= 97;
                    m_origin_text += (m_cipher_text[i] - m_key) % 26 + 97;
                    std::cout << m_origin_text[i]; //printf("%c", ciphertext[i]);
                }
            }
            else if (isdigit(m_cipher_text[i]))
            {
                m_cipher_text[i] -= 48;
                m_origin_text += (m_cipher_text[i] + m_key) % 10 + 48;
                std::cout << m_origin_text[i]; //printf("%c", ciphertext[i]);
            }
            else 
            {
                m_origin_text += m_cipher_text[i];
                std::cout << m_origin_text[i]; //printf("%c", ciphertext[i]);
            }
        }
    }
    else
    {
        // ... exception
    }
}
std::string Caesar::decrypt(int key)
{
    if (!m_cipher_text.empty())
    {
        for (int i = 0, n = m_cipher_text.length(); i < n; i++)
        {
            if (isalpha(m_cipher_text[i]))
            {
                if (isupper(m_cipher_text[i]))
                {
                    m_cipher_text[i] = m_cipher_text[i] - 65;
                    m_origin_text += (m_cipher_text[i] - key) % 26 + 65;
                    std::cout << m_origin_text[i]; //printf("%c", ciphertext[i]);
                }
                else if (islower(m_cipher_text[i]))
                {
                    m_cipher_text[i] -= 97;
                    m_origin_text += (m_cipher_text[i] - key) % 26 + 97;
                    std::cout << m_origin_text[i]; //printf("%c", ciphertext[i]);
                }
            }
            else if (isdigit(m_cipher_text[i]))
            {
                m_cipher_text[i] -= 48;
                m_origin_text += (m_cipher_text[i] + key) % 10 + 48;
                std::cout << m_origin_text[i]; //printf("%c", ciphertext[i]);
            }
            else 
            {
                m_origin_text += m_cipher_text[i];
                std::cout << m_origin_text[i]; //printf("%c", ciphertext[i]);
            }
        }
    }
    else
    {
        // ... exception
    }
    return m_origin_text;
}

std::string Caesar::getOriginText()
{
    return m_origin_text;
}
std::string Caesar::getCipherText()
{
    return m_cipher_text;
}

int Caesar::getKey()
{
    return m_key;
}
void Caesar::setIntegerKey(std::string str)
{
	/*
	Funtion:    print category and check inputting varieble for correct data
	Get:        integer varieble from user
	Return:     int
	*/
	// int m_key{ 0 };
	while (true)
	{
		std::cout << "\nEnter your " << str << ": ";
		std::cin >> m_key;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}
		// our data shoul be Non-zero
		if (m_key <= 0) { continue; }

		break;
	}
	//return number;
}
bool Caesar::isCorrectKey()
{}
void Caesar::setCipherText(std::string str)
{
   /*
    Funtion:    print category and check inputting varieble for correct data
    Get:        string varieble from user
    Return:     string
    */
    while (true)
    {
        std::cout << "Enter " << str << ": ";
        std::getline(std::cin, m_cipher_text); // get all line

        bool bRejected = false;

        // checking each character at the entered word
        for (std::size_t nIndex = 0; nIndex < m_cipher_text.length() && !bRejected; ++nIndex)
        {
            // if a current character is a letter -> ok
            if (isalpha(m_cipher_text[nIndex])) { continue; }

            // digits in ASCII from 48 to 57
            if (isdigit(m_cipher_text[nIndex])) { continue; }

            // if we want to allow "SPACE"
            if (m_cipher_text[nIndex] == ' ') { continue; }
            // if we want to allow "!"
            if (m_cipher_text[nIndex] == '!') { continue; }
            // if we want to allow "?"
            if (m_cipher_text[nIndex] == '?') { continue; }

            // another situations - re-enter 
            bRejected = true;
        }
        // if all is good
        if (!bRejected && m_cipher_text.length() > 1) { break; }
    }
    //return str;
}
void Caesar::setOriginText(std::string str)
{
   /*
    Funtion:    print category and check inputting varieble for correct data
    Get:        string varieble from user
    Return:     string
    */
    while (true)
    {
        std::cout << "Enter " << str << ": ";
        std::getline(std::cin, m_origin_text); // get all line

        bool bRejected = false;

        // checking each character at the entered word
        for (std::size_t nIndex = 0; nIndex < m_origin_text.length() && !bRejected; ++nIndex)
        {
            // if a current character is a letter -> ok
            if (isalpha(m_origin_text[nIndex])) { continue; }

            // digits in ASCII from 48 to 57
            if (isdigit(m_origin_text[nIndex])) { continue; }

            // if we want to allow "SPACE"
            if (m_origin_text[nIndex] == ' ') { continue; }
            // if we want to allow "!"
            if (m_origin_text[nIndex] == '!') { continue; }
            // if we want to allow "?"
            if (m_origin_text[nIndex] == '?') { continue; }

            // another situations - re-enter 
            bRejected = true;
        }
        // if all is good
        if (!bRejected && m_origin_text.length() > 1) { break; }
    }
    //return str;
}

// check for equal between decrypt text and original
bool Caesar::isDecrypt()
{
    // if s1.compare(s2) == 0 // => equal
}


// main ->
// brutforce -> each version check for isDecrypt
// print key and original text
// void
std::vector<std::string> Caesar::bruteforce(std::string encrypted_text)
{
    std::vector<std::string> vec;
    std::string alphabet = "abcdefghijklmnopqrstuvwzyx";
    int length_of_keys = alphabet.length();
    for (size_t index_key = 0; index_key < length_of_keys; ++index_key)
    {
        vec.push_back(decrypt(index_key));
        std::cout << "Key:\t" << index_key << "\ttext:\t" << vec[index_key] << std::endl;
    }
    return vec;
}

int Caesar::bruteforce_key(std::string encrypted_text, std::string original_text)
{
    // std::vector<std::string> vec;
    // std::string alphabet = "abcdefghijklmnopqrstuvwzyx";
    // int length_of_keys = alphabet.length();
    // for (size_t index_key = 0; index_key < length_of_keys; ++index_key)
    // {
    //     vec.push_back(decrypt(encrypted_text, index_key));
    //     std::cout << "Key:\t" << index_key << "\ttext:\t" << vec[index_key] << std::endl;
    // }
    // return key;
}


// int main(int argc, char** argv)
int main(int argc, char* argv[])
{

    // if (argc != 2)
    // {
    //     std::cout << "Usage: ./caesar key\n"; // printf("Usage: ./caesar key\n");
    //     return 1;
    // }
    // // get argument as key from command-line and move to integer
    // int k = atoi(argv[1]); // ascii to integer
    // if (k < 0 || k > 1000) // 1000 -> length of alphabet
    // {
    //     std::cout << "Usage: ./caesar key\n"; // printf("Usage: ./caesar key\n");
    //     return 1;
    // }
    // for (int i = 0; i < strlen(argv[1]); i++)
    // {
    //     if (argv[1][i] > 57 || argv[1][i] < 48)
    //     {
    //         std::cout << "Usage: ./caesar key\n"; // printf("Usage: ./caesar key\n");
    //         return 1;
    //     }
    // }
    std::string text = get_string("plaintext:\t");
    std::string ciphertext = "";
    std::cout << "ciphertext:\t";
    
    std::cout << ciphertext << std::endl;


    // start
    std::string origin_text = get_string("Enter some text to encrypt: ");
    int key = get_int("Enter a key from 0 to 25: ");
    Caesar c(origin_text, key);
    std::string cipher_text = c.ecrypt();
    std::vector<std::string> v;
    v = c.bruteforce(cipher_text);
    for (const auto& text : v)
    {
        // text.compare(c.isDecrypt(text, origin))
    }
    

    return 0;
}



int get_int(std::string str)
{

}