#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1002

using namespace std;

int main()
{
    bool a[502][502];
    int n, m;
    while(cin >> n >> m)
    {
        int i, j;
        bool x, b;
        ffr(i,0,n)
        {
            ffr(j,0,m)
            {
                cin >> a[i][j];
            }
        }
        int ans;
        bool got=0;
        ffr(i,0,n)
        {
            ans=0;
            ffr(j,0,m)
            {
                cin >> x;
                b=a[i][j];
                ans+=(int)(b^x);
                a[i][j]=b^x;
            }
            if(ans&1)
                got=1;
        }
        if(got)
        {
            cout << "No\n"; continue;
        }
        ffr(j,0,m)
        {
            ans=0;
            ffr(i,0,n)
            {
                b=a[i][j];
                ans+=(int)(b);

            }
            if(ans&1)
                break;
        }
        if(j<m)
        {
            cout << "No\n";
        }
        else cout << "Yes\n";
    }
    return 0;
}
