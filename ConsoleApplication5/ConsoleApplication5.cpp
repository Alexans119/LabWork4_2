#include <iostream>
#include <array>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int m, n;
    cout << "Введите размер массива:"; cin >> m;
    cout << "Введите сдвиг:"; cin >> n;
    cout << endl;
    /* создаем 2 вектора: 
    1 - основной из m-элементов, 
    2 - сдвиг на n-элементов (буффер)*/
    vector <int> arr(m);
    vector<int> arr2(n);
    int b = m - 1;
    int j = 0;    
    
    //Проверяем является ли свдиг по размеру больше самого массива
    if (n > m) {
        
        cout << "!Свдиг не может быть больше самого массива!"<<endl;
        cout << "          Перезапустите программу";
        cout << endl;

        return 0;
    }
    //Вводим значения в освной массив
    for (int i = 0; i <= b; i++) {
        cout << "Введите arr[" << i << "]:";
        cin >> arr[i];
    }

    //Наводим красоты добавив интерфейса
    cout << "Ваш массив:" << endl;
    for (int i = 0; i <= b; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Преобразуем сдвинув элементы на " << n << " элементов влево:" << endl;

    //Переносим в буффер-массив выпадающие (первые) элементы из основного
    for (int i = 0; i <= n-1; i++) {
        arr2[i] = arr[i];
    }

    //Сдвигаем элементы влево
    for (int i = 0; i <= (b - n); i++) {
        arr[i] = arr[i + n];
    }
    //Переносим из буффер-массива элементы в конец основного
    for (int i = n - 1; i >= 0; i--) {
        arr[b - i] = arr2[j];
        j++;
    }

    //Вывод преобразованного массива
    for (int i = 0; i <= b; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}