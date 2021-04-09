#include <iostream>
#include <fstream>
#include "circle.h"

using namespace std;

int main() {
    ifstream infile("..\\unitcircle.dat", ios::binary);
    circle c;
    infile.read(reinterpret_cast<char*>(&c),sizeof(c));
    cout << c << endl;
}