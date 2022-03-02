#include <iostream>
#include <vector>

using namespace std;

int M =4;

string szinek[] = {"voros", "kek", "rozsaszin", "narancs","zold"};

bool lehet(vector<string> gyongysor, string ujszin)
{
    for(int i=0; i<gyongysor.size(); i++)
    {
        if(ujszin == gyongysor[i])
        {
            return false;
        }
    }

    return true;
}
void kiir(vector<string> gyongysor)
{
    for(int i=0; i<gyongysor.size(); i++)
    {
        cout << gyongysor[i] << " ";
    }
    cout << endl;
    return;
}

void backtrack(vector<string> gyongysor)
{
    if(gyongysor.size() == M)
    {
        for(int i=1;i<gyongysor.size();i++){
            if(gyongysor[i] == "voros"){
                if(gyongysor[i-1] != "kek" || gyongysor[i+1] != "kek"){
                    kiir(gyongysor);
                    return;
                }
            }
        }


    }

    for(int i=0; i<5; i++)
    {
        if(lehet(gyongysor,szinek[i]))
        {
            vector<string>tempgyongysor;
            for(int j=0; j<gyongysor.size(); j++)
            {
                tempgyongysor.push_back(gyongysor[j]);
            }
            tempgyongysor.push_back(szinek[i]);
            backtrack(tempgyongysor);
        }
    }
}
int main()
{

    vector<string>gyongysor;

    backtrack(gyongysor);


    return 0;
}
