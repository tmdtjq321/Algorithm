#include <stdio.h>
int BCD(int a, int b){
	if (b == 0){
		return a;
	}
	else{
		BCD(b,a % b);
	}
}

int main(){
	int a, b;
	int max_div;
	int min_mult;
	double sum;
	
	printf("PARTITION INTO FRACTIONS\n");
	printf("NUMERATOR DEENOMINATOR? ");
	scanf("%d %d", &a, &b);
	sum = (double)a / (double)b;
	int cal; // 연산 후 분자 값 분모는 최소 공배수 min_mult 
	printf("FRACTION %d/%d = ", a, b);
	for (int i = 2; i < 100000; i++){
		double Egypt = 1.0 / (double)i;
		if (sum > Egypt){
			printf("1/%d + ",i);
			max_div = BCD(b,i);
			min_mult = b * i / max_div;
			cal = a * (i / max_div) - (b / max_div);
			a = cal;
			b = min_mult;
			if (cal == 1){
				printf("%d/%d", cal, min_mult);
				break;
			}
			else{
				sum = (double)cal / (double)min_mult;
			}
		}
		
	} 
	return 0;
}

