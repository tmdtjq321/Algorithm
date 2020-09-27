#include <stdio.h>
#include <string.h>

int result[1000];

int main() {
	char input[20];
	char input2[20];
	int num[20];
	int num2[20];
	printf("숫자1 : ");
	scanf("%s", input);
	printf("숫자2 : ");
	scanf("%s", input2);
	for (int i = 0; i < strlen(input); i++) { num[i] = input[i] - '0'; }	// 정수로 변환 
	for (int i = 0; i < strlen(input2); i++) { num2[i] = input2[i] - '0'; }
	int cnt = 0, t = 0;
	for (int i = strlen(input2)-1; i >= 0; i--, cnt++) {
		for (int j = strlen(input)-1; j >= 0; j--) {
			result[999-t-cnt] += num2[i] * num[j];
			t++;
		}
		t = 0;
	}

	for (int i = 999; i >= 0; i--) {
		if (result[i] >= 10) {
			result[i - 1] = result[i - 1] + result[i] / 10;
			result[i] = result[i] % 10;
		}
	}

	int start_num = 0;
	for (int i = 0; i < 1000; i++) {
		if (result[i] != 0) {
			start_num = i;
			break;
		}
	}

	for (int i = start_num; i < 1000; i++) {
		printf("%d", result[i]);
	}

}
