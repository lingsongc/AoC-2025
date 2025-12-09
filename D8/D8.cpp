#include <bits/stdc++.h>
using namespace std;

float getDistance(string coord1, string coord2) {
    vector<int> c1, c2;
    string curr;
    
    for (char c : coord1) {
        if (c == ',') {
            c1.push_back(stoi(curr));
            curr.clear();
        } else {
            curr.push_back(c);
        }
    }
    c1.push_back(stoi(curr));
    curr.clear();

    for (char c : coord2) {
        if (c == ',') {
            c2.push_back(stoi(curr));
            curr.clear();
        } else {
            curr.push_back(c);
        }
    }
    c2.push_back(stoi(curr));
    curr.clear();

    return sqrt( pow(c1[0] - c2[0], 2) + pow(c1[1] - c2[1], 2) + pow(c1[2] - c2[2], 2));
}

long long getX(string coord) {
    string curr;
    for (char c : coord) {
        if (c == ',') {
            break;
        } else {
            curr.push_back(c);
        }
    }
    return stoll(curr);
}

int main() {
    vector<string> input;
    ifstream inputFile("D8.txt");
    string line;
    if (inputFile.is_open()) {
        while(getline(inputFile, line)) {
            input.push_back(line);
        }
    }
    inputFile.close();

    vector<array<float, 3>> dists;

    for (float i = 0; i < input.size() - 1; i++) {
        for (float j = i+1; j < input.size(); j++) {
            dists.push_back({getDistance(input[i], input[j]), i, j});
        }
    }

    sort(dists.begin(), dists.end());

    // part 1
    // vector<int> links[input.size()];
    // int numOfConnections = 20; // note that this value is 10 for the test case

    // for (int i = 0; i < numOfConnections; i++) {
    //     int index1 = dists[i][1], index2 = dists[i][2];

    //     links[index1].push_back(index2);
    //     links[index2].push_back(index1);
    // }

    // for (int i = 0; i < input.size(); i++) {
    //     vector<int> &curr_lst = links[i];
    //     if (!curr_lst.empty()) {
    //         for (int j = 0; j < curr_lst.size(); j++) {
    //             vector<int> &add_lst = links[curr_lst[j]];
                
    //             for (int k : add_lst) {
    //                 if (find(curr_lst.begin(), curr_lst.end(), k) == curr_lst.end() && k != i) {
    //                     curr_lst.push_back(k);
    //                 }
    //             }

    //             add_lst.clear();
    //         }
    //     }
    // }

    // vector<int> sizes;

    // for (vector<int> connected : links) {
    //     if (!connected.empty()) {
    //         sizes.push_back(connected.size() + 1);
    //     }
    // }

    // sort(sizes.begin(), sizes.end(), greater<int>());
    // cout << sizes[0] * sizes[1] * sizes[2];

    // part 2
    vector<vector<int>> graph;
    
    for (array<float, 3> entry : dists) {               // entry is of the format [distance, vertex1, vertex2]
        int vertex1 = entry[1], vertex2 = entry[2];     // the vertex, which is also the position of the junction box
        int pos1 = -1, pos2 = -1;                       // hold the position of the subgraph of vertex 1 and 2
        for (int i = 0; i < graph.size(); i++) {
            vector<int> &subgraph = graph[i];
            for (int vertex : subgraph) {
                if (vertex == vertex1) {
                    pos1 = i;
                } else if (vertex == vertex2) {
                    pos2 = i;
                }
                if (pos1 != -1 && pos2 != -1) {
                    break;
                }
            }
        }
        if (pos1 == -1) {                               // if vertex 1 is not found
            if (pos2 == -1) {                           // if vertex 2 is also not found
                graph.push_back({vertex1, vertex2});    // create a subgrapg with vertex 1 and 2
            } else if (pos2 != -1) {                    // if vertex 2 is found
                graph[pos2].push_back(vertex1);         // add vertex 1 to the subgraph of vertex 2
            }
        } else if (pos1 != -1) {                        // if vertex 1 is found
            if (pos2 == -1) {                           // if vertex 2 is not found
                graph[pos1].push_back(vertex2);         // add vertex 2 to the subgraph of vertex 1
            } else if (pos1 != pos2) {                  // if vertex 2 is also found
                graph[pos1].insert(graph[pos1].end(), graph[pos2].begin(), graph[pos2].end());  // merge the 2 subgraphs together
                graph.erase(graph.begin() + pos2);
            }
        }

        if (graph.size() == 1 && graph[0].size() == input.size()) {
            cout << getX(input[vertex1]) * getX(input[vertex2]);
            break;
        }

    }

}