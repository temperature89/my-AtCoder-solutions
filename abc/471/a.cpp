#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    if (A + B == 9 || A - B == 9 || A * B == 9 || A == B * 9) {
        cout << "Nine";
    } else {
        cout << "Nein";
    }
    return 0;
}