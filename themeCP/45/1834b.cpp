#include <bits/stdc++.h>

using namespace std;

bool f(string& s1, string s2, int idx){
	string t1= s1.substr(0,idx);
	string t2= s2.substr(0,idx);
	if(t1 > t2) return true;
	return false;
}
void solve(){
	string l, r;

	cin >> l >> r;
	int n = l.size();
	int m = r.size();
	if(n > m){while(m++ < n) r.insert(r.begin(), '0');
		m--;
	}
	else if(n < m){ while(n++ < m) l.insert(l.begin(),'0');
			n--;}

	string s1 = l, s2=r;
	int ans= 0 ;
	for(int i = max(n-1, m-1); i>=0;i--){
		while((s1[i] < '9' && s1[i] < r[i]) || (s1[i] <'9' && f(r, l, i))){ 
			s1[i]++;
		}
		while((s2[i] > '0' && s2[i] > l[i]) || (s2[i] > '0' && f(r,l,i))){
			s2[i]--;
		}
		ans+=abs(s2[i]-s1[i]);
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
