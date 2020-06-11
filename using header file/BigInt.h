#include<iostream>
#include<string>

class BigInt {
    private:
        std::string number;
    public:
        BigInt();
        BigInt(const char arr[]);

        friend std::istream& operator>> (std::istream& stream, BigInt& obj);
        friend std::ostream& operator<< (std::ostream& stream, BigInt& obj);

        BigInt operator+ (BigInt& other);
        BigInt operator* (BigInt& other);
        BigInt reverse();
};

