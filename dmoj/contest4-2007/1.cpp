#include <bits/stdc++.h>

using namespace std;
int const N=1003;
int arr[N];
void t(int num){

	if(num == 0){
		cout << "none" << '\n';
	}else if(num == 1){
		cout << "one" << '\n';
	}else{
		cout << "both" << '\n';
	}
}
int main(){
	int a, b, c, d;
	int p, m, g;

	cin >> a >> b >> c >> d;

	cin >> p >> m >> g;
	for(int i =1;i<N;i++){
		for(int j = i;j<i+a;j++){
			arr[j]++;
		}
		i=i+a+b;
		
	}
	for(int i =1;i<N;i++){
		for(int j = i;j<i+c;j++){
			arr[j]++;
		}
		i=i+c+d;
	}
	t(arr[p]);
	t(arr[m]);
	t(arr[g]);


}
