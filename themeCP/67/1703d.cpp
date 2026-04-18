#include <bits/stdc++.h>


using namespace std;
void solve(){
	int n;
	cin >>n;
	string a[n];
	set<string> s;
	for(int i =0;i<n;i++){
		cin >> a[i];
		s.insert(a[i]);
	}
	string ans = "";
	for(int i =0;i<n;i++){
		int m = a[i].size();
		string q = "";
		q+=a[i][0];
		bool f =0;
		for(int j =1;j<m;j++){
			string t = "";
			for(int k = j;k<m;k++){
				t+=a[i][k];
			}
			if(s.find(t) != s.end() && s.find(q) != s.end()){
				f=1;
				break;
			}
			q+=a[i][j];
		}
		if(f){
			ans+='1';
		}else{
			ans+='0';
		}
	}
	cout<< ans << '\n';
}

int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
