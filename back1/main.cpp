#include <iostream>
#include <string>
#include <sstream>
int osszeg=10;
int megoldasokszama = 0;
int penzermek[] = {10, 5, 1};
int elegendo[] = {3,1, 5};
int N = 3;
using namespace std;
string megoldas = "";
/*
logikai fuggveny, amely megvizsgalja, hogy megvan e az adott osszeg
igazat terit vissza, ha igen
hamisat, ha nem
*/
bool egyenlo(int ideiglenesosszeg)
{
    if (ideiglenesosszeg == osszeg)
    {
        return true;
    }
    return false;
}
/*
logikai fuggveny, amely megvizsgalja,
hogy az adott penzermet hozza lehet e meg adni az ideiglenes osszeghez
igazat terit vissza, ha igen
hamisat, ha nem
*/
bool hozzaadhatom(int ideiglenesosszeg, int penzerme, int hanyvan)
{
    if (penzerme + ideiglenesosszeg > osszeg)
    {
        return false;
    }
    if (hanyvan < 1) {
        return false;
    }
    return true;
}

bool backtrack(int ideiglenesosszeg,int index, string megoldas, int eleg[])
{
    if(egyenlo(ideiglenesosszeg))
    {
        // kiir();
        megoldasokszama++;
        //cout << megoldasokszama << endl;
        //ideiglenesosszeg = 0;
        cout << megoldas << endl;
        //megoldas = "";
        //backtrack(ideiglenesosszeg,index+1);
        return 0;
    }

    for(int i=index; i<N; i++)
    {
        if (hozzaadhatom(ideiglenesosszeg, penzermek[i], eleg[i]))
        {
            ostringstream oss;
            oss  << penzermek[i] << " ";
            string tempmegoldas;
            tempmegoldas = megoldas;
            tempmegoldas += oss.str();
            int tempeleg[N];
            for(int k = 0; k<N; k++){
                tempeleg[k] = eleg[k];
            }
            tempeleg[i] --;
            int temposszeg = ideiglenesosszeg+penzermek[i];
            //megoldas.append(" ");
            backtrack(temposszeg, i, tempmegoldas, tempeleg);
        }
    }
    return 0;
}
int main()
{
    string megoldas = "";
    backtrack(0,0, megoldas, elegendo);
    cout << "a lehetseges megoldasok szama " << megoldasokszama;
    return 0;
}

