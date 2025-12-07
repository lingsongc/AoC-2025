#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("D3.txt");
    string line;
    vector<string> banks;
    vector<int> jolts;
    vector<char> values = {'9','8','7','6','5','4','3','2','1'};

    if (inputFile.is_open()) {
        while(getline(inputFile, line)) {
            banks.push_back(line);
        }
    }
    inputFile.close();

    // part 1;
    // size_t found;
    // int total;
    // for (string batt : banks) {
    //     string jolt;
        
    //     for (char v : values) {
    //         found = batt.substr(0, batt.length()-1).find(v);
    //         if (found != string::npos) {
    //             jolt = v;
    //             break;
    //         } 
    //     }
    //     for (char v : values) {
    //         if (batt.find(v, found+1) != string::npos) {
    //             jolt = jolt + v;
    //             break;
    //         } 
    //     }
    //     //cout << jolt << endl;
    //     total += stoi(jolt);

    // } 

    // part 2;
    size_t found = 0;
    long long total = 0;

    for (string batt : banks) {
        string jolt = "";
        int start = 0;
        int batt_len = batt.length();

        for (int i = 11; i>=0; i--) {
            for (char v : values) {
                found = batt.substr(start, batt_len-i-start).find(v);
                if (found != string::npos) {
                    //cout << batt.substr(start, batt_len-i-start) << endl;
                    jolt = jolt + v;
                    start += found + 1;
                    //cout << i << "; " << found << " " << start << endl;
                    break;
                } 
            }
        }
        cout << jolt << endl;
        total += stoll(jolt);

    } 

    cout << total;
}