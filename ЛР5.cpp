#include <iostream>
using namespace std;


// Дано дійсні числа (xi, yi), i = 1,2, ... n, – координати точок на 
площині. 
// Визначити кількість точок, що потрапляють в фігуру заданого 
кольору (або групу фігур).
void task1();


// Дано дійсне число х і натуральне число n. Необхідно: 
// a) Обчислити значення виразу при заданих x і n для виразу з табл.2.
// b) Вивести: для парних варіантів – значення кожного третього елемента, для непарних – значення кожного четвертого елемента.
void task2();

// Дослідити ряд на збіжність. Умова закінчення циклу обчислення суми прийняти у вигляді:
// | un | < е або | un | > g, де е – мала величина для переривання циклу обчислення суми збіжного ряду (е = 10-5 ... 10-20); 
// g – величина для переривання циклу обчислення суми розбіжного ряду (g = 102 ... 105).
void task3();

// Перевірка коректності
bool check_in(float &in);


int main() {
	int menu; // Змінна для номера завдання
	cout << "Task1: 1\nTask2: 2\nTask3: 3\nExit: -1" << endl;
	do
	{// Початок циклу
		cout << "Task number:";
		cin >> menu; // Вибір номера завдання

		// Перевірка вводу
		if (cin.fail()) {
			cin.clear();        // Скидає стан помилки
			cin.ignore(10000, '\n'); // Очищає буфер
			continue;           // Повертається до початку циклу
		}

		switch (menu) {
		case 1: task1(); break; // Завдання 1
		case 2: task2(); break; // Завдання 2
		case 3: task3(); break; // Завдання 3
		case -1: cout << "Exit ..." << endl; break; // Вихід
		default: cout << "Wrong task!" << endl; // Інший номер - повторити
		}
	} // Кінець циклу
	while (menu != -1); // Умова виконання: поки не -1
	return 0;
}

// завдання 1
void task1() {
	float x, y, a, r, k;
	cout << "************* Geom25*****************" << endl;
	cout << "Enter a, r, k: " << endl;
	// Перевірка коректності даних 
	if (!check_in(a) || !check_in(r) || !check_in(k)) {
			// Повідомлення про помилку
		cout << "Must be numeric, positive, non-zero, r<a/2!" << endl;
	}
	else // Дані коректні
	{
		for (int i = 0; i < k; i++) {
			// Перевірка коректності даних 
			cout << "Enter x, y: " << endl;
			if (!check_in(x) || !check_in(y)) {
				cout << "Must be numeric!" << endl;
			}
			else
			{
				// Обчислення для кола
				float crcl = x * x + y * y;
				// Чверть кола
				if (crcl <= r * r && x < 0 && y < 0)
					cout << "In region!" << endl;
				// Частка квадрата
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
	// Перевірка коректності даних 
	if (!check_in(x) || !check_in(n)) {
		cout << "Must be numeric!" << endl;
	}
	else { // Дані коректні
		for (int k = 0; k < n; k++) {
			for (int i = 1; i <= k; i++) {
				fk = fk * i; // Факторіал k
			}
			sum += pow(x - k, k + 1) / fk; // Сума
			if (int(k) % 3 == 0) { // Кожна третя сума
				cout << "Result: " << sum << endl;
			}
		}
	}
}

// Завдання 3
void task3() {
	float x;                  // Значення x для ряду
	float epsilon = 1e-20;     // Умова для збіжності
	float g = 1e20;            // Умова для розбіжності
	float M;                  // Крок виводу даних
	int n = 1;                 // Початковий індекс
	float sum = 0.0;          // Сума ряду
	float term;               // Поточний член ряду
	float factorial = 1.0;    // Змінна для обчислення факторіалу в циклі

	cout <<"************* Suma27*****************" << endl;
	cout << "Enter x, M: " << endl;
	// Перевірка коректності даних 
	if (!check_in(x) || !check_in(M) || M<0) {
		cout << "Must be numeric or M>0!" << endl;
	}
	else { // Дані коректні

		do {
			// Оновлення факторіалу для поточного n
			if (n > 1) factorial *= n;

			// Обчислення поточного члена ряду
			float numerator = pow(-1, n) * pow(x, n - 1) * sqrt(3 * n + 1);
			term = numerator / factorial;

			// Додавання члена до суми
			sum += term;

			// Вивід значень з заданим кроком M
			if (n % int(M) == 0 || fabs(term) < epsilon || fabs(term) > g) {
				cout << "n = " << n << ", u_n = " << term << ", sum = " << sum << endl;
			}

			// Перевірка умов закінчення циклу
			if (fabs(term) < epsilon) {
				cout << "|u_n| < epsilon." << endl; // Збігається
				break;
			}
			if (fabs(term) > g) {
				cout << "|u_n| > g." << endl; // Розбігається
				break;
			}

			++n; // Збільшення індексу
		} while (true);

		cout << "Suma: " << sum << endl;
	}
}

// Функція для перевірки помилок консольного введення
bool check_in(float& in) {
	cin >> in;
	if (!cin) {// Перевірка помилок консольного введення
		cin.clear();       // Очистка стану помилки
		cin.ignore(10000, '\n'); // Очищення буфера вводу
		return false;
	}
	else return true;
}
