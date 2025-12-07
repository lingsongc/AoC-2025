#include <bits/stdc++.h>
using namespace std;

bool checkExist(int r, int c, int max_r, int max_c, const vector<string>& arr) {
    if (r < 0 || c < 0 || r >= max_r || c >= max_c) {
        return false;
    } else if (arr[r][c] == '.') {
        return false;
    } else {
        return true;
    }

}

int main() {
    ifstream inputFile("D4.txt");
    string line;
    vector<string> arr;

    if (inputFile.is_open()) {
        while(getline(inputFile, line)) {
            arr.push_back(line);
        }
    }
    inputFile.close();

    int row = arr.size();
    int col = arr[0].length();
    int countTotal = 0;

    // part 1
    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         if (arr[i][j] == '@') {
    //             int countAround = 0;
                
    //             for (int r = i-1; r <= i+1; r++) {
    //                 for (int c = j-1; c <= j+1; c++) {
    //                     if (checkExist(r, c, row, col, arr)) {
    //                         countAround++;
    //                     }
    //                 }
    //             }

    //             if (countAround-1 < 4) {
    //                 countTotal++;
    //             }
    //         }
    //     }
    // }

    // part 2
    vector<pair<int, int>> coords;
    int countPerRound = -1;
    while (countPerRound != 0) {
        countPerRound = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (arr[i][j] == '@') {
                    int countAround = 0;
                    
                    for (int r = i-1; r <= i+1; r++) {
                        for (int c = j-1; c <= j+1; c++) {
                            if (checkExist(r, c, row, col, arr)) {
                                countAround++;
                            }
                        }
                    }

                    if (countAround-1 < 4) {
                        countPerRound++;
                        coords.push_back(make_pair(i, j));
                    }
                }
            }
        }

        for (int x = 0; x < coords.size(); x++) {
            arr[coords[x].first][coords[x].second] = '.';
        }
        coords.clear();
        countTotal += countPerRound;
    }


    cout << countTotal;

}