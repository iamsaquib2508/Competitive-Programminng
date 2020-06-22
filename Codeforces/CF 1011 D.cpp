#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, got, lo, hi, mid, i, a[30];
    while(cin >> m >> n)
    {
        cout << 1 << endl;
        cin >> got;
        if(!got) break; //1 is ok
        a[0]=got;
        for(i=1;i<n;i++)
        {
            cout << 1 << endl;
            cin >> a[i];
        }
        lo=2; hi=m+1;
        i=0;
        while(hi-lo>1)
        {
            mid=(hi+lo)/2;
            cout << mid << endl;
            cin >> got;
            if(!got) break;
            if(got*a[i]<0) hi=mid;
            else lo=mid;
            i++; if(i==n) i=0;
        }
        if(hi-lo==1) cout << lo << endl;
        break;
    }
    return 0;
}
