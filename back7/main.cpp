#include <iostream>
#include <vector>

using namespace std;

int N = 4;
int M ;
string gyumik[] = {"afonya", "kajszin", "citrom", "alma", "korte"};

bool lehet(vector<string> ital, string ujgyumi)
{
    for(int i=0; i<ital.size(); i++)
    {
        if(ujgyumi == ital[i])
        {
            return false;
        }
    }
    if(ujgyumi == "citrom")
    {
        for(int i=0; i<ital.size(); i++)
        {
            if(ital[i] == "korte")
            {
                return false;
            }
        }
    }
    if(ujgyumi == "korte")
    {
        for(int i=0; i<ital.size(); i++)
        {
            if(ital[i] == "citrom")
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

    if(ital.size() == M)
    {
        if(ital[0] == "afonya" && ital[M-1] != "alma"){
            kiir(ital);
            return;
        }

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
    for(M=2; M<5; M++)
    {
        backtrack(ital);
    }

    return 0;
}
