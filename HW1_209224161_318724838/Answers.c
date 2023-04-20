#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

q1() {
	int grade = 0, grades_num = 0;
	double final_grade = 0, sum = 0;
	while (grade != -1) {
		printf("Please enter grade:\n");
		scanf("%d", &grade);
		if (grade == -1) { //stop condition
			break;
		}
		if ((grade < 0) || (grade > 100)) {
			printf("Invalid grade. ");
			continue;
		}
		grades_num += 1;
		final_grade = 1.1 * grade;// add 10% to the grade
		if (final_grade - (int)final_grade != 0) { // round up the final grade if its not an integer
			final_grade = (int)final_grade + 1;
		}
		final_grade += 2; // adds 2 point to the final grade
		if (((int)final_grade) % 10 == 0) { // if the first digit is 0 we add 1 more to the final grade
			final_grade += 1;
		}
		if ((int)final_grade > 100) { 
			final_grade = 100;
		}
		sum += final_grade;
		printf("Final grade: %d\n", (int)final_grade);
		printf("Current average after factor: %.2f\n", (sum/grades_num));
	}
	return 0;
}

q2() {
	int message = 0, length = 0;
	printf("Please select message to print:\nEnter 1 for \"Hurray!\"\nEnter 2 for \"You Win!!\"\nEnter 3 for \"How do i get out of this rhombus?\"\n");		
	scanf("%d", &message);
	while ((message < 1) || (message > 3)) {
		printf("Invalid message index, please enter an index between 1 and 3:\n");
		scanf("%d", &message);
	}
	char symbol = 'a';
	printf("Please enter your favorite character:\n");
	scanf(" %c", &symbol);
	printf("Please enter edge length:\n");
	scanf("%d", &length);
	int message_length = 0;
	switch (message) { // in each message we check if the message length fit in the shape
	case 1:
		message_length = 7; 
		while (length < 6) {
			printf("Invalid edge length, please enter a larger number:\n");
			scanf("%d", &length);
		}
		  break;
	case 2:
		message_length = 9;
		while (length < 7) {
			printf("Invalid edge length, please enter a larger number:\n");
			scanf("%d", &length);
		}
		  break;
	case 3: 
		message_length = 33;
		while (length < 19) {
			printf("Invalid edge length, please enter a larger number:\n");
			scanf("%d", &length);
		}
		  break;
	}
	int rows = 1, row_idx = 1, spacer = 1, space_increment = 1;
	while (rows < (2 * length)) {
		if ((rows == 1) || (rows == (2 * length - 1))) { // takes care of the first and last row
			row_idx = 1;
			while (row_idx < (2 * length)) {
				if (row_idx == length) {
					printf("%c", symbol);
				}
				else if (row_idx == ((2 * length) - 1)) {
					printf(" \n");
				}
				else {
					printf(" ");
				}
				row_idx += 1;
			}
			rows += 1;
		}
		else if (rows == length) { // middle row
			row_idx = 1;
			while (row_idx < (2 * length)) {
				if (row_idx == 1) {
					printf("%c", symbol);
				}
				else if (row_idx == ((2 * length) - 1)) {
					printf("%c\n", symbol);
				}
				else if (row_idx == (length - (message_length / 2))) {
					switch (message) {
					case 1: printf("Hurray!"); break;
					case 2: printf("You Win!!"); break;
					case 3: printf("How do i get out of this rhombus?"); break;
					}
					row_idx += message_length;
					continue;
				}
				else {
					printf(" ");
				}
				row_idx += 1;
			}
			rows += 1;
			space_increment = -1; // we change the space increment for the rows after the middle
			spacer += space_increment;
		}
		else { // handle the rows that are inbetween the first and last rows not including the middle row
			row_idx = 1;
			while (row_idx < (2 * length)) {
				if ((row_idx == (length - spacer)) || (row_idx == (length + spacer))) {
					printf("%c", symbol);
				}
				else if (row_idx == ((2 * length) - 1)){
					printf(" \n");
				}
				else {
					printf(" ");
				}
				row_idx += 1;
			}
			spacer += space_increment; //space increment
			rows += 1;
		}
		
	}
}

int main() {
	q1();
	q2();
	return 0;
}