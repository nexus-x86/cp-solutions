// https://dmoj.ca/problem/ccc01s3
// https://github.com/nexus-x86/cp-solutions
// Wednesday December 28 2022

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
const int mx = 2e3;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string in;
    cin >> in;
    int roads = 0;
    unordered_map<char, vector<char>> adjList;
    vector<pair<char, char>> connections;
    while (in != "**")
    {
        // path between in[0] and in[1]
        adjList[in[0]].push_back(in[1]);
        adjList[in[1]].push_back(in[0]);
        connections.push_back({in[0], in[1]});
        cin >> in;
    }

    for (pair<char, char> c : connections)
    {
        }

    cout << "There are " << roads << " disconnecting roads.\n";
}