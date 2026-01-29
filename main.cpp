#include <iostream>
#include <string>

using namespace std;
const int abc = 26;


string caesarEncrypt(const string text, int shift) { 
    string result = text;
    shift = shift % abc;

    for (int i = 0; i < result.length(); i++) {
        char c = result[i];

        if (c >= 'A' && c <= 'Z') {
            result[i] = 'A' + (c - 'A' + shift + abc) % abc;
        }
        else if (c >= 'a' && c <= 'z') {
            result[i] = 'a' + (c - 'a' + shift + abc) % abc;
        }
    }
    return result;
}

string caesarDecrypt(const string text, int shift) {
    return caesarEncrypt(text, -shift);
}

int main() {
    string text;
    int shift;

    cout << "enter text: ";
    getline(cin, text);

    cout << "enter the offset: ";
    cin >> shift;

    cout << "Encrypted text: "
        << caesarEncrypt(text, shift) << endl;

    cout << "Decrypted text: "
        << caesarDecrypt(caesarEncrypt(text, shift), shift) << endl;

}
