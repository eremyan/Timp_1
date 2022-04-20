pragma once
#include <iostream>
#include <string>
#include "RouteTableCipher.h"
#include <cctype>
using namespace std;
bool isValidkey(const int& skey)
{
    if(isdigit(skey))
        return true;
    else
        return false;

}

bool isValidText(string& open_text)
{
    for (auto w:open_text) {
        if(!isalpha(w))
            return false;
        return true;
    }
}
int main()
{
    int c;
    int key;
    string text;
    cout<<"Установите ключ: ";
    cin>>key;
    if (isValidkey(key)) {
        cerr<<"Ключ не валиден"<<endl;
    }
    cout<<"Ключ установлен"<<endl;
    RouteTableCipher cipher(key);
    do {
        cout<<"Введите 1 для зашифрования, 2 для расшифрования, 0 для выхода: ";
        cin>>c;
        if(c>2)
            cerr<<"Неверная операция"<<endl;
        else if(c>0) {
            cout<<"Введите текст:"<<endl;
            cin.get();
            getline(cin,text);
            if (isValidText(text)) {
                if(c==1) {
                    cout<<"Зашифрованный текст:"<<cipher.encrypt(text,key)<<endl;
                } else {
                    cout<<"Расшифрованный текст:"<<cipher.decrypt(text,key)<<endl;
                }
            } 
            else
                cout<<"Неверный текст"<<endl;
            
        }

    }
    while(c!=0);
    return 0;
}