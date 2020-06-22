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

int a[mmxx], n, h;

bool ok(int x)
{
    int *arr=new int[x], i;
    ffr(i,0,x)
    {
        arr[i]=a[i];
    }
    sort(arr,arr+x);
    int prev=0, temp;
    for(i=x-1;i>=0;i--)
    {
        temp=arr[i];
        i--;
        prev+=temp;
        if(prev>h) return false;

    }
    return true;
}

int main()
{
    while(cin >> n >> h)
    {
        int i, x, lo, hi, mid;
        ffr(i,0,n)
        {
            cin >> x; a[i]=x;
        }
        lo=2; hi=n;
        while(hi-lo>1)
        {
            mid=(lo+hi)/2;
            if(ok(mid))
            {
                lo=mid;
            }
            else hi=mid;
        }
        if(ok(hi)) x=hi;
        else x=lo;

        cout << x << endl;
    }
}
