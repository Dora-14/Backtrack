#include <iostream>
#include <vector>

using namespace std;

int M =5;

string iroszerek[] = {"toll", "golyostoll", "ceruza", "toltotoll","ecset"};

bool lehet(vector<string> doboz, string ujiroszer)
{
    for(int i=0; i<doboz.size(); i++)
    {
        if(ujiroszer == doboz[i])
        {
            return false;
        }
    }
    if(ujiroszer == "ceruza")
    {
        for(int i=0; i<doboz.size(); i++)
        {
            if(doboz[i] == "toltotoll" || doboz[i] == "golyostoll")
            {
                return false;
            }
        }
    }
    return true;
}
void kiir(vector<string> doboz)
{
    for(int i=0; i<doboz.size(); i++)
    {
        cout << doboz[i] << " ";
    }
    cout << endl;
    return;
}

void backtrack(vector<string> doboz)
{
    if(doboz.size() == M)
    {
        kiir(doboz);
        return ;
    }

    for(int i=0; i<5; i++)
    {
        if(lehet(doboz,iroszerek[i]))
        {
            vector<string>tempdoboz;
            for(int j=0; j<doboz.size(); j++)
            {
                tempdoboz.push_back(doboz[j]);
            }
            tempdoboz.push_back(iroszerek[i]);
            backtrack(tempdoboz);
        }
    }
}
int main()
{

    vector<string>doboz;

    backtrack(doboz);


    return 0;
}
