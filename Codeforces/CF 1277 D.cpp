#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

void swapp(int &a, int &b)
{
    a^=b; b^=a; a^=b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int sz, n, i, maximum, minimum, niuo=0, niuz=0, olo=0, olz=0, z, o, onlyo=0, onlyz=0;
        string str, rev;
        map<string,int> mp;
        cin >> n;

        set<int> zs, os;
        zs.clear(); os.clear();
        ffr(i,0,n)
        {
            cin >> str;
            rev=str;
            reverse(rev.begin(),rev.end());
            sz=str.size();
            if(mp.find(rev)==mp.end())
            {
                //new
                mp[str]=i;
                if(str[0]=='0' && str[sz-1]=='1') {niuz++; zs.insert(i);}
                else if(str[0]=='1' && str[sz-1]=='0') { niuo++; os.insert(i);}
                else if(str[0]=='1' && str[sz-1]=='1') onlyo++;
                else onlyz++;
            }
            else
            {
                //cannot touch
                int temp=mp[rev];
                mp.erase(rev);

                if(str[0]=='0' && str[sz-1]=='1') { olz++; niuo--; olo++; os.erase(temp);}
                else if(str[0]=='1' && str[sz-1]=='0') { olo++; niuz--; olz++; zs.erase(temp);}
                else if(str[0]=='1' && str[sz-1]=='1') onlyo++;
                else onlyz++;
            }
        }
        maximum=(niuz+olz+olo+niuo+1)/2;
        if(olz>maximum || olo>maximum) cout << "-1\n";
        else if(onlyo+onlyz==n && onlyo*onlyz>0) cout << "-1\n";
        else
        {
            minimum=niuz+olz+olo+niuo-maximum;
            z=(niuz+olz); o=(niuo+olo);
            set<int>::iterator it;
            if(z<minimum)
            {
                cout << minimum-z << endl;
                it=os.begin();
                ffr(i,0,minimum-z)
                {
                    cout << (*it)+1 << " "; it++;
                }
                cout << endl;
            }
            else if(o<minimum)
            {
                cout << minimum-o << endl;
                it=zs.begin();
                ffr(i,0,minimum-o)
                {
                    cout << (*it)+1 << " "; it++;
                }
                cout << endl;
            }
            else cout << "0\n";
        }
        // z=(niuz+olz); o=(niuo+olo);
        // if(z>o)
        // {
        //     swapp(z,o); swapp(niuo,niuz); swapp(olo,olz);
        // }
    }
}
