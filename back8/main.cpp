#include <iostream>
#include <vector>

using namespace std;

int N = 3;

string kremek[] = {"karamella", "csokolade", "tejszin", "dio", "vanilia"};

bool lehet(vector<string> torta, string ujkrem)
{
    for(int i=0; i<torta.size(); i++)
    {
        if(ujkrem == torta[i])
        {
            return false;
        }
    }
    if(ujkrem == "karamella"){
        for(int i=0; i<torta.size(); i++){
            if(torta[i] == "dio"){
                return false;
            }
        }
    }
    if(ujkrem == "dio"){
        for(int i=0; i<torta.size(); i++){
            if(torta[i] == "karamella"){
                return false;
            }
        }
    }
    return true;
}
void kiir(vector<string> torta)
{
    for(int i=0; i<torta.size(); i++)
    {
        cout << torta[i] << " ";
    }
    cout << endl;
    return;
}

void backtrack(vector<string> torta)
{

    if(torta.size() == N)
    {
        if(torta[0] != "tejszin" && torta[1] != "vanilia" && torta[0] != "vanilia" && torta[1] != "tejszin")
        {
            if(torta[N-1] == "tejszin" || torta[N-1] == "vanilia")
            {
                kiir(torta);
                return;
            }
        }
    }

    for(int i=0; i<5; i++)
    {
        if(lehet(torta,kremek[i]))
        {
            vector<string>temptorta;
            for(int j=0; j<torta.size(); j++)
            {
                temptorta.push_back(torta[j]);
            }
            temptorta.push_back(kremek[i]);
            backtrack(temptorta);
        }
    }
}
int main()
{

    vector<string>torta;
    backtrack(torta);


    return 0;
}
