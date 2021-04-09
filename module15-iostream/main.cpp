#include <iostream>
#include <fstream>
#include "circle.h"

using namespace std;

int main() {
    circle c1(1,2,3);
    cout << c1 << endl;
    cout << c1.area() << endl;
    ofstream outfile("..\\unitcircle.dat",ios::binary);
    outfile.write(reinterpret_cast<char*>(&c1),sizeof(c1));
    return 0;
}
