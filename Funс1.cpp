#include "Func2.h"
#include "class.h"
#include <iostream>

string way_value;
string gruz_value;
int num_value;
Train::Train() {
    way = "Null";
    gruz = "Null";
    num = 0;
}

void Train::SetTrain(string way_value, string gruz_value, int num_value) {
    way = way_value;
    gruz = gruz_value;
    num = num_value;
}
string Train::GetWay() {
    return way;
}

string Train::GetGruz() {
    return gruz;
}


int Train::GetNum() {
    return num;
}

void Train::Putinfile() {
    ofstream file;
    file.open("info.txt", ios_base::app);
    if (!file) {
        cout << "Файл не открыт" << endl;
    }
    else{
    file << way << " ";
    file << gruz << " ";
    file << num << " " << endl;
	}
    file.close();
}
void Train::Print() {
    setlocale(LC_CTYPE, "Russian");
    cout << "\t Направление - " << way << "\t Груз - " << gruz << "\t Номер - " << num << endl;
}


void Train:: ScanTrain() {
    setlocale(LC_CTYPE, "Russian");
    cout << "Введите данные" << endl;
    cout << "Направление:" << endl;
    cin >> way;
    cout << "Груз" << endl;
    cin >> gruz;
    cout << "Номер:" << endl;
    cin >> num;
};
void addtrain() {
    setlocale(LC_CTYPE, "Russian");
    Train* train;
    train = new Train;
    train->ScanTrain();
    train->Print();
    train->Putinfile();
    cout << "Данные записаны в файл" << endl;
		}
void deletetrain() {
    cout << "Введите направление состава" << endl;
    string deleteway;
    string archiv;
    cin >> deleteway;
    fstream file;
    int n, s = 0;
    Train *train;
    train = new Train;
    file.open("test.txt");
    if (!file) {
        cout << "Файл не открыт" << endl;
    		}
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    do
    {
        Train *train;
	train = new Train;
        file >> *train;
        s = file.tellg();
        if (deleteway != train->GetWay())
        {
            string numstr = to_string(train->GetNum());

            archiv += train->GetWay() + " " + train->GetGruz() + " " +" " + numstr + "\n";
        }
        delete train;

    } while (s < n - 4);
    file.close();
    file.open("info.txt");
    if (!file) {
        cout << "файл не открыт 2" << endl;
    }
    file << archiv;
    file.close();
    cout << "состав удалён!" << endl;
}

void searchtrain() {
    cout << "Выберите параметр поиска:" << endl << "1)Направление" << endl << "2)груз" << endl;
    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        searchtrain_way();
        break;
    case 2:
        searchtrain_gruz();
        break;
    }
}

void searchtrain_way() {
    string check;
    cout << "Введите направление" << endl;
    cin >> check;
    ifstream file;
    int n, s = 0;
    char c;
    Train *train;
    train = new Train;
    file.open("info.txt");
    if (!file) {
        cout << "файл не открыт" << endl;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    cout << "Информация о составе:" << endl;
    do
    {
        file >> *train;
        s = file.tellg();
        if (train->GetWay() == check) {
            train->Print();
        }



    } while (s < n - 4);
    file.close();
}

void searchtrain_gruz() {
    string check;
    cout << "Введите наименование груза" << endl;
    cin >> check;
    ifstream file;
    int n, s = 0;
    char c;
    Train *train;
    train = new Train;
    file.open("info.txt");
    if (!file) {
        cout << "Файл не открыт" << endl;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    cout << "Информация о составе:" << endl;
    do
    {
        file >> *train;
        s = file.tellg();
        if (train->GetGruz() == check) {
            train->Print();
        }



    } while (s < n - 5);
    file.close();
}

void listtrain() {
    fstream file;
    int n, s = 0;
    Train *train;
    train = new Train;
    file.open("info.txt");
    if (!file) {
        cout << "Не удалось открыть файл" << endl;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    do
    {
        file >> *train;
        train->Print();
        s = file.tellg();



    } while (s < n - 5);
    file.close();
}

void changetrain() {
    string changeway;
    string archive;
    cout << "Введите направление: ";
    cin >> changeway;
    fstream file;
    int n, s = 0;
    char c;
    Train *train;
    train = new Train;
    file.open("info.txt");
    if (!file) {
        cout << "Файл не открыт" << endl;
    }
    file.seekg(0, ios_base::end);
    n = file.tellg();
    file.seekg(0);
    do {
        file >> *train;
        s = file.tellg();
        if (changeway == train->GetWay()) {
            train->Print();
            cout << "Что будем менять?"<<endl;
            cout << "1)Направление" << endl << "2)груз" << endl << "3)Номер" << endl;
            int c;
            cin >> c;
            string newway;
            string newgruz;
            int newnum;
            string numstr = to_string(train->GetNum());
            switch (c)
            {
            case 1:
                cout<<"Введите новое направление: ";
                cin >> newway;
                archive += newway + " " + train->GetGruz() + " " +  numstr + "\n";
                cout << "готово!"<<endl;
                break;
            case 2:
                cout << "введите новый груз: ";
                cin >> newgruz;
                archive += train->GetWay() + " " + newgruz + " " + numstr + "\n";
                cout << "готово!" << endl;
                break;
            case 3:
                cout << "Введите новый номер: ";
                cin >> newnum;
                numstr = to_string(newnum);
                archive += train->GetWay() + " " + train->GetGruz() + " " + numstr + "\n";
                cout << "готово!" << endl;
                break;
            }
        }
        else {
            string numstr = to_string(train->GetNum());

            archive += train->GetWay() + " " + train->GetGruz() + " " + numstr + "\n";
        }
    } while (s < n - 5);
    file.close();
    file.open("info.txt");
    if (!file) {
        cout << "Файл не октрыт" << endl;
    }
    file << archive;
    file.close();
}

ostream& operator<<(ostream& os, const Train& train) {
    os << train.way << " " << train.gruz << " " << train.num << "\n";
    return os;
}

istream& operator>>(istream& is, Train& train) {
    is >> train.way >> train.gruz  >> train.num;
    return is;
}
int menu_select()
{
    char s[100];
    int c;
    do
    {
        cout << "______________" << endl;
        cout << "1 - Добавить состав" << endl << "2 - Показать все составы" << endl << "3 - Поиск состава" << endl << "4 - Удалить остав" << endl << "5 - Редактирование" << endl << "6 - Выход" << endl;
        cin >> s;
        c = atoi(s);
        cout << "______________" << endl;
    } while (c<0 || c>6);
    return c;
}
