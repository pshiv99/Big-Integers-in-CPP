# Implementation Using Header File

- **BitInt.h** - This file contains the declaration of class `BigInt`.

- **BigInt.cpp** - This file contains the definition of class `BigInt` *member functions*.

## How to run:

- Download these two files into a directory of your choice in your local computer.

- Create a C++ source file but make sure it is saved in the directory where you downloaded above two files.
  - Include the following line in C++ source file:
  
    ```
    #include "BigInt.h"
    ```

- Go into the directory on command line and run the follwing commands:
  ```bash
  g++ file_name.cpp -o file_name  BigInt.cpp
  ```
  On Windows:
  ```
  file_name.exe
  ```

## Example:

- I have included an example file named `example.cpp` that contains minimal code for demonstration.

- Go to command line and change your working directory to the directory where these files are contained.

- Run the following commands:
  ```
  g++ example.cpp -o example BigInt.cpp
  ```
  On Windows:
  ```
  example.exe
  ```
  **Output:**
  ```
  First number is: 8794654897846516689465456514897846
  Second Number is: 5148641478946974897649784558468764
  The multiplication is: 45280525000076746126954476674306058124147814148593564536011641882344
  ```

- Feel free to edit the `example.cpp` file.
