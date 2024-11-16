#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int reps = 0;
    string romanNumber;
    
    unordered_map<char, int> conversions;
    conversions['I'] = 1;
    conversions['V'] = 5;
    conversions['X'] = 10;
    conversions['L'] = 50;
    conversions['C'] = 100;
    conversions['D'] = 500;
    conversions['M'] = 1000;

    cin >> reps;
    cin.ignore();

    for (int j = 0; j < reps; j++) {
        int res = 0;
        int acum = 0;
        int prevCount = 0;
        getline(cin, romanNumber);
        
        string prev = "";
        for (size_t i = 0; i < romanNumber.length(); i++) {
            if (prev == "") {
                acum += conversions[romanNumber[i]];
                prev = romanNumber[i];
            } else {
                if (romanNumber[i] == prev[0]) {
                    acum += conversions[romanNumber[i]];
                } else {
                    if (conversions[romanNumber[i]] < conversions[romanNumber[i-1]]) {
                        res += conversions[romanNumber[i]] + acum;
                    } else {
                        res += conversions[romanNumber[i]] - acum;
                    }
                    acum = 0;
                    prev = "";
                }
            }

            if (i == romanNumber.length() - 1 && acum > 0) {
                res += acum;
            }
        }
        cout << res << endl;
    }

    return 0;
}
