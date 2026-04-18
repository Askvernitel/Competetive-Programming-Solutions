#include <bits/stdc++.h>

using namespace std;
bool isVow(char ch){ 
	return ch =='a' || ch =='e' || ch =='i' || ch =='o' || ch == 'u';  
}
int main(){
	string words;
	getline(cin, words);
	int n = words.size();	
	string cur_word;
	for(int i =0;i<n;i++){
		if(words[i] ==' '){ 
			cout << cur_word << " ";
			cur_word = "";
			continue;
		}
		cur_word+=words[i];	
		if(isVow(words[i])){ 

			i+=2;
		}
	} 
	cout << cur_word;
	
	
}
