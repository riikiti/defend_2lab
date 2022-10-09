﻿#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;



int modulo(int a, int b) {
    return a >= 0 ? a % b : (b - abs(a % b)) % b;
}

string encryptText(string text, string key) {
    int len = text.length();
    int key_len = key.length();
    string e_text;
    for (int i = 0; i < len; i++)
        e_text += ((text[i] + key[i % key_len]) % 128);
    return e_text;
}

string decryptText(string text, string key) {
    int len = text.length();
    int key_len = key.length();
    string d_text;
    for (int i = 0; i < len; i++)
        d_text += modulo(text[i] - key[i % key_len], 128);
    return d_text;
}

int main(int argc, char** argv) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string text = "helloiamruslan";
    string key = "water";

    string encrypted = encryptText(text, key);
    string decrypted = decryptText(encrypted, key);

    cout << text << std::endl;
    cout << encrypted << std::endl;
    cout << decrypted << std::endl;

    return 0;
}