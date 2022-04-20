#include "RouteTableCipher.h"
using namespace std;
RouteTableCipher::RouteTableCipher(const int& skey)
{
    key=skey;
}

string RouteTableCipher::encrypt(string& open_text, const int& skey)
{
    int height;
    if(open_text.length()%skey!=0) {
        height=open_text.length()/skey+1;
    } else {
        height=open_text.length()/skey;
    }
    char mass[height][skey];
    int k=0;
    for (int i=0; i<height; i++) {
        for (int j=0; j<skey; j++) {
            if (k<open_text.length()) {
                mass[i][j]=open_text[k];
                k++;
            } else
                mass[i][j]=' ';

        }

    }
    string cipher_text;
    for (int i=skey-1; i>=0; i--) {
        for (int j=0; j<height; j++) {
            cipher_text+=mass[j][i];
        }
    }
    return cipher_text;

}

string RouteTableCipher::decrypt(string& cipher_text, const int& skey)
{
    int height=cipher_text.length()/skey;
    char mass[skey][height];
    int k=0;
    for(int i=skey-1; i>=0; i--) {
        for(int j=0; j<height; j++) {
            mass[i][j]=cipher_text[k];
            k++;

        }
    }
    string decrypted_text;
    for(int i=0; i<height; i++) {
        for(int j=0; j<skey; j++) {
            decrypted_text+=mass[j][i];
        }
    }
    return decrypted_text;
}