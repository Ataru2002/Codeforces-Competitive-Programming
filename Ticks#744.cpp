//Link to Problem: https://codeforces.com/contest/1579/problem/C
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


int cases, n, m, k;
vs grid;
int Ataru(){
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    //std::cout<<std::setprecision(9)<<std::fixed;
    cin >> cases;
    while(cases--){
        cin >> n >> m >> k;
        grid.resize(n);
        for(int i = 0; i < n; i++) cin >> grid[i];
        int mxtik = min(n - 1, (m - 1) / 2);
        bool full = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '*') full = false;
            }
        }
        if(full) cout << "YES\n";
        else if(mxtik < k) cout << "NO\n";
        else{
            string sub(m, '.');
            vs draw(n, sub);
            for(int i = k; i <= mxtik; i++){
                for(int x = 0; x <= (n - (i + 1)); x++){
                    for(int y = 0; y <= (m - (1 + i * 2)); y++){
                        if(grid[x][y] == grid[x][y + (1 + i * 2) - 1] && grid[x][y] == '*'){
                            int l = y;
                            int r = y + (1 + i * 2) - 1;
                            int d = x;
                            while(d < n && l <= r && grid[d][l] == grid[d][r] && grid[d][l] == '*'){
                                l++;
                                r--;
                                d++;
                            }
                            if(l > r){
                                int l = y;
                                int r = y + (1 + i * 2) - 1;
                                int d = x;
                                while(l <= r){
                                    draw[d][l] = '*';
                                    draw[d][r] = '*';
                                    l++;
                                    r--;
                                    d++;
                                }
                            }
                        }
                    }
                }
            }
            bool ok = true;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] != draw[i][j]) ok = false;
                }
            }
            judge(ok);
        }
    }
    return 0;
}
