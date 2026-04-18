#include <bits/stdc++.h>

using namespace std;
#define int long long 

string s;
set<char> s1 = {'A', 'E', 'I', 'O', 'U', '#'};
int ans = 0;
void isValid(string s){
	int n = s.size();	
	bool valid = false;
	bool pos = false;
	bool p = false;
	int idx = 0;
	for(int i =0;i<n;i++){
		if(s[i] == 'L') valid = true;
	//	if(s[i] == '%') pos = true;
	}

	for(int i =0;i<n-2;i++){
		if(s1.find(s[i]) != s1.end() && s1.find(s[i+1]) != s1.end() && s1.find(s[i+2]) != s1.end()){
			valid = false;
	//		pos = false;
		}
		if(s1.find(s[i]) == s1.end() && s1.find(s[i+1]) == s1.end() && s1.find(s[i+2]) == s1.end()){
			valid = false;
	//		pos = false;
		}
		
	}


	if(!valid){ 
		return;	
	}
	int cnt = 1;
/*	if(!valid){ 
		cnt = 0;
		for(int i =0;i<n;i++){
			if(s[i] == '%'){ 
				s[i] = 'L';
				int cnt1 = 1;
				for(int j =0;j<n;j++){
					if(s[j] == '#') cnt1 *=5;
					else if(s[j] == '%') cnt1*=20;
				}
				s[i] = '%';
				cnt += cnt1;
			}
		}
	}else{*/
		for(int i =0;i<n;i++){
			if(s[i] == '#') cnt *= 5;
			else if(s[i] == '%') cnt *= 20;
		}
	//}
	ans += cnt;

}

void rec(int k){ 
	int n = s.size();	
	if(k == n){
		isValid(s);	
		return;
	}
	if(s[k] != '_'){rec(k+1) ; return;}

	for(int i = 0;i<3;i++){
		if(i == 0){ 
			s[k] = '#';
			rec(k+1);
			s[k] = '_';
		}else if(i == 1){
			s[k] = '%';
			rec(k+1);
			s[k] = '_';
		}else{
			s[k] = 'L';
			rec(k+1);
			s[k] = '_';
		}
	}
		
}

signed main(){
	
	cin >> s;
	int n = s.size();
	rec(0);
	cout << ans;
}
