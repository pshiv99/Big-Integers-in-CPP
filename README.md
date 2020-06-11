# Big Integers in C++

- This is a little project for handling really **large integers** in *C++*.
- Most modern modern programming languages support the implementation of big integers. To have the same
functionality in C++, I did this little project that can handle big integers and provide different operations on them just like primitive integer data type in C++.

## Implementation:

- Object Oriented Programming is used for handling the big integers in C++.
    - A user defined data structure called `BigInt` is created using class.
    - The class `BigInt` implements big integers using *string* as private data member. This hides the
    implementation from outside code.
    - The class `BigInt` overloads the following operators:
        - *Extraction operator (>>)*
        - *Insertion operator (<<)*
        - *Addition operator (+)*
        - *Multiplication operator (\*)*
    - This overloading of operators provides the same interface as provided for primitive data type `int`.
   
        ```cpp
        class BigInt {
            private:
                string number;
            public:
                BigInt() {     // constructor
                    // code
                }
                friend istream& operator>> (istream& stream, BigInt& obj);  // overloaded >> operator
                friend ostream& operator<< (ostream& stream, BigInt& obj);  // overloaded << operator
                BigInt operator+ (BigInt& other) {  // overloaded + operator
                    // code
                }
                BigInt operator* (BigInt& other) {  // overloaded * operator
                    // code
                }
        }
        ```

## Syntax:

The most interesting thing about this implementation is that it provides the same interface as provided by the int data type.

- **Declaring object:** 
  ```cpp
  BigInt num;
  ```

- **Reading integers:** 
  ```cpp
  cin>>num;     // where num is BigInt object
  ```

- **Printing integers:**
  ```cpp
  cout>>num;     // where num is BigInt object
  ```

- **Adding:**
  ```cpp
  result = num1 + num2;     // where result, num1, num2 are BigInt objects
  ```

- **Multiplication:**
  ```cpp
  result = num1 * num2;     // where result, num1, num2 are BigInt objects
  ```
- **Initializing at the time of declaration:**
  ```cpp
  BigInt num = "46513564894651346879461534"   // the integer must be passed as a string.
  ```

## Examples:

- One example when the code in file *BigInt.cpp* is run:
  ```
  Enter first number: 64846598469846519846513894658946513684648946549846548615
  Enter second number: 8465489654894654896548648946897465498654815498654854865486
  The multiplication is: 548958208501593271574141358512166485252787157019535340292479121617224383536582532321984778940943800657217184601890
  ```