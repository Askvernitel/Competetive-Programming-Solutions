#include <bits/stdc++.h>

using namespace std;

int n;
char nxt[28];
char prv[28];
void solve(){
	cin >> n;

	string s;

	cin >> s;
	set<char> sc;
	memset(nxt, '#', sizeof(nxt));
	memset(prv, '#', sizeof(prv));
	for(char ch:s) sc.insert(ch);
	int m = sc.size();
	int k = 1;
	for(int j =0;j<n;j++){
		char ch = s[j];
		if(prv[ch-'a'] != '#'){ 
//			cout << prv[ch-'a'];
			continue;
		}
		for(int i=0;i<26;i++){
			if(nxt[i] != '#') continue;
			int op = 0;
			bool found = 0;
			nxt[i] = ch;
			char ch1 = (char)('a'+i);
//			cout << ch-'a' << '\n';
			while(op<40){ 
				ch1 = nxt[(ch1-'a')];
				if(ch1 == '#') break;
				if(ch1 == ('a'+i)){found = 1; break;}
				op++;
			}
			if(found && k>=26){
				prv[ch-'a'] = 'a'+i;
				nxt[i] = ch;
				break;
			}
			if(found){ 
				nxt[i] = '#';
				continue;
			}
			prv[ch-'a']='a'+i;
			k++;
			break;
		}
//		cout << prv[ch-'a'];
	}

	for(int i = 0;i<n;i++){
		cout << prv[s[i]-'a'];
	}
	cout << endl;
}
int main(){ 
	int tc;
	cin >> tc;

	while(tc--) solve();

}
