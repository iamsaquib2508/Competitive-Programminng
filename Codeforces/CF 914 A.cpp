







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




int main()
{
	int i, n, a[10000], rt;
	//while(1){
		
	cin >> n;
	ffr(i,0,n)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	for(i=n-1;i>=0;i--)
	{
		if(a[i]<0)
		{
			cout << a[i] << endl;
			break;
		}
		rt=sqrt(a[i]);
		if(rt*rt==a[i])
		{
			continue;
		}
		else 
		{
			cout << a[i] << endl;
			break;
		}
	}
//}

	return 0;
	
	
}
