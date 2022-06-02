#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int testCase, player;
    cin >> testCase;

    int maxPlayerPrice=0;
    string maxPlayerName="";
    string result="";

    for(int i =0; i<testCase; i++){
        cin >> player;
        int price =0;
        string name = "";
        maxPlayerPrice=0;
        for(int j=0; j<player; j++){
            cin >> price >> name;
            if(price>maxPlayerPrice){
             maxPlayerPrice = price;
             maxPlayerName = name;   
            }
        }
        result.append(maxPlayerName);
        result.append("\n");
    }
    cout<<result;
    
}