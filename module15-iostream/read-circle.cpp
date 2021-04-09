#include <iostream>
#include <fstream>
#include "circle.h"

using namespace std;

int main() {
    ifstream infile("..\\unitcircle.dat", ios::binary);
    while (!infile.eof()) {
        circle c;
        infile.read(reinterpret_cast<char *>(&c), sizeof(c));
        if (!infile.eof() && infile.good())
            cout << c << endl;
    }
}