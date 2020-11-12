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

int main(){
    int tt=1;
    while(tt--){
        ll n, i, temp, a[200005], b[200005];
        int indeg[200005];
        mm(indeg,0);
        ll sum=0, ans=0;
        vector<ll> v; v.clear();
        stack<ll> stk;
        queue<ll> q; //q.clear();

        cin >> n;
        ffrr(i,1,n){
            cin >> a[i];
        }
        ffrr(i,1,n){
            cin >> b[i];
            if(b[i]>0)
                indeg[b[i]]++;
        }
        a[0]=0;
        ffrr(i,1,n){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int st=q.front();
            q.pop();
            if(a[st]>=0){
                v.pb(st);
                ans += a[st];
                if(b[st]>0){
                    a[b[st]] += a[st];
                    indeg[b[st]]--;
                    if(indeg[b[st]]==0) q.push(b[st]);
                }
            }
            else{
                ans += a[st];
                stk.push(st);
                if(b[st]>0){
                    indeg[b[st]]--;
                    if(indeg[b[st]]==0) q.push(b[st]);
                }
            }
        }

        cout << ans << endl;
        for(ll aa: v) cout << aa << ' ';
        while(!stk.empty()){
            cout << stk.top() << ' ';
            stk.pop();
        }
        cout << endl;
    }
}
