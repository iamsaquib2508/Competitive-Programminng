#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define ll long long int
#define mm(a,b) memset(a,b,sizeof(a))

using namespace std;

int par[100005];
vector<int> v[100005];
ll s[100005];

int main()
{
    int n, i, x;
    while(cin >> n)
    {
        ffr(i,0,100005) v[i].clear();
        ffrr(i,2,n)
        {
            cin >> x;
            par[i]=x;
            v[x].pb(i);
        }
        ffrr(i,1,n)
        {
            cin >> s[i];
        }
        s[0]=0;
        par[1]=0;
        queue<int> q;
        q.push(1);

        ll curans=0;

        bool valid=true;
        while(!q.empty())
        {
            if(!valid) break;
            int u=q.front();
            q.pop();
            int sz=v[u].size(), uu;
            ll tsum=0, mn=1000000009;
            ffr(i,0,sz)
            {
                uu=v[u][i];

                if(s[uu]==-1)
                {

                }
                else
                {
                    ll curs=s[uu]-s[par[u]];
                    if(curs<0) {valid=false; break;}
                    tsum+=curs;
                    mn=min(mn,curs);
                }
                q.push(uu);
            }
            if(sz>0 && s[uu]!=-1)
            {
                curans+=tsum;
                curans-=((sz-1)*mn);
            }
            //cout << curans << " ans i " << u << endl;
        }
        if(!valid)
        {
            cout << "-1\n";
        }
        else cout << curans+s[1] << endl;
    }
}

/*
9
1 1 1 2 2 2 3 3
4 -1 -1 -1 10 9 5 6 4

*/
