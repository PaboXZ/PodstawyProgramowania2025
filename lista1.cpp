/*
* Autor: Pawe≥ Koz≥owski
* Grupa: PN/P 13.15
* Temat:
* Data: 20 paüdziernika 2025 r.
*/

#include<stdio.h>
#include<iostream>
#include<math.h>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

void zadanie1() {
	cout << "Z1. Wprowadü dane: a b c\n";
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	
	if(a == 0){
		cout << "a = 0!" << endl;
		return;
	}
	float delta = b * b - (4 * a * c);
	if(delta < 0){
		cout << "Brak rozwiπzaÒ, wyrÛønik ujemny" << delta << endl;
		return;
	}
	if(delta == 0){
		float x1 = -delta/2*a;
		cout << "Istnieje jedno rozwiπzanie x = " << x1 << endl;
		return;
	}
	
	float x1 = (-b - sqrt(delta)) / 2 * a;
	float x2 = (-b + sqrt(delta)) / 2 * a;
 	cout << "Rozwiπzania rÛwnania kwadratowego: " << x1 << " " << x2 << "\n";
 	return;
}

void zadanie2() {
	int day, month, year;
	printf("Z2. Wprowadü dane: day month year\n");
	scanf("%d %d %d", &day, &month, &year);
	bool yearFlag = true, failFlag = false;
	if(year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)){
		yearFlag = false;
	}
	if(month < 1 || month > 12 || day < 1){
		failFlag = true;
	}
	if(month == 2){
		if(yearFlag && day > 29)
			failFlag = true;
		if(!yearFlag && day > 28)
			failFlag = true;
	}
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
		if(day > 31)
			failFlag = true;
	}
	else{
		if(day > 30)
			failFlag = true;
	}
	printf("%d.%d.%d\n", day, month, year);
	if(failFlag)
		printf("Data niepoprawna\n");
	else
		printf("Data poprawna\n");
	
	return;
}
void zadanie3(){
	cout << "Z3. Wprowadü dane: a b c\n";
	unsigned int a, b, c;
	scanf("%u %u %u", &a, &b, &c);
	int max = a, x1 = b, x2 = c;
	if(max < b){
		max = b;
		x1 = a;
	}
	if(max < c){
		x2 = max;
		max = c;
	}
	if(x2 + x1 <= max){
		cout << "Nie moøna utworzyÊ trÛjkπta\n";
	}
	else {
		cout << "Moøna utworzyÊ trÛjkπt\n";
	}
	return;
}
void zadanie4() {
	cout << "Z4. Wprowadü dane: min max rows \n";
	float rMax, rMin;
	unsigned int rows;
	scanf("%f %f %d", &rMin, &rMax, &rows);
	if(rMin<0){
		rMin = -rMin;
	}
	if(rMax<0){
		rMax = -rMax;
	}
	if(rMax < rMin){
		int placeholder = rMax;
		rMax = rMin;
		rMin = placeholder;
	}
	float diff = (rMax - rMin) / (rows - 1);
	float r;
	printf("=========================================\n");
	printf("| Lp | promien | obwÛd ko≥a | pole ko≥a |\n");
	printf("=========================================\n");
	for(int i = 1; i <= rows; i++){
		r = rMin + (i-1)*diff;
		printf("| %2d | %7.2f | %10.2f | %9.2f |\n", i, r, 2 * M_PI * r, r * r * M_PI);
	}
	printf("=========================================\n");
	return;
}
int main(int argc, char** argv)
{
	
	setlocale(LC_CTYPE, "Polish");
	cout << "Autor: Pawe≥ Koz≥owski 208725, PN/P 13.15\n";
	
	zadanie1();
	zadanie2();
	zadanie3();
	zadanie4();
	return 0;
}

