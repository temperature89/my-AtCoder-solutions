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
    for (int i = 0; i < (int)v.size(); i++) {
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
const ll MOD = 1000000007;
vector<vector<ll>> G;
vector<ll>b;
vector<ll>w;
void dfs(ll v,ll p) {
    for (auto u:G[v]) {   
        if (u == p) continue;
        dfs(u,v);
        b[v] *= w[u];
        b[v] %= MOD;
        w[v] *= (b[u]+w[u]) % MOD;
        w[v] %= MOD;
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    G.assign(N,vector<ll>());
    rep(i,N-1) {
        ll x,y;
        cin >> x >> y;
        x--; y--;
        G[x].PB(y);
        G[y].PB(x);
    }
    b.assign(N,1);
    w.assign(N,1);
    dfs(0,-1);
    dprint(b);
    dprint(w);
    cout << (b[0] + w[0]) % MOD;


    return 0;
}

/*
independent set...グラフにおいて隣接しない頂点の集合
一番大きい独立集合を最大独立集合という
その独立集合のパターンを求める問題
一般的なグラフの独立集合を求めるのはむずかしい
木は簡単

葉の独立集合は白か黒の2つ
配列b,wをよういする
bはその頂点を黒に塗ったときのその根つき木のパターン数
根が白の時、その子は何色でもいい
黒の時、その子は白でなければならない
b[v] = (総乗u←vの子供)w[u]
w[v] = (総乗u←vの子供)w[u]+b[u]
*/