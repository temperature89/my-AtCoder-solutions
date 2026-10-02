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
    ll N, D;
    cin >> N >> D;
    vector<ll> X(N, 0);
    INP(X);
    vector<vector<ll>> XX(N, vector<ll>(2));
    rep(i, N) {
        XX[i][0] = X[i];
        XX[i][1] = i + 1;
    }
    sort(all(XX));
    vector<ll> issen(0,0);

    if (XX[1][0] - XX[0][0] >= D) {
        issen.push_back(XX[0][1]);
    }

    rep2(i, 1, N - 1) {
        if (XX[i][0] - XX[i - 1][0] >= D && XX[i + 1][0] - XX[i][0] >= D) {
            issen.push_back(XX[i][1]);
        }
    }

    if (XX[N - 1][0] - XX[N - 2][0] >= D) {
        issen.push_back(XX[N - 1][1]);
    }
    sort(all(issen));
    cout << issen.size() << endl;
    printV(issen);
    return 0;
}