// #define DEBUG true  // DEBUG=trueのときデバッグ表示ON
#define DEBUG false

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#include <algorithm>
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

// pairの出力用 (vectorの中にpairが入っている場合などに便利)
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

// vectorの出力用
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i] << (i == v.size() - 1 ? "" : " ");
    }
    os << "]";
    return os;
}

ll MOD = 1000000007;

template <typename... Args>
void dprint(Args... args) {
    if (!DEBUG) return; // デバッグOFF時は何もしない

    if constexpr (sizeof...(args) > 0) {
        int i = 0;
        int size = sizeof...(args);
        // 最後の要素以外は直後に "," を出力する
        ((cout << args << (++i < size ? "," : "")), ...);
    }
    cout << endl; // 最後に改行
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    string S;
    cin >> N >> S;
    string target = "atcoder";
    // dp[j] = targetの先頭j文字目までを作る通り数
    vector<ll> dp(8,0);
    dp[0] = 1;
    rep(i, N) {
        rep(j, 7) { 
            if (S[i] == target[j]) {
                dp[j + 1] = (dp[j + 1] + dp[j]) % MOD;
            }
        }
    }
    cout << dp[7];
    // vector<char> atcoder = {'a','t','c','o','d','e','r'};
    // vector<ll> counter(7,0);
    // vector<char> str(0);
    // rep(i,N) {
    //     if (find(atcoder.begin(), atcoder.end(), S[i]) != atcoder.end()) {
    //         str.PB(S[i]);
    //     }
    // }
    // dprint(str);
    // ll i = -1;
    // ll j = 0;
    // ll ans = 0;
    // ll M = str.size();
    // rep(k,M) {
    //     if (str[k] == 'a') {
    //         i = k;
    //         break;
    //     }
    // }
    // if (i == -1) {
    //     cout << 0;
    //     exit(0);
    // }
    // dprint(M);
    // while (i < M) {
    //     if (str[i] == atcoder[j]) { 
    //         counter[j] = (counter[j] + 1) % MOD;
    //     }
    //     dprint(atcoder[j]);
    //     if (str[i] == atcoder[(j + 1) % 7]) {
    //         counter[(j + 1) % 7] = (counter[(j + 1) % 7] + 1) % MOD;
    //         if (atcoder[(j + 1) % 7] == 'a') {
    //             ll cnt = 1;
    //             rep(k,7) {
    //                 cnt *= counter[k] % MOD;
    //                 cnt %= MOD;
    //             } 
    //             ans = (ans + cnt) % MOD;
    //             counter.assign(7,0);
    //         }
    //         j++;
    //         j %= 7;
    //     }
    //     if (atcoder[j] == 'r' && i == M - 1) {
    //         dprint("aaa");
    //         ll cnt = 1;
    //         rep(k,7) {
    //             cnt *= counter[k] % MOD;
    //             cnt %= MOD;
    //         } 
    //         ans = (ans + cnt) % MOD;
    //         counter.assign(7,0);
    //     }
    //     i++;
    //     dprint(atcoder[j],counter);
    // }
    // cout << ans % MOD << '\n';
    return 0;
}

/*
20
atcodeeeeeerrrrrrrrrr
 
*/