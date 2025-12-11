#include <bits/stdc++.h>
using namespace std;

long long getArea(array<long long, 2> coord1, array<long long, 2> coord2) {
    long long x1 = coord1[0], y1 = coord1[1], x2 = coord2[0], y2 = coord2[1];
    return (abs(x1-x2)+1) * (abs(y1-y2)+1);
}

// for part 2
int compressVal(int val, const vector<long long> &arr) {
    return lower_bound(arr.begin(), arr.end(), val) - arr.begin();
}

void sortUnique(vector<long long> &vals) {
    sort(vals.begin(), vals.end());
    long long compare = -1;
    for (int i = 0; i < vals.size(); i++) {
        long long num = vals[i];
        if (num != compare) {
            compare = num;
        } else {
            vals.erase(vals.begin()+i);
            i--;
        }
    }
    return;
}

void drawOutline(vector<string> &arr, const array<int, 2> &coords1, const array<int, 2> &coords2) {
    int x1 = min(coords1[0], coords2[0]), x2 = max(coords1[0], coords2[0]);
    int y1 = min(coords1[1], coords2[1]), y2 = max(coords1[1], coords2[1]);
    
    for (int c = x1; c <= x2; c++) {
        for (int r = y1; r <= y2; r++) {
            arr[r][c] = 'O';
        }
    }
    return;
}

void fillOutside(vector<string> &arr){
    int H = arr.size(), W = arr[0].length();

    for (string &row : arr) {
        for (int i = 0; i < W; i++) {
            if (row[i] == 'O') {
                break;
            } else {
                row[i] = 'X';
            }
        }
        for (int i = W-1; i >=0; i--) {
            if (row[i] == 'O') {
                break;
            } else {
                row[i] = 'X';
            }
        }
    }

    for (int c = 0; c < W; c++) {
        for (int r = 0; r < H; r++) {
            if (arr[r][c] == 'O') {
                break;
            } else {
                arr[r][c] = 'X';
            }
        }
        for (int r = H-1; r >= 0; r--) {
            if (arr[r][c] == 'O') {
                break;
            } else {
                arr[r][c] = 'X';
            }
        }
    }    
    return;
}

bool checkValid(const vector<string> &arr, const array<int, 2> &coords1, const array<int, 2> &coords2){
    int x1 = min(coords1[0], coords2[0]), x2 = max(coords1[0], coords2[0]);
    int y1 = min(coords1[1], coords2[1]), y2 = max(coords1[1], coords2[1]);

    for (int c = x1; c <= x2; c++) {
        for (int r = y1; r <= y2; r++) {
            if (arr[r][c] == 'X') {
                return false;
                break;
            }
        }
    }
    return true;
}

int main() {
    vector<array<long long, 2>> input;
    ifstream inputFile("D9.txt");
    string line;
    long long coords[2];

    vector<long long> xvals, yvals; // for part 2

    if (inputFile.is_open()) {
        while(getline(inputFile, line)) {
            size_t index = line.find(',');
            long long x = stoll(line.substr(0, index));
            long long y = stoll(line.substr(index+1));
            input.push_back({x, y});
            xvals.push_back(x); // for part 2
            yvals.push_back(y); // for part 2
        }
    }
    inputFile.close();

    long long biggest = 0;

    // part 1
    // for (int i = 0; i < input.size(); i++) {
    //     for (int j = i+1; j < input.size(); j++) {
    //         long long area = getArea(input[i], input[j]);
    //         if (area > biggest) {
    //             biggest = area;
    //         }
    //     }
    // }

    // part 2
    sort(xvals.begin(), xvals.end());
    xvals.erase(unique(xvals.begin(), xvals.end()), xvals.end());
    sort(yvals.begin(), yvals.end());
    yvals.erase(unique(yvals.begin(), yvals.end()), yvals.end());

    vector<array<int, 2>> inputComp;
    for (array<long long, 2> coord : input) {
        int cx = compressVal(coord[0], xvals);
        int cy = compressVal(coord[1], yvals);
        inputComp.push_back({cx, cy});
    }
    // everything above is to compress the coordinates so that it is more manageable

    // here i drew the outline between the points and fill the outside
    int rownum = xvals.size();
    int colnum = yvals.size();
    string row(colnum, '.');
    vector<string> diagram(rownum, row);
    for (int i = 0; i < inputComp.size(); i++) {
        if (i == inputComp.size()-1) {
            drawOutline(diagram, inputComp[i], inputComp[0]);
        } else {
            drawOutline(diagram, inputComp[i], inputComp[i+1]);
        }
    }
    fillOutside(diagram);

    for (int i = 0; i < input.size(); i++) {
        for (int j = i+1; j < input.size(); j++) {
            long long area = getArea(input[i], input[j]);
            if (area > biggest) {
                if (checkValid(diagram, inputComp[i], inputComp[j])) { //added a check to see if the rectangle is valid
                    biggest = area;
                }
            }
        }
    }

    cout << biggest;
}