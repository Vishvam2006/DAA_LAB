#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int length(int a)
{
    return to_string(a).length();
}

int maxVal(int a, int b)
{
    return (a > b) ? a : b;
}

int dcMultiplication(int a, int b)
{
    if (a < 10 || b < 10)
    {
        return a * b;
    }
    int n = maxVal(length(a), length(b));
    int half = n / 2;
    int p10 = (int)pow(10, half);
    int w = a / p10;
    int x = a % p10;
    int y = b / p10;
    int z = b % p10;

    int p = dcMultiplication(w, y);
    int q = dcMultiplication(x, z);
    int r = dcMultiplication(w + x, y + z);
    int s = r - p - q;

    return p * pow(10, 2 * half) + s * pow(10, half) + q;
}

int main()
{

    cout << dcMultiplication(198, 234); 

    return 0;
}