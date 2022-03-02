#include <iostream>
#include <vector>

using namespace std;

int M ;

string nyelvek[] = {"PHP", "Java", "Python", "C++", "MatLab"};

bool lehet(vector<string> kurzus, string ujnyelv)
{
    for(int i=0; i<kurzus.size(); i++)
    {
        if(ujnyelv == kurzus[i])
        {
            return false;
        }
    }
    if(ujnyelv == "Java")
    {
        for(int i=0; i<kurzus.size(); i++)
        {
            if(kurzus[i] == "Python")
            {
                return false;
            }
        }
    }
    if(ujnyelv == "Python")
    {
        for(int i=0; i<kurzus.size(); i++)
        {
            if(kurzus[i] == "Java")
            {
                return false;
            }
        }
    }
    return true;
}
void kiir(vector<string> kurzus)
{
    for(int i=0; i<kurzus.size(); i++)
    {
        cout << kurzus[i] << " ";
    }
    cout << endl;
    return;
}

void backtrack(vector<string> kurzus)
{
    if(kurzus.size() == M)
    {
        kiir(kurzus);
        return ;
    }

    for(int i=0; i<5; i++)
    {
        if(lehet(kurzus,nyelvek[i]))
        {
            vector<string>tempkurzus;
            for(int j=0; j<kurzus.size(); j++)
            {
                tempkurzus.push_back(kurzus[j]);
            }
            tempkurzus.push_back(nyelvek[i]);
            backtrack(tempkurzus);
        }
    }
}
int main()
{

    vector<string>kurzus;
    for(M=2; M<5; M++)
    {
        if(M%2==0)
        {
            backtrack(kurzus);
        }
    }

    return 0;
}
