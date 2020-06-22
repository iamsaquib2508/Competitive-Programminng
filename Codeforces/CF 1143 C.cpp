#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define rmax 5000006

using namespace std;

int main()
{
    int ar[100005], n, i, p, c;
    vector<int> v;
    while(cin >> n)
    {
        v.clear();
        mm(ar,0);
        ffrr(i,1,n)
        {
            cin >> p >> c;
            if(p==-1) continue;
            if(c==0)
            {
                ar[p]=1;
            }
            else v.pb(i);
        }
        sort(v.begin(), v.end());
        int ans=-1, sz=v.size();
        bool pp=0;
        ffr(i,0,sz)
        {
            if(ar[v[i]]==0)
            {
                //ans=v[i];
                if(pp==1) cout << ' ';
                cout << v[i] ;

                pp=1;
            }
        }
        if(!pp)
        cout << "-1" ;
        cout << endl;
    }
}
