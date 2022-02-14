#include"Functions.h"
int main() {
	srand(time(NULL));
	setlocale(0, "rus");
	IN = fopen("input.txt", "w");
	trigger();
	vvod();
	IN = fopen("input.txt", "r");
	trigger();
	OUT= fopen("output.txt", "w");
	trigger2();
	typeintOUT();
	return 0;
}


