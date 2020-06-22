#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    cin >> tt;
    while(tt--)
    {
        cin >> n >> s >> t;
        if(n==2)
        {
            if(s[0]==s[1] && t[0]==t[1])
            {
                cout << "Yes\n1\n1 2\n";
            }
            else if(s[0]==t[1] && t[0]==s[1])
            {
                cout << "Yes\n2\n2 2\n1 2\n";
            }
            else cout << "No\n";
        }
        else
        {
            vector<int> v[26][26];
            ffr(i,0,26) ffr(j,0,26) v[i][j].clear();
            ffr(i,0,n)
            {
                if(s[i]!=t[i])
                {
                    v[s[i]-'a'][t[i]-'a'].pb(i);
                }
            }
            ffr(i,0,26)
            {
                ffr(j,0,26)
                {
                    if(v[i][j].size()>0)
                    {
                        ffr(jj,j+1,26)
                        {
                            if(v[i][jj].size()>0)
                            {
                                //exchange *1
                                break;
                            }
                        }

                    }
                }
            }
            ffr(i,0,26)
            {
                ffr(j,0,26)
                {
                    if(v[i][j].size()>0)
                    {
                        if(v[j][i].size()>0)
                        {
                            //exchange *3/2
                        }
                        else
                        {
                            ffr(jj,0,26)
                            {
                                if(v[jj][i].size()>0)
                                {
                                    //exchange *2
                                }
                            }
                        }
                    }

                }
            }
            print();
        }
    }
    return 0;
}
