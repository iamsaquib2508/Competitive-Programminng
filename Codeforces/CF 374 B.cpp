#include<bits/stdc++.h>
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(),x.end()

using namespace std;

bool cmp(string a, string b)
{
	return a.size()<b.size();
}

int main()
{
	
	int i, j, k, m, n, p, id, ans, ans2;
	
	while(cin >> n >> k)
	{
	string s[105], t;
	 ans=0, ans2=0;
	ffr(i,0,n)
	{
		cin >> s[i];
	}
	i=0;
	cin >> t;
	sort(s,s+n,cmp);
	p=t.size();
	
	while(s[i].size()<p)
	{
		id=s[i].size();
		j=0;
		while(s[i].size()==id)
		{
			i++; j++;
		}
		//
		ans+=(j/k)*5+(j);
	}
	ans2=ans;
	ans++;
	id=s[i].size();
	j=0;
	while(s[i].size()==id) i++, j++;
	ans2+=(j/k)*5+(j);
	if(j%k==0) ans2-=5;
	
	ffr(i,0,n)
	cout << s[i] << endl;
	
	
	cout << ans << " " << ans2 << endl;
	}
	return 0;
}
