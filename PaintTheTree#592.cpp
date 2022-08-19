//Link to Problem: https://codeforces.com/contest/1244/problem/D
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
const ll INF= 1e18;
const ll MAX=1e6 + 1;
const ll LOG_MAX = 20;
const double pi = 3.141592653;

ll n;
vector<vector<ll>> store;
vector<vector<ll>> graph;
vector<int> order;
vector<bool> visited;


void dfs(int s){
    visited[s] = true;
    order.pb(s);

    for(int i = 0; i < graph[s].size(); i++){
        if(!visited[graph[s][i]]){
            dfs(graph[s][i]);
        }
    }
}

int Ataru(){
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    //std::cout<<std::setprecision(9)<<std::fixed;
    cin >> n;
    store.assign(3, vector<ll>(n, 0));
    graph.resize(n + 1);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cin >> store[i][j];
        }
    }
    for(int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
        if(graph[x].size() > 2 || graph[y].size() > 2){
            cout << -1 << "\n";
            return 0;
        }
    }
    int start = -1;
    for(int i = 1; i <= n; i++){
        if(graph[i].size() == 1) start = i;
    }
    order.clear();
    visited.assign(n + 1, false);
    dfs(start);
    ll mn = 1e18;
    vi perm = {0, 1, 2};
    vi ans;
    do{
        vi build(n, 0);
        ll cur = 0;
        for(int i = 0; i < n; i++){
            if(i < 3) build[i] = perm[i];
            else build[i] = build[i - 3];
        }
        for(int i = 0; i < n; i++) cur += store[build[i]][order[i] - 1];
        if(cur < mn){
            mn = cur;
            vi ordering(n, 0);
            for(int i = 0; i < n; i++) ordering[order[i] - 1] = build[i] + 1;
            ans = ordering;
        }

    }while(next_permutation(all(perm)));
    cout << mn << "\n";
    prtarr(ans, n);
    return 0;
}
