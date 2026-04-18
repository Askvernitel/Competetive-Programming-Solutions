#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;

	string s, t;
	cin >> s >> t;
	int a=0, b=0, c=0;
	int pos = 1;
	for(int i =0;i<n;i++){
		if(a < 0){ 
			pos = 0;
			break;
		}
		if(b < 0){ 
			pos = 0;
			break;
		}
		if((s[i] =='a' && t[i] == 'c') || (s[i] =='c' && t[i] =='a')){ 
			pos = 0;
			break;
		}
		if(s[i] == 'a' && t[i] == 'b'){ 
			if(b != 0) {
				pos = 0;
				break;
			}
			a++;
		}	
		if(s[i] == 'b' && t[i] == 'a'){ 
			if(b != 0) {
				pos = 0;
				break;
			}
			a--;
		}
	
		if(s[i] == 'c' && a != 0){ 
			pos = 0;
			break;
		}
		if(s[i] == 'a' && b != 0){ 
			pos =0;
			break;
		}
		if(s[i] == 'b' && t[i] == 'c') {
			if(a != 0) {
				pos=0;
				break;
			}
			b++;
		}
		if(s[i] == 'c' && t[i] == 'b'){ 
			if(a !=0){
				pos=0;
				break;
			}
			b--;
		}
	}
	if(a != 0 || b != 0){ 
		pos = 0;
	}
	if(pos){ 
	cout << "YES\n";
	}else{ 
		cout << "NO\n";
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
