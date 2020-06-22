#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

int main()
{
    int n, i;
    while(cin >> n)
    {
        int a[10004];
        ffrr(i,1,n)
        {
            cin >> a[i];
        }
        int ans=0;
        i=1;
        while(i<=n)
        {
            int lim=a[i];
            while(i<=lim)
            {
                lim=max(lim,a[i]);
                i++;
                //lim=max(lim,a[i]);
            }
            ans++;
        }
        cout << ans << endl;
    }
}
