//Link to Problem: https://codeforces.com/problemset/problem/1350/B
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
#define alla(a,n) a, a + n
#define endstring std::string::npos
#define prtarr(n,len) {for(int i=0;i<len;i++) cout<<n[i]<<" "; cout<<"\n";}
#define prtpair(n) {cout<<n.fr<<" "<<n.sc<<"\n";}
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;
using namespace std;

int cases,n;
vi lists;
int main() {
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    cin>>cases;
    while(cases--){
        cin>>n;
        lists.clear();
        for(int i=0;i<n;i++){
            int sub;
            cin>>sub;
            lists.pb(sub);
        }
        vi dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=((i+1)*2)-1;j<n;j+=i+1){
                if(lists[j]>lists[i]){
                    dp[j]=max(dp[i]+1,dp[j]);
                }
            }
        }
        int ans=0;
        //prtarr(dp,n);
        for(int i=0;i<n;i++) ans=max(ans,dp[i]);
        cout<<ans<<"\n";
    }
    return 0;
}

 
