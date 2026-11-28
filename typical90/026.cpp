// #define DEBUG true // DEBUG=trueのときデバッグ表示ON
#define DEBUG false

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

const ll INF = 2e18; // INF+INFがオーバフローしない程度の大きい値
void answer(bool res)
{
    if (res)
        cout << "Yes\n";
    else
        cout << "No\n";
}

template <typename T>
void printV(T A)
{
    for (auto a : A)
    {
        cout << a << " ";
    }
    cout << endl;
}

// pairの出力用 (vectorの中にpairが入っている場合などに便利)
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

// vectorの出力用
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (size_t i = 0; i < v.size(); i++)
    {
        os << v[i] << (i == v.size() - 1 ? "" : " ");
    }
    os << "]";
    return os;
}

template <typename... Args>
void dprint(Args... args)
{
    if (!DEBUG)
        return; // デバッグOFF時は何もしない

    if constexpr (sizeof...(args) > 0)
    {
        int i = 0;
        int size = sizeof...(args);
        // 最後の要素以外は直後に "," を出力する
        ((cout << args << (++i < size ? "," : "")), ...);
    }
    cout << endl; // 最後に改行
}

ll N;
vector<vector<ll>> G;
vector<ll> used;
void dfs(ll p, ll v) {
    for (auto c : G[v]) {
        if (c == p) continue;
        if (used[v] == 1) used[c] = 0;
        else if (used[v] == 0) used[c] = 1;
        // dprint(used);
        dfs(v,c);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    G.assign(N,vector<ll>());
    used.assign(N,-1);
    rep(i,N-1) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].PB(b);
        G[b].PB(a);
    }
    dprint(G);
    used[0]=1;
    dfs(-1,0);
    dprint(used);
    vector<ll> ans0(0);
    vector<ll> ans1(0);
    rep(i,N) {
        if (used[i] == 0) {
            ans0.PB(i+1);
        } else {
            ans1.PB(i+1);
        }
    }
    vector<ll> ans;
    if (ans0.size() >= N / 2) ans = ans0;
    else ans = ans1;
    rep(i,N / 2) {
        cout << ans[i];
        if (i != N / 2 - 1) {
            cout << " ";
        }
    }
    return 0;
}