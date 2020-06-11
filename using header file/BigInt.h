#include<iostream>
#include<string>

class BigInt {
    private:
        std::string number;
    public:
        BigInt();
        BigInt(const char[]);
        BigInt(std::string);
        BigInt(int);

        friend std::istream& operator>> (std::istream&, BigInt&);
        friend std::ostream& operator<< (std::ostream&, BigInt&);

        BigInt operator+ (BigInt&);
        BigInt operator+ (int);
        BigInt operator* (BigInt&);
        BigInt operator* (int);
        bool operator<= (BigInt&);
};
