


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
		
	ll a, b, x, y, z, yc, bc;
	cin >> a >> b;
	cin >> x >> y >> z;
	yc = x+x+y-a;
	bc = y+z+z+z-b;
	cout << (yc>0)*yc+(bc>0)*bc << endl;
	
	
	
	
	
	return 0;
}
