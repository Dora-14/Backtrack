#include <iostream>
#include <vector>
using namespace std;
int N=3;
string szinek[]={"feher", "sarga", "fekete", "piros", "zold"};
bool lehet(vector<string>zaszlo, string ujszin){
   for(int i=0; i<zaszlo.size(); i++){
    if(ujszin==zaszlo[i]){
        return false;
    }
   }
   if(ujszin=="zold"){
    for(int i=0; i<zaszlo.size(); i++){
        if(zaszlo[i]=="fekete"){
            return false;
        }
    }
   }
 if(ujszin == "fekete")
    {
        for(int i=0; i<zaszlo.size(); i++)
        {
            if(zaszlo[i] == "zold")
            {
                return false;
            }
        }
    }
    return true;

}
void kiir(vector<string>zaszlo)
{
    for(int i=0; i<zaszlo.size(); i++)
    {
        cout << zaszlo[i] << " ";
    }
    cout << endl;
    return;
}
void backtrack(vector<string> zaszlo)
{

    if(zaszlo.size() == N)
    {
        kiir(zaszlo);
        return;
    }
    for(int i=0; i<3; i++)
    {
        if(lehet(zaszlo,szinek[i]))
        {
            vector<string>tempzaszlo;
            for(int j=0; j<zaszlo.size(); j++)
            {
                tempzaszlo.push_back(zaszlo[j]);
            }
            tempzaszlo.push_back(szinek[i]);
            backtrack(tempzaszlo);
        }
    }
}
int main()
{
    vector<string>zaszlo;
    backtrack(zaszlo);
    return 0;
}
