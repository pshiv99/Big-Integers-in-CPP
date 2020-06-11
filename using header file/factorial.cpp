#include <iostream>
#include "BigInt.h"
using namespace std;

int main() {
    int num;
    BigInt temp;
    cout<<"Enter a number: ";
    cin>>num;
    BigInt result = 1;

    for(int i = 1; i <= num; i++) {
        result = result * i;
    }

    cout<<result;
    return 0;
}

