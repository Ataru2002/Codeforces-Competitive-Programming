//Link to Problem: https://codeforces.com/contest/1407/problem/C
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
int judge(int x,int y){
    cout<<"? "<<x+1<<" "<<y+1<<endl;
    int a; cin>>a;
    return a;
}

int n;
vi ans;
int main() {
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    cin>>n;
    ans.resize(n);
    for(int i=0;i<n;i++) ans[i]=0;
    set<int> lists;
    int mys=0;
    for(int i=1;i<n;i++){
        int ans1=judge(mys,i);
        int ans2=judge(i,mys);
        if(ans1<ans2){
            ans[i]=ans2;
        }else{
            ans[mys]=ans1;
            mys=i;
        }
    }
    cout<<"! ";
    for(int i=0;i<ans.size();i++)
        if(ans[i]==0) cout<<n<<" ";
        else cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}

 
