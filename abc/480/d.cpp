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

// ll get_col(ll a) {
//     return lower_bound(all(idx_li), a) - idx_li.begin();
// }

// ll get_row(ll a) {
//     return a - *lower_bound(all(idx_li), a);
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    INP(A);

    // Aの累積和
    vector<ll> A_sum(N, 0);
    ll sum = 0;
    rep(i, N) {
        sum += A[i];
        A_sum[i] = sum;
    }

    // Aの逆順の累積和
    // vector<ll> A_revsum(N, 0);
    // sum = 0;
    // repR(i, N) {
    //     sum += A[i];
    //     A_revsum[i] = sum;
    // }
    // printV(A_revsum);
    
    // Aの累積和の累積和(dp?)
    vector<ll> A_sumsum(N, 0);
    sum = 0;
    rep(i, N) {
        sum += A_sum[i];
        A_sumsum[i] = sum;
    }

    // idxに第何項まで含まれるかの配列
    vector<ll> idx_li(N + 1, 0);
    sum = 0;
    rep(i, N) {
        sum += i + 1;
        idx_li[i + 1] = sum;
    }
    // printV(idx_li);

    // cout << "===" << endl;
    ll L, R;
    rep(i, Q) {
        cin >> L >> R;
        L--; R--;
        ll L_col = upper_bound(all(idx_li), L) - idx_li.begin() - 1;
        ll R_col = upper_bound(all(idx_li), R) - idx_li.begin() - 1;
        ll L_row = L - *(upper_bound(all(idx_li), L) - 1);
        ll R_row = R - *(upper_bound(all(idx_li), R) - 1);
        if (L == R) {
            cout << A[L_row] << endl;
        } else {
            // cout << L_col << "," << L_row << "," << R_col << "," << R_row << endl;
            // 中の列の計算
            ll center = A_sumsum[R_col - 1] - A_sumsum[L_col];
            ll upper = A_sum[R_row];
            ll lower;
            if (L_row == 0) {
                lower = A_sum[L_col];
            } else {
                lower = A_sum[L_col] - A_sum[L_row - 1];
            }
            cout << lower + center + upper << endl;

        }
    }
    return 0;
}