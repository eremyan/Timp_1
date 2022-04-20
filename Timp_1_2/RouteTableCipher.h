#pragma once
#include <string>
using namespace std;
class RouteTableCipher
{
private:
    int key;// ключ (число столбцов)
public:
    RouteTableCipher()=delete;
    RouteTableCipher(const int& skey); // конструктор для установки ключа
    string encrypt(string& open_text, const int& skey); // метод шифрования
   string decrypt(string& cipher_text, const int& skey); // метод расшифрования

};
