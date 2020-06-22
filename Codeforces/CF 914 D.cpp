




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
#define xx first
#define yy second
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */
#define MX 500005

ll a[MX], gc[MX+MX+MX+MX];

int build(int pos, int L, int R)
{
    if(L==R)
    {
        gc[pos]=a[L];
        return a[L];
    }
    int mid=(L+R)/2;
    int xx=pos+pos;
    return gc[pos]=__gcd(build(xx+1, mid+1, R), build(xx, L, mid) );
    
}

void upd(int pos, int L, int R, int i, int y)
{
    int mid=(L+R)/2;
    
    if(L==R) 
    {
        gc[pos]=y;
        
        return ;
    }
    
    int xx=pos+pos;
    if(i<=mid) upd(xx, L, mid, i, y);
    else upd(xx+1, mid+1, R, i, y);
    gc[pos]=__gcd(gc[xx], gc[xx+1]);
    
    return;
}

int find(int pos, int L, int R, int l, int r, int y)
{
    if(r<L || R<l) return 0;
    if(L==R)
    {
        
        if(gc[pos]%y==0) return 0;
        else return 1;
    }
    if(l<=L && R<=r)
    {
        
        if(gc[pos]%y==0) return 0;
    }
    
    int mid=(L+R)/2;
    int xx=pos+pos, cnt;
    cnt=find(xx, L, mid, l, r, y);
    if(cnt<2)
    cnt+=find(xx+1, mid+1, R, l, r, y);
    //cout << cnt << endl;
    return cnt;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, q, i, com, l, r, y;

    cin >> n ;
    ffrr(i,1,n)
    {
        cin >> a[i];
    }
    cin >> q;
    build(1,1,n);
    while(q--)
    {
        cin >> com;
        if(com==1)
        {
            cin >> l >> r >> y;
            
            cout << ( ( (find(1, 1, n, l, r, y) ) <2 ) ? "YES\n" : "NO\n" );
        }
        else
        {
            cin >> i >> y;
            upd(1, 1, n, i, y);
        }

    }

    //fix size
    return 0;
}
