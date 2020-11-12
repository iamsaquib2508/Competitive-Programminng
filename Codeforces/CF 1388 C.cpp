#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

#define MMAX 200005

ll hap[MMAX], liv[MMAX];
vector<int> v[MMAX];

#define pii pair<ll,ll>
#define mp make_pair
#define inff 1000000000000000007

pii dfs2(int s, int p){

    int sz=v[s].size();
    pii ans=mp(-liv[s],liv[s]), temp;
    //if(s==1) ans.first = liv[s];
    //cout << s << endl;
    for(int aa:v[s]){
        if(aa!=p){
            temp = dfs2(aa,s);
            if(temp.first==inff) return temp;
            ans.first += temp.first;
            ans.second += temp.second;
        }
    }
    ll diff = ans.second-hap[s];
    if(ans.first<=hap[s] && hap[s]<=ans.second && (diff&1)==0 ) ans = mp(hap[s],ans.second);
    else ans = mp(inff,-inff);
    //cout << "at " << s << "   -  " << ans.first << "  fi  ss  " << ans.second << endl;
    return ans;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n, i, uu, vv, m;
        ffr(i,0,MMAX) v[i].clear();
        cin >> n >> m;

        ffrr(i,1,n){
            cin >> liv[i];
        }
        ffrr(i,1,n){
            cin >> hap[i];
        }

        ffr(i,1,n){
            cin >> uu >> vv;
            v[uu].pb(vv);
            v[vv].pb(uu);
        }
        pii ans = dfs2(1,-1); //fixparent

        if(ans.first<=ans.second){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    cin >> tt;
}
