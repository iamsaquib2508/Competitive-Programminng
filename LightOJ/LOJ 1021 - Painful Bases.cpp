#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define ll long long
#define zeroat(a,b) !(a & (1<<b))
#define set(a,b) a|(1<<b)

using namespace std;
int b, k, n;
string s;

ll dp[65600][23];
int limit;

int val(char a)
{
	if('0'<= a && a<='9') return a-'0';
	else return a-'A'+10;
}

ll call(int mask, int rem)
{
	if(mask==limit) return (!rem);
	if(dp[mask][rem]!=-1) return dp[mask][rem];
	ll ret=0;
	int i;
	ffr(i,0,n)
	{
		if(zeroat(mask,i))
		ret+=call( set(mask,i) , ( rem*b+val(s[i]) ) %k );
	}
	dp[mask][rem]=ret;
	return ret;
}

int main()
{
	int cc=1, t;
	cin >> t;
	while(t--)
	{
		mm(dp,-1);
		cin >> b >> k >> s;
		n=s.size();
		limit=(1<<n)-1;
		ll ans=call(0,0);
		printf("Case %d: %lld\n", cc++, ans);
	}
	return 0;
}