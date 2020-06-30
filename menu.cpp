
#include <iostream>
#include <string>
#include <fstream>
#include "class.h"
#include "Func2.h"
using namespace std;
bool work=true;

int main(int argc, char* argv[])
{
	for(int i=0; i<argc; i++){
				cout<< "argument" << i << argv[i] << endl;
				}
    setlocale(LC_CTYPE, "Russian");
    char choice;
    cout << "Вас приветствует база данных московского жд вокзала" << endl << "Выберите действие:" << endl;
    while (work) {
        choice = menu_select();
        switch (choice) {
        case 1: addtrain();
            break;
        case 2: listtrain();
            break;
        case 3: searchtrain();
            break;
        case 4: deletetrain();
            break;
        case 5: changetrain();
            break;
        case 6: exit(0);
            return 0;
        }
    }
    return 0;
}
    

