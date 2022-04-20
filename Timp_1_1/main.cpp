#pragma once
#include <iostream>
#include "modalphacipher.h"
#include <locale>
#include <cctype>
#include <string>
using namespace std;
bool isValid(const wstring& s)
{
    for(auto c:s)
        if (!iswupper(c) || !iswalpha(c))
            return false;
        return true;
}
int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring key;
    wstring text;
    unsigned op;
    wcout<<"Cipher ready. Input key: ";
    wcin>>key;
    if (!isValid(key)) {
        wcerr<<"key not valid\n";
        return 1;
    }
    wcout<<"Key loaded\n";
    modAlphaCipher cipher(key);
    do {
        wcout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        wcin>>op;
        if (op > 2) {
            wcout<<"Illegal operation\n";
        }
        else if (op >0) {
            wcout<<"Cipher ready. Input text: ";
            wcin>>text;
            if (isValid(text)) {
                if (op==1) {
                    wcout<<"Encrypted text: "<<cipher.encrypt(text)<<endl;
                } else {
                    wcout<<"Decrypted text: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                wcout<<"Operation aborted: invalid text\n";
               
            }
        }
    } while (op!=0);
    return 0;
}