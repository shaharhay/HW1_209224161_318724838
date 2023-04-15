#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

q1() {
	int x = 0, cnt = 0;
	double y = 0, sum = 0;
	while (x != -1) {
		printf("Please enter grade:\n");
		scanf("%d", &x);
		if (x == -1) {
			break;
		}
		if ((x < 0) || (x > 100)) {
			printf("Invalid grade. ");
			continue;
		}
		cnt += 1;
		y = 1.1 * x;
		if (y - (int)y != 0) {
			y = (int)y + 1;
		}
		if (((int)y + 2) % 10 == 0) {
			y += 3;
		}
		y += 2;
		if ((int)y > 100) {
			y = 100;
		}
		sum += y;
		printf("Final grade: %d\n", (int)y);
		printf("Current average after factor: %.2f\n", (sum/cnt));
	}
	return 0;
}

q2() {
	int a = 0, length = 0;
	printf("Please select message to print:\nEnter 1 for \"Hurray!\"\nEnter 2 for \"You Win!!\"\nEnter 3 for \"How do i get out of this rhombus?\"\n");		
	scanf("%d", &a);
	while ((a < 1) || (a > 3)) {
		printf("Invalid message index, please enter an index between 1 and 3:\n");
		scanf("%d", &a);
	}
	char c = 'a';
	printf("Please enter your favorite character:\n");
	scanf(" %c", &c);
	printf("Please enter edge length:\n");
	scanf("%d", &length);
	switch (a) {
	case 1: while (length < 6) {
		printf("Invalid edge length, please enter a larger number:\n");
		scanf("%d", &length);
	}break;
	case 2: while (length < 7) {
		printf("Invalid edge length, please enter a larger number:\n");
		scanf("%d", &length);
	}break;
	case 3: while (length < 19) {
		printf("Invalid edge length, please enter a larger number:\n");
		scanf("%d", &length);
	}break;
	}
	int cnt_1 = 1;
	while (cnt_1 < ((2 * length) - 1)) {
		int cnt_2 = 1;
		if (cnt_1 == 1) {
			while (cnt_2 <= ((2 * length) - 1)) {
				if (cnt_2 != length) {
					printf(" ");
				}
				else {
					printf("%c", c);
				}
				cnt_2 += 1;
			}
		}
		cnt_1 += 1
	}
}

int main() {
//	q1();
	q2();
	return 0;
}