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

bool solve(vector<ll> mul, ll one_ten, ll N) {
    ll begin = 0;
    ll end = 0;
    rep(begin,N) {
        rep2(end, begin, begin + N) {
            ll sum = mul[end + 1] - mul[begin];
            // cout << begin << "," << end << "," << sum << endl;
            if (sum == one_ten) {
                return true;
            } else if (sum > one_ten) {
                break;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    vector<ll> A(N);
    INP(A);
    ll s = accumulate(all(A), 0LL);
    if (s % 10 != 0) {
        cout << "No";
        return 0;
    }
    ll one_ten = s / 10;
    vector<ll> B(2 * N);
    rep(i,N) {
        B[i] = A[i];
    }
    rep(i,N) {
        B[i+N] = A[i];
    }
    ll sum = 0;
    vector<ll> mul(2 * N + 1);
    rep(i,2*N) {
        sum += B[i];
        mul[i + 1] = sum;
    }
    // cout << one_ten << endl;
    // printV(mul);
    answer(solve(mul, one_ten, N));
    return 0;
}

/*
    * *
  1 2 3 4 5
  *   *
0 1 3 61015
*/ 