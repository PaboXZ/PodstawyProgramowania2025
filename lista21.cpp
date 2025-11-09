/*
* Autor: Pawe³ Koz³owski
* Grupa: PN/P 13.15
* Temat: Lista nr 2
* Data: 07 listopada 2025 r.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<iostream>
#include<time.h>
/*
 * Helper Functions
 */
char intToASCI(int number) {
	if(number < 0 || number > 42) {
		return '0';
	}
	if(number < 10)
		return '0' + number;
	else
	{
		number -= 10;
		return 'A' + number;
	}
}
int ASCItoNum(char character) {
	if (character >= 48 && character < 58)
		return character - '0';
	if (character > 64 && character < 91)
		return character - 'A' + 10;
	return 0;
}
/*
 * Main Functions
 */
int tabliczka() {
	/*
	 * Program rysuje tabliczkê mno¿enia dla
	 * zakresu podanego na standardowym wejœciu.
	 */
	int rows, columns;
	
	columnsInput:
	
	printf("WprowadŸ iloœæ kolumn:\n\n");
	scanf("%d", &columns);
	if(columns > 15) {
		printf("\033cNieprawid³owa iloœæ kolumn. Max: 15\n\n");
		goto columnsInput;
	}
	
	rowsInput:
	printf("WprowadŸ iloœæ wierszy:\n\n");
	scanf("%d", &rows);
	if(rows > 20) {
		printf("\033cNieprawid³owa iloœæ wierszy. Max: 20\n\n");
		goto rowsInput;
	}
	//Header
	printf("\033cRysujê tabliczkê mno¿enia %d x %d\n\n", columns, rows);
	printf("%*c|", 4, ' ');
	for(int i = 0; i < columns;i++) {
		printf("%4d", i + 1);
	}
	printf("\n==");
	//Licznik zaczyna siê od -1 aby nie obliczaæ columns + 1 przy ka¿dej iteracji pêtli
	for(int i = -1; i < columns;i++) {
		printf("====");
	}
	//Body
	printf("\n");
	for(int i = 1; i < rows + 1; i++) {
		printf("%3d | ", i);
		for(int j = 1; j < columns + 1; j++) {
			printf("%4d", j*i);
		}
		printf("\n");
	}
	
	printf("\n\nWprowadŸ dowolny znak aby zakoñczyæ\n\n");
	fflush(stdin);
	getchar();
	return 0;
}
int sumDigits() {
	/*
	 * Program liczy sumê cyfr liczby w wybranym systemie numerycznym
  	 * System oraz liczba wprowadzane z standardowego wejœcia
  	 */
    
	long int number;
	int system;
	char changedNumber[32];
	int counter = -1;
	int remainder;
	bool negativeFlag = false;
	char newNumber;
	int digitsSum;
	
	startDigits:
	counter = -1;
	digitsSum = 0;
	printf("\033cWprowadŸ system z zakresu 2-42:\n");
	scanf("%d", &system);
	if(system < 2 || system > 42) {
		printf("\033cSystem spoza zakresu!\n");
		goto startDigits;
	}
	
	printf("WprowadŸ liczbê:\n");
	scanf("%ld", &number);
	
	if(number < 0){
		number = number * -1; 
		negativeFlag = true;
	}
	while(number > 0) {
		remainder = number % system;
		number = number/system;
		digitsSum += remainder;
		changedNumber[31 - ++counter] = intToASCI(remainder);	
	}
	if(negativeFlag)
		changedNumber[31 - ++counter] = '-';
	//Drukowanie liczby
	printf("Wprowadzona liczba w systemie %d\n", system);
	for(int i = counter; i >= 0; i--) {
		printf("%c", changedNumber[31 - i]);
	}
	printf("\nSuma cyfr zapisana w zapisie dziesiêtnym:\n%d\n", digitsSum);
	
	printf("\nNastêpna liczba? Y/*");
	fflush(stdin);
	newNumber = getchar();
	if(newNumber == 'Y' or newNumber == 'y')
		goto startDigits;
	
	return 0;
}
int approx() {
	double sumPI, sumE, precision, nextNumber, precisionHolder;
	unsigned long int iterator;
	int zerosNumber;
	char newNumber;
	
	startApprox:
	nextNumber = 0;
	sumPI = 0;
	iterator = 1;
	zerosNumber = 0; 
	
	printf("WprowadŸ ¿¹dan¹ dok³adnoœæ z przedzia³u (0.1 , 0)\n");
	scanf("%lf", &precision);
	if(precision > 0.1 || precision < 0) {
		printf("Wartoœæ spoza zakresu!\n");
		goto startApprox;
	}
	precisionHolder = precision;
	while(precisionHolder < 1) {
		zerosNumber++;
		precisionHolder *= 10;
	}
	
	do {
		nextNumber = 4.0 / (iterator * 2 - 1);
		nextNumber = iterator % 2 == 1 ? nextNumber : -nextNumber;
		sumPI += nextNumber;
		iterator++;
		if(iterator %10000000 == 0){
			printf("\b\\");
			if(iterator %20000000 == 0)
			{
				printf("\b/");
				if(iterator >  4200000000)
					break;
			}
		}
		
	}
	while(fabs(nextNumber) > precision);
	
	if(iterator > 10000000)
		printf("\b");
	
	nextNumber = 1;
	iterator = 1;
	sumE = 1;
	do {
		nextNumber = nextNumber / iterator;
		sumE += nextNumber;
		iterator++;
		if(iterator %10000000 == 0){
			printf("\b\\");
			if(iterator %20000000 == 0)
			{
				printf("\b/");
				if(iterator >  4200000000)
				break;
			}
		}
	} while (nextNumber > precision);
	
	
	if(iterator > 10000000)
		printf("\b");
	
	printf("PI: %.*lf\nE: %.*lf\n",zerosNumber, sumPI, zerosNumber, sumE);
	
	printf("\nPonowiæ? Y/*");
	fflush(stdin);
	newNumber = getchar();
	if(newNumber == 'Y' or newNumber == 'y')
		goto startApprox;
	
	return 0;
}
int randomAVG() {
	int min, max, newNumber;
	unsigned int number;
	unsigned int negativeCount, positiveCount;
	int valueHolder;
	long int negativeSum, positiveSum;
	
	startRandomAVG:
	negativeCount = 0;
	positiveCount = 0;
	negativeSum = 0.0;
	positiveSum = 0.0;
	
	printf("WprowadŸ przedzia³ liczb losowych (a b):\n");
	scanf("%d %d", &min, &max);
	printf("WprowadŸ iloœæ liczb:\n");
	scanf("%ud", &number);
	srand(time(NULL));
	
	for(unsigned int i = number; i > 0; i--) {
		valueHolder = min + rand() % (max - min + 1);
		if(valueHolder < 0) {
			negativeCount++;
			negativeSum += valueHolder;
		}
		else {
			positiveCount++;
			positiveSum += valueHolder;
		}
	}
	printf("Liczby wiêksze od zera: %d\nŒrednia liczb wiêkszych od zera: %.1f\nLiczby mniejsze od zera: %d\nŒrednia liczb mniejszych od zera: %.1f\n", positiveCount, (float) positiveSum / (positiveCount == 0 ? 1 : positiveCount), negativeCount, (float) negativeSum / (negativeCount == 0 ? 1 : negativeCount));
	
	printf("\nPonowiæ? Y/*");
	fflush(stdin);
	newNumber = getchar();
	if(newNumber == 'Y' or newNumber == 'y')
		goto startRandomAVG;
	
	return 0;
}
int szachownica() {
	int fieldX, fieldY;
	int sideA, sideB;
	
	char colorA[] = "\033[41m";;
	char colorB[] = "\033[42m";
	bool currColor;
	bool switchFlag;
	
	int helperProduct;
	int helperBottomLength;
	char newBoard;
	
	szachownicaStart:
	printf("Podaj wymiar pola w formacie x y (maks. 10):\n");
	fflush(stdin);
	scanf("%d %d", &fieldX, &fieldY);
	fieldX = abs(fieldX);
	fieldY = abs(fieldY);
	if(fieldX > 10 || fieldY > 10) {
		   printf("\033cPrzekroczono zakres\n")	;
		   goto szachownicaStart;
	}
	
	szachownicaBok:
	printf("Podaj wymiar planszy w formacie x y (maks. 10)\n");
	fflush(stdin);
	scanf("%d %d", &sideA, &sideB);
	sideA = abs(sideA);
	sideB = abs(sideB);
	if(sideA > 10 || sideB > 10) {
		printf("\033cPrzekroczono zakres\n")	;
		goto szachownicaBok;
	}
	
	currColor = true;
	switchFlag = false;
	helperProduct = fieldX*sideA*fieldY*sideB;
	helperBottomLength = fieldX * sideA;
	
	for(int i = 0; i < helperProduct; i++) {
		if(i % fieldX == 0 && i % helperBottomLength != 0) {
			switchFlag = true;
			goto printColors;
		}
		if(i % helperBottomLength == 0){
			printf("\n");
			switchFlag = true;
			currColor = !((i / helperBottomLength / fieldY) % 2);
		}                        
		printColors:
		if(switchFlag){
			currColor = !currColor;
			printf("%s", currColor ? colorA : colorB);
		}
		printf("#");
		switchFlag = false;
	}

	printf("\033[0m\nNowa szachownica? Y/*");
	fflush(stdin);
	newBoard = getchar();
	if(newBoard == 'Y' or newBoard == 'y'){
		printf("\033c");	
		goto szachownicaStart;
	}
	
	return 0;
}
int main() {
	setlocale(LC_CTYPE, "Polish");
	printf("Autor: Pawe³ Koz³owski\nGrupa: PN/P 13.15\nData: 07 listopada 2025 r.\n==================================");
	
	start:
	printf("\033c\n\nWybierz program:\n\n1: Tabliczka Mno¿enia\n2: Suma Cyfr\n3: Przybli¿enie pi/e\n4: Œrednia RAND()\n5: Szachownica\ne: Exit\n\n");
	int tempInput;
	do {
		tempInput = getchar();
		switch(tempInput) {
			case 49:
				printf("\033cWybrano Program \"Tabliczka Mno¿enia\"\n");
				tabliczka();
				goto start;
			case 50:
				printf("\033cWybrano Program \"Suma Cyfr\"\n");
				sumDigits();
				goto start;
			case 51:
				printf("\033cWybrano Program \"Przybli¿enie pi/e\"\n");
				approx();
				goto start;
			case 52:
				printf("\033cWybrano Program \"Œrednia RAND()\n");
				randomAVG();
				goto start;
			case 53:
				printf("\033cWybrano Program \"Szachownica\"\n");
				szachownica();
				goto start;
		}
	} while (tempInput != 'e');
	
	return 0;
}
