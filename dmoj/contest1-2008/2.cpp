#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	
	string s1 = "ABC", s2 ="BABC", s3 = "CCAABB";

	string s;
	cin >> s;

	int scores[3]={0,0,0};
	string names[3] = {"Adrian", "Bruno", "Goran"};
	for(int i =0;i<n;i++){
		if(s1[i%3] == s[i]){
			scores[0]++;
		}if(s2[i%4] == s[i]){
			scores[1]++;
		}if(s3[i%6] == s[i]){
			scores[2]++;
		}
	}
	int mx = max({scores[0], scores[1], scores[2]});
	cout << mx << '\n';

	for(int i =0;i<3;i++){
		if(mx == scores[i]){
			cout << names[i] << '\n';
		}
	}

}
