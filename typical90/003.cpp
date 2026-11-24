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

// #define DEBUG true  // DEBUG=trueのときデバッグ表示ON
#define DEBUG false
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

ll N;
vector<vector<ll>> G;
vector<ll> v_depth;
void dfs(ll p, ll v, ll depth) {
    v_depth[v] = depth;
    depth++;
    for (auto c : G[v]) {
        if (c == p) continue;
        dfs(v, c, depth);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    G.assign(N,vector<ll>());
    v_depth.assign(N,0);
    rep(i,N-1) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].PB(b);
        G[b].PB(a);
    }
    dfs(-1,0,0);
    ll max_v = max_element(all(v_depth)) - v_depth.begin();
    dprint(v_depth);
    v_depth.assign(N,0);
    dfs(-1,max_v,0);
    ll max_depth = *max_element(all(v_depth));
    cout << max_depth + 1;


    return 0;
}