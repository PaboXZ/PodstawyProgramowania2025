/*
* Autor: Pawe³ Koz³owski
* Grupa: PN/P 13.15
* Temat: Lista nr 2
* Data: 07 listopada 2025 r.
*/

#include <stdio.h>
#include<conio.h>
#include<iostream>
int main() {
	setlocale(LC_CTYPE, "Polish");
	printf("Autor: Pawe³ Koz³owski\nGrupa: PN/P 13.15\nData: 07 listopada 2025 r.\n==================================");
	
	start:
	printf("\n\nWybierz program:\n\n1: Tabliczka Mno¿enia\n2: Suma Cyfr\n3: Przybli¿enie pi/e\n4: Œrednia RAND()\n5: Szachownica\ne: Exit\n\n");
	int tempInput;
	do {
		tempInput = getch();
		switch(tempInput) {
			case 49:
				printf("Wybrano Program \"Tabliczka Mno¿enia\"\n");
				goto start;
			case 50:
				printf("Wybrano Program \"Suma Cyfr\"\n");
				goto start;
			case 51:
				printf("Wybrano Program \"Przybli¿enie pi/e\"\n");
				goto start;
			case 52:
				printf("Wybrano Program \"Œrednia RAND()\"\n");
				goto start;
			case 53:
				printf("Wybrano Program \"Szachownica\"\n");
				goto start;
		}
	} while (tempInput != 'e');
	
	return 0;
}