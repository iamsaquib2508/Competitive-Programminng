#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define pb push_back
#define ll long long int
#define pf printf

using namespace std;



int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int n, m, i, ase[100], x, a[100];
    mm(ase,0);
    cin >> n >> m;
    ffr(i,0,n)
    {
        cin >> x;
        a[i]=x;

    }
    ffr(i,0,m)
    {
        cin >> x;
        ase[x]=1;
    }
    ffr(i,0,n)
    {
        x=a[i];
        if(ase[x])
        {
            cout << x << " ";
        }
    }



    return 0;
}
