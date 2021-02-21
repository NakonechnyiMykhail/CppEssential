#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <vector>

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
    Caesar(std::string text);
    Caesar(int key);
    Caesar(std::string text, int key);

    void encryption(std::string origin_text);
    std::string ecrypt(std::string origin_text);

    void decryption(std::string origin_text);
    std::string decrypt(std::string origin_text);

    std::string getOriginText();
    std::string getCipherText();

    int getKey();
    int getIntegerKey();
    bool isCorrectKey();

    std::string getString(std::string str);

    // check for equal between decrypt text and original
    bool isDecrypt(); 

    // look for all versions of Encrypted text
    // index of vector is equal for index of key
    std::vector<std::string> brutforce(std::string encrypted_text); 

    // using inside at function std::vector<std::pair<std::string, int> > 
    std::pair<std::string, int> findOriginalText(); 
};

// main ->
// brutforce -> each version check for isDecrypt
// print key and original text




// int main(int argc, char** argv)
int main(int argc, char* argv[])
{

    if (argc != 2)
    {
        std::cout << "Usage: ./caesar key\n"; // printf("Usage: ./caesar key\n");
        return 1;
    }
    // get argument as key from command-line and move to integer
    int k = atoi(argv[1]); // ascii to integer
    if (k < 0 || k > 1000) // 1000 -> length of alphabet
    {
        std::cout << "Usage: ./caesar key\n"; // printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] > 57 || argv[1][i] < 48)
        {
            std::cout << "Usage: ./caesar key\n"; // printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    std::string text = get_string("plaintext:\t");
    std::string ciphertext = "";
    std::cout << "ciphertext:\t";
    for (int i = 0, n = text.length(); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = text[i] - 65;
                ciphertext += (text[i] + k) % 26 + 65;
                //std::cout << ciphertext[i]; //printf("%c", ciphertext[i]);
            }
            else if (islower(text[i]))
            {
                text[i] -= 97;
                ciphertext += (text[i] + k) % 26 + 97;
                //std::cout << ciphertext[i]; //printf("%c", ciphertext[i]);
            }
        }
        else if (isdigit(text[i]))
        {
            text[i] -= 48;
            ciphertext += (text[i] + k) % 10 + 48;
            //std::cout << ciphertext[i]; //printf("%c", ciphertext[i]);
        }
        else 
        {
            ciphertext += text[i];
            //std::cout << ciphertext[i]; //printf("%c", ciphertext[i]);
        }
    }
    std::cout << ciphertext << std::endl;

    return 0;
}

std::string get_string(std::string str)
{
    while (true)
    {
        std::string text;
        std::cout << str;
        //std::cin >> text;
        std::getline(std::cin, text);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
        }
        else
        {
            return text;
        }
    }
}

