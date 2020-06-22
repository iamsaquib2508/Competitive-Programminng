




/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define ff first
#define ss second
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

#define MX 200005

void build(int pos, int L, int R)
{
    if(L==R)
    {
        tree[pos]=a[L];
        return;
    }
    int mid=(L+R)/2, x=pos+pos;
    build(x,L,mid);
    build(x+1,mid+1,R);
    
    return;
}

int q(int pos, int L, int R, int l, int r, int qr)
{
    if(R<l || r<L) return 0;
    if(L==R)
    {
        return a[L]>=qr;
    }
    int mid=(L+R)/2, x=pos+pos, ans;
    ans=q(x,L,mid,l,r,qr);
    ans+=q(x+1,mid+1,R,l,r,qr);
    
    return ans;
}


int main()
{
    cin >> n;
    ffrr(i,1,n)
    {
        cin >> x;
        x=min(x,n);
        a[i]=x;
        
    }
    
    build(1,1,n);
    
    ffrr(i,1,n)
    {
        curv=a[i];
        curind=i;
        
    }
    return 0;
}
