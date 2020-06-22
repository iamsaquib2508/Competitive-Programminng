#include <bits/stdc++.h>
#define ull uint64_t
#define uint uint32_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair

using namespace std;

int main()
{
    while(cin >> n >> m)
    {
        ffr(i,0,n)
        {
            cin >> x;
            if(mpp.find(x)==mpp.end())
            {
                vector<int> temp; temp.pb(i+1);
                mpp[x]=temp;
            }
            else mpp[x].pb(i+1);
        }
        ffr(j,0,m)
        {
            cin >> l >> r >> x;
            if(mpp.find(x)==mpp.end())
            {
                ans=l;
            }
            else
            {
                vector<int> v=mpp[x];
                lid = lower_bound(v.begin(), v.end(), l) - v.begin();
                rid = lower_bound(v.begin(), v.end(), r) - v.begin();
                if(rid-lid == r-l )
                {
                    ans=-1;
                }
                else
                {
                    
                }
            }
        }
    }
}
