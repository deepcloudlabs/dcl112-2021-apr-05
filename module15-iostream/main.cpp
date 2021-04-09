#include <iostream>
#include <fstream>
#include "circle.h"

using namespace std;

int main() {
    circle c1(1,2,3);
    circle c2(4,5,6);
    cout << c1 << endl;
    cout << c1.area() << endl;
    cout << c2 << endl;
    cout << c2.area() << endl;
    ofstream outfile("..\\unitcircle.dat",ios::binary);
    outfile.write(reinterpret_cast<char*>(&c1),sizeof(c1));
    outfile.write(reinterpret_cast<char*>(&c2),sizeof(c2));
    return 0;
}
