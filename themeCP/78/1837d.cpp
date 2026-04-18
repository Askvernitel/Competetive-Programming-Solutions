#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	char a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	vector<char> s1, s2;
	vector<int> pos2;
	map<char,set<int>> m, m2;
	for(int i =0;i<n;i++){
		if(a[i] == '(' && s2.empty()){
			m[a[i]].insert(i);
			s1.push_back('(');
		}else if(a[i] == '(' && !s2.empty()){
			pos2.push_back(i);
			s2.pop_back();
		}else if(a[i] == ')' && s1.empty()){
			pos2.push_back(i);
			s2.push_back(')');
		}else if(a[i] == ')' && !s1.empty()){
			m[a[i]].insert(i);
			s1.pop_back();
		}
	}

	if(!s1.empty() || !s2.empty()){
		cout << -1 << '\n';
		return;
	}
	if(!pos2.empty() && ((int)pos2.size())%2 == 0){
		int mid = ((int)(pos2.size()))/2;

		int l = pos2[mid-1]+1;
		int r = pos2[mid]-1;
		vector<int> p;
		while(l <= r){ 
			if(a[l] == '(' && a[r] == ')'){
				break;
			}
			p.push_back(l);
			p.push_back(r);
			l++;
			r--;
		}
		if(r < l){
			for(int x : p){
				m[a[x]].erase(x);
				pos2.push_back(x);
			}
		}
	}

	int sz=1;
	if(!m['('].empty() && !m[')'].empty() && !pos2.empty()){
		sz++;
	}
	cout << sz << '\n';
	int ans[n];
	int k = 1;
	for(int i =0;i<pos2.size();i++){
		ans[pos2[i]] = k;
	}
	if(!pos2.empty()){
		k++;
	}

	for(auto x : m['(']){
		ans[x] = k;
	}

	for(auto x : m[')']){
		ans[x] = k;
	}
	
	for(int i =0;i<n;i++){
		cout << ans[i] << " ";
	}
	cout << '\n';	
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
 
