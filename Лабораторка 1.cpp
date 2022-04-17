// Comp_sys.cpp 
//long и double. Выполнить циклический сдвиг в заданную пользователем сторону на заданное количество разрядов в пределах определённой группы разрядов, 
//количество которых и номер старшего разряда в группе задаются с клавиатуры
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
void num_long()
{
	long a;
	unsigned long mask = 1 << 31;
	while (true)
	{
		cout << "Введите число типа long - ";
		cin >> a;
		if (cin.fail())
		{
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else break;
	}
	for (int i = 0; i <= 31; i++) {
		if (i == 1) {
			cout << " ";
		}
		putchar(a & mask ? '1' : '0');
		mask >>= 1;
	}
	cout << " - long binary" << endl;
}
void num_double()
{
	union {
		long int tool[2];
		double num;
	};
	unsigned int two = 1 << 31;
	while (true)
	{
		cout << "Введите число типа Double через <.> - ";
		cin >> num;
		if (cin.fail())
		{
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else break;
	}
	for (int i = 0; i <= 31; i++) {
		if (i == 1 || i == 12) {
			cout << " ";
		}
		putchar(tool[1] & two ? '1' : '0');
		tool[1] <<= 1;
	}
	for (int j = 0; j <= 31; j++) {

		putchar(tool[0] & two ? '1' : '0');
		tool[0] <<= 1;
	}
	cout << " - double binary" << endl;
}
int menu()
{
	cout << endl << "\t" << "\t" << "\t" << "ОСНОВНОЕ МЕНЮ" << endl;
	cout << "\t" << "\t" << "long " << sizeof(long) << " Byte" << "\t" << "double " << sizeof(double) << " Byte" << endl;
	cout  << "1. Тип данных Long внутреннее представление в двоичной системе счисления.\n";
	cout  << "2. Тип данных Double внутреннее представление в двоичной системе счисления.\n";
	cout  << "3. Выполнить циклический сдвиг Тип данных Long.\n";
	cout  << "4. Выполнить циклический сдвиг Тип данных Double.\n";
	cout  << "5. Выход" << endl;
	unsigned qwe = 0;
	while (true)
	{
		cout << "Выберите необходимые действия:" << endl;
		cin >> qwe;
		if (cin.fail())
		{
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (qwe == 0)
		{
			cout << " Значение должно быть больше 0" << endl;
			continue;
		}
		if (qwe > 5)
		{
			cout << " Возможное значение <В диапозоне от 1-3>" << endl;
			continue;
		}
		else break;
	}
	system("cls");
	return qwe;
}
void change() {
	long num;
	unsigned low, count;								//номер младшего разряда, количество разрядов группы
	int side, dist;									//сторона сдвига, кол-во разрядов сдвига
	int i;										//номер разряда
	long result = 0;								//число в десятичном виде
	while (true)
	{
		cout << "Введите число типа long: ";
		cin >> num;
		if (cin.fail())
		{
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else break;
	}
	while (true) {
		cout << "Введите номер младшего разряда в группе (0..31): ";
		cin >> low;
		if (cin.fail()) {
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (low > 31) {
			cout << "Ошибка значения проверьте ввод" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else break;
	}
	while (true) {
		cout << "Введите количество разрядов группы (0..32): ";
		cin >> count;
		if (cin.fail()) {
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (count < 0) {
			cout << "Ошибка значения проверьте ввод" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (low + count > 32) {
			cout << "Ошибка значения проверьте ввод" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else break;
	}
	do {
		cout << "Выберите сторону: 1-влево, 2-вправо. ";
		cin >> side;
		if (cin.fail()) {
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (side != 1 && side != 2);
	while (true) {
		cout << "Введите количество разрядов сдвига (0..32): ";
		cin >> dist;
		if (cin.fail()) {
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (dist > 32) {
			cout << "Ошибка значения проверьте ввод" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (dist < 0) {
			cout << "Ошибка значения не может быть отрицательным " << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else break;
	}
	if (side == 2) dist = count - dist;
	cout << endl;
	cout << "Число в двоичном виде:   \t";
	unsigned long mask = 1 << 31;
	for (int i = 0; i <= 31; i++) {
		if (i == 1) {
			cout << " ";
		}
		putchar(num & mask ? '1' : '0');
		mask >>= 1;
	}
	cout << endl;
	for (i = 0; i <= 31; i++) {
		int k = i;
		if (i >= low && i < low + count)
			k = (((i - low) + dist) % count) + low;
		if (num&(1 << i))
			result += (1 << k);
	}
	cout << "Результат в двоичном виде: \t";
	for (i = 31; i >= 0; i--) {
		if (i == 30) {
			cout << " ";
		}
		printf("%u", (result >> i) & 1);
	}
	cout << endl;
	cout <<"В десятичном виде после изменений: "<< result << endl;
}
void end() {
	union {
		long int tool[2];
		double num;
	};
	unsigned low, count;								//номер младшего разряда, количество разрядов группы
	int side, dist;									//сторона сдвига, кол-во разрядов сдвига
	int i;										//номер разряда
	double result;									//результат - десятичное число
	while (true)
	{
		cout << "Введите число типа double: ";
		cin >> num;
		if (cin.fail())
		{
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else break;
	}
	while (true) {
		cout << "Введите номер младшего разряда в группе (0..63): ";
		cin >> low;
		if (cin.fail()) {
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (low > 63) {
			cout << "Ошибка значения проверьте ввод" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else break;
	}
	while (true) {
		cout << "Введите количество разрядов группы (0..64): ";
		cin >> count;
		if (cin.fail()) {
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (count < 0) {
			cout << "Ошибка значения проверьте ввод" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (low + count > 64) {
			cout << "Ошибка значения проверьте ввод" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else break;
	}
	do {
		cout << "Выберите сторону: 1-влево, 2-вправо. ";
		cin >> side;
		if (cin.fail()) {
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (side != 1 && side != 2);
	while (true) {
		cout << "Введите количество разрядов сдвига (0..64): ";
		cin >> dist;
		if (cin.fail()) {
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (dist > 64) {
			cout << "Ошибка значения проверьте ввод" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (dist < 0) {
			cout << "Ошибка значения не может быть отрицательным " << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else break;
	}
	if (side == 2) dist = count - dist;
	cout << endl;
	cout << "Число в двоичном виде:   \t";
	unsigned int two = 1 << 31;
	for (int i = 0; i <= 31; i++) {
		if (i == 1 || i == 12) {
			cout << " ";
		}
		putchar(tool[1] & two ? '1' : '0');
		tool[1] <<= 1;
	}
	for (int j = 0; j <= 31; j++) {

		putchar(tool[0] & two ? '1' : '0');
		tool[0] <<= 1;
	}
	cout << endl;

	cout << "Не успел до 17.04.2022" << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Mem1:
	int lab = menu();
	if (lab == 1) {
		cout << "Тип данных Long внутреннее представление в двоичной системе счисления.\n";
		num_long();
		goto Mem1;
	}
	if (lab == 2) {
		cout << "Тип данных Double внутреннее представление в двоичной системе счисления.\n";
		num_double();
		goto Mem1;
	}
	if (lab == 3) {
		cout << "Выполнить циклический сдвиг Тип данных Long." << endl;
		change();
		goto Mem1;
	}
	if (lab == 4) {
		cout << "Выполнить циклический сдвиг Тип данных Double." << endl;
		end();
		goto Mem1;
	}
	if (lab == 5) {
		cout << "\n GEME OVER \n";
		return 0;
	}
	return 0;
}
