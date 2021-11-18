#include <cstdio> 
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N;
string target, pattern;
vector<int> pi;
vector<int> res;
void kmp(){
	int j = 0;
	for (int i = 0; i < target.length(); i++){
		while (j > 0 && target[i] != pattern[j]){
			j = pi[j - 1];
		}
		if (target[i] == pattern[j]){
			if (j == pattern.length() - 1){
				res.push_back(i - pattern.length() + 2);
				j = pi[j];
			}
			else{
				j++;
			}
		}
	}
}

void getpi(){
	pi.resize(pattern.length());
	int j = 0;
	for (int i = 1; i < pattern.length(); i++){
		while (j > 0 && pattern[i] != pattern[j]){
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j]){
			pi[i] = ++j;
		}
	}
}

int main() { 
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	getline(cin,target);
	getline(cin,pattern);
	getpi();
	kmp();
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << "\n";
	}
    return 0;
}
