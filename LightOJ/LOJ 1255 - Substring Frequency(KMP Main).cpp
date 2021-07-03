#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back

using namespace std;

int back[1000003];

void backbuild(string W)
{
    int pos, id, sz=W.size();
    pos=1, id=0;
    back[0]=-1;
    while(pos<sz)
    {
        if(W[pos]!=W[id])
        {
            back[pos]=id;
            id=back[id];
            while(id>0 && W[id]!=W[pos])
            {
                id=back[id];
            }
        }
        else
        {
            back[pos]=back[id];
        }
        // cout << back[pos] << ' ';
        pos++, id++;
    }
    // cout << id;
    back[pos]=id; //back[pos]=-1 for non overlapping occurrences
}

int KMP(string S, string W) //in a, occurrence of b
{
    int ss = S.size(), ws = W.size(), j, k;
    backbuild(W);
    j = 0, k = 0;
    vector<int> v;
    while(j < ss)
    {
        if(S[j] == W[k]) //if current match
        {
            j++; k++; //simply procees
            if(k == ws) //if full match found
            {
                v.pb(j-k);
                k = back[k]; //start from somewhere back
                //k=0; // for non overlapping occurrences
            }
        }
        else
        {
            k = back[k];
            if(k<0)
            {
                j++; k=0;
            }
        }
    }
    return v.size(); //return all for all starting places

}

int main()
{
    int cc=1, T;
    cin >> T;
    string A, B;
    while(T--)
    {
        cin >> A >> B;
        // cout << "-1 ";
        // backbuild(B);

        pf("Case %d: %d\n", cc, KMP(A,B));
        cc++;
    }
}
