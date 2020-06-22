#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pii pair<int,int>
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}


int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

vector<int> v[500005];
pii t[500005];
int num[500005];

int main()
{
    int n, m, uu, vv, i, x, tval, id, temp, j;
    while(cin >> n >> m)
    {
        ffr(i,0,500005) {v[i].clear(); num[i]=0;}
        ffr(i,0,m)
        {
            cin >> uu >> vv;
            v[uu].pb(vv);
            v[vv].pb(uu);
        }
        ffr(i,0,n)
        {
            cin >> x;
            t[i]=mp(x,i+1);
        }
        sort(t,t+n);
        bool done[500005], feld;
        mm(done,0);
        ffr(i,0,n)
        {
            //cout << t[i].second << ' ';
            feld=0;
            tval=t[i].first;
            id=t[i].second;

            done[0]=1;
            for(int uu: v[id])
            {
                temp = num[uu];
                if(temp>=tval) {done[0]=0; break;}
                else done[temp]=1;
            }
            ffr(j,0,tval)
            {
                if(done[j]==0) feld=1;
                else done[j]=0;
            }
            if(!feld)
            {
                //success
                num[id]=tval;
            }
            else
            {
                break;
            }
        }
        if(i==n)
        {
            //success
            ffr(i,0,n)
            {
                cout << t[i].second << ' ';
            }
            cout << endl;
        }
        else
        {
            cout << "-1\n";
        }

    }
}
