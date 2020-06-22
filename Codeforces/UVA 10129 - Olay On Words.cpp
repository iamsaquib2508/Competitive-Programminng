#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

using namespace std;

vector<pii> path;
int arr[26][26];
int outdeg[26], indeg[26];

void euler_path(int start)
{
    int i;
    ffr(i,0,26)
    {
        if(arr[start][i]>0)
        {
            arr[start][i]--;
            euler_path(i);
            path.pb(mp(start,i));
            i--;
        }
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    int n, i, j, stnode, st, end, endnode;
    string s;
    while(t--)
    {
        mm(arr,0);
        path.clear();
        mm(indeg,0);
        mm(outdeg,0);

        cin >> n;
        ffr(i,0,n)
        {
            cin >> s;
            st=s[0]-'a'; end=s[s.size()-1]-'a';
            indeg[end]++;
            outdeg[st]++;
            arr[st][end]++;
        }
        if(n==1)
        {
            cout << "Ordering is possible.\n"; continue;
        }
        bool stfound=0, endfound=0;
        ffr(i,0,26)
        {
            if(!stfound && outdeg[i]-indeg[i]==1)
            {stfound=1; stnode=i;}
            else if(!endfound && outdeg[i]-indeg[i]==-1)
            {endfound=1; endnode=i;}
            else if(outdeg[i]!=indeg[i])
            {
                //err?
                break;
            }
        }
        if(i<26)
        {
            cout << "The door cannot be opened.\n";
        }
        else
        {
            if(!stfound)
            {
                ffr(i,0,26) if(outdeg[i]>0) {stnode=i; endnode=i;}
            }
            //cout << stnode << " start node\n";
            euler_path(stnode);
            int edgedone=path.size();
            if(edgedone<n || (edgedone>0 && path[0].second!=endnode))
            {
                cout << "The door cannot be opened.\n";
            }
            else
            {
                cout << "Ordering is possible.\n";
            }
        }
    }
    return 0;
}
