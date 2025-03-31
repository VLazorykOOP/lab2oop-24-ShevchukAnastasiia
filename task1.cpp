#include <iostream>

int main() {
    int a = 1, b = 2, c = 3, d = 4;

    int term1 = (b << 4) + b;                     // 17*b = 34
    int term2 = (a << 11) + (a << 9) + (a << 8) + 
                (a << 7) + (a << 6) + (a << 2);   // 3012*a = 3012
    int division_result = (term1 + term2) >> 5;   // (34 + 3012)/32 = 95
    int term3 = (c << 7) - (c << 3);              // c*120 = 360
    int term4 = (d << 7) - d;                      // d*127 = 508
    int result = division_result - term3 + term4;   

    std::cout << "Result: " << result << std::endl; 
    return 0;
}
