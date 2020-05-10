#include "Menu.h"

menu::menu()
{
    type = 0;
    cout << "Выберите операцию из списка доступных и введите ее номер в консоль:" << endl;
    cout << "1)Умножение комплексного числа на вещественное число" << endl;
    cout << "2) Сложение двух комплексных чисел" << endl;
    cout << "3) Умножение двух комплексных чисел" << endl;
    cout << "4) Длина комплексного числа" << endl;
    cin >> type;
}

void menu::switchMenu(menu settings)
{
    switch (settings.type)
    {
        case 1:
        {
            cout << "Введите вещественную часть комплексного числа: " << endl;
            double realPart;
            cin >> realPart;
            cout << "Введите мнимую часть комплексного числа: " << endl;
            double imaginaryPart;
            cin >> imaginaryPart;
            complexNumber complex(realPart, imaginaryPart);

            cout << "Введите вещественное число: " << endl;
            double realNumber;
            cin >> realNumber;

            complexNumber::complexNumberPrint(complexNumber::complexNumber_x_realNumber(complex, realNumber));
            break;
        }
        case 2:
        {
            cout << "Введите вещественную часть первого комплексного числа: " << endl;
            double firstRealPart;
            cin >> firstRealPart;
            cout << "Введите мнимую часть комплексного числа: " << endl;
            double firstImaginaryPart;
            cin >> firstImaginaryPart;
            complexNumber firstComplex(firstRealPart, firstImaginaryPart);

            cout << "Введите вещественную часть второго комплексного числа: " << endl;
            double secondRealPart;
            cin >> secondRealPart;
            cout << "Введите мнимую часть комплексного числа: " << endl;
            double secondImaginaryPart;
            cin >> secondImaginaryPart;
            complexNumber secondComplex(secondRealPart, secondImaginaryPart);

            complexNumber::complexNumberPrint(complexNumber::complexNumbersSummary(firstComplex, secondComplex));
            break;
        }
        case 3:
        {
            cout << "Введите вещественную часть первого комплексного числа: " << endl;
            double firstRealPart;
            cin >> firstRealPart;
            cout << "Введите мнимую часть комплексного числа: " << endl;
            double firstImaginaryPart;
            cin >> firstImaginaryPart;
            complexNumber firstComplex(firstRealPart, firstImaginaryPart);

            cout << "Введите вещественную часть первого комплексного числа: " << endl;
            double secondRealPart;
            cin >> secondRealPart;
            cout << "Введите мнимую часть комплексного числа: " << endl;
            double secondImaginaryPart;
            cin >> secondImaginaryPart;
            complexNumber secondComplex(secondRealPart, secondImaginaryPart);

            complexNumber::complexNumberPrint(complexNumber::complexNumbersMultiplication(firstComplex, secondComplex));
            break;
        }
        case 4:
        {
            cout << "Введите вещественную часть комплексного числ: " << endl;
            double realPart;
            cin >> realPart;
            cout << "Введите мнимую часть комплексного числа: " << endl;
            double imaginaryPart;
            cin >> imaginaryPart;
            complexNumber complex(realPart, imaginaryPart);

            cout << "Длина: " << complexNumber::complexNumberLength(complex) << endl;
            break;
        }
        default:
        {
            cout << "Ошибка, введите действительный номер операции" << endl;
            break;
        }
    }
}
