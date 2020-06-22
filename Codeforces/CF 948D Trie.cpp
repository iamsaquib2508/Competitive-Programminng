




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

class trie
{
    public:
    trie* zer;
    trie* wan;
    int rem;
    trie(){ rem=0; zer=NULL; wan=NULL;
    }
    void neww(){ rem=0; zer=NULL; wan=NULL;
    }
};

int t[35];
trie* init;

void insert(trie* a, int pos)
{
    if(pos==31) return;
    int c;
    c=t[pos];
    if(c==0)
    {

        if(a->zer==NULL)
        {
            
            a->zer=new trie[1];
            a->zer->neww();
        }
        a->zer->rem++;
        
        insert(a->zer, pos+1);
    }
    else
    {
        
        if(a->wan==NULL)
        {
            
            a->wan=new trie[1];
            a->wan->neww();
        }
        a->wan->rem++;
        
        insert(a->wan, pos+1);
    }
    return;
}

void search(trie* a, int pos, int mul, int s) //1<<30, 0
{
    if(pos==31)
    {
        cout << s << " ";
        return;
    }
    int c;
    c=t[pos];
    if(c==0)
    {
        
        if(a->zer==NULL || a->zer->rem==0)
        {
            a->wan->rem--;
            
            
            search(a->wan, pos+1, mul>>1, s+mul);
        }
        else
        {
            a->zer->rem--;

            search(a->zer, pos+1, mul>>1, s);
        }
        
    }
    else
    {
        if(a->wan==NULL || a->wan->rem==0)
        {
            a->zer->rem--;
            search(a->zer, pos+1, mul>>1, s+mul);
        }
        else
        {
            a->wan->rem--;
            search(a->wan, pos+1, mul>>1, s);
        }
    }
    return;
}

#define MX 300005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a[MX],  i, j, mul, x;
    init=new trie[1];
    init->neww();
    
    //#define bug
    cin >> n;
    ffr(i,0,n) cin >> a[i];
    ffr(i,0,n)
    {
        cin >> x;
        for(j=30; j>=0; j--)
        {
            t[j]=x&1;
            x>>=1;
        }
        
        insert(init, 0);
    }
    mul=1<<30;
    ffr(i,0,n)
    {
        x=a[i];
        for(j=30; j>=0; j--)
        {
            t[j]=x&1;
            x>>=1;
        }
        search(init, 0, mul, 0);
    }

    
	return 0;

}
