//Link to Problem: https://codeforces.com/problemset/problem/1661/C
// Author: Ataru
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
#define judge(a) {if(a) cout<<"yes"<<"\n"; else cout<<"no"<<"\n";}
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

ll cases, n;
vll lists;
int Ataru(){
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    //std::cout<<std::setprecision(9)<<std::fixed;
    cin >> cases;
    while(cases--){
        cin >> n;
        lists.resize(n);
        ll mx = 0;
        for(int i = 0; i < n; i++){
        	cin >> lists[i];
        	mx = max(mx, lists[i]);
        }
        ll ans = 1e18;
        for(int need = mx; need <= mx + 1; need++){
        	ll l = 0;
        	ll r = 1e18;
        	ll res = -1;
        	while(l <= r){
        		ll mid = (l + r) / 2;
        		ll cnt1 = (mid / 2) + (mid % 2);
        		ll cnt2 = mid - cnt1;
        		ll need1 = 0;
        		for(int i = 0; i < n; i++){
        			ll curtree = (need - lists[i]) / 2;
        			if((need - lists[i]) % 2 == 1) need1++;
        			if(cnt2 >= curtree) cnt2 -= curtree;
        			else{
        				curtree -= cnt2;
        				cnt2 = 0;
        				need1 += (curtree * 2);
        			}
        		}
        		if(need1 <= cnt1){
        			res = mid;
        			r = mid - 1;
        		}else l = mid + 1;
        	}
        	ans = min(ans, res);
        }
        cout << ans << "\n";
    }
    return 0;
}
