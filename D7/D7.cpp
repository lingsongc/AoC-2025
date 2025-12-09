#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> input;
    ifstream inputFile("D7.txt");
    string line;
    if (inputFile.is_open()) {
        while(getline(inputFile, line)) {
            input.push_back(line);
        }
    }
    inputFile.close();

    long long count = 0;
    int row_len = input[0].length();
    long long beams[row_len];

    // part 1
    // beams[input[0].find('S')] = 1;
    // for (string row : input) {
    //     for (int i = 0; i < row_len; i++) {
    //         if (beams[i] == 1 && row[i] == '^') {
    //             beams[i-1] = 1;
    //             beams[i+1] = 1;
    //             beams[i] = 0;
    //             count ++;
    //         }
    //     }
    // }

    //part 2
    for (int i = 0; i < row_len; i++) {
        beams[i] = 0;
    }
    beams[input[0].find('S')] = 1;

    for (string row : input) {
        for (int i = 0; i < row_len; i++) {
            if (beams[i] > 0 && row[i] == '^') {
                beams[i-1] += beams[i];
                beams[i+1] += beams[i];
                beams[i] = 0;
            }

        }
    }
    for (long long i : beams) {
        count += i;
    }

    cout << count;
}