//Link to Problem: https://codeforces.com/problemset/problem/1490/E
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
typedef vector<string> vs;
using namespace std;
int inquire(int x){
    cout<<x<<endl;
    int a; cin>>a;
    return a;
}
const ll INF= 0x3f3f3f3f;
const ll MAX=1e5+1;
ll cases,n;
vpll lists;
int Ataru() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    //std::cout<<std::setprecision(2)<<std::fixed;
    cin>>cases;
    while(cases--){
        cin>>n;
        lists.resize(n);
        for(int i=0;i<n;i++){
            lists[i].sc=i+1;
            cin>>lists[i].fr;
        }
        sort(all(lists));
        int l=0;
        int r=n;
        while(l<=r){
            int mid=(l+r)/2;
            ll sum=0;
            //cout<<lists[mid].fr;
            for(int i=0;i<=mid;i++) sum+=lists[i].fr;
            bool pos=true;
            for(int i=mid+1;i<n;i++){
                if(sum<lists[i].fr){
                    pos=false;
                    break;
                }else{
                    sum+=lists[i].fr;
                }
            }
            if(pos) r=mid-1;
            else l=mid+1;
            //cout<<mid<<" "<<l<<" "<<r<<"\n";
        }
        //cout<<l<<"\n";
        vll ans;
        for(int i=l;i<n;i++){
            ans.pb(lists[i].sc);
        }
        sort(all(ans));
        cout<<(int)ans.size()<<"\n";
        prtarr(ans,(int)ans.size());
    }
    return 0;
}
