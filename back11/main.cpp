#include <iostream>
#include <vector>

using namespace std;

int M =3;

string edessegek[] = {"csokigolyo", "karamella", "drazse", "nyaloka"};

bool lehet(vector<string> doboz, string ujedesseg)
{
    for(int i=0; i<doboz.size(); i++)
    {
        if(ujedesseg == doboz[i])
        {
            return false;
        }
    }
    if(ujedesseg == "drazse")
    {
        for(int i=0; i<doboz.size(); i++)
        {
            if(doboz[i] == "nyaloka")
            {
                return false;
            }
        }
    }
    if(ujedesseg == "nyaloka")
    {
        for(int i=0; i<doboz.size(); i++)
        {
            if(doboz[i] == "drazse")
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

    for(int i=0; i<4; i++)
    {
        if(lehet(doboz,edessegek[i]))
        {
            vector<string>tempdoboz;
            for(int j=0; j<doboz.size(); j++)
            {
                tempdoboz.push_back(doboz[j]);
            }
            tempdoboz.push_back(edessegek[i]);
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
