#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define pf printf
#define ll long long int
#define ff first
#define ss second
#define sf(a) scanf("%d", &a)
#define CMAX 30002

using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

ll b[12], at[12], ninin, sing[12];

ll allsum(ll n)
{
    if(n==0) return 0;
    ll cur=n-at[ninin-1];
    return ninin * (cur+1) * cur / 2 + cur * (sing[ninin-1]) + b[ninin-1];
}

ll solve(ll n)
{
    ll i, lo, hi, mid, num, val, res, last, mod, temp;
    ffr(i,1,10)
    {
        if(b[i]>n) break;
    }
    lo=at[i-1];
    //cout << lo << " lo\n";
    ninin=i;
    hi=at[i];
    while(hi-lo>1)
    {
        mid=(lo+hi)/2;
        temp=allsum(mid);
        if(temp>n) hi=mid;
        else if(temp<n) lo=mid;
        else
            return mid%10;
    }
    //cout << ans(10) << endl;
    n-=allsum(lo);
    //cout << lo << " lo\n";
    num=1; val=9;
    res=0;
    while(1)
    {
        res+=(num*val);
        if(res==n) return at[num]%10;
        if(res>n) break;
        num++; val*=10;
    }

    res= n-res+(num*val);
    //cout << res << " res\n";
    //num++;
    last=at[num-1]+res/num;
    mod=res%num;
    if(mod==0){mod=num;}
    else last++;
    mod=num-mod;
    while(mod--)
    {
        last/=10;
    }
    return last%10;

}

int main()
{
    int t; cin >> t;
    ll i, numm, cur, n;
    b[0]=0; at[0]=0; sing[0]=0;
    numm=9; cur=9;
    ffr(i,1,10)
    {
        sing[i]=10*sing[i-1]+cur+(i-1)*cur;
        b[i]= i * (cur+1) * cur / 2 + cur * (sing[i-1]) + b[i-1];

        cout << b[i] << endl;
        cin >> t;
        cur*=10;
        at[i]=numm;
        numm+=cur;
    }
    ll temp=1000000000000000000-b[9], num;
    // ffr(num,0,100000)
    // if(10*num*(num+1)/2+(num+1)*b[5]>temp)
    // {
    //     cout << num << endl; break;
    // }
    num=99;
    //cout << 6*num*(num+1)/2+(num+2)*b[5]-1000000000000000000 << endl;
    while(t--)
    {
        cin >> n;
        cout << solve(n) << endl;
    }
}
