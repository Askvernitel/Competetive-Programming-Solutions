#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;

	int n = s.size();
	int ans = 0;
	int p = 0;
	int u = 0;
	int v = 0, t = 0;
	int maxv = 0;
	int minv = 1;
	int c = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == '('){
			c=0;
			v=0;
			p++;
			maxv=max(p,maxv);
		}
		else {
			
			if(p == 0){
				u++;
				v++;
				maxv=max(v,maxv);
			}else{
				c++;
				maxv=max(p,maxv);
				minv=max(c,minv);
				p--;	
			}
		}
	}
	u=0; v=0; p=0; c=0;
	for(int i = n-1;i>=0;i--){
		if(s[i] == ')'){
			v=0;
			c=0;
			p++;
			maxv=max(p,maxv);
		}
		else {
			
			if(p == 0){
				u++;
				v++;
				maxv=max(v,maxv);
			}else {
				c++;
				maxv=max(p,maxv);
				minv=max(c,minv);
				p--;	
			}
		}
	}
	cout << minv << ' ' << max(1,maxv) << '\n';
}
