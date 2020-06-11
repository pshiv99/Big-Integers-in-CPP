#include <iostream>
#include "BigInt.h"
using namespace std;

int main() {
    BigInt i = "8794654897846516689465456514897846";
    BigInt j = "5148641478946974897649784558468764";

    cout<<"The first number is: "<<i<<endl;
    cout<<"The second number is: "<<j<<endl;

    BigInt result = i * j;
    cout<<"The multiplication is: "<<result;
    
    return 0;
}