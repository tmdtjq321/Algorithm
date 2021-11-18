#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
 
int N, M, flag = 1, l, r, bs, cs;
char a[27], input[300002];

vector<char> seq;
vector<char> re_seq;

bool chk(){
	if (flag){
		if (bs < M){
			return false;
		}
		for (int i = 0; i < M; i++){
			if (a[i] != seq[bs - M + i]){
				return false;
			}
		}
		for (int i = 0; i < M; i++){	// 삭제 
			seq.pop_back();
		}
		bs -= M;
	}
	if (!flag){
		if (cs < M){
			return false;
		}
		for (int i = 0; i < M; i++){
			if (a[i] != re_seq[cs - 1 - i]){
				return false;
			}
		}
		for (int i = 0; i < M; i++){	// 삭제 
			re_seq.pop_back();
		}
		cs -= M;
	}
	return true;
}

 
int main() {
    scanf("%s", &a);
    scanf("%s", &input);
    N = strlen(input), M = strlen(a);
    l = 0, r = N - 1;
    while (l<=r) {
        if (flag) {
            seq.push_back(input[l]);
            bs++;
            if (input[l] == a[M - 1] && chk()) {
                flag = 1 - flag;
            }
            l++;
        }
        else {
            re_seq.push_back(input[r]);
            cs++;
            if (input[r] == a[0] && chk()) {
                flag = 1 - flag;
            }
            r--;
        }
    }
    flag = 1;
    if (cs) {
        while(cs--) {
            seq.push_back(re_seq[cs]);
            bs++;
            if (seq[bs - 1] == a[M - 1]) 
                chk();
        }
    }
    for (int i = 0; i < bs; i++) printf("%c", seq[i]);
    return 0;
}
