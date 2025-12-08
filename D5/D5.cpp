#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("D5.txt");
    string line;
    vector<string> input;
    vector<long long> ingreds;
    vector<pair<long long, long long>> ranges;

    if (inputFile.is_open()) {
        while(getline(inputFile, line)) {
            input.push_back(line);
        }
    }
    inputFile.close();

    int split = distance(input.begin(), find(input.begin(), input.end(), ""));

    for (int i = 0; i < split; i++) {
        string range = input[i];
        for (int j = 0; j < range.length(); j++) {
            if (range[j] == '-') {
                ranges.push_back(make_pair(stoll(range.substr(0, j)), stoll(range.substr(j+1))));
            }
        }
    }

    // part 1
    // for (int i = split + 1; i < input.size(); i++) {
    //     ingreds.push_back(stoll(input[i]));
    // }

    // int count = 0;
    // for (long long food : ingreds) {
    //     for (pair<long long, long long> range : ranges) {
    //         if (range.first <= food && food <= range.second) {
    //             count++;
    //             break;
    //         }
    //     }
    // }
    // cout << count;

    // part 2
    sort(ranges.begin(), ranges.end());
    vector<pair<long long, long long>> new_ranges = {ranges[0]};

    for (pair<long long, long long> range : ranges) {
        if (new_ranges.back().second >= range.first) {
            new_ranges.back().second = max(new_ranges.back().second, range.second);
        } else {
            new_ranges.push_back(range);
        }
    }

    long long count = 0;
    for (pair<long long, long long> range : new_ranges) {
        count += range.second - range.first + 1;
    }

    cout << count;

}