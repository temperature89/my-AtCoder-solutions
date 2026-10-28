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

// 訪問済み管理用の配列をグローバル、あるいは引数で持たせる
vector<bool> seen;
vector<vector<ll>> graph;

// DFSの関数（再帰）
void dfs(ll u) {
    seen[u] = true; // 訪問したフラグを立てる

    // 必要に応じてここで行う処理を書く（例: 頂点uに到着したときの処理）
    // cout << "Visiting: " << u + 1 << "\n";

    // 接続している次の頂点を探索
    for (auto v : graph[u]) {
        if (seen[v]) continue; // すでに訪問済みの場合はスキップ
        dfs(v);                // 再帰的に次の頂点へ
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M; // N: 頂点数, M: 辺数
    cin >> N >> M;

    graph.assign(N, vector<ll>());
    rep(i, M) {
        ll u, v;
        cin >> u >> v;
        u--; v--; // 0-indexed に変換
        graph[u].PB(v);
        // 無向グラフ（双方向）の場合はこちらも追加
        // graph[v].PB(u);
    }

    seen.assign(N, false);

    ll start = 0; // スタート地点（例: 0）
    cin >> start;
    start--;

    // DFSを実行
    dfs(start);

    // すべての頂点に到達できたか、あるいは連結成分の数を数えるなどの処理
    bool all_visited = true;
    rep(i, N) {
        if (!seen[i]) all_visited = false;
    }

    if (all_visited) {
        cout << "All vertices are reachable\n";
    } else {
        cout << "Some vertices are unreachable\n";
    }
    
    return 0;
}