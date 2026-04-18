#include <bits/stdc++.h>
using namespace std;
int conv(string str){
	int k = str.size();
	int num = 0;
	for(int i=k-1;i>=0;i--){
		if(str[i] == '1')
		num += (1<<((k-1)-i));
	}
	return num;
}
int main(){
	string s;
	cin >> s;
	int n = s.size();
	string ans = "";
	string t = "";
	for(int i=n-1;i>=0;i--){
		int k = t.size();
		if(k == 3){
			ans.push_back((char)(conv(t) + '0'));
			t = "";
		}

		t.push_back(s[i]);
	}
	if(t != "")ans.push_back((char)(conv(t)+'0'));
	reverse(ans.begin(),ans.end());
	int z = 0;
	while(ans[z] == '0') z++;
	for(int i =z;i<ans.size();i++){
		cout << ans[i];
	}
	cout << '\n';
}
