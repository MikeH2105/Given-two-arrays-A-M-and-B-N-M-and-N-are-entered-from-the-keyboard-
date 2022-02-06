/*Дано два масиви: А[M] і B[N] (M і N вводяться з клавіатури). Необхідно створити третій масив
мінімально можливого розміру, у якому потрібно зібрати елементи масиву A, які не включаються до масиву B, без повторень*/

#include <iostream>
#include <locale>
#include <windows.h>
using namespace std;

void inputArr(int* arr, int size) {               //Функція вводу рандомних чисел у масив.
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20;
    }
}
void Special(int* arrA, int size1, int* arrB, int size2, int*& arrC, int& size3) {  //Функція збору елементів А які не включають елементи В
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arrA[i] == arrB[j]) {
                break;
            }
            if (j == size2 - 1) {
                arrC[k] = arrA[i];
                k++;
            }

        }
    }
    size3 = k;


}

void parnDel(int* arr, int& size) {     //Функція для видалення парних елементів з масиву
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j]) {
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
            }
        }
    }
}
void printArr(int* arr, int& size) {

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size1 = 0;
    int size2 = 0;
    cout << "Введіть розмір масиву A  = ";
    cin >> size1;
    int* arrA = new int[size1];

    cout << "Введіть розмір масиву В    = ";
    cin >> size2;
    int* arrB = new int[size1];

    inputArr(arrA, size1);                 //Викликаємо ф-цію вводу масиву для А
    cout << "Заповнений довільно масив А виглядає наступним чином:" << endl;
    printArr(arrA, size1);                  //Виводимо рандомно заповнений масив для наглядності
    cout << endl;
    inputArr(arrB, size2);                 //Викликаємо ф-цію вводу масиву для В
    cout << "Заповнений довільно масив В виглядає наступним чином:" << endl;
    printArr(arrB, size2);
    cout << endl;
    int size3 = 10;
    int* arrC = new int[size3];
    Special(arrA, size1, arrB, size2, arrC, size3);     //Викликаємо функцію для збору елементів
    parnDel(arrC, size3);           //Викликаємо функцію для видалення парних елементів
    cout << endl;
    cout << "Tретій  масив  без повторень виглядає так:" << endl;
    printArr(arrC, size3);          //Виводимо третій масив на екран через функцію.


    delete[]arrA;
    delete[]arrB;
    delete[]arrC;

}

