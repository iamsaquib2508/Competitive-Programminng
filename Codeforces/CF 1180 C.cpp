#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

ll arr[300005];
ll a[300005], b[300005], n;

void compute(ll mx)
{
    ll i, aa, bb;
    ffr(i,0,mx)
    {
        aa=arr[i], bb=arr[i+1];
        a[i]=aa, b[i]=bb;
        if(aa>bb)
        {
            arr[i+1]=aa;
            arr[i+n]=bb;
        }
        else
        {
            arr[i+n]=aa;
        }

    }
}

int main()
{
    ll q;
    while(cin >> n >> q)
    {
        ll mx=0, i, rem, x, mxindex=0;
        ffr(i,0,n)
        {
            cin >> x;
            arr[i]=x;
            arr[i+n]=x;
            if(x>mx)
            {
                mxindex=i;
                mx=x;
            }
        }
        compute(mxindex);
        n--;
        while(q--)
        {
            cin >> x;
            x--;
            if(x<mxindex)
            {
                cout << a[x] << " " << b[x] << endl;
            }
            else
            {
                rem=(x-mxindex)%(n);
                cout << mx << " " << arr[rem+1+mxindex] << endl;
            }
        }
    }
}
