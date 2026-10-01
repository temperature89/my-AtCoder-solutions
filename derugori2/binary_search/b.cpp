#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
using ll = long long;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    auto ans = lower_bound(a[0], a[n], 4);
    return 0;
}