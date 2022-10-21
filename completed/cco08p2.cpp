// https://dmoj.ca/problem/cco08p2
// https://github.com/nexus-x86/cp-solutions
// Saturday October 15 2022

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
vector < int > p, height, setSize;
int numSets;
void initialize(int N) {
  p.assign(N, 0);
  for (int i = 0; i < N; ++i)
    p[i] = i;
  height.assign(N, 0); // optional speedup
  setSize.assign(N, 1); // optional feature
  numSets = N - (N/20) * 19; // optional feature
}
int findSet(int i) {
  if (p[i] == i)
    return i;
  p[i] = findSet(p[i]); // Path Compression

  // debug
   // cout << "Node: "<< i << " found in " << findSet(p[i]) << "\n"; 
  // debug
  return p[i];
}
bool isSameSet(int i, int j) {
  return findSet(i) == findSet(j);
}

int numDisjointSets() // optional
{
  return numSets;
}
int sizeOfSet(int i) // optional
{
  return setSize[findSet(i)];
}

void unionSet(int i, int j) {
  if (isSameSet(i, j)) // i and j are in same set
    return;
  int x = findSet(i); // find rep items
  int y = findSet(j); // find rep items
  if (height[x] > height[y])
    swap(x, y); // Union by rank
  p[x] = y; // set x under y
  if (height[x] == height[y])
    ++height[y]; // optional speedup
  setSize[y] += setSize[x]; // combine set sizes at y
  --numSets; // a union reduces numSets
}

unordered_map<string, int> nums;

int main() {
    int m,n;
    cin >> m >> n;
    initialize(m*20); // max number of streets given input
    // times 2 because everything could just be unique
    // times another 2 to account for perpendicular vals
    // adding 1 so we get * 5 to avoid a segfault
    // adding 15 to avoid a segfault
    // worked
    int runningCounter = 0;
    for (int i = 0; i < m; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        if (nums.find(a) == nums.end()) { // a not in nums
            nums[a] = runningCounter;
            // adding "hgja1012" at the end of string to indicate perpendicular
            runningCounter++;
            nums[a+"hgja1012"] = runningCounter;
            runningCounter++;
        }
        if (nums.find(b) == nums.end()) {
            nums[b] = runningCounter;
            runningCounter++;
            nums[b+"hgja1012"] = runningCounter;
            runningCounter++;
        }
        if (c == "parallel") {
            unionSet(nums[a+"hgja1012"],nums[b+"hgja1012"]); 
            // adding this line of code made submissions work for all testcases, AC'ing this question for me.
            // this code is important because we realize that if 2 lines are parallel, their perpendicular lines are parallel
            unionSet(nums[a],nums[b]);
        } else if (c == "intersect") {
            unionSet(nums[a+"hgja1012"],nums[b]);
            unionSet(nums[a],nums[b+"hgja1012"]);
            //intersecting lines are assumed to be perpendicular, (follows manhatten assumption)
            // if statement below checks whether or not this is true

            if (isSameSet(nums[a+"hgja1012"],nums[b+"hgja1012"])) {
                cout << "Waterloo" << "\n";
                return 0;
            }
        }
    }
    // in cities following the manhatten assumption (code that runs past this point)
    // all lines can really only be vertical and horizontal
    // all vert's will intersect with all horiz's
    // and vice versa
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (nums.find(a) == nums.end()) { // a not in nums
            nums[a] = runningCounter;
            // adding "hgja1012" at the end of string to indicate perpendicular
            runningCounter++;
            //nums[a+"hgja1012"] = runningCounter;
            nums.insert(make_pair(a+"hgja1012",runningCounter));
            runningCounter++;
        }
        if (nums.find(b) == nums.end()) {
            nums[b] = runningCounter;
            runningCounter++;
           // nums[b+"hgja1012"] = runningCounter;
            nums.insert(make_pair(b+"hgja1012",runningCounter));
            runningCounter++;
        }
        
        
        if (isSameSet(nums[a],nums[b]) || isSameSet(nums[a+"hgja1012"],nums[b+"hgja1012"])) {
            cout << "parallel" << "\n";
        } else if (isSameSet(nums[a+"hgja1012"],nums[b]) || isSameSet(nums[a],nums[b+"hgja1012"])) {
            cout << "intersect" << "\n";
        } else {
            cout << "unknown" << "\n";
        }
    }
}

// make additional entries in the disjoint data structure for perpendicular streets to each street
// street1 should have a street1 perpendicular
// so if street 2 is perpendicular to street 1 then street2 and street1 perpendicular should be in the same set
