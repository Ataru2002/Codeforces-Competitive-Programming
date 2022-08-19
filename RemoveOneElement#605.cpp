//Link to Problem: https://codeforces.com/problemset/problem/1272/D
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
#define prtarr(n,len) {for(int i=0;i<len;i++) cout<<n[i]<<" "; cout<<"\n";}

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

int n;
string s;
int main() {
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    cin>>n;
    vi lists(n);
    for(int i=0;i<n;i++) cin>>lists[i];
    vi dp1(n,1);
    int ans=1;
    for(int i=n-2;i>=0;i--){
        if(lists[i+1]>lists[i]) dp1[i]=dp1[i+1]+1;
        ans=max(ans,dp1[i]);
    }
    vi dp2(n,1);
    for(int i=1;i<n;i++){
        if(lists[i-1]<lists[i]) dp2[i]=dp2[i-1]+1;
        ans=max(ans,dp2[i]);
    }
    for(int i=1;i<n-1;i++){
        if(lists[i-1]<lists[i+1]) ans=max(ans,dp1[i+1]+dp2[i-1]);
    }
    cout<<ans<<"\n";

    return 0;
}

 
