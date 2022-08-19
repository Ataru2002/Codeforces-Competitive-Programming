//Link to Problem: https://codeforces.com/contest/1419/problem/C
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
#define prtpair(n) {cout<<n.fr<<" "<<n.sc<<"\n";}
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
int judge(int x,int y){
    cout<<"? "<<x+1<<" "<<y+1<<endl;
    int a; cin>>a;
    return a;
}
const ll INF= 0x3f3f3f3f;
const ll bignum=1e18;

ll cases,n,x;
vi lists;
int Ataru(){
    /// #jojofan
    /// #csgofan
    /// Author: Ataru
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    cin>>cases;
    while(cases--){
        cin>>n>>x;
        lists.clear();
        lists.resize(n);
        bool equals=true;
        bool infected=false;
        int dif=0;
        for(int i=0;i<n;i++){
            cin>>lists[i];
            if(lists[i]!=x) equals=false;
            else infected=true;
            if(lists[i]>x) dif-=abs(x-lists[i]);
            else dif+=abs(x-lists[i]);

        }
        if(equals) cout<<0<<"\n";
        else if(dif==0 || infected) cout<<1<<"\n";
        else cout<<2<<"\n";

    }
    return 0;
}
