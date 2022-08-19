//Link to Problem: https://codeforces.com/contest/1475/problem/E
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
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define alla(a,n) a, a + n
#define endstring std::string::npos
#define prtarr(n,len) {for(int i=0;i<len;i++) cout<<n[i]<<" "; cout<<"\n";}
#define prtset(n) {for(auto i:n) cout<<i<<" "; cout<<"\n";}
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
typedef vector<string> vs;
using namespace std;
int inquire(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int a; cin>>a;
    return a;
}
const ll INF= 0x3f3f3f3f;
const ll bignum=1e18;
ll factorial(ll n){
    ll ans=1;
    for(int i=1;i<=n;i++) ans=(ans*i)%MOD;
    return ans;
}
ll pows(ll a,ll p){
    int res = 1;
    while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % MOD;
      p /= 2;
    } else {
      res = res * 1ll * a % MOD;
      p--;
    }
  }
  return res;
}
ll combination(ll a,ll b){
    return (factorial(a))*1ll*pows(factorial(b),MOD-2)%MOD*1ll*pows(factorial(a-b),MOD-2)%MOD;
}

ll cases,n,k;
vll lists;
int Ataru() {
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    //std::cout<<std::setprecision(2)<<std::fixed;
    cin>>cases;
    while(cases--){
        cin>>n>>k;
        lists.resize(n);
        vll cnt(1001,0);
        for(int i=0;i<n;i++){
            cin>>lists[i];
            cnt[lists[i]]++;
        }
        sort(allr(lists));
        ll ans=1;
        //cout<<combination(50,2);
        for(int i=0;i<k;i++){
            int j=i;
            ll cnt3=0;
            for(;j<k && lists[j]==lists[i];j++) cnt3++;
            ans=(ll)(ans*combination(cnt[lists[i]],cnt3))%MOD;
            i=j-1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
 
