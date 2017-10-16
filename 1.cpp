#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int num = 0;
	int num_even = 0; //Â¦¼ö
	int num_odd = 0; //È¦¼ö
	scanf_s("%d", &num);

	for (int i = 0; i <= num; i++) {
		if (i % 2 == 0) {
			num_even += i;
			printf("Â¦¼öµéÀÇ ÇÕ : %d\n", num_even);
		}
		else {
			num_odd += i;
			printf("È¦¼öµéÀÇ ÇÕ : %d\n", num_odd);
		}
	}

	printf("-----------------------------------\n");
	printf("Â¦¼öµéÀÇ ÇÕ : %d\n", num_even);
	printf("È¦¼öµéÀÇ ÇÕ : %d\n", num_odd);
	printf("È¦¼ö¿Í Â¦¼öÀÇ ÇÕ : %d", num_even + num_odd);

	system("pause");
	return 0;
}