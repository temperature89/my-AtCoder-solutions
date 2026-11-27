#define DEBUG true  // DEBUG=trueのときデバッグ表示ON
// #define DEBUG false

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
    ll H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<ll>> field(H,vector<ll>(W,0));
    dsu d(H*W);
    rep(i,Q) {
        ll q;
        cin >> q;
        if (q == 1) {
            ll r,c;
            cin >> r >> c;
            r--;c--;
            field[r][c] = 1;
            ll cord = r * W + c;
            if (r != 0 && field[r-1][c] == 1) d.merge(cord, (r-1) * W + c);
            if (r != H-1 && field[r+1][c] == 1) d.merge(cord, (r+1) * W + c);
            if (c != 0 && field[r][c-1] == 1) d.merge(cord, r * W + (c-1));
            if (c != W-1 && field[r][c+1] == 1) d.merge(cord, r * W + (c+1));
        } else {
            ll ra,ca,rb,cb;
            cin >> ra >> ca >> rb >> cb;
            ra--;ca--;rb--;cb--;
            ll a_cord = ra * W + ca;
            ll b_cord = rb * W + cb;
            if (field[ra][ca] == 1 && field[rb][cb] == 1 && d.same(a_cord,b_cord)) {
                answer(true);
            } else {
                answer(false);
            }
        }
    }
    return 0;
}

/*

**-
-**
-*-

*/