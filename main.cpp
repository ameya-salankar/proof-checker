#include <iostream>
#include "start.h"

using namespace std;

int main(void)
{
    int c;
    char ch;

    cout << "Enter:\n1 for executing Part 1\n2 for executing Part 2\n>>> ";
    cin >> c;
    
    switch (c)
    {
        case 1:
            start_part1();
            break;
        case 2:
            start_part2();
            break;
        default:
            cout << "Invalid input, please try again" << endl;
    }

    return 0;
}
