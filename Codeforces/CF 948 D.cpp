




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
    void sett()
    {
        rem++;
    }
};

trie* init;
void insert(trie* a, int pos)
{
    if(pos==31) return;
    
    c=t[pos];
    if(c==0)
    {
        if(a->zer==NULL)
        {
            a->zer=new trie[1];
            a->zer.neww();
        }
        a->zer.set();
        insert(a->zer, pos+1);
    }
    else
    {
        if(a->wan==NULL)
        {
            a->wan=new trie[1];
            a->wan.neww();
        }
        a->wan.set();
        insert(a->wan, pos+1);
    }
    return;
}

void search(trie* a, int pos, int mul, int s) //1<<30, 0
{
    if(pos==31) 
    {
        cout << s << " ";
    }

    trie* next;
    c=t[pos];
    if(c==0)
    {
        if(a->zer==NULL || a->zer->rem==0)
        {
            next=a->wan; s+=mul;
        }
        else next=a->zer;
        next->rem--;
        search(next, pos+1, mul>>1, s);
    }
    else
    {
        if(a->wan==NULL || a->wan->rem==0)
        {
            next=a->zer; s+=mul;
        }
        else
        {
            next=a->wan; 
        }
        next->rem--;
        search(a->next, pos+1, mul>>1, s);
    }
    return;
}

#define MX 300005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a[MX], sz, hi, lo, mid, i, j, cur, tm, t[35], mul, div, ulo, uhi, x;
    vector<int> v(MX); v.clear();
    cin >> n;
    ffr(i,0,n) cin >> a[i];
    ffr(i,0,n) { cin >> x; v.pb(x);
    }
    
    sort(v.begin(), v.end());
    
    init=new trie[1];
    init->neww();
    
    
    
    sz=n;
    ffr(i,0,n)
    {
        cur=a[i];
        mul=1;
        ffr(j,0,31)
        {
            t[j]=cur&1;
            cur>>=1;
            //mul<<=1;
        }
        mul<<=30;
        div=mul;
        
        ulo=0; uhi=sz-1;
        for(j=j-1;j>=0;j--)
        {
            lo=ulo, hi=uhi;
            if(hi==lo)
            {
                break;
            }
            //hello;
            if(t[j]==0)
            {
                if(v[uhi]<div)
                {
                    mul>>=1;
                    div-=mul;
                    continue;
                }
                if(v[ulo]>=div)
                {
                    mul>>=1;
                    div+=mul;
                    continue;
                }
                //pf("div %d mul %d hi %d lo %d uhi %d ulo %d\n", div, mul, hi, lo, uhi, ulo);
                while(hi-lo>1)
                {
                    mid=(hi+lo)/2;
                    if(v[mid]<div)
                    {
                        lo=mid;
                    }
                    else if(v[mid]>=div)
                    {
                        hi=mid;
                    }
                    
                }
                
                uhi=lo;
                
                //pf("div %d mul %d hi %d lo %d uhi %d ulo %d again\n", div, mul, hi, lo, uhi, ulo);
                mul>>=1;
                div-=mul;
                continue;
            }
            else
            {
                if(v[uhi]<div)
                {
                    mul>>=1;
                    div-=mul;
                    continue;
                }
                if(v[ulo]>=div)
                {
                    mul>>=1;
                    div+=mul;
                    continue;
                }
                //pf("div %d mul %d hi %d lo %d uhi %d ulo %d in 1\n", div, mul, hi, lo, uhi, ulo);
                while(hi-lo>1)
                {
                    mid=(hi+lo)/2;
                    if(v[mid]<div)
                    {
                        lo=mid;
                    }
                    else if(v[mid]>=div)
                    {
                        hi=mid;
                    }

                }
                ulo=hi;
                //pf("div %d mul %d hi %d lo %d uhi %d ulo %d again in 1\n", div, mul, hi, lo, uhi, ulo);
                mul>>=1;
                div+=mul;
                continue;
            }
            
        }
        
        cout << (v[hi]^a[i]) << " ";
        v.erase(v.begin()+hi);
        sz--;
    }
	return 0;

}
