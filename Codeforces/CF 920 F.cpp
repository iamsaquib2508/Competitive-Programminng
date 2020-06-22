




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

using namespace std;


class numberTheory
{

public:
    numberTheory(){}

    plolo extendedEuclid(ll a, ll b) { // returns x, y | ax + by = gcd(a,b)

        if(b == 0) return plolo(1LL, 0LL);
        else {
            pii d = extendedEuclid(b, a % b);
            return plolo(d.yy, d.xx - d.yy * (a / b));
        }

    }

    ll modularInverse(ll a, ll n) {
        plolo ret = extendedEuclid(a, n);
        return ((ret.xx % n) + n) % n;
    }


    ll bigMod(ll a, ll n , ll m)
    {

        ll res=1, x=a;
        while ( n )
    	{
        	if ( n & 1 )
        	{
            	res = ( res * x ) % m;
        	}
        	x = ( x * x ) % m;
        	n = n >> 1;
    	}
    	return res;
    }

};

/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

#define nsize 300002
#define valsize 1000002

int divv[valsize], a[nsize];
bool sat[4*nsize];
ll tree[4*nsize];

void build(int pos, int L, int R)
{
    
    
    if(L==R)
    {
        tree[pos]=a[L];
        if(tree[pos]<3) sat[pos]=1;
        return;
    }

    int mid=(L+R)/2;
    int left=pos+pos;
    build(left, L, mid);
    build(left+1, mid+1, R);

    tree[pos]=tree[left]+tree[left+1];
    sat[pos]=sat[left] & sat[left+1];
    
    return;
}

void update(int pos, int L, int R, int l, int r) //LR nije, lr query
{
    if(r<L || R<l) return;
    if(sat[pos]) return;
    if(L==R)
    {
        tree[pos]=divv[tree[pos]];
        if(tree[pos]<3) sat[pos]=1;
        return;
    }
    
    int mid=(L+R)/2;
    int left=pos+pos;
    update(left, L, mid, l, r);
    update(left+1, mid+1, R, l, r);
    
    tree[pos]=tree[left]+tree[left+1];
    sat[pos]=sat[left] & sat[left+1];
    
    return;
}

ll que(int pos, int L, int R, int l, int r) //LR nije, lr query
{
    if(r<L || R<l) return 0;
    if (l<=L && R<=r) return tree[pos];
    //if(sat[pos]) return tree[pos];
    if(L==R)
    {
        
        return tree[pos];
    }

    int mid=(L+R)/2;
    int left=pos+pos;
    ll ret=que(left, L, mid, l, r);
    ret+=que(left+1, mid+1, R, l, r);
    
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, i, x, l, r, j;
    mm(divv,0);
    mm(sat,0);
    
    divv[1]=1;
    ffr(i,2,valsize)
    {
        divv[i]++;
        for(j=i; j<valsize; j+=i)
        {
            divv[j]++;
        }
    }
    //ffr(i,1,30) cout << i << " " << divv[i] << endl;
    cin >> n >> q;
    ffrr(i,1,n) cin >> a[i];
    build(1,1,n);
    
    while(q--)
    {
        cin >> x >> l >> r;
        if(x==1)
        {
            update(1, 1, n, l, r);
        }
        else 
        {
            ll ans=que(1, 1, n, l, r);
            cout << ans << endl;
        }
    }
    
	return 0;

}
