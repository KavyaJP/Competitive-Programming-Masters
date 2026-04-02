#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Find number of bits
    int temp = n;
    int bits = 0;

    while (temp > 0)
    {
        bits++;
        temp >>= 1;
    }

    // Flip LSB
    n = n ^ 1;

    // Flip MSB
    if (bits > 0)
    {
        n = n ^ (1 << (bits - 1));
    }

    cout << n;

    return 0;
}