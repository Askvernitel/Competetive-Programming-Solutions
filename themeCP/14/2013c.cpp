#include <bits/stdc++.h>

using namespace std;
bool ask(string s){

	cout << "? "<< s << '\n';
	int ans;
	cin >> ans;
	return ans;
}
void solve(){
	int n;
	cin >>n;
	
	string s="";
	char cur = '1';
	while(true){ 
		int l = 0, r=n+1;	
		while(r-l>1){
			int m = (r+l)/2;
			if(ask(s + string(m, cur))){
				l=m;
			}else{
				r=m;
			}
		}
	}

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
