#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int num = 0;
	int num_even = 0; //¦��
	int num_odd = 0; //Ȧ��
	scanf_s("%d", &num);

	for (int i = 0; i <= num; i++) {
		if (i % 2 == 0) {
			num_even += i;
			printf("¦������ �� : %d\n", num_even);
		}
		else {
			num_odd += i;
			printf("Ȧ������ �� : %d\n", num_odd);
		}
	}

	printf("-----------------------------------\n");
	printf("¦������ �� : %d\n", num_even);
	printf("Ȧ������ �� : %d\n", num_odd);
	printf("Ȧ���� ¦���� �� : %d", num_even + num_odd);

	system("pause");
	return 0;
}