#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string,int> areaCodes;
    areaCodes[string("ankara")] = 312;
    areaCodes[string("istanbul-anadolu")] = 216;
    areaCodes[string("istanbul-avrupa")] = 212;

    auto code = areaCodes.find(string("ankara"));
    cout << code->second << endl;
    cout << areaCodes[string("ankara")] << endl;
    if (areaCodes.find(string("izmir")) == areaCodes.end()){
        cerr << "Cannot find izmir in the map!" << endl;
    }
    for (auto const& [city,code] : areaCodes){
        cout << city << " : " << code << endl;
    }
}
