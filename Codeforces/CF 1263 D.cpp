#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf
#define PI acos(-1.0)

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

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int par[26];
bool vis[26];

int find(int v)
{
    if(v==par[v]) return v;
    else return par[v]=find(par[v]);
}

int main()
{
    int n;
    while(cin >> n)
    {
        int i, j, k, u, v, uu, vv;
        string s;

        ffr(i,0,26)
        {
            par[i]=i;
            vis[i]=0;
        }
        ffr(i,0,n)
        {
            cin >> s;
            int sz=s.size();
            ffr(j,0,sz)
            {
                u=s[j]-'a';
                uu=find(u);
                vis[u]=1;

                ffr(k,j+1,sz)
                {
                    v=s[k]-'a';
                    vv=find(v);
                    vis[v]=1;

                    if(uu!=vv)
                    {
                        par[v]=uu;
                    }
                }
            }
        }
        set<int> st; st.clear();
        ffr(i,0,26)
        {
            if(vis[i]) find(i);
        }
        ffr(i,0,26)
        {
            if(vis[i])
            //cout << i+'a' << " " << find(i);
            st.insert(par[i]);
        }
        cout << st.size() << endl;
    }
}
