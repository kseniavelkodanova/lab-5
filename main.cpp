#include <iostream>
using namespace std;


/*Дано дійсні числа (xi, yi), i = 1,2, ... n, – координати точок на 
площині. Визначити кількість точок, що потрапляють в фігуру заданого 
кольору (або групу фігур).*/
void task1();


/*Дано дійсне число х і натуральне число n. Необхідно: 
a) Обчислити значення виразу при заданих x і n для виразу з табл.2.
b) Вивести: для парних варіантів – значення кожного третього 
елемента, для непарних – значення кожного четвертого елемента.
*/
void task2();

/*Дослідити ряд на збіжність. Умова закінчення циклу 
обчислення суми прийняти у вигляді: | un | < е або | un | > g, де е – мала величина 
для переривання циклу обчислення суми збіжного ряду 
(е = 10-5 ... 10-20); g – величина для переривання циклу обчислення суми 
розбіжного ряду (g = 102 ... 105).*/
void task3();

//перевірка коретності
bool check_in(float &in);


int main() {
	int menu; // змінна для номера завдання
	cout << "Task1: 1\nTask2: 2\nTask3: 3\nExit: -1" << endl;
	do
	{// початок циклу
		cout << "Task number:";
		cin >> menu; // Щоб вибрати номер завдання

		// Перевірка вводу
		if (cin.fail()) {
			cin.clear();        // Скидає стан помилки
			cin.ignore(10000, '\n'); // Очищає буфер
			continue;           // Повертається до початку циклу
		}

		switch (menu) {
		case 1: task1(); break; // 1 - завдання 1
		case 2: task2(); break; // 2 - завдання 2
		case 3: task3(); break; // 3 - завдання 3
		case -1: cout << "Exit ..." << endl; break; // - 1 - вихід
		default: cout << "Wrong task!" << endl; // інший номер - повторити
		}
	} // кінець циклу
	while (menu != -1); // умова виконання: поки не -1
	return 0;
}

// завдання 1
void task1() {
	float x, y, a, r, k;
	cout << "************* Geom25*****************" << endl;
	cout << "Enter a, r, k: " << endl;
	// перевірка коректності даних !!!
	if (!check_in(a) || !check_in(r) || !check_in(k)) {
			//повідомлення про помилку
		cout << "Must be numeric, positive, non-zero, r<a/2!" << endl;
	}
	else // дані коректні
	{
		for (int i = 0; i < k; i++) {
			// перевірка коректності даних !!!
			cout << "Enter x, y: " << endl;
			if (check_in(x) || check_in(y)) {
				cout << "Must be numeric!" << endl;
			}
			else
			{
				// обчислення для кола
				float crcl = x * x + y * y;
				// чверть кола
				if (crcl <= r * r && x < 0 && y < 0)
					cout << "In region!" << endl;
				// частка квадрата
				else if (x > -y && x < a / 2 && -y < a / 2 && crcl > r * r && x > 0 && y < 0)
					cout << "In region!" << endl;
				else cout << "Out of region!" << endl;
			}
		}
	}
}

//завдання 2
void task2() {
	float x, fk=1, n, sum = 0;
	cout << "************* Suma12*****************" << endl;
	cout << "Enter x, n: " << endl;
	// перевірка коректності даних !!!
	if (!check_in(x) || !check_in(n)) {
		cout << "Must be numeric!" << endl;
	}
	else { // дані коректні
		for (int k = 0; k < n; k++) {
			for (int i = 1; i <= k; i++) {
				fk = fk * i; // факторіал k
			}
			sum += pow(x - k, k + 1) / fk; // сума
			if (int(k) % 3 == 0) { // кожна третя сума
				cout << "Result: " << sum << endl;
			}
		}
	}
}

//завдання 3
void task3() {
	float x;                  // значення x для ряду
	float epsilon = 1e-20;     // умова для збіжності
	float g = 1e20;            // умова для розбіжності
	float M;                  // крок виводу даних
	int n = 1;                 // початковий індекс
	float sum = 0.0;          // сума ряду
	float term;               // поточний член ряду
	float factorial = 1.0;    // змінна для обчислення факторіалу в циклі

	cout <<"************* Suma27*****************" << endl;
	cout << "Enter x, M: " << endl;
	// перевірка коректності даних !!!
	if (!check_in(x) || !check_in(M) || M<0) {
		cout << "Must be numeric or M>0!" << endl;
	}
	else { // дані коректні

		do {
			// оновлення факторіалу для поточного n
			if (n > 1) factorial *= n;

			// обчислення поточного члена ряду
			float numerator = pow(-1, n) * pow(x, n - 1) * sqrt(3 * n + 1);
			term = numerator / factorial;

			// додавання члена до суми
			sum += term;

			// вивід значень з заданим кроком M
			if (n % int(M) == 0 || fabs(term) < epsilon || fabs(term) > g) {
				cout << "n = " << n << ", u_n = " << term << ", sum = " << sum << endl;
			}

			// перевірка умов закінчення циклу
			if (fabs(term) < epsilon) {
				cout << "|u_n| < epsilon." << endl; //збігається
				break;
			}
			if (fabs(term) > g) {
				cout << "|u_n| > g." << endl; //розбігається
				break;
			}

			++n; // збільшення індексу
		} while (true);

		cout << "Suma: " << sum << endl;
	}
}

//функція для перевірки помилок консольного введення
bool check_in(float& in) {
	cin >> in;
	if (!cin) {//перевірка помилок консольного введення
		cin.clear();       // очистка стану помилки
		cin.ignore(10000, '\n'); // очищення буфера вводу
		return false;
	}
	else return true;
}