#include <iostream>
// Memory: Stack, Heap, Text, Data
// Local Variable -> Stack: i
// Global Variable -> Data: j
// Heap variable: new operator
// C functions, Class methods -> Text
// Heap: new/delete operator -> new: allocates, delete: disallocate
//       memory leak, new -> ?, pointer
int j = 42 ; // global variable -> Data, value -> 42
int *p = &j; // pointer -> data -> address, p -> j

int fun(int); // declaration -> does not generate code!

int sun(int x,int y){
    return x+fun(y);
}

int fun(int u){ // Text -> Definition
    // Local/Stack/Automatic variable: k, u
    // Scope:
    int k;
   return u*u; // end of scope: destroys k, u
}

int i = 42; // Global variable

int main() { // Text
    int i = 108; // local variable, declaration + definition
    ::i = ::i + 1; // i in stack
    // k : undefined
    {
        int a = 0; // Stack
        for (int n=0;n<10;n++){ // n's scope: for loop
            a++;
            int q = 42; // p is created 10 times!
            std::cout << a << std::endl;
        }
        std::cout << a << std::endl;
    } // end of scope: destroys the variable "a"
    // application continues...

    return 0;
}
