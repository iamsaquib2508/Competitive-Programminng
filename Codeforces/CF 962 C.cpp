#include<bits/stdc++.h>
using namespace std;

string liczba, nowy;
int cnt, ans = 10000, v;

int getvalue(string s)
{
	int res = 0;
	int p = 1;
	for( int a = s.size() - 1; a >= 0; a-- )
	{
		res += p*((int)s[a] - (int)'0');
		p *= 10;
	}
	return res;
}
bool sq( int x )
{
	int r = sqrt(x);
	if( r*r == x || (r-1)*(r-1) == x || (r+1)*(r+1) == x )return true;
	return false;
}
int main()
{
    cout << sq(195) << endl;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>liczba;
	int n = liczba.length();
	int pot =  (1<<n);
	for( int a = 1; a < pot; a++ )
	{
		nowy = "";
		cnt = 0;
		for( int b = 0; b < n; b++ )
		{
			if( (a&(1<<b)) )nowy += liczba[b], cnt++;
		}
		if( nowy[0] != '0' )
		{
			v = getvalue(nowy);
			if( sq(v) )
			{
				//if( cnt == 1 )cout<<a<<" "<<v<<" "<<nowy<<endl;
				ans = min( ans,  n - cnt );
			}
		}
	}
	if( ans != 10000 )cout<<ans<<endl;
	else cout<<-1;
	return 0;
}
