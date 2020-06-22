#include<bits/stdc++.h>
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(),x.end()
#define endl "\n"

using namespace std;

int main()
{
	
	int i, j, k, m, n, p;
	string s;
	vector<int> v;
	cin >> n >> s;
	ffr(i,0,n)
	{
		j=0;
		if(s[i]=='B')
		{
			while(i<n && s[i]=='B') i++, j++;
		}
		if(j)
		v.pb(j);
	}
	cout << v.size() << endl;
	ffr(i,0,v.size()) cout << v[i] << " ";
	
	
	return 0;
}
