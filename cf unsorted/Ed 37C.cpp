







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




int main()
{
	ll t, i, n, a[200004], mx;
	char c;
	bool flag;
	
	//while(1)
	{
		flag=1;
		mx=0;
		cin >> n;
		ffrr(i,1,n) cin >> a[i];
		string ss;
		cin >> ss;
		ss='-'+ss;
		
		ffrr(i,1,n)
		{
			mx=max(mx,a[i]);
			c=ss[i];
			if(c=='0' && mx>i)
			{
				flag=0; break;
			}
		}
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
	
}
