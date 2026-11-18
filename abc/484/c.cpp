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
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    INP(A);
    INP(B);
    A.PB(-1);
    B.PB(-1);
    ll diff_a = -1;
    ll diff_b = -1;
    ll diff_idx = -1;
    ll i = 0;
    ll j = 0;
    while (!(A[i] == -1 || B[j] == -1)) {
        if(A[i] != B[j]) {
            dprint(A[i], B[j]);
            diff_a = A[i];
            diff_b = B[j];
            diff_idx = i;
            break;
        }
        i++;
        j++;
    }
    if (diff_idx == -1) { 
        answer(true);
        exit(0);
    }

    // 数字の大きいものを挿入した場合
    i = diff_idx;
    j = diff_idx + 1;
    bool flag = false;
    while (true) {
        if (A[i] != B[j]) {
            if (flag == false) {
                if (A[i] == diff_b) {
                    flag = true;
                    i++;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        if (A[i] == -1 || B[j] == -1) {
            answer(true);
            exit(0);
        } 
        i++;
        j++;
    }

    // 数字の小さいものを挿入した場合
    i = diff_idx + 1;
    j = diff_idx;
    flag = false;
    while (true) {
        if (A[i] != B[j]) {
            if (flag == false) {
                if (B[j] == diff_a) {
                    flag = true;
                    j++;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        if (A[i] == -1 || B[j] == -1) {
            answer(true);
            exit(0);
        } 
        i++;
        j++;
    }
    answer(false);
    


    
    return 0;
}