#include <string>
#include <algorithm>
#include "BigInt.h"
using namespace std;

//-------------------------------------Constructors-------------------------------------

BigInt::BigInt() {
    number = "";
}

BigInt::BigInt(const char arr[]) {
    number = arr;
}

BigInt::BigInt(string s) {
    number = s;
}

BigInt::BigInt(int i) {
    number = to_string(i);
}

//-------------------------------------Overloaded Operators-------------------------------------

//**********Mathematical Operators**********

BigInt BigInt::operator+ (BigInt& other) {
    BigInt revResult;
    int carry = 0, sum = 0, temp;

    string::reverse_iterator iterFirst = this->number.rbegin();
    string::reverse_iterator iterSecond = other.number.rbegin();
            
    for(; iterFirst != this->number.rend() && iterSecond != other.number.rend(); iterFirst++, iterSecond++) {
        temp = *iterFirst + *iterSecond - 96 + carry;
        sum = temp % 10;
        carry = temp / 10;
        revResult.number.push_back(sum + 48);
    }

    if(iterFirst != this->number.rend()) {
        while(iterFirst != this->number.rend()) {
            temp = *iterFirst - 48 + carry;
            sum = temp % 10;
            carry = temp / 10;
            revResult.number.push_back(sum + 48);
            iterFirst++;
        }
    }
    else {
        while(iterSecond != other.number.rend()) {
            temp = *iterSecond - 48 + carry;
            sum = temp % 10;
            carry = temp / 10;
            revResult.number.push_back(sum + 48);
            iterSecond++;
        }
    }
    
    if(carry != 0) {
        revResult.number.push_back(carry + 48);
    }

    std::reverse(revResult.number.begin(), revResult.number.end());
    return revResult;
}

BigInt BigInt::operator+ (int i) {
    BigInt temp = i;
    return *this + temp;
}

BigInt BigInt::operator* (BigInt& other) {
    BigInt temp, partialSum;
    int n, count = 0, carry, mul;
    partialSum.number.insert(partialSum.number.begin(), this->number.size(), '0');
            
    string::reverse_iterator iter1 = other.number.rbegin();

    for(; iter1 != other.number.rend(); iter1++) {
        string::reverse_iterator iter2 = this->number.rbegin();
        temp.number = "";
        carry = 0;
                
        for(; iter2 != this->number.rend(); iter2++) {
            n = (*iter2 - 48) * (*iter1 - 48) + carry;
            mul = n % 10;
            carry = n / 10;
            temp.number.push_back(mul + 48);
        }

        if(carry != 0) {
            temp.number.push_back(carry + 48);
        }

        std::reverse(temp.number.begin(), temp.number.end());
        temp.number.append(count, '0');
        partialSum = partialSum + temp;
        count += 1;
    }

    return partialSum;
}

BigInt BigInt::operator* (int i) {
    BigInt temp = i;
    return *this * temp;
}

//**********Relational Operators**********

bool BigInt::operator<= (BigInt& other) {
    if(this->number.size() == other.number.size()) {
        if(this->number <= other.number) {
            return true;
        }
        return false;
    }
    if(this->number.size() < other.number.size()) {
        return true;
    }
    return false;
}

//-------------------------------------Overloaded Stream Operators-------------------------------------

istream& operator>> (istream& stream, BigInt& obj) {
    stream>>obj.number;
    return stream;
}

ostream& operator<< (ostream& stream, BigInt& obj) {
    stream<<obj.number;
    return stream;
}

//-------------------------------------Other Member Functions-------------------------------------

int BigInt::length() {
    return this->number.size();
}


