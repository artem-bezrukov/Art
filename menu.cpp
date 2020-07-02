
#include <iostream>
#include <string>
#include <fstream>
#include "class.h"
#include "Func2.h"
using namespace std;
bool work=true;

int main(int argc, char* argv[])
{
string argum = argv[1];
cout<< argum << endl;
    setlocale(LC_CTYPE, "Russian");
    char choice;
    cout << "Вас приветствует база данных московского жд вокзала" << endl << "Выберите действие:" << endl;
    while (work) {
        choice = menu_select();
        switch (choice) {
        case 1: addtrain(string(argv[1]));
            break;
        case 2: listtrain(string(argv[1]));
            break;
        case 3: searchtrain_way(string(argv[1]));
            break;
	case 4 : searchtrain_gruz(string(argv[1]));
	    break;
        case 5: deletetrain(string(argv[1]));
            break;
        case 6: changetrain(string(argv[1]));
            break;
        case 7: exit(0);
            return 0;
        }
    }
    return 0;
}
    

