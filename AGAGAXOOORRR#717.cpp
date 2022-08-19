//Link to Problem: https://codeforces.com/contest/1516/problem/B
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
#define search(a,n) a.find(n);
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
const ll INF= 0x3f3f3f3f;
const ll MAX=1e5 + 5;
const ll LOG_MAX = 20;

ll cases,n;
int Ataru() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    //std::cout<<std::setprecision(2)<<std::fixed;
    cin>>cases;
    while(cases--){
        cin>>n;
        vll a(n);
        ll mx=0;
        ll ts=0; //XOR of every element in the given array
        for(int i=0;i<n;i++){
            cin>>a[i];
            ts^=a[i];
        }
        int prefix=a[0];
        bool exist=false;
        for(int i=1;i<n;i++){
            int mid=a[i];
            for(int j=i+1;j<n;j++){
                if(mid==prefix && mid==ts) exist=true;
                mid^=a[j];
            }
            prefix^=a[i];
            // prefix is the XOR of every element in the 1st segment
            // mid is the XOR of every element in the middle segment
            // ts is the XOR of every element in the last segment
        }
        judge(ts==0 || exist);
        // if ts = 0, then no matter where we split the array the 2 portions will always equal

    }
    return 0;
}
