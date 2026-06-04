#include <iostream>
#include <string>
const int abc = 26;

std::string caesarEncrypt(const std::string& text, int shift) {
    std::string result = "";

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        char encryptedChar;

        if (c >= 'a' && c <= 'z') {
            encryptedChar = (c - 'a' + shift) % abc + 'a';
        }
        else if (c >= 'A' && c <= 'Z') {
            encryptedChar = (c - 'A' + shift) % abc + 'A';
        }
        else {
            encryptedChar = c;
        }

        result += encryptedChar;
    }

    return result;
}
int main() {
	std::string text;
	int shift;

	std::cout << "Enter text for encrypt" << std::endl;
	std::getline(std::cin, text);
	std::cout << "Enter shift key" << std::endl;
	std::cin >> shift;
	std::cout << "Encrypted text: " << caesarEncrypt(text, shift) << std::endl;

    while (true);
}
