#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;

	string s;
	cin >> s;
	vector<int> v;
	for(int i=1;i*i<=n;i++){
		if(!(n%i)){ 
			v.push_back(i);
			if(n/i != i) v.push_back(n/i);
		}
	}
	int ans = n;
	for(int x:v){
		map<string,int> m;
		for(int i = 0;i<n;i+=x){
			string t; 
			for(int j=i;j<i+x;j++) t += s[j];
			m[t]++;
			//cout <<s.substr(i,i+x) << " ";
		}
		if(m.size() <= 2){ 
			if(m.size()<=1){
				ans =min(ans,x);
				m={};
				continue;
			}
			int pos = 0;
			string s1="", s2="";
			for(auto &[c,d]:m){
				if(d != 1) pos++;
				if(s1 == "") s1 = c;
				else s2 = c;
			}
			int diff=0;
			for(int i = 0;i<(int)s1.size();i++){
				if(s1[i] != s2[i]) diff++;
			}
			if(pos <2 && diff <= 1) ans = min(ans,x);

		}
		m={};
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
