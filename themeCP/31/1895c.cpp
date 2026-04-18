#include <bits/stdc++.h>
#define int long long
using namespace std;

int toi(char s){ 
	return s-48;
}
int ssum(string s){
	int res = 0;
	for(char ch:s){ 
		res += toi(ch);
	}
	return res;
}
signed main(){
	int n;
	cin >> n;
	string a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int ans = 0;
	sort(a, a+n, [](string a, string b){
		return a.size() < b.size();
	});
	map<int,vector<vector<int>>> eo;
	map<int,map<int,int>> v;
	for(int i =0;i<n;i++){
		string s=a[i];
		int sz = s.size();
		v[sz][ssum(s)]++;
		if(sz == 1){ 
			//v[sz][ssum(s)]++;$
			int cnt1=v[1][ssum(s)];
			cnt1+=max((int)0,(cnt1-1));
			ans+=cnt1;
		}else if(sz == 2){
			int cnt1=v[2][ssum(s)];
			cnt1+=max((int)0,(cnt1-1));
			ans+=cnt1;
			//v[sz][ssum(s)]++;
		}else if(sz == 3){
			int cnt1=v[1][ssum(s)-toi(s[0])-toi(s[0])];
			int cnt2=v[1][ssum(s)-toi(s[2])-toi(s[2])];
			int cnt3=v[3][ssum(s)];
			cnt3+=max((int)0,(cnt3-1));
			ans+=cnt1+cnt2+cnt3;
		}else if(sz == 4){
			int cnt1=v[2][ssum(s)-toi(s[0])-toi(s[0])];
			int cnt2=v[2][ssum(s)-toi(s[3])-toi(s[3])];
			int cnt3=v[4][ssum(s)];
			cnt3+=max((int)0,(cnt3-1));
			ans+=cnt1+cnt2+cnt3;
		}else{ 
			int cnt1=v[1][ssum(s)-toi(s[0])-toi(s[1])-toi(s[0])-toi(s[1])];
			int cnt2=v[1][ssum(s)-toi(s[4])-toi(s[3])-toi(s[4])-toi(s[3])];
			int cnt3=v[3][ssum(s)-toi(s[0])-toi(s[0])];
			int cnt4=v[3][ssum(s)-toi(s[4])-toi(s[4])];
			int cnt5=v[5][ssum(s)];
			cnt5+=max((int)0,(cnt5-1));
			ans+=cnt1+cnt2+cnt3+cnt4+cnt5;
		}
	}

	cout << ans << '\n';
}
