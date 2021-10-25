#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc_in_c.cpp"

/*
 * 1 курс (1 семестр). Декабрь 2017
 * Курсовая работа по "Программированию".
 * Тема курсовой работы #9:
 *      Разработка программы-калькулятора с разбором выражений.
 *      Написать программу-калькулятор. Вычисление выражения (например, 5+(12*55*(1-4)) ).
 */




 /*
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Прототипы ф-ий ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

void	clearStr(char *str);
char  * ReadStrFromFille(char *fileName);
void	RecordStrToFille(char *fileName, char *expression, double answer);



 /*
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */


int main(){
	std::cout << "Курсовая работа по \"Программированию\". Выполнил Толкачев С.П. (З-17ИВТ2мг)\n\n\n";

	std::cout << "Правила использования калькулятора\n\n";
	std::cout << "1) В выражении допускается использование следующих математических операций: '+', '-', '*', '/'.\n\n";
	std::cout << "2) В выражении допускается использование скобок.\n\n";
	std::cout << "3) В выражении допускается использование следующих тригонометрических функций: 'cos()', 'sin()', 'tan()', 'ctan()'.";
	std::cout << " Внутри скобок тригономитрической функции допускается наличие вложенных математических выражений (например, 'cos(1+(2+3*4))').\n\n";
	std::cout << "4) В выражении допускается использование переменных.";
	std::cout << " Инициализировать переменную можно следующим образом: '$one = 1;', где 'one' - имя переменной, а '1' присваиваемое значение.";
	std::cout << " Так же при инициализации вместо числа можно указывать математическое выражение, которое будет рассчитано и преобразовано в число присваиваемое переменной (например, '$exp = 2 + (3 - 4 * 5);').";
	std::cout << " Начало имени переменной обозначется символом '$'.";
	std::cout << " Первым символом имени переменной может быть любая латинская буква [a-zA-Z] либо символ нижнего подчёркивания [_].";
	std::cout << " Вторым и последующими символами имени переменной могут быть любая латинская буква [a-zA-Z], цифра [0-9] либо символ нижнего подчёркивания [_].";
	std::cout << " Инициализация переменной ВСЕГДА должна заканчиваться символом точка с запятой ';'.";
	std::cout << " Если предполагается инициализация переменной внутри выражения присваиваемого другой переменной, то такое выражение должно быть заключено в круглые скобки (например, '$exp = ($three = 3; 2 + ($three - 4 * 5));').\n";

	std::cout << "-----------------------------------------------\n\n\n";


	char *expression; 
	char *initExpression; // Копия выражения
	double result = 0;
	int typeInput = 0;


		int inputExpLength = 1;
			
		do {
			std::cout << "\nУкажите длинну вводимого математического выражения (всего символов с учётом пробельных символов; >1):\n";
			std::cin >> inputExpLength;
		} while ( inputExpLength < 1 );
		

		initExpression = new char(++inputExpLength);
		expression = new char(inputExpLength);

		std::cout << "\nВведите математическое выражение для рассчёта (не более " << --inputExpLength << " символов):\n";

		std::cin >> initExpression;

		if ( !fgets(expression, inputExpLength, stdin) ) {
			std::cout << "\nОшибка указания выражения.";
			getchar(); // ожидание нажатия клавиши
			exit(3); // завершаем программу и передаём код завершения
		}


	strcpy(expression, initExpression);

	result = ParserMathExpression(expression);




	delete expression; // освобождаем память

	//Результат вычислений 
	std::cout << initExpression << " = " << result << "\n";

	delete initExpression; // освобождаем память (копию выражения)

	std::cout << "\nПрограмма завершена. Нажмите любую клавишу для закрытия окна...";
	getchar(); // ожидание нажатия клавиши
}





/*
 * Чистка строки от символов перевода строки
 *
 * Чистит строку от символов перевода строки, полученную вводом в терминале
 * с помощью ф-ии fgets();
 *
 * @param char	* str - очищаемая строка
 *
 * @return void
 */
void clearStr(char *str) {
	int carentChar = 0;
	char c;
	while ((c = str[carentChar]) != '\0') {
		if (c == '\n' || c == '\r') {
			str[carentChar] = '\0';

			break;
		}
		carentChar++;
	}
}
