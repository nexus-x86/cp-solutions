// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=403
// https://github.com/nexus-x86/cp-solutions
// Friday December 30 2022

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string cards;

    unordered_map<char, int> mapping = {
        {'S', 0},
        {'H', 1},
        {'C', 2},
        {'D', 3}};
    unordered_map<int, string> rMapping = {
        {0, "S"},
        {1, "H"},
        {2, "C"},
        {3, "D"}};

    while (getline(cin, cards))
    {
        stringstream stream(cards);

        vector<vector<char>> myCards(4, vector<char>(0));
        int stopped[4];
        memset(stopped, 0, sizeof(stopped));
        // while (true)
        // {
        //     string a;
        //     stream >> a;
        //     myCards[mapping[a[1]]].push_back(a[0]);
        //     if (!stream)
        //     {
        //         break;
        //     }
        // }
        for (int i = 0; i < 13; i++)
        {
            string a;
            stream >> a;
            myCards[mapping[a[1]]].push_back(a[0]);
        }
        int points = 0;
        int tooBeAdded = 0;
        for (int i = 0; i < 4; i++)
        {
            if (find(myCards[i].begin(), myCards[i].end(), 'K') != myCards[i].end())
            {
                points += 3;
                if (myCards[i].size() == 1)
                {
                    points--;
                }
                else
                {
                    stopped[i] = 1;
                }
            }
            if (find(myCards[i].begin(), myCards[i].end(), 'A') != myCards[i].end())
            {
                points += 4;
                stopped[i] = 1;
            }
            if (find(myCards[i].begin(), myCards[i].end(), 'Q') != myCards[i].end())
            {
                points += 2;
                if (myCards[i].size() <= 2)
                {
                    points--;
                }
                if (myCards[i].size() >= 3)
                {
                    stopped[i] = 1;
                }
            }
            if (find(myCards[i].begin(), myCards[i].end(), 'J') != myCards[i].end())
            {
                points += 1;
                if (myCards[i].size() <= 3)
                {
                    points--;
                }
            }
            if (myCards[i].size() == 2)
            {
                tooBeAdded++;
            }
            else if (myCards[i].size() == 1)
            {
                tooBeAdded += 2;
            }
            else if (myCards[i].size() == 0)
            {
                tooBeAdded += 2;
            }
        }

        // cout << points << "\n";
        // cout << tooBeAdded << "\n";
        // for (int i = 0; i < 4; i++)
        // {
        //     for (char c : myCards[i])
        //     {
        //         cout << c << " ";
        //     }
        //     cout << "\n";
        // }

        if (points + tooBeAdded < 14)
        {
            cout << "PASS\n";
        }
        else if (points >= 16 && stopped[0] == 1 && stopped[1] == 1 && stopped[2] == 1 && stopped[3] == 1)
        {
            cout << "BID NO-TRUMP\n";
        }
        else
        {
            int maxCards = -1;
            string suit = "A";
            // Priority
            // S H D C

            for (int i = 0; i < 4; i++)
            {
                // cout << (int)myCards[i].size() << "\n";

                int myCardSize = 0;
                for (char c : myCards[i])
                {
                    if (c == ' ')
                    {
                        continue;
                    }
                    // cout << c << " ";
                    myCardSize++;
                }

                // cout << myCardSize << "\n";

                if (myCardSize > maxCards)
                {
                    maxCards = myCardSize;
                    suit = rMapping[i];
                }
                else if (myCardSize == maxCards && rMapping[i] > suit)
                {
                    maxCards = myCardSize;
                    suit = rMapping[i];
                }
            }
            cout << "BID " << suit << "\n";
        }
    }
}