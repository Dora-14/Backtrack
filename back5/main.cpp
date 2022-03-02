#include <iostream>
#include <vector>

using namespace std;

int N = 4;

string gyumik[] = {"eper", "alma", "sargadinnye", "korte", "narancs"};

bool lehet(vector<string> ital, string ujgyumi)
{
    for(int i=0; i<ital.size(); i++)
    {
        if(ujgyumi == ital[i])
        {
            return false;
        }
    }
    if(ujgyumi == "narancs")
    {
        for(int i=0; i<ital.size(); i++)
        {
            if(ital[i] == "sargadinnye")
            {
                return false;
            }
        }
    }
    if(ujgyumi == "sargadinnye")
    {
        for(int i=0; i<ital.size(); i++)
        {
            if(ital[i] == "narancs")
            {
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
    for(int i=0; i<5; i++)
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
