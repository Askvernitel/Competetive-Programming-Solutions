#include <bits/stdc++.h>

using namespace std;
void prt(int a,int b,int c, string s){
	cout << a << s << b << "=" << b; 
}
int main(){
	double a, b, c;

	cin >> a >> b >> c;

	for(int i = 0;i<2;i++){	
		if(a + b == c){
			prt(a,b,c,"+");
			break;
		}else if(a - b == c){
			prt(a,b,c,"-");
			break;
		}else if(a * b == c){
			prt(a,b,c,"*");
			break;
		}else if(a / b == c){
			prt(a,b,c,"/");
			break;
		}
	}

}
