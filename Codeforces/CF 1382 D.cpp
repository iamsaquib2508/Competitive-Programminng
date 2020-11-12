#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define bug cout << "hello\n"
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int maxx(int a, int b){
    if(a>b) return a; return b;
}

vector<int> v;
int sz;

bool dp[2001][2001];
bool vis[2001][2001];

bool ok(int pos, int target){
    if(vis[pos][target]==1) return dp[pos][target];

    if(target<0) return 0;
    if(target==0) return 1;
    if(pos==sz) return 0;
    vis[pos][target]=1;
    bool temp = ok(pos+1,target-v[pos]);
    if(!temp)
        return dp[pos][target]= ok(pos+1,target);
    else
        return dp[pos][target]=1;
}

void clean(int pos, int target){
    if(vis[pos][target]==0) return ;

    if(target<=0) return ;
    if(pos==sz) return ;
    vis[pos][target]=0;
    clean(pos+1,target-v[pos]);
    clean(pos+1,target);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    mm(vis,0);
    int tt; cin >> tt;
    while(tt--){
        int n, x, prev, i, cnt;

        v.clear();

        cin >> n;
        n<<=1;

        cnt=1;
        cin >> prev;
        ffr(i,1,n){
            cin >> x;
            if(x<prev){
                cnt++;
            }
            else{
                prev=x;
                v.pb(cnt);
                cnt=1;
            }
        }
        v.pb(cnt);
        sort(v.begin(),v.end());
        sz=v.size();
        //for(int aa:v) cout << aa << " "; cout << endl;
        n>>=1;
        if(ok(0,n)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        clean(0,n);
    }
    cin >> tt;
}
