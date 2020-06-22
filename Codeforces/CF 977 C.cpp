#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)

using namespace std;

int main()
{
    int n, k, i, cur, a[200005];
    cin >> n >> k;
    ffr(i,1,n+1)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(k==0)
    {
        if(a[1]==1) cout << "-1\n";
        else cout << "1\n";
        return 0;
    }
    ffr(i,1,n+1)
    {
        cur=a[i];
        while(i<=n && a[i]<=cur) i++;
        i--;
        if(i==k)
        {
            cout << cur << endl;
            break;
        }
        else if(i>k)
        {
            cout << "-1\n";
            break;
        }
    }

    return 0;
}
