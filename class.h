
#include <string>
#include <fstream>
using namespace std;
class Train
{
private:
    string way;
    string gruz;
    int num;
public:
    Train();
    void SetTrain(string way_value, string gruz_value, int num_value);
    string GetWay();
    string GetGruz();
    float GetRatting();
    int GetNum();
    void ScanTrain();
    void Print();
    void Putinfile(string argum);
    friend ostream& operator << (ostream& os, const Train& train);
    friend istream& operator >> (istream& is, Train& train);
};
