







/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)

using namespace std;



/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */

class tp
{
	public:
	ll id, l, r;
	tp(){
	}
	
	bool operator<(const tp b) const
	{
		if(l<b.l) return true;
		if(l==b.l && id<b.id) return true;
		return false;
	}
};


int main()
{
	ll t, n, i, l, r, clk, ans[1003];
	tp a[1003];
	cin >> t;
	while(t--)
	{
		cin >> n;
		ffr(i,0,n)
		{
			cin >> l >> r;
			a[i].id=i+1; a[i].l=l; a[i].r=r;
			
		}
		sort(a,a+n);
		clk=1;
		ffr(i,0,n)
		{
			if(clk<a[i].l) clk=a[i].l;
			if(clk>a[i].r)
			{
				ans[a[i].id]=0;
			}
			else
			{
				ans[a[i].id]=clk;
				clk++;
			}
		}
		//cout << "ans\n";
		ffrr(i,1,n)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}

	return 0;
	
}
