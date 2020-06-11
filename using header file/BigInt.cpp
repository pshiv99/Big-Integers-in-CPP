#include <string>
#include "BigInt.h"
using namespace std;

BigInt::BigInt() {
    number = "";
}

BigInt::BigInt(const char arr[]) {
    number = arr;
}

BigInt BigInt::operator+ (BigInt& other) {
    BigInt revResult;
    int carry = 0, sum = 0, temp;

    if(this->number.size() < other.number.size()) {
        this->number.insert(this->number.begin(), other.number.size() - this->number.size(), '0');
    }
    else {
        other.number.insert(other.number.begin(), this->number.size() - other.number.size(), '0');
    }

    string::reverse_iterator iterFirst = this->number.rbegin();
    string::reverse_iterator iterSecond = other.number.rbegin();
            
    for(; iterFirst != this->number.rend(); iterFirst++, iterSecond++) {
        temp = *iterFirst + *iterSecond - 96 + carry;
        sum = temp % 10;
        carry = temp / 10;
        revResult.number.append(to_string(sum));
    }
    if(carry != 0) {
        revResult.number.append(to_string(carry));
    }

    BigInt result = revResult.reverse();
    return result;
}

BigInt BigInt::operator* (BigInt& other) {
    BigInt temp, partialSum, t;
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
            temp.number.append(to_string(mul));
        }

        if(carry != 0) {
            temp.number.append(to_string(carry));
        }

        t = temp.reverse();
        t.number.append(count, '0');
        partialSum = partialSum + t;
        count += 1;
    }

    return partialSum;
}

BigInt BigInt::reverse() {
    BigInt temp;
    string::reverse_iterator iter = this->number.rbegin();
    for(; iter != this->number.rend(); iter++) {
        temp.number.push_back(*iter);
    }
    return temp;
}

istream& operator>> (istream& stream, BigInt& obj) {
    stream>>obj.number;
    return stream;
}

ostream& operator<< (ostream& stream, BigInt& obj) {
    stream<<obj.number;
    return stream;
}