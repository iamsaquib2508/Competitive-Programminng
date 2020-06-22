
/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */
ll n, m, ta, tb, k, i, j, x, a[200005], b[200005];

int main()
{

    while(cin >> n >> m >> ta >> tb >> k)
    {
        ffr(j,0,n)
        {
            cin >> x;
            a[j]=x+ta;
        }
        ffr(i,0,m)
        {
            cin >> b[i];
        }
        sort(a,a+n);
        sort(b,b+m);
        a[n]=a[n-1];
        b[m]=b[m-1];
        i=0; j=0;
        while(i<m && j<n )
        {
            //i in b
            if(b[i]<a[j]) i++;
            else break;

        }
        while(i<m && j+1<n && k>0)
        {
            //i in b
            if(b[i]>=a[j+1]) {j++; k--;}
            else break;

        }
        while(k>0)
        {
            //cout << "hello\n";
            //cout << i << " i j " << j << endl;
            if(i<m && j<n)
            {
                if(b[i+1]<a[j+1])
                {
                    j++;
                }
                else if(b[i+1]>=a[j+1])
                {
                    i++;
                }
                k--;
            }
            else
            {
                i=m; break;
            }

            while(i<m && j<n )
            {
                //i in b
                if(b[i]<a[j]) i++;
                else break;

            }
            while(i<m && j+1<n && k>0)
            {
                //i in b
                if(b[i]>=a[j+1]) {j++; k--;}
                else break;

            }


        }
        if(i==m)
        {
            cout << "-1\n";
        }
        else cout << b[i]+tb << endl;
    }
}
