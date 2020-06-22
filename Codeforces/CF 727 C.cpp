#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)

using namespace std;

int main()
{
    int n, a, b, c, arr[5000], i;
    while(cin >> n)
    {
        cout << "? 1 2" << endl;
        cin >> a;
        cout << "? 1 3" << endl;
        cin >> b;
        cout << "? 2 3" << endl;
        cin >> c;

        arr[0]=(a+b-c)/2;
        arr[1]=(a+c-b)/2;
        arr[2]=(b+c-a)/2;
        ffr(i,3,n)
        {
            cout << "? 1 " << i+1 << endl;
            cin >> a;
            arr[i]=a-arr[0];
        }
        cout << '!';
        ffr(i,0,n) cout << ' ' << arr[i]; cout << endl;
        break;
    }
    return 0;
}
