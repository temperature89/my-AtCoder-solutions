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
    ll Q;
    string S, T;
    cin >> Q >> S >> T;

    // string rev_S = string(S.rbegin(), S.rend());
    // string rev_T = string(T.rbegin(), T.rend());
    vector<ll> mul(S.length(), 0);

    ll cnt = 0;
    ll T_len = T.length();
    rep(i, S.length()) {
        // if (rev_S[i] == rev_T[0] && rev_S.substr(i, rev_T.length()) == rev_T) {
        if (i >= T_len - 1) {
            if (S.substr(i - T_len + 1, T_len) == T) {
                cnt++;
            }
        }
        mul[i] = cnt;
    }
    
    rep(i, Q) {
        ll L, R;
        cin >> L >> R;
        L--; R--;
        // cout << mul[R] << "," << mul[L] << endl;
        if (R - L + 1 < T_len) {
            answer(false);
            continue;
        }
        ll left_idx = L + T_len - 2;
        if (left_idx < 0) {
            answer(mul[R] > 0);
        } else {
            answer(mul[R] - (mul[left_idx]) > 0);
        }
    }

    // printV(mul);
    return 0;
}


/*
bbbaaabbbaaaaaabbbab
11111122222222233333
bbbaaabbbaaaaaabbbab
00111111222222222333
 *   *
      * *

abcdabc
0111122

*/