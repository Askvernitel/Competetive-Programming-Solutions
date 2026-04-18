#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s1, s2;

	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();

	char t1 = s1[n-1];
	char t2 = s2[m-1];

	if(t1 < t2){ 
		cout << ">\n";
	}else if(t1 > t2){ 
		cout << "<\n";
	}else if(t1 == t2){ 
		if(n < m){ 
			if(t1 == 'S') cout << ">\n";
			else cout << "<\n";
		}else if(n > m){ 
			if(t1 == 'S') cout << "<\n";
			else cout << ">\n";
		}else{ 
			cout << "=\n";
		}
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
