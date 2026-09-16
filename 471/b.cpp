#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

int main()
{
    map<string, int> dict;
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        // transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (char &c : s) {
            c = tolower(c);
        }
        dict[s]++;
    }

    int mymax = -1;
    for (auto d : dict)
    {
        mymax = max(mymax, d.second);
    }
    cout << mymax;
    return 0;
}