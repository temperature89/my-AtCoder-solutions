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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,a,b;
    cin >> n >> m;
    pair<ll,ll> c1 = {INF,-1}, c2 = {INF,-1};
    vector<vector<ll>> second_vote(n,vector<ll>());
    vector<ll> first_vote(n,0);
    rep(i,m) {
        cin >> a >> b;
        a--; b--;
        first_vote[a]++;
        second_vote[a].PB(b);
    }
    rep(i,n) {
        if(first_vote[i] > c1.second) {
            c2 = c1; c1 = {i, first_vote[i]};
        } else if (first_vote[i] > c2.second) {
            c2 = {i, first_vote[i]};
        }
    }
    rep(i,n) {
        ll sz = second_vote[i].size();
        rep(j,sz) {
            first_vote[second_vote[i][j]]++;
        }
        first_vote[i] = 0;
        pair<ll,ll> c0 = {INF, -1};
        rep(j,sz+2) {
            if (j < sz) a = second_vote[i][j];
            else if (j == sz) a = c1.first;
            else a = c2.first;

            if(first_vote[a] > c0.second) c0 = {a, first_vote[a]};
            else if((first_vote[a] == c0.second) && (a < c0.first)) c0 = {a, first_vote[a]};
        }
        cout << (c0.first + 1) << "\n";
        first_vote[i] = sz;
        rep(j,sz) {
            first_vote[second_vote[i][j]]--;
        }
    }

    return 0;
}