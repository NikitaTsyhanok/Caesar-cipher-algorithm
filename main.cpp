#include <iostream>
#include <string>

using namespace std;

string caesarEncrypt(const string& text, int shift) {
    string result = text;
    shift = shift % 26;

    for (int i = 0; i < result.length(); i++) {
        char c = result[i];

        if (c >= 'A' && c <= 'Z') {
            result[i] = 'A' + (c - 'A' + shift + 26) % 26;
        }
        else if (c >= 'a' && c <= 'z') {
            result[i] = 'a' + (c - 'a' + shift + 26) % 26;
        }
    }
    return result;
}

string caesarDecrypt(const string& text, int shift) {
    return caesarEncrypt(text, -shift);
}

int main() {
    string text;
    int shift;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the offset: ";
    cin >> shift;

    cout << "Encrypted text: "
        << caesarEncrypt(text, shift) << endl;

    cout << "Decoded text: "
        << caesarDecrypt(caesarEncrypt(text, shift), shift) << endl;

    return 0;
}
