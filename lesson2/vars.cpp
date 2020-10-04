#include <iostream>



int main()
{
    bool b = true; // false
    char c = 'a'; // '\n'
    std::string s = "my name is mike";
    short sh = 0;
    int i = 0;
    long l = 0l;
    float f = 0.0;
    double d = 0.1e12;


    
/* condition
> < >= <= == != & && (and) | || (or) ^ (xor) !(not)
a > b (4>3) -> true
a == b (5 == 5) -> true
true && true          (true and true) (4 > 3 and a == b)
|| (or)
(a != b and c != b and a == c) or (a == b and b == c)
!true -> false
!false -> true
 */

    // if (!true)
    // {
    //     std::cerr << "Error!!!" << std::endl;
    //     return -1;
    // }

    // if (/* condition */)
    // {
    //     /* code */
    // }
    // else
    // {
    //     /* code */
    // }

    // if (/* condition */)
    // {
    //     /* code */
    // }
    // else if (/* condition */)
    // {
    //     /* code */
    // }
    // else
    // {
    //     /* code */
    // }
    int a = 1;
    switch (a)
    {
    case 1:
        std::cout << "Monday" << std::endl;
        break;
    case 2:
        std::cout << "Tuesday" << std::endl;
        break;
    case 5:
        std::cout << "Friday" << std::endl;
        break;
    default:
        break;
    }
    

    // for (size_t i = 0; i < count; i++)
    // {
    //     /* code */
    // }
    // for(;;)
    // {

    // }
    // for (auto &&i : v)
    // {
        
    // }
    // while (a>0) // a <10
    // {
    //     /* code */
    //     --a; // ++a;
    // }
    // do
    // {
    //     /* code */
    // } while (a<0);
    
    const int count = 10;

    int arr[count];
    int arr2[count] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // arr2[0] = 0;
    // arr2[1] = 0;
    // arr2[2] = 0;
    // arr2[3] = 0;
    // arr2[4] = 0;
    for (size_t i = 0; i < count; i++)
    {
        arr[i] = 0;
    }
    for (size_t i = 0; i < count; i++)
    {
        arr[i] = i*i;
        std::cout << arr[i] << ' ';
    }
    

    return 0;
}