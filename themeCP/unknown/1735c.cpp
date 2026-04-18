#include <bits/stdc++.h>
using namespace std;
char prv[26];	
char nxt[26];

int used[26];
int n, m;
int k = 0;
char findc(char ch){
	if(prv[ch-'a'] != '#' ){ 
		return prv[ch-'a'];
	}
	if(ch == 'a' && k == 0){ 
		k++;
		nxt[1] = 'a';
		prv[0] = 'b';
		used[1]=1;
		used[0]=1;
		return prv[ch-'a'];
	}
	k++;
	for(int i=0;i<26;i++){
		if((used[i] && k !=m) || ch == 'a'+i) continue;
		if((nxt[i] == '#' && ch > 'a'+i) || ((ch < ('a'+i)) && (prv[ch-'a'] != ('a'+i)) && (nxt[ch-'a'] != ('a'+i)))){ 
			prv[ch-'a'] = 'a' + i;
			nxt[i]=ch;
			used[i] = 1;
			break;
		}
	}
	return prv[ch-'a'];
}
void solve(){
	cin >> n;
	string s;
	cin >> s;

	memset(prv,'#',sizeof(prv));
	memset(nxt,'#',sizeof(nxt));
	memset(used,0,sizeof(used));
	set<char> sc;
	for(int i=0;i<n;i++){
		sc.insert(s[i]);
	}
	m=(int)sc.size();
	for(int i=0;i<n;i++){
		cout << ((findc(s[i]) == '#')?'a': findc(s[i]));
	}
	cout << '\n';
	k=0;
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
