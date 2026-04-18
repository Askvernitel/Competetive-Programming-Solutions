#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, substr;
    cin >> s;
    cin >> substr;
    string ans = "";
    string b = "";
    vector<int> stack;
    stack.push_back(0);
    for(int i =0;i<n;i++){
        int x = stack.back();
        if(x == substr.size()){ 
            int t = substr.size();
            while(t > 0){ 
                stack.pop_back();
                b.pop_back();
                t--;
            }
        }
        x = stack.back();
        if(s[i] == substr[x]){ 
            b+=s[i];
            stack.push_back(x+1);
        }else if(s[i] == substr[0]){ 
            b+=s[i];
            stack.push_back(1);
        }else{ 
            ans+=b;
            ans+=s[i];;;;
        }
    }
    cout << ans << '\n';
}
