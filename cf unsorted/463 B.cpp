




/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */




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


class numberTheory{

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

class vec
{
	public:
	
	ld x, y;
	vec (){
	}
	vec(ld xxx, ld yyy)
	{
		x=xxx, y=yyy;
	}
	vec operator +(const vec b) const
	{
		return vec(x+b.x,y+b.y);
	}
	vec operator -(const vec b) const
	{
		return vec(x-b.x,y-b.y);
	}
	vec operator *(ld b) const
	{
		return vec(x*b,y*b);
	}
	vec operator /(ld b) const
	{
		return vec(x/b,y/b);
	}
	bool operator <(const vec b) const
	{
		return (x<b.x) || ( (x==b.x) && (y<b.y) );
	}
	void print()
	{
		pf("x=%.15Lf y=%.15Lf\n", x, y);
	}
};

class line
{
	public:
	vec f, dir;
	line(){
	}
	line(vec ff, vec dirr)
	{
		f=ff, dir=dirr;
	}
};


ld magnitude(vec a)
{
	return sqrt(a.x*a.x+a.y*a.y);
}

ld dot(vec a, vec b)
{
	return (a.x*b.x+a.y*b.y);
}

ld cross2D(vec a, vec b)
{
	return (a.x*b.y-a.y*b.x);
}


vec rotate_CCWnT(vec a, ld t)
{
	return vec(a.x*cos(t)-a.y*sin(t), a.x*sin(t)+a.y*cos(t));
}

ld intersect1(line a, line b)
{
	ld temp=b.dir.x*a.dir.y-a.dir.x*b.dir.y;
	ld temp2=b.dir.x*(b.f.y-a.f.y)-b.dir.y*(b.f.x-a.f.x);
	return temp2/temp;
}



/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */


int ar[1000005];

int func(int a)
{
	if(a<10) return a;
	if(ar[a]!=-1) return ar[a];
	ll pro=1;
	ll x=a, t;
	while(a>0)
	{
		t=a%10;
		if(t>0) pro*=t;
		a/=10;
		
		
		
	}
	return func(pro);
}


int main()
{
	int l, r, n, k;
	int i;
	mm(ar,-1);
	vector<int> v[10];
	ffr(i,0,10)
	{
		 v[i].clear();
		 
	}
	int cons=1000003;
	
	ffr(i,1,cons)
	{
		if(ar[i]==-1)
		ar[i]=func(i);
	}
	
	ffr(i,1,cons)
	{
		v[ar[i]].pb(i);
	}
	
	cin >> n;
	int lo, hi, mid, lfin, rfin;
	
	ffr(i,0,n)
	{
		cin >> l >> r >> k;
		//cout << "\nhello\n";
		lo=0, hi=v[k].size();
		
		if(l<v[k][0])
		{
			lfin=0; hi=0;
		}
		else if(v[k][hi-1]<l)
		{
			lfin=hi; hi=0;
		}
		while(lo<hi)
		{
			mid=(lo+hi)/2;
			//cout << mid << endl;
			if(lo==mid)
			{
				if(v[k][mid]==l) lfin=mid;
				else lfin=mid+1;
				break;
			}
			
			
			if(v[k][mid]<l) lo=mid;
			else if(v[k][mid]>l) hi=mid;
			else
			{
				lfin=mid; break;
			}
			
			
		}
		
		
		lo=0, hi=v[k].size();
		if(r<v[k][0])
		{
			rfin=-1; hi=0;
		}
		else if(v[k][hi-1]<r)
		{
			rfin=hi-1; hi=0;
		}
		while(lo<hi)
		{
			mid=(lo+hi)/2;
			if(lo==mid)
			{
				if(v[k][hi]==r) rfin=hi;
				else rfin=mid;
				break;
			}
			
			
			if(v[k][mid]<r) lo=mid;
			else if(v[k][mid]>r) hi=mid;
			else
			{
				rfin=mid; break;
			}
			
			
		}
		
		cout << rfin-lfin+1 << endl;
		
	}	

	return 0;
	
}
