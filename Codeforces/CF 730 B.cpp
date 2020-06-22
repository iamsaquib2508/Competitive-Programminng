#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, minn, maxx, tmin, tmax, i;
        char got;
        cin >> n;
        if(n==1)
        {
            cout << "! 1 1" << endl;
        }
        else
        {
            cout << "? 1 2" << endl;
            cin >> got;
            if(got=='>') minn=2, maxx=1; else minn=1, maxx=2;
            i=4;
            while(i<=n)
            {
                cout << "? " << i-1 << ' ' << i << endl;
                cin >> got;
                if(got=='>') tmin=i, tmax=i-1; else tmin=i-1, tmax=i;

                cout << "? " << minn << ' ' << tmin << endl;
                cin >> got;
                if(got=='>') minn=tmin;

                cout << "? " << maxx << ' ' << tmax << endl;
                cin >> got;
                if(got=='<') maxx=tmax;

                i+=2;
            }
            if(n&1)
            {
                cout << "? " << minn << ' ' << n << endl;
                cin >> got;
                if(got=='>') minn=n;

                cout << "? " << maxx << ' ' << n << endl;
                cin >> got;
                if(got=='<') maxx=n;
            }
            cout << "! " << minn << ' ' << maxx << endl;
        }

    }
}
