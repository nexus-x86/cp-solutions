// https://dmoj.ca/problem/ccc00s3
// https://github.com/nexus-x86/cp-solutions
// Monday December 26 2022

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, vector<string>> adjList;

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string website;
        getline(cin, website);

        string currLine;
        getline(cin, currLine);

        // cout << "Website is " << website << ".\n";
        // cout << "First line is " << currLine << ".\n";

        while (currLine != "</HTML>")
        {
            size_t firstOccurrence = currLine.find('"');
            if (firstOccurrence == string::npos)
            {
                // cin.ignore();
                getline(cin, currLine);
                continue;
            }
            currLine = currLine.substr(firstOccurrence + 1);
            size_t secondOccurrence = currLine.find('"');

            string currWebsite = currLine.substr(0, secondOccurrence);
            adjList[website].push_back(currWebsite);

            cout << "Link from " << website << " to " << currWebsite << "\n";

            currLine = currLine.substr(secondOccurrence + 1);
        }
    }

    string query, query2;
    getline(cin, query);
    getline(cin, query2);

    while (query != "The End")
    {
        stack<string> myStack;
        unordered_map<string, int> visited;
        myStack.push(query);
        int flag = 0;
        while (!myStack.empty())
        {
            string a = myStack.top();

            if (a == query2)
            {
                flag = 1;
                break;
            }

            myStack.pop();

            for (string b : adjList[a])
            {
                if (visited[b] == 0)
                {
                    visited[b] = 1;
                    myStack.push(b);
                }
            }
        }
        if (flag == 1)
        {
            cout << "Can surf from " << query << " to " << query2 << ".\n";
        }
        else
        {
            cout << "Can't surf from " << query << " to " << query2 << ".\n";
        }
        getline(cin, query);
        getline(cin, query2);
    }

    return 0;
}