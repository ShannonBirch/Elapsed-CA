//Shannon Birch X00110806 Labsheet 4

#include<iostream>
using namespace std;

void averageN(double numbers[],int size);
void InputAndAverage();
bool fillArray(char (&chars)[100], int &size);
void outputInReverse(char chars[100], int size);

void main(){
	char chars[100];
	int size=0;
	fillArray(chars, size);
	cout << "\n\n Reversed?\n\n\n";
	outputInReverse(chars, size);
	system("pause");
}

void averageN(double numbers[], int size){

	double sum = 0;
	double average = 0;

	for (int i = 0; i < size; i++){
		sum += numbers[i];

	}
	average = sum / size;

	cout << "\n\n\nThe average of the numbers is " << average;
}


void InputAndAverage(){
	double numbers[5];

	cout << "Enter five numbers seperated by a space:\n";
	cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3] >> numbers[4];

	averageN(numbers, 5);
}

bool fillArray(char (&chars)[100], int &size){
	size = 0;
	cout << "Enter character followed by enter. Enter a full stop to signify you're done\n";
	cin >> chars[size];
	size++;

	while ((size < 100) && (chars[(size - 1)] != '.')){
		cin >> chars[size];
		size++;
	}
	if (size == 100){
		return true;
	}
	else{
		return false;
	}
}
void outputInReverse(char chars[], int size){
	for (int i = (size - 2); i >= 0; i--){
		cout << chars[i] <<"\n";
	}
}


