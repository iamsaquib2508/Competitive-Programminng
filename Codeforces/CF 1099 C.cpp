#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define ll long long int
#define mm(a,b) memset(a,b,sizeof(a))

using namespace std;

int main()
{
    string s;
    int n;
    while(cin >> s >> n)
    {
        if(s[0]=='?')
        s.erase(s.begin());
        int i, sz=s.size(), candy=0, j, snow=0; //snow repeat

        ffr(i,0,sz)
        {
            if(s[i]=='?') candy++;
            if(s[i]=='*') snow++;
        }
        if(n<sz-candy-candy-snow-snow)
        {
            cout << "Impossible\n";
        }
        else if(n>sz-candy && snow==0)
        {
            cout << "Impossible\n";
        }
        else
        {
            string aa="";
            int req=n-(sz-candy-candy-snow-snow);
            ffr(i,0,sz)
            {

                if(s[i+1]=='*')
                {
                    if(req>0)
                    {
                        //aa+=s[i];
                        ffr(j,0,req)
                        //cout << s[i-1];
                        aa+=s[i];
                        req=0;
                    }

                }
                else if(s[i+1]=='?')
                {
                    if(req>0)
                    {
                        aa+=s[i];
                        req--;
                    }
                }
                else if(s[i]=='?' || s[i]=='*')
                {

                }
                else
                aa+=s[i];
                //cout << s[i];
            }
            cout << aa << endl;
        }
    }
}
