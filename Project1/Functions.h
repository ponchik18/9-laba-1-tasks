#include"library.h"
FILE* IN;
FILE* OUT;
void print_in_file();
int count_character();
void trigger() {
	if (IN == NULL) {
		cout << "Файл не может быть открыт" << endl;
		exit(0);
	}
}
void trigger2() {
	if (OUT == NULL) {
		cout << "Файл не может быть открыт" << endl;
		exit(0);
	}
}
void vvod() {
	char c;
	int flag = 0;
	cout << "Введите количество чисел" << endl;
	cin >> flag;
	int i = 0;
	while (i < flag) {
		print_in_file();
		i++;
		if (i != flag)
			putc(' ', IN);
	}
	fclose(IN);
}
char* print_number() {
	char num_string[4];
	int num = 0;
	int flag = 0;
	num = 10+rand()%90;
	flag = 0 + rand()%2;
	if (flag == 1)
		num *= -1;
	_itoa(num, num_string, 10);
	return num_string;
}
void print_in_file() {
	char num_string[4];
	int i = 0;
	strcpy(num_string, print_number());
	while (num_string[i]) {
		putc(num_string[i++], IN);
	}
	return;
}

int count_character() {
	rewind(IN);
	int c, count = 0;
	while ((c = getc(IN) != EOF)) {
		count++;
	}


	rewind(IN);
	
	return count;
}
void typeintOUT() {
	int count = count_character();
	char* str = new char[count + 1];
	fgets(str, count, IN);

	int K=0;
	cout << "Введисте число К" << endl;
	cin >> K;
	char* number = strtok(str, " ");
	int c;
	while (number != NULL) {
		c = atoi(number);
		if (c % K == 0) {
			fprintf(OUT, "%s", number);
			number = strtok(NULL, " ");
			if(number!=NULL)
				putc(' ', OUT);
			
		}
		else 
			number = strtok(NULL, " ");
		
	}

	fclose(OUT);
	fclose(IN);
}
