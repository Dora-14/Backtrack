#include <iostream>
#include <vector>

using namespace std;

int N = 5;

string gyumik[] = {"duzsman", "bany", "jubita", "iminnya"};

bool lehet(vector<string> ital, string ujgyumi)
{
    int nr=0;
    for(int i=0; i<ital.size(); i++)
    {
        if(ujgyumi == ital[i])
        {
            nr++;
            if(nr>1){
                return false;
            }
        }
    }
    return true;
}
void kiir(vector<string> ital)
{
    for(int i=0; i<ital.size(); i++)
    {
        cout << ital[i] << " ";
    }
    cout << endl;
    return;
}

void backtrack(vector<string> ital)
{

    if(ital.size() == N)
    {
                    kiir(ital);
                    return;
    }
    for(int i=0; i<4; i++)
    {
        if(lehet(ital,gyumik[i]))
        {
            vector<string>tempital;
            for(int j=0; j<ital.size(); j++)
            {
                tempital.push_back(ital[j]);
            }
            tempital.push_back(gyumik[i]);
            backtrack(tempital);
        }
    }
}
int main()
{
    vector<string>ital;
    backtrack(ital);
    return 0;
}
