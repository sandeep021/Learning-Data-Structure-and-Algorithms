#include <iostream>
#include <stack>
using namespace std;

bool checkParenthesis(string s){
    stack <char> c;
    for (int i=0;i<s.size();++i){
        char x=s[i];
        if (x=='(')  c.push(x);
        else if (x==')'){
            if (c.empty() || c.top()!='(') return false;
            c.pop();
        }
    }
    return c.empty();
}

int main(){
    string s;
    cin>>s;
    bool ans=checkParenthesis(s);
    cout<<ans;
}