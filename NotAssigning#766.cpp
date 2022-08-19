//Link to Problem: https://codeforces.com/problemset/problem/1627/C
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
typedef vector<vi> vvii;
typedef vector<string> vs;
using namespace std;
int inquire(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    int a; cin>>a;
    return a;
}
const ll INF= 0x3f3f3f3f;
const ll MAX=1e5+1;

int cases, n;
vector<vector<int>> graph;
vector<pair<int, int>> lists;
vector<bool> visited;
vector<vector<pair<int, int>>> results;
vector<int> decoy = {2, 3};

void dfs(int u, int prev){
        visited[u] = true;
        int start = 0;
        for(int v = 0; v < graph[u].size(); v++){
            int node = graph[u][v];
            if(!visited[node]){
                if(prev == -1){
                    int num = decoy[start];
                    results[u].pb(mp(node, num));
                    results[node].pb(mp(u, num));
                    start++;
                    dfs(node, num);
                }else if(prev == 2){
                    results[u].pb(mp(node, 3));
                    results[node].pb(mp(u, 3));
                    dfs(node, 3);
                }else if(prev == 3){
                    results[u].pb(mp(node, 2));
                    results[node].pb(mp(u, 2));
                    dfs(node, 2);
                }
            }
        }
}

int Ataru() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    //std::cout<<std::setprecision(2)<<std::fixed;
    cin >> cases;
    for(int tc = 1; tc <= cases; tc++){
        cin >> n;
        graph.clear();
        visited.clear();
        lists.clear();
        results.clear();
        graph.resize(n + 1);
        visited.assign(n + 1, false);
        results.resize(n + 1);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            lists.pb(mp(u, v));
            graph[u].pb(v);
            graph[v].pb(u);
        }
        bool ok = true;
        for(int i = 1; i <= n; i++){
            if(graph[i].size() > 2) ok = false;
        }
        if(!ok){
            cout << -1 << "\n";
            continue;
        }
        dfs(1, -1);
        vi ans;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < results[lists[i].fr].size(); j++){
                if(results[lists[i].fr][j].fr == lists[i].sc) ans.pb(results[lists[i].fr][j].sc);
            }
        }
        prtarr(ans, (int)ans.size());
    }
    return 0;
}
