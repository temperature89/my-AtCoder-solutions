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


// ll get_digit(ll n) {
    //     return to_string(n).length();
    // }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 修正箇所：i=19 のとき 10^19 となり ll を超えるため、定義済みの LL を使用
    vector<LL> p10(20, 1);
    rep2(i, 1, 20) {
        p10[i] = p10[i - 1] * 10;
    }
    ll L, R;
    ll mod = 1000000007;
    cin >> L >> R;
    ll ans = 0;

    rep2(i, 1, 20) {
        // 修正箇所：p10 に合わせてこちらも LL で受ける
        LL left_val = p10[i - 1];
        LL right_val = p10[i] - 1;

        // 修正箇所：max, min の引数の型を合わせるため L, R を LL にキャスト
        LL min_num = max((LL)L, left_val);
        LL max_num = min((LL)R, right_val);

        if (min_num > max_num) continue;
        // cout << min_num << "," << max_num << endl;
        LL num = (max_num - min_num + 1);
        LL sum_val = (LL)(min_num + max_num) * num / 2;
        sum_val %= mod;
        LL add = (sum_val * i) % mod;
        ans = (ans + (ll)add) % mod;
    }
    cout << ans << "\n";
    return 0;
}