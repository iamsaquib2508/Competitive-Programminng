#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
using namespace std;

int main() {
	// your code goes here
	ll q, n, i, x, sum;
	//while(cin >> q)
	cin >> q;
	{
		while(q--)
		{
			sum=0;
			cin >> n;
			ffr(i,0,n)
			{
				cin >> x; sum+=x;
			}
			if(sum%n==0) cout << sum/n << endl;
			else cout << sum/n+1 << endl;
		}
	}
	return 0;
}
