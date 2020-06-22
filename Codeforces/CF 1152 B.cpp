#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

int main()
{
    int n, z, w;
    while(cin >> n)
    {
        vector<int> v;
        v.clear();
        z=0, w=0;
        int sum=0;
        int x=n;
        while(n>0)
        {
            if(n&1)
            {
                if(z>0) {sum+=z; v.pb(sum);  z=0;}
                w++;
            }
            else
            {
                if(w>0) { sum+=w; v.pb(sum); w=0;}
                z++;
            }
            n/=2;
        }
        if(x&1)
        {
            int i, sz=v.size();
            int put=(sz<<1);
            if(sz>0 && v[0]==1) put-=2;
            cout << put << endl;

            for(i=sz-1;i>0;i--) cout << v[i] << ' ';
            if(sz>0 && v[0]>1) cout << v[0];
            cout << endl;
        }
        else
        {
            int i, sz=v.size();
            int put=(sz<<1)-1;
            if(sz>1 && v[1]-v[0]==1) put-=2;
            cout << put << endl;
            for(i=sz-1;i>1;i--) cout << v[i] << ' ';

            if( sz==1 || (sz>1 && v[1]-v[0]==1)) cout << v[0] << endl;
            else if(sz>1) cout << v[1] << ' '  << v[0] << endl;
        }
    }
}
