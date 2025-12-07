#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> instruc;
    int dial = 50;

    ifstream inputFile("D1.txt");
    string line;
    if (inputFile.is_open()) {
        while(getline(inputFile, line)) {
            instruc.push_back(line);
        }
    }
    inputFile.close();
    
    int num;
    int count = 0;
    
    // part 1
    // for (string inst : instruc) {
    //     if (inst[0] == 'L') {
    //         num = stoi(inst.erase(0, 1));
    //         dial -= num;
    //     } else if (inst[0] == 'R') {
    //         num = stoi(inst.erase(0, 1));
    //         dial += num;
    //     }

    //     while (dial < 0) {
    //         dial = 100 + dial;
    //     }
    //     while (dial > 99) {
    //         dial = dial - 100;
    //     }

    //     if (dial == 0) {
    //         count++;
    //     }

    //     cout << "dial " << dial << endl;
    // }

    //part 2
    for (string inst : instruc) {
        if (inst[0] == 'L') {
            num = stoi(inst.erase(0, 1));
            dial -= num;
        } else if (inst[0] == 'R') {
            num = stoi(inst.erase(0, 1));
            dial += num;
        }

        while (dial < 0) {
            if (dial != -1*num) {
                count++;
            }
            dial = 100 + dial;

        }
        while (dial > 99) {
            if (dial != 100) {
                count++;
            }
            dial = dial - 100;
            
        }

        if (dial == 0) {
            count++;
        }

        //cout << "dial " << dial << endl;
    }

    cout << count;

}