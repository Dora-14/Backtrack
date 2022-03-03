#include<iostream>
#include<vector>
using namespace std;
int N=4;
string szinek[]= {"voros", "kék", "rózsaszín", "narancs", "zold"};
bool lehet(vector<string>gyongyok, string ujszin)
{
    for(int i=0; i<gyongyok.size(); i++)
    {
        if(ujszin==gyongyok[i])
        {
            return false;
        }
    }
    if(gyongyok.size() > 1 && gyongyok[0]!="narancs" )
    {
        return false;
    }
    return true;
}
void kiir(vector<string>gyongyok)
{
    for(int i=0; i<gyongyok.size(); i++)
    {
        cout << gyongyok[i] << " ";
    }
    cout << endl;
    return;

}
void backtrack(vector<string>gyongyok)
{
    if(gyongyok.size()==N)
    {

        if(gyongyok[N-1]=="zold" )
        {

            kiir(gyongyok);

        }

        return;
    }


    for(int i=0; i<5; i++)
    {
        if(lehet(gyongyok,szinek[i]))
        {
            vector<string>tempgyongyok;
            for(int j=0; j<gyongyok.size(); j++)
            {
                tempgyongyok.push_back(gyongyok[j]);
            }
            tempgyongyok.push_back(szinek[i]);
            backtrack(tempgyongyok);
        }
    }
}
int main()
{

    vector<string>gyongyok;
    backtrack(gyongyok);



    return 0;
}
