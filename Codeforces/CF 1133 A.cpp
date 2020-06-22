#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    int h1, h2, m1, m2;
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        h1=0; m1=0; h2=0; m2=0;
        int i=0;
        while(s1[i]!=':')
        {
            h1*=10; h1+=s1[i]-'0';
            i++;
        }
        i++;
        while(i<s1.size())
        {
            m1*=10; m1+=s1[i]-'0';
            i++;
        }

        i=0;
        while(s2[i]!=':')
        {
            h2*=10; h2+=s2[i]-'0';
            i++;
        }
        i++;
        while(i<s2.size())
        {
            m2*=10; m2+=s2[i]-'0';
            i++;
        }

        //cout << h1 << m1 << endl << h2 << m2 << endl;
        int tim=(h2-h1)*60+(m2-m1);
        tim/=2;
        while(tim--)
        {
            m1++;
            if(m1==60) {m1=0; h1++;}
        }
        if(h1<10) cout << "0";
        cout << h1 << ":";
        if(m1<10) cout << "0";
        cout << m1 << endl;
    }
}
