#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n, m;
	string s, a;
	stack<char> stk;
	while(cin >> n)
	{
		cin.ignore();
		getline(cin,s);
		//cout << s << endl;
		cin >> m;
		//cout << m << endl;
		bool cap=0;
		while(m--)
		{
			cin >> a;
			if(a=="Backspace")
			{
				if(!stk.empty()) stk.pop();
			}
			else if(a=="CapsLock") cap^=1;
			else if(a=="Space")
			{
				stk.push(' ');
			}
			else stk.push(a[0]+cap*('A'-'a'));
		}
		a="";
		while(!stk.empty())
		{
			a+=(stk.top()); stk.pop();
		}
		reverse(a.begin(),a.end());
		cout << s << " " << a << endl;
		if(s!=a) cout << "Incorrect\n";
		else cout << "Correct\n";
	}
	return 0;
}
