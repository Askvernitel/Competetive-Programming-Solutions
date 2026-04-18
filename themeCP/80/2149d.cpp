#include <bits/stdc++.h>
#define int long long

using namespace std;
int f(vector<int>& v, int m){ 
	if(m < 0){
		return INT_MAX;
	}
	int n = v.size();

	int ans = 0;
	int t = 0;
	for(int i =0;i<m;i++){
		ans += v[m]-v[i]-1-t;
		t++;
	}
	//ans -= (max((int)0,(m-1))*max((int)0,(m-2)))/2;
	t = 0;
	for(int i=m+1;i<n;i++){
		ans += v[i]-v[m]-1-t;
		t++;
	}
	//ans -= (max((int)0,(n-m-1))*max((int)0,(n-m-2)))/2;
//	cout << (max(0,(n-m-1))*max(0,(n-m-2)))/2 << '\n';

	return ans;
	
}
void solve(){
	int n;
	cin >> n;
	char s[n];
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	
	vector<int> sa, sb;
	for(int i =0;i<n;i++){
		if(s[i] == 'a'){
			sa.push_back(i);
		}else{
			sb.push_back(i);
		}
	}

	int ans = min({f(sa, ((int)sa.size()/2)), f(sa, ((int)sa.size()/2)-1), f(sb, ((int)sb.size()/2)), f(sb, ((int)sb.size()/2)-1)});
	cout << max((int)0,ans) << '\n'	;
}

signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}

