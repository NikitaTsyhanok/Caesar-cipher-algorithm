#include <iostream>
#include <string>

const int abc = 26;

std::string caesarEncrypt(const std::string& text, int shift) {
    std::string result = "";

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        char encryptedChar;

        if (c >= 'a' && c <= 'z') {
            encryptedChar = ((c - 'a' + shift) % abc + abc) % abc + 'a';
        }
        else if (c >= 'A' && c <= 'Z') {
            encryptedChar = ((c - 'A' + shift) % abc + abc) % abc + 'A';
        }
        else {
            encryptedChar = c;
        }

        result += encryptedChar;
    }

    return result;
}


std::string caesarDecrypt(const std::string& text, int shift) {
    return caesarEncrypt(text, -shift);
}

int main() {
    std::string text;
    int shift;

    std::cout << "enter text: ";
    std::getline(std::cin, text);

    std::cout << "enter the offset: ";
    std::cin >> shift;

    std::string encrypted = caesarEncrypt(text, shift);
    std::cout << "Encrypted text: " << encrypted << std::endl;

    std::string decrypted = caesarDecrypt(encrypted, shift);
    std::cout << "Decrypted text: " << decrypted << std::endl;

    while (true);
}
