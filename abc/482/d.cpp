#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
// #include <boost/multiprecision/cpp_int.hpp>  //遅いけど実装が楽になるかも

using ll = long long;
using ull = unsigned long long;
using ll2 = pair<ll, ll>;
using ll3 = tuple<ll, ll, ll>;
using ll4 = tuple<ll, ll, ll, ll>;
using ll5 = tuple<ll, ll, ll, ll, ll>;

// using boost::multiprecision::cpp_int;  // 遅いけど実装が楽になるかも
using LL = __int128_t;
using LL2 = pair<LL, LL>;

#define rep(i, k) for (ll i = 0; i < (ll)(k); i++)
#define repR(i, k) for (ll i = k - 1; i >= 0; i--)
#define rep2(i, l, r) for (ll i = l; i < (ll)(r); i++)
#define repR2(i, l, r) for (ll i = r - 1; i >= l; i--)
#define all(v) v.begin(), v.end()
#define PB push_back
#define INP(X) rep(zzz, X.size()) cin >> X[zzz]
#define INP2(X, Y) rep(zzz, X.size()) cin >> X[zzz] >> Y[zzz]
#define INP3(X, Y, Z) rep(zzz, X.size()) cin >> X[zzz] >> Y[zzz] >> Z[zzz]
#define INP4(X, Y, Z, W) \
    rep(zzz, X.size()) cin >> X[zzz] >> Y[zzz] >> Z[zzz] >> W[zzz]
#define DEC(X) rep(zzz, X.size()) X[zzz]--

const ll INF = 2e18;  // INF+INFがオーバフローしない程度の大きい値
void answer(bool res) {
    if (res)
        cout << "Yes\n";
    else
        cout << "No\n";
}

template <typename T>
void printV(T A) {
    for (auto a : A) {
        cout << a << " ";
    }
    cout << endl;
}

#define DEBUG true  // DEBUG=trueのときデバッグ表示ON
// #define DEBUG false
template <class... VARTYPE>
void dprint(VARTYPE... a) {
    if (DEBUG) printf(a...);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    vector<ll> X(N,0);
    INP(X);
    ll b = X.front();
    ll e = X.back();
    rep(i,N) {
        ll k = X[i];
        if (i == 0 || i == X.size() - 1) {
            cout << (e - b) / 2 << endl;
        // } else if (k - b < e - k) {
        //     ll length = (e - k) / 2;
        //     ll b_length = (X[i + 1] - b) / 2;
        //     cout << max(length, b_length) << endl;
        // } else if (k - b > e - k) {
        //     ll length = (k - b) / 2;
        //     ll e_length = (e - X[i - 1]) / 2;
        //     // cout << length << "," << e_length << en÷dl;
        //     cout << max(length, e_length) << endl;
        // } else {
        //     ll length = (k - b) / 2;
        //     ll be_length;
        //     if (X[i + 1] - k < k - X[i - 1]) {
        //         be_length = (X[i + 1] - b) / 2;
        //     } else {
        //         be_length = (e - X[i - 1]) / 2;
        //     }
        //     cout << max(length, be_length) << endl;
        // }
        } else {
            ll left = max((k - b) / 2, (e - X[i - 1]) / 2);
            ll right = max((X[i + 1] - b) / 2, (e - k) / 2);
            cout << min(left, right) << endl;
        }
    }

    return 0;
}