#include "stdafx.h"
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	string stroka;
	double x, y, z;
	char op1, op2;        //Объявление переменных

	getline(cin, stroka);                                // Считывание строки из консоли до символа ограничителя
	istringstream stream(stroka);                        //переводит строку в поток
	stream >> x; stream >> op1;                          // a - первое число.  op1 - первый знак
	while (stream >> y) {                                // пока вводится 2-я переменнаяя (y)
		if ((op1 == '*') || (op1 == '/')) {              // Если первый оператор * или / выполняется умножение или деление
			if (op1 == '*') {
				x = x*y;
			}
			if (op1 == '/') {         
 				if (y != 0) {                            
					x = x / y;
				}
				else {  
					cout << "ERROR" << endl;              
					return -1;
				}
			}
			if (!(stream >> op1)) {                       // если оператор не является * или / 
				break;                                    
			}
		}
		else if ((op1 == '+') || (op1 == '-')) {           //а + или - то выполняется сложение или вычитание
			if (stream >> op2) {                           //если и второй оператор тоже + или -
				if ((op2 == '+') || (op2 == '-')) {        
					if (op1 == '+') {
						x +=y;
					}
					if (op1 == '-') {
						x -=y;
					}
					op1 = op2; op2 = 0;
				}
				if ((op2 == '*') || (op2 == '/')) {
					while ((op2 == '*') || (op2 == '/')) {              // пока оператор2 * или / выполняется деление или умножение
						stream >> z;                                     // и есть третья переменная z
						if (op2 == '*') {
							y = y*z;
						}
						if (op2 == '/') {
							if (z != 0) {
								y = y / z;
							}
							else {
								cout << "ERROR" << endl;
								return -1;
							}
						}
						if (!(stream >> op2)) {
							break;
						}
					}
					if (op1 == '+') {
						x += y;
					}
					if (op1 == '-') {
						x -= y;
					}
					op1 = op2; op2 = 0;
				}
			}
			else {
				if (op1 == '+') {
					x += y;
				}
				if (op1 == '-') {
					x -= y;
				}
			}
		}
	}
	cout << x << endl;
	return 0;
}
