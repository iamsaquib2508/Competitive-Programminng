#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, p, i, j, sz;
    string s;
    cin >> n >> p;
    cin >> s;
    sz=s.size();
    for(i=0,j=p;j<sz;j++,i++)
    {
        if(s[i]==s[j])
        {
            if(s[i]=='0' || s[i]=='1')
            {
                continue;
            }
            else
            {
                s[i]='0';
                s[j]='1';
                break;
            }
        }
        else if(s[i]=='.')
        {
            s[i]=((s[j]-'0')^1)+'0';
            break;
        }
        else if(s[j]=='.')
        {
            s[j]=((s[i]-'0')^1)+'0';
            break;
        }
        else break;
    }
    if(j==sz)
    {
        cout << "No\n";
    }
    else
    {
        //cout << "YES\n";
        for(i=0;i<sz;i++)
        {
            if(s[i]=='.') cout << '0';
            else cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}
