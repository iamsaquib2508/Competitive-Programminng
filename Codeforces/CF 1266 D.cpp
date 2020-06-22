#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 100003
#define pil pair<int,ll>
#define mp make_pair

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

ll in[MMAX]={}, out[MMAX]={};


int main()
{
    int n, m, u, v, i, j;
    ll x;

    while(cin >> n >> m)
    {
        ffr(i,0,m)
        {
            cin >> u >> v >> x;
            in[u]+=x;
            out[v]+=x;;
        }

        ffrr(i,1,n)
        {
            if(in[i]>out[i])
            {
                in[i]-=out[i]; out[i]=0;
            }
            else
            {
                out[i]-=in[i]; in[i]=0;
            }
        }
        map< pair<int,int>, ll > mpp;
        map< pair<int,int>, ll > :: iterator it;
        j=1;
        int cnt=0;
        ffrr(i,1,n)
        {
            if(in[i]>0)
            ffrr(j,j,n)
            {
                if(out[j]==0) continue;
                pair<int,int> p=mp(i,j);
                if(in[i]>out[j])
                {
                    in[i]-=out[j];
                        cnt++;
                        mpp[p]=out[j];
                    out[j]=0;
                }
                else
                {
                    out[j]-=in[i];
                        cnt++;
                        mpp[p]=in[i];
                    in[i]=0;
                    break;
                }
            }
        }
        cout << cnt << endl;

        for(it=mpp.begin();it!=mpp.end();it++)
        {
            cout << it->first.first << ' ' << it->first.second << ' ' << it->second << endl;
        }
        mpp.clear();
        ffr(i,0,MMAX) {in[i]=0; out[i]=0;}
    }
}
