#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;


// int ff(int ir)
// {
//     int lo=-1, hi=v.size(), mid;
//     while(hi-lo>1)
//     {
//         mid=(lo+hi)/2;
//         if(v[mid]<=ir) lo=mid;
//         else hi=mid;
//     }
//     return v.size()-hi;
// }

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int n, i, a[200005];
        cin >> n;
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        //a[i]=0;
        sort(a,a+n);

        for(i=n-1;i>=0;i--)
        {
            if(a[i]<=i+1) break;
        }
        cout << i+2 << endl;

    }
}
