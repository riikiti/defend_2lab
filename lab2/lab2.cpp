#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;


class Vigenere {
private:
    int  abcSize = 128;
    string  abc = "";
    string key = "";
public:
    Vigenere() {
        // заполнили базовый алфавит
        for (int i = 128; i < 256; i++)
            abc += (char)i;
    }

    //dodelat file
    int modulo(int a, int b) {
        return a >= 0 ? a % b : (b - abs(a % b)) % b;
    }

    string setKey(string Tkey) {
        if (key.length() < 5) {
            key = "арбуз";
        }
        else {
            key = Tkey;
        }
        return key;
    }

    string getKey() {
        return key;
    }

    string encryptText(string text) {
        int len = text.length();
        int key_len = key.length();

        string e_text;
        for (int i = 0; i < len; i++)
            e_text += ((text[i] + key[i % key_len]) % abc.length());
        return e_text;
    }

    string decryptText(string text) {
        int len = text.length();
        int key_len = key.length();

        string d_text;
        for (int i = 0; i < len; i++)
            d_text += modulo(text[i] - key[i % key_len], abc.length());
        return d_text;
    }

};

template <typename T>
void file(string fileRead, string fileWrite, T code) {
    ifstream read(fileRead);
    string k = "", msg = "";
    while (getline(read, k))
        msg += k;
    read.close();

    ofstream write(fileWrite);
    if (fileWrite == "encrypt.txt")
        write << code.encryptText(msg);
    else
        write << code.decryptText(msg);
    write.close();
}






int main(int argc, char** argv) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string text = "arbuz2fs";
    string key = "privet";
    Vigenere vigenere;
    cout << "Введите текст" << endl;
    cin >> text;

    cout << "Введите ключ" << endl;
    cin >> key;

  
    vigenere.setKey(key);
    key = vigenere.getKey();

    cout << text << endl;
    file<Vigenere>("decrypt.txt", "encrypt.txt", vigenere);
    cout << vigenere.encryptText(text) << endl;
    file<Vigenere>("encrypt.txt", "decrypt.txt", vigenere);
    cout << vigenere.decryptText(vigenere.encryptText(text)) << endl;
  
}