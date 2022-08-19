//Link to Problem: https://codeforces.com/problemset/problem/1228/B
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


ll h, w;
vll r;
vll c;
vvll grid;
vvll ban;
int Ataru(){
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    //std::cout<<std::setprecision(9)<<std::fixed;
    cin >> h >> w;
    r.resize(h);
    c.resize(w);
    grid.assign(h, vll(w, 0));
    ban.assign(h, vll(w, 0));
    for(int i = 0; i < h; i++) cin >> r[i];
    for(int i = 0; i < w; i++) cin >> c[i];
    for(int i = 0; i < h; i++){
        ll p = 0;
        for(int j = 0; j < r[i]; j++){
            grid[i][j] = 1;
            p++;
        }
        if(p < w){
            ban[i][p] = -1;
        }
    }
    for(int i = 0; i < w; i++){
        ll p = 0;
        for(int j = 0; j < c[i]; j++){
            grid[j][i] = 1;
            p++;
        }
        if(p < h){
            ban[p][i] = -1;
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == 1){
                ban[i][j] = -1;
            }
        }
    }

    bool ok = true;
    for(int i = 0; i < h; i++){
        int j = 0;
        for(; j < w && grid[i][j] == 1; j++);
        if(j != r[i]) ok = false;
    }

    for(int i = 0; i < w; i++){
        int j = 0;
        for(; j < h && grid[j][i] == 1; j++);
        if(j != c[i]) ok = false;
    }
    if(!ok){
        cout << 0 << "\n";
        return 0;
    }




    ll unban = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            unban += (ban[i][j] != -1);
        }
    }

    ll start = 1;
    for(int i = 0; i < unban; i++){
        start = (start * 2) % MOD;
    }
    cout << start % MOD;
    return 0;
}
