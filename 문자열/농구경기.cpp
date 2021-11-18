#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string> 
using namespace std;
int N;
int num[27];
int main() {
	ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
	string str;
    for (int i = 0; i < N; i++){
    	cin >> str;
    	num[str[0]-'a']++;
	}
	bool isit = false;
	for (int i = 0; i < 26; i++){
    	if (num[i] >= 5){
    		isit = true;
    		char c = i + 'a';
    		cout << c;
		}
	}	
	if (!isit){
		cout << "PREDAJA";
	}
    return 0;
}
