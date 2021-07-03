//5
string nthCharacterRemoval(string s, int n=4)
{
    int len = s.size();
    if(len < 4){
        //not described in the requirement.
        //returning the entire string.
        return s;
    }
    else{
        string ret = "";
        for(int i = 0; i + 1 < n; i++){
            ret += s[i];
        }
        for(int i = n; i < len; i++){
            ret += s[i];
        }
        return ret;
    }
}

//6
string intraWordReversal(string s){
    int len = s.size();
    stack<char> st;
    string ans = "";
    for(int i = 0; i < len; i++){
        if(s[i] == ' ' || i == len - 1){
            //end of word or sentence //need to generate the returnee string
            if(i == len - 1)
                st.push(s[i]);
            while(!st.empty()){
                char a = st.top();
                st.pop();
                ans += a;
            }
            if(s[i] == ' ') //really end of word, put space
                ans += ' ';
        }
        else{
            st.push(s[i]);
        }
    }
    return ans;
}

//7
double averageFromFile(string filename){
    ifstream fin;
    fin.open(filename, ifstream::in);
    int element, count = 0;
    double sum = 0.0;
    while(fin >> element){
        sum += element;
        count++;
    }
    if(count > 0)
        return sum / count;
    else{
        //numeric average doesn't exist.
        //nothing described in the requirement.
        //throwing error.
        throw "No number found, average is undefined.";
    }
}

//9
void func9(int n = 10){
    int limit = n + n - 1, printable = n;
    for(int i = 0; i < limit; i++){
        cout << printable << ' ';
        if(i + 1 < n){
            printable--;
        }
        else{
            printable++;
        }
    }
    cout << '\n';
    return;
}

//10
void func10(){
    for(int i = 199; i > 0; i -= 2){
        cout << i << ' ';
    }
    cout << '\n';
    return;
}

//2
void func2(int n = 10){
    int limit = n + n - 1, printable = 1;
    for(int i = 0; i < limit; i++){
        cout << printable << ' ';
        if(i + 1 < n){
            printable++;
        }
        else{
            printable--;
        }
    }
    cout << '\n';
    return;
}

//3
void func3(){
    for(int i = 198; i > 0; i -= 3){
        cout << i << ' ';
    }
    cout << '\n';
    return;
}

//4
string interWordReversal(string s){
    int len = s.size();
    stack<string> st;
    string ans = "", temp="";
    for(int i = 0; i < len; i++){
        if(s[i] == ' ' || i == len - 1){
            //end of word or before end of sentence
            if(i == len - 1)
                temp += s[i];
            st.push(temp);
            temp = "";
            
        }
        else{
            temp += s[i];
        }
    }
    ans = st.top();
    st.pop();
    while(!st.empty()){
        ans += ' ';
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main(){
    // cout << nthCharacterRemoval("abcdel") << endl; // 5
    // cout << intraWordReversal("i eat apple") << endl; // 6
    // func9(); // 9
    // func10(); // 10
    func2(); // 2
    func3(); // 3
    cout << interWordReversal("i eat apple") << endl; // 4
}