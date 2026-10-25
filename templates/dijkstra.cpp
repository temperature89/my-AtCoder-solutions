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

// 辺
struct Edge {
    ll to;
    ll weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ノードの数、辺の数
    ll N, M;
    cin >> N >> M;
    vector<vector<Edge>> graph(N);

    // グラフ作成
    rep(i,M) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].PB({v,w});
    }
    
    int start = 0;
    cin >> start;
    start--;

    // 辺の重み
    vector<ll> dist(N, INF);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (const auto& edge: graph[u]) {
            ll v = edge.to;
            ll next_cost = d + edge.weight;

            if (next_cost < dist[v]) {
                dist[v] = next_cost;
                pq.push({dist[v], v});
            }
        }
    }

    rep(i, N) {
        if(dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
    return 0;
}