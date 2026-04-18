#include <bits/stdc++.h>

using namespace std;
bool is_num(char ch){ 
    return ch >= '0' && ch <='9';
}

string conv(int num){ 
    string res=""; 
    while(num !=0){
        int a= 0;
        if(num%26 == 0){ 
            a+=26;
            num-=26;
        }else a = num%26;
        res.push_back('A'-1+a);
        num/=26;
    }
    reverse(res.begin(),res.end());
    /*
    int i = 0;
    while(num >=pow(26,i)) i++;
        
    while(num != 0){ 
        
        int k = num /pow(26,i);
        res.push_back('A kkk'+);
    }*/
    return res;
}

int conv26(string s){     
    int res = 0;
    int n = s.size();
    for(int i =0;i<n;i++){
        res*=26;
        res+=(s[i]-'A'+1);
    }
    return res;
}
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int pos1=0, pos2 = 0;
    int type = 0;
    for(int i =0;i<n;i++){
        if(s[i] == 'R' && i+1<n && is_num(s[i+1])) pos1=1;
        if(s[i] == 'C' && i+1<n && is_num(s[i+1])) pos2=1;
    }
    type = pos1 && pos2;
//    if(pos1+1 < pos2 && cnt1 == 1 && cnt2 == 1 ) type = 1;
    
    if(type){ 
        int i = 0;
        string first_num ="", second_num="";
        while(i<n && s[i] != 'C'){
            if(s[i] == 'R') {i++; continue;}
            first_num.push_back(s[i++]);
        }

        while(i<n){ 
            if(s[i] == 'C'){i++; continue;}
            second_num.push_back(s[i++]);
        }
        int num1 = stoi(first_num), num2 = stoi(second_num);
        cout << conv(num2) << num1;
    }else{ 
        int i =0;
        string str="", num="";
        while(i<n && !is_num(s[i])){ 
            str.push_back(s[i++]);
        }

        while(i<n){ 
            num.push_back(s[i++]);
        }
        int num1 = conv26(str), num2 = stoi(num);
        
        cout << 'R' << num2 << 'C' << num1;
    }
    cout <<endl;
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();

}
