







/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf

using namespace std;




/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */

int rett(int n)
{
	int cnt=0;
	while(n>0)
	{
		cnt+=(n%2);
		n/=2;
	}
	return cnt;
}

string s;
int sz;
ll mod=1000000007;

ll DP[1002][1002][2];

ll digdp(int i, int k, int threat)
{
	//pf("i %d k %d threat %d\n", i, k, threat);
	if(i==sz && k>0) return 0;
	//if(i==sz && k==0) return 1;
	if(k==0) return 1;
	if(DP[i][k][threat]!=-1) return DP[i][k][threat];
	ll ret;
	if(threat==0)
	{
		if(sz-i<k) return DP[i][k][threat]=0;
		ret=(digdp(i+1, k-1, 0)+digdp(i+1, k, 0))%mod;
		goto dd;
	}
	if(s[i]=='0')
	{
		ret=digdp(i+1, k, 1);
	}
	else
	{
		ret= (digdp(i+1, k-1, 1)+digdp(i+1, k, 0)) %mod;
	}
	dd:
	//pf("i %d k %d threat %d ret %d\n", i, k, threat, ret);
	return DP[i][k][threat]=ret;
}

int main()
{
	
	
	int i, Kvalue[1005], ssz, kk;
	//while(1){
	
	ll ans=0;
	
	mm(DP,-1);
	Kvalue[0]=-1;
	Kvalue[1]=0;
	ffr(i,2,1001)
	{
		Kvalue[i]=Kvalue[rett(i)]+1;
	}
	cin >> s >> kk;
	
	sz=s.size();
	if(kk==1) 
	{
		cout << s.size()-1 << endl;
		return 0;
	}
	ffr(i,0,1001) 
	{
		if(Kvalue[i]==kk-1) 
		{
			//v.pb(i);
			if(i<=sz)
			ans=(ans+digdp(0,i,1))%mod;
			//cout << i << " ";
		}
		
		
	}
	//cout << endl;
	int p;
	//cin >> p;
	cout << ans << endl;
//}
	return 0;
	
	
}

/*

11011 1
11010001110 4
1000101010101 2
1000101010111101110101 2
1000101010111101110101 3
1000101010111101110101 4
1000101010111101110101 5

*/
