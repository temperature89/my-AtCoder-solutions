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

const vector<ll> dx = {1, 0, -1, 0};
const vector<ll> dy = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll R,C;
    cin >> R >> C;
    ll sy,sx,gy,gx;
    cin >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;
    vector<string> S(R);
    rep(i,R) {
        cin >> S[i];
    }
    vector<vector<ll>> dist(R, vector<ll>(C, -1));
    dist[sy][sx] = 0;
    queue<pair<ll,ll>> q;
    q.push({sy, sx});

    while (!q.empty()) {
        auto [y, x] = q.front();
        // cout << x << "," << y << endl;
        q.pop();
        rep(i,4) {
            ll x2 = x + dx[i];
            ll y2 = y + dy[i];

            if (y2 < 0 || y2 >= R || x2 < 0 || x2 >= C) continue;
            if (S[y2][x2] == '#') continue;
            if (dist[y2][x2] != -1) continue;
            q.push({y2,x2});
            dist[y2][x2] = dist[y][x] + 1;
            // cout << x2 << y2 << endl;
        }
        
    }
    cout << dist[gy][gx] << endl;

    return 0;
}