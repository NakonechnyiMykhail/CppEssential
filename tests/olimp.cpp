#include <iostream>
using namespace std;
int main(){
    int array[100];
    int num = 0; // 0 - 9
    int numr = 0; // count
    int max = 9;
    for(int i = 0; i<100;){
        if(num>max){
            ++numr;
            num = 0;
        }

        for(int j = 1; j < numr; ++j)
        {
            array[i] = num;
            ++i;
            
        } 
        ++num;
       
    }
    for(int o = 0; o < 100; o++){
        cout << array[o] << endl;
    }
    // int mininp;
    // int maxinp;
    // cin >> mininp;
    // cin >> maxinp;
    // mininp = mininp - 1;
    // int result = 0;
    // for(;mininp<maxinp;mininp++){
    //     result = result + array[mininp];
    // }
    // cout << result << endl;
    return 0;
}

// a = 5
// cout << a++ -> 5
// cout << a   -> 6
// cout << ++a -> 6