







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
//while(1){

	int i, n, a[100002], rt, ch=1, cnt=0;
		
	cin >> n;
	ffr(i,0,n)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	rt=a[n-1];
	for(i=n-1;i>=0;i--)
	{
		if(a[i]==rt)
		{
			cnt++;
		}
		else
		{
			if(cnt%2==1) 
			{
				ch=1; break;
			}
			else
			{
				rt=a[i];
				cnt=1;
				
			}
			
		}
	}
	if(cnt%2==1) cout << "Conan\n";
	else cout << "Agasa\n";
//}
	return 0;
	
}
