#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define ll long long int
#define mm(a,b) memset(a,b,sizeof(a))

using namespace std;

int main()
{
    int w, h, u1, d1, u2, d2;
    while(cin >> w >> h)
    {
        cin >> u1 >> d1 >> u2 >> d2;
        //w+=h;
        while(h>0)
        {
            w+=h;
            if(d1==h)
            {
                w=max(0,w-u1);
            }
            if(d2==h)
            {
                w=max(0,w-u2);
            }
            h--;
            //cout << w << endl;
        }
        cout << w << endl;

    }
    return 0;
}
