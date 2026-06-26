#include <bits/stdc++.h>


using namespace std;


int get_first_unique_letter_index(string input){ 
        unordered_map<char, int> h;

        for(char c: input){
                h[c]++;
        }

        for(int i =0;i<input.size();i++){
                if(h[input[i]] == 1){
                        return i;
                }
        }

        return -1;

}

int main(){
        string input; 
        cin >> input;
        

        int idx = get_first_unique_letter_index(input);

        cout << idx << endl;
}
