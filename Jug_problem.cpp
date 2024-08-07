#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int x, int y);
bool isMultiple(int gcd_value, int target);
int printSolution(int smaller_jug, int larger_jug, int a, int b, int target);

int gcd(int x, int y) {
    return (x % y == 0 ? y : gcd(y, x % y));
}

bool isMultiple(int gcd_value,int target) {
	return (target % gcd_value == 0 ? true:false);
}

int printSolution(int smaller_jug,int larger_jug,int a,int b, int target){

    if (a == target || b == target) return 1;
    
    if (a == 0) a = smaller_jug;
    else if (b == larger_jug) b = 0;
    else {
        int pour_amount = min(a, larger_jug - b);
        a -= pour_amount;
        b += pour_amount;
    }

    cout << "->" <<"(" << a << "," << b << ")";
    printSolution(smaller_jug, larger_jug, a, b, target);

}

int main()
{
    int smaller_jug, larger_jug, target;

    cout << "Enter the capacity of the smaller jug : " << endl;
    cin >> smaller_jug;

    cout << "Enter the capacity of the larger jug : " << endl;
    cin >> larger_jug;

    cout << "Enter the target amount of water : " << endl;
    cin >> target;

    if (smaller_jug > larger_jug) {
        swap(smaller_jug, larger_jug);
    }

    if (isMultiple(gcd(smaller_jug, larger_jug), target)) {
        cout << "(" << 0 << "," << 0 << ")";
        printSolution(smaller_jug, larger_jug, 0, 0, target);
    }
    else
        cout << "\n-1" << endl;

    return 0;
}

