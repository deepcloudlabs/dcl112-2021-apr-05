#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <regex>

using namespace std;

int main() {
    ifstream dictionary("..\\dictionary.txt");
    ifstream cards("..\\credit-cards.txt");
    vector<string> words;
    vector<string> creditCards;
    string line;
    smatch result;
    // const regex pattern("^[^eiauo]+$");
    // const regex pattern("^[aA][a-zA-Z]{3}[zZ]$");
    const regex pattern("^\\s+$");
    const regex ccpattern("^([0-9]{4}-){3}[0-9]{4}\\s*$");

    while (getline(dictionary, line)) {
        words.push_back(line);
    }
    while (getline(cards, line)) {
        creditCards.push_back(line);
    }
    // external loop
    /*
    for (auto &word : words){
        if (regex_search(word, result, pattern)) {
            // cout << word << endl;
        }
    }
     */
    // internal loop
        int empty=0;
        int count=0;
        int valid=0;
    for_each(creditCards.begin(),creditCards.end(),[&valid,&ccpattern,&empty,&count,&pattern,&result](string& word){
        if (regex_search(word, result, pattern)) {
            empty++;
        } else {
            count++;
            if (regex_search(word, result, ccpattern)) {
                valid++;
            }
        }
    });
    cout << "empty: " << empty
         << ", non-empty: " << count
         << ", valid: " << valid
         << endl;
    /*
    sort(words.begin(),words.end(),[](auto& left,auto& right){
       return left.length() > right.length();
    });
    for_each(words.begin(),words.end(),[](auto &word){
       cout << word << endl;
    });
     */
    return 0;
}
