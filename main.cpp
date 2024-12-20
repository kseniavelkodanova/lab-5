#include <iostream>
using namespace std;
/*Описати функцію Sign (X) цілого типу, яка повертає для дійсного числа X 
наступні значення: -1, якщо X <0; 0, якщо X = 0; 1, якщо X> 0. За 
допомогою цієї функції знайти значення виразу Sign (A) + Sign (B) для 
даних дійсних чисел A і B.*/
void task_1(); // завдання 1 

int Sign(double X); // декларація функції(Proc16)

/* Дано тризначне число. Перевірити істинність висловлювання: «Цифри даного 
числа утворюють зростаючу або спадаючу послідовність» */
void task_2();// завдання 2 

bool in_number(int& pL); // введення з перевіркою Boolean22
bool out_number(int pr); // виведення резудьтатів Boolean22


/* Дано ціле число, більше 999. Використовуючи одну операцію ділення 
остачі і одну операцію взяття залишку від ділення, знайти цифру, 
відповідну розряду тисяч в записі цього числа. */
void task_3();// завдання 3

bool in_L(int& pL); // введення з перевіркою Integer18
int check_L(int pL); // підрахунок Integer18
void out_res(int pr); // виведення резудьтатів Integer18


int main() {
	int menu;
	cout << "Task1: 1\nTask2: 2\nTask3: 3" << endl;
	cout << "Task number:";
	cin >> menu;
	// перемикання між завданнями
	switch (menu)
	{
	case 1: task_1(); break; // Завдання 1
	case 2: task_2(); break; // Завдання 2
	case 3: task_3(); break; // Завдання 3
	default: cout << "Wrong task! (Only 1,2,3)" << endl; //повідомлення про помилку
	}
	system("pause");
	return 0;
}

// визначення функцій завдання 1
void task_1() {
	double A, B; //декларація змінної
	cout << "************* Proc16 *****************"<<endl;
	cout << "Enter A and B: ";
	cin >> A >> B; //введення даних
	if (cin.fail()) { //перевірка коректності даних
		cout << "Must be number!" << endl;
	}
	else {
		cout << Sign(A) + Sign(B) << endl; //виклик обрахунку
	}
}
// визначення функцій
int Sign(double X) {
	if (X < 0) {
		return -1;
	}
	else if (X == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

// визначення функцій завдання 2
void task_2() {
	int L; //декларація змінної
	cout << "************* Boolean22 *****************"<<endl;
	if (in_number(L)) // некоректні дані
		cout << "Must be number or >=100 and <=999 " << endl;
	else {
		// підрахунок і виведення результату
		if (out_number(L)) {
			cout << "This is an increasing or decreasing sequence"<<endl;
		}
		else {
			cout << "This is not an increasing or decreasing sequence"<<endl;
		}
	}
}
// визначення функцій введення і перевірки вхідних даних на коректність
bool in_number(int& pL){
	cout << "L2 = ";
	cin >> pL;
	if (cin.fail() || pL < 100 || pL > 999) //перевірка помилок консольного введення
		return true;

	else return false;
}
// визначення функцій розрахунку на підставі коректних вхідних даних результату
bool out_number(int number) {
	int hundreds = number / 100;          // Сотні
	int tens = (number / 10) % 10;        // Десятки
	int units = number % 10;              // Одиниці

	// Перевірка зростаючої або спадаючої послідовності
	if ((hundreds < tens && tens < units) || (hundreds > tens && tens > units)) {
		return true;
	}
	else {
		return false;
	}
}

// визначення функцій завдання 3
void task_3()
{
	int L; //декларація змінної
	cout << "************* Integer18 *****************"<<endl;
	if (in_L(L)) // некоректні дані
		cout << "Must be integer and >999" << endl;
	else
		// підрахунок і виведення результату
		out_res(check_L(L));
}
// визначення функцій введення вхідних значень з консолі з перевіркою їх на коректність
bool in_L(int& pL)
{
	cout << "L3 = ";
	cin >> pL;
	if (cin.fail() || pL <= 999) //перевірка помилок консольного введення
		return true;

	else return false;
}
// визначення функцій підрахунку результату
int check_L(int pL)
{
	return (pL / 1000) % 10;
}
// визначення функцій виведення результату в консоль
void out_res(int pr)
{
	cout << "Answer: " << pr << endl;
}
