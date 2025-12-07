#include <bits/stdc++.h>
using namespace std;

bool checkSame(vector<string> v) {
    string first = v[0];
    for (string chunk : v) {
        if (chunk != first) {
            return false;
        }
    }
    return true;
}

bool checkId(string s) {
    int len = s.length();
    vector<string> chunks;
    for (int i = 1; i < len; i++) {
        if (len%i == 0) {
            for (int j = 0; j < len; j+=i) {
                chunks.push_back(s.substr(j, i));
            }

            if (checkSame(chunks)) {
                return true;
            } else {
                chunks.clear();
            }
        }
    }
    return false;
}

int main() {
    string input, range, current;
    vector<string> ids;
    vector<long long> ids_num, invalid;

    ifstream inputFile("D2.txt");
    if (inputFile.is_open()) {
        getline(inputFile, input);
    }
    inputFile.close();

    for (char c : input) {
        if (c == ',' || c == '-') {
            ids.push_back(current);
            current.clear();
        } else {
            current.push_back(c);
        }
    }   
    ids.push_back(current);
    
    for (string id : ids) {
        ids_num.push_back(stoll(id));
    }

    // part 1
    // int num_len;
    // string n;

    // for (int i = 0; i < ids.size(); i+=2) {
    //     num_len = ids[i].length();

    //     if (num_len%2 == 0 || num_len != ids[i+1].length()){
    //         if (num_len == 1) {
    //             n = "1";
    //         } else {
    //             n = ids[i].substr(0, floor(num_len/2));
    //         }
            
    //         for (int a = stoi(n); a < pow(10, num_len); a++) {
    //             string pos = to_string(a) + to_string(a);
    //             long long pos_num = stoll(pos);

    //             if (pos_num >= ids_num[i]) {
    //                 if (pos_num <= ids_num[i+1]) {
    //                     invalid.push_back(pos_num);
    //                 } else {
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }


    // part 2
    for (int i = 0; i < ids.size(); i+=2) {
        for (long long a = ids_num[i]; a <= ids_num[i+1]; a++) {
            if (checkId(to_string(a))) {
                invalid.push_back(a);
            }
        }
    }

    long long count = 0;
    for (long long id : invalid) {
        // cout << id << endl;
        count += id;
    }
    cout << count;
}