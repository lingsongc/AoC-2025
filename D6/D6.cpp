#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> input;
    vector<vector<int>> nums;

    ifstream inputFile("D6.txt");
    string line;
    if (inputFile.is_open()) {
        while(getline(inputFile, line)) {
            input.push_back(line);
        }
    }
    inputFile.close();

    // part 1
    // int args = input.size() - 1;
    // string ops = input.back();
    // string curr_num;

    // for (int i = 0; i < args; i++) {
    //     nums.push_back({});
    //     for (char c : input[i]) {
    //         if (c == ' ') {
    //             if (!curr_num.empty()) {
    //                 nums[i].push_back(stoi(curr_num));
    //             }
    //             curr_num.clear();
    //         } else {
    //             curr_num.push_back(c);
    //         }
    //     }
    //     if (!curr_num.empty()) {
    //         nums[i].push_back(stoi(curr_num));
    //     }
    //     curr_num.clear();;
    // }

    // ops.erase(remove_if(ops.begin(), ops.end(), ::isspace), ops.end());

    // long long total = 0, countRound;

    // for (int i = 0; i < ops.length(); i++) {
    //     if (ops[i] == '+') {
    //         countRound = 0;
    //         for (int j = 0; j < args; j++) {
    //             countRound += nums[j][i];
    //         }
    //     } else {
    //         countRound = 1;
    //         for (int j = 0; j < args; j++) {
    //             countRound *= nums[j][i];
    //         }
    //     }

    //     total += countRound;
    // }

    // cout << total << endl;

    //part 2
    int args = input.size() - 1;
    string num = "";
    vector<int> colNums;

    string ops = input.back();
    ops.erase(remove_if(ops.begin(), ops.end(), ::isspace), ops.end());
    int op_i = 0;
    long long countCol, total = 0;
    
    for (int i = 0; i < input[0].length(); i++) {
        for (int j = 0; j < args; j++) {
            if (input[j][i] != ' ') {
                num += input[j][i];
            }
        }
        
        if (num != "") {
            colNums.push_back(stoi(num));
            num = "";
        } else {
            if (ops[op_i] == '+') {
                countCol = 0;
                for (int k = 0; k < colNums.size(); k++) {
                    countCol += colNums[k];
                }
            } else {
                countCol = 1;
                for (int k = 0; k < colNums.size(); k++) {
                    countCol *= colNums[k];
                }
            }
            total += countCol;
            colNums.clear();
            op_i++;
        }  
    }

    //account for last column
    if (ops[op_i] == '+') {
        countCol = 0;
        for (int k = 0; k < colNums.size(); k++) {
            countCol += colNums[k];
        }
    } else {
        countCol = 1;
        for (int k = 0; k < colNums.size(); k++) {
            countCol *= colNums[k];
        }
    }
    total += countCol;

    cout << total << endl;

}