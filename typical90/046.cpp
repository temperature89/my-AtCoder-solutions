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
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    INP(A);
    INP(B);
    INP(C);
    rep(i, N) {
        A[i] %= 46;
        B[i] %= 46;
        C[i] %= 46;
    }
    sort(all(A));
    sort(all(B));
    sort(all(C));
    // printV(A);
    // printV(B);
    // printV(C);
    vector<ll> A_fd(46, 0);
    vector<ll> B_fd(46, 0);
    vector<ll> C_fd(46, 0);
    
    rep(i, N) {
        A_fd[A[i]]++;
        B_fd[B[i]]++;
        C_fd[C[i]]++;
    }
    // printV(A_fd);
    // printV(B_fd);
    // printV(C_fd);
    ll ans = 0;
    rep(i, 46) {
        if (A_fd[i] == 0) continue;
        rep(j, 46) {
            if (B_fd[j] == 0) continue;
            int idx = (46 - (i + j) % 46) % 46;
            if (C_fd[idx] == 0) continue;
            // cout << i << "," << j << "," << idx << endl;;
            // cout << A_fd[i] * B_fd[j] * C_fd[idx] << endl;
            ans += A_fd[i] * B_fd[j] * C_fd[idx];
        }
    }
    cout << ans;
    // rep(i, N) {
    //     auto idx = lower_bound(B.begin(), B.end(), A[i]);
        


    // }
    return 0;
}