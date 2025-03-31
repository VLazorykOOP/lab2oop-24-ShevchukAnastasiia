#include <iostream>
#include <fstream>

using namespace std;

void Decrypt(unsigned short data[64], char text[64]) {
    for (int i = 0; i < 64; i++) {
        unsigned short value = data[i];
        
        // Get character position (bits 0-5)
        int pos = value & 0x3F;
        
        // Get ASCII code (bits 7-14)
        text[pos] = (value >> 7) & 0xFF;
    }
    text[64] = '\0'; // Add null terminator
}

int main() {
    unsigned short encrypted[64];
    char decrypted[65];

    // Read encrypted data
    ifstream in("encrypted.bin", ios::binary);
    if (!in) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    in.read((char*)encrypted, sizeof(encrypted));
    in.close();

    // Decrypt
    Decrypt(encrypted, decrypted);

    cout << "Decrypted text:\n" << decrypted << endl;

    ofstream out("decrypted.txt");
    out << decrypted;
    out.close();

    cout << "Result saved to decrypted.txt" << endl;
    return 0;
}
