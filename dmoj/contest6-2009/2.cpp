#include <bits/stdc++.h>

using namespace std;

int teams[10], broken[10], c[10];
int main(){
	int n, s, r;
	cin >> n >> s >> r;
	

	for(int i =0;i<s;i++){
		int k;
		cin >> k;	
		teams[k-1]=1;
	}
	memcpy(broken, teams, sizeof(teams));
	int repair[r];
	for(int i =0;i<r;i++){
		cin >> repair[i];
		c[repair[i]-1] = 1;	
	}
	for(int i = 0;i<r;i++){
		int u = --repair[i];
		if(teams[u] == 1) teams[u]  =0;
		else if(u-1 >= 0 && teams[u-1] == 1 && !c[u-1]) teams[u-1] = 0;
		else if(u+1 < n && teams[u+1] == 1 && !c[u+1]) teams[u+1] = 0;
	}
	int ans =0;
	for(int i =0;i<n;i++){
		ans += teams[i];
	}
	cout << ans << '\n';

}
