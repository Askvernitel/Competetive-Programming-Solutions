#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    char a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    int minv = 0, maxv = 0;

    int start = 0, end = 0;
    int am = 0;
    char prev='#'; 
    for(int i=0;i<n;i++){
        if(a[i] == 'F'){ 
            am++;
            continue;
        } 

        if(prev == '#') { 
            start += am;
            maxv+=am;
            prev = a[i];
            am=0;
            continue;
        }

        if(prev == a[i]){ 

            if(!(am%2)){ 
                minv++;
            }
            
            maxv+=am+1;
        }else{ 

            if((am%2)){ 
                minv++;
            }
            maxv+=am;
        }
        prev = a[i];
        am=0;
    }
    int j = n-1;
    while(j>=0 && a[j] == 'F'){
        end++;
        j--;
    }
    if(end == n){ 
        minv = 0;
        maxv = n-1;
    }else{ 
        maxv+=end;
    }

    if(start == 0 && end ==0){ 
        cout << ((maxv-minv+1)/2 + 1) << '\n';
        for(int i = minv;i<=maxv;i+=2){ 
            cout << i << '\n';
        }
    }else{ 
        cout << maxv-minv + 1 << '\n';
        for(int i = minv;i<=maxv;i++){
            cout << i << '\n';
        }
    }
}
