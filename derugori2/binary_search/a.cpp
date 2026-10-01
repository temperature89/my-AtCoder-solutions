#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
// using long long ll;
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int A[n];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A[i] = a;
    }

    int left = -1;
    int right = n;

    while (abs(right - left) > 1) {
        int mid = (left + right) / 2;
        if (A[mid] > k) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if (right > n - 1) {
        cout << -1;
    } else {
        cout << right;
    }
    return 0;
}