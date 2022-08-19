//Link to Problem: https://codeforces.com/contest/1559/problem/D1
/** Hanabi?
**                                .
**                              .'
**                            .'
**                            /`-._'
**                           /   /
**                          /   /
**                         /   /
**                        (`-./
**                         )
**                        '       .
**                              .'
**                            .'
**                            /`-._'
**                           /   /
**                          /   /
**                         /   /
**                        (`-./
**                         )
**                        '
**/
//Kaicho Shirogane Miyuki
//Grieveous lady Shinomiya Kaguya
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define alla(a,n) a, a + n
#define endstring std::string::npos
#define prtarr(n,len) {for(int i=0;i<len;i++) cout<<n[i]<<" "; cout<<"\n";}
#define prtarrr(n,len) {for(int i=len - 1;i>=0;i--) cout<<n[i]<<" "; cout<<"\n";}
#define prtset(n) {for(auto jjj:n) cout<<jjj<<" "; cout<<"\n";}
#define prtpair(n) {cout<<n.fr<<" "<<n.sc<<"\n";}
#define judge(a) {if(a) cout<<"YES"<<"\n"; else cout<<"NO"<<"\n";}
#define search(a,n) a.find(n)
#define Ataru main
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vi> vvii;
typedef vector<string> vs;
using namespace std;
int inquire(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int a; cin>>a;
    return a;
}
const ll INF= 1e18;
const ll MAX= 1e3 + 10;
const ll LOG_MAX = 20;
const double pi = 3.141592653;
const ll MOD = 1e9 + 7;
template<int MOD>
struct ModInt {
    static const int mod = MOD;
    int v;

    explicit operator int() const { return v; }

    ModInt() : v(0) {}

    ModInt(int _v) {
        v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD;
    }

    ModInt(long long _v) {
        v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD;
    }

#define COMPAREOP(OP) bool constexpr operator OP(ModInt other) const { return v OP other.v; }
    COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

    ModInt& operator+=(const ModInt& other) {
        if ((v += other.v) >= MOD) v -= MOD;
        return *this;
    }

    ModInt& operator-=(const ModInt& other) {
        if ((v -= other.v) < 0) v += MOD;
        return *this;
    }

    ModInt& operator*=(const ModInt& other) {
        v = int((ll)v * other.v % MOD);
        return *this;
    }

    ModInt &operator/=(const ModInt &other) { return (*this) *= inv(other); }

    friend ModInt pow(ModInt a, ll p) {
        ModInt ans = 1;
        assert(p >= 0);
        for (; p; p /= 2, a *= a)
            if (p & 1)
                ans *= a;
        return ans;
    }

    // if MOD is not prime number, you have to use Extended Euclidean Algorithm
    friend ModInt inv(const ModInt& a) {
        assert(a.v != 0);
        return pow(a, MOD-2);
    }

    ModInt operator-() const { return ModInt(-v); }
    ModInt& operator++() { return *this += 1; }
    ModInt& operator--() { return *this -= 1; }
    ModInt operator++(int) {
        ModInt temp = *this;
        *this += 1;
        return temp;
    }
    ModInt operator--(int) {
        ModInt temp = *this;
        *this -= 1;
        return temp;
    }
    friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }

    friend std::ostream& operator << (std::ostream& os, const ModInt& m) { return os << m.v; }
    friend std::istream& operator >> (std::istream& is, ModInt& m) { return is >> m.v; }
};

using modular = ModInt<MOD>;

ll n, m1, m2;
vector<set<ll>> mocha;
vector<set<ll>> diana;
vll dsum;
vll dsud;
void makeset(int n){
    for(int i = 0; i < n; i++){
        dsum[i] = i;
        dsud[i] = i;
    }
}
int findset(int u, vll &dsu){
    if(dsu[u] != u) dsu[u] = findset(dsu[u], dsu); //optimize the path from the child node to the root
    return dsu[u];
}
void unions(int u, int v, vll &dsu){
    int pu = findset(u, dsu);
    int pv = findset(v, dsu);
    dsu[pv] = pu;
}

int Ataru(){
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    //std::cout<<std::setprecision(9)<<std::fixed;
    cin >> n >> m1 >> m2;
    mocha.resize(n);
    diana.resize(n);
    dsum.resize(n);
    dsud.resize(n);
    makeset(n);
    for(int i = 0; i < m1; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        mocha[u].insert(v); //adding the edges to the graph
        mocha[v].insert(u); //undirected graph
        unions(u, v, dsum); //unionize the 2 sets together
    }
    for(int i = 0; i < m2; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        diana[u].insert(v);
        diana[v].insert(u);
        unions(u, v, dsud);
    }
    for(int i = 0; i < n; i++) dsum[i] = findset(dsum[i], dsum); //make sure that the set is completely correct
    for(int i = 0; i < n; i++) dsud[i] = findset(dsud[i], dsud);
    vpll ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(mocha[i].find(j) == mocha[i].end() && diana[i].find(j) == diana[i].end()){
                //checking if the edge we add is not present in both graphs
                bool m = false;
                bool d = false;
                if(findset(dsum[i], dsum) != findset(dsum[j], dsum)) m = true;
                if(findset(dsud[i], dsud) != findset(dsud[j], dsud)) d = true;
                //checking if the 2 nodes we're connecting don't belong in the same set
                if(m && d){ //if both graph is good we add the edge to both graphs
                    ans.pb(mp(i + 1, j + 1));
                    mocha[i].insert(j);
                    mocha[j].insert(i);
                    diana[i].insert(j);
                    diana[j].insert(i);
                    unions(i, j, dsum);
                    unions(i, j, dsud);
                    //update the current disjoint-set
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < (int)ans.size(); i++) prtpair(ans[i]);
    return 0;
}
