//Link to Problem: https://codeforces.com/contest/1579/problem/D
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
#define prtarrr(n,len) {for(int i=len - 1;i>=0;i--) cout<<n[i]<<" "; cout<<"\n";}
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
typedef vector<vi> vvii;
typedef vector<string> vs;
using namespace std;
int inquire(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int a; cin>>a;
    return a;
}
const ll INF= 1e9;
const ll MAX=1e6 + 1;
const ll LOG_MAX = 20;
const double pi = 3.141592653;

int cases, n;
vpii lists;
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
        priority_queue<pair<int, int>, vector<pair<int, int>>> res;
        for(int i = 0; i < n; i++){
            cin >> lists[i].fr;
            lists[i].sc = i + 1;
            if(lists[i].fr != 0) res.push({lists[i].fr, lists[i].sc});
        }
        vpll ans;
        while(res.size() > 1){
            //cout << res.size() << "\n";
            pair<int, int> p1 = res.top();
            res.pop();
            pair<int, int> p2 = res.top();
            res.pop();
            ans.pb({p1.sc, p2.sc});
            p1.fr--;
            p2.fr--;
            if(p1.fr != 0) res.push(p1);
            if(p2.fr != 0) res.push(p2);
        }
        cout << (int)ans.size() << "\n";
        for(int i = 0; i < (int)ans.size(); i++){
            cout << ans[i].fr << " " << ans[i].sc << "\n";
        }

    }
    return 0;
}
