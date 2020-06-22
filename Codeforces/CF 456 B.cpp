


/*  *******************************************            DONATE BLOOD, SAVE LIFE!               *****************************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf


using namespace std;

int main()
{

	
	ll n , k;
	cin >> n >> k;
	string N="";
	if(k==1)  
	{
		cout << n << endl; return 0;
	}
	ll temp=n;
	while(temp)
	{
		int x=temp&1;
		temp/=2;
		
		N+=(x+'0');
	}
	int i, sz=N.size();
	n=1;
	ffr(i,0,sz) n*=2;
	n--;
	cout << n << endl;
	return 0;
}
