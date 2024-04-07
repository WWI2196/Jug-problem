#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int x, int y);

int gcd(int x, int y) { 
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}

int main()
{
    int first_jug, second_jug, target;

    cout << "Enter the capacity of the first jug : " << endl;
    cin >> first_jug;

    cout << "Enter the capacity of the second jug : " << endl;
    cin >>  second_jug;

    cout << "Enter the target amount of water : " << endl;
    cin >> target;

    if (first_jug > second_jug) {
        swap(first_jug, second_jug);
    }
   

    return 0;
}

