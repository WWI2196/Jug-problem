#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int x, int y);
bool isMultiple(int gcd_value, int target);
int printSolution(int smaller_jug, int larger_jug, int a, int b, int target);

int gcd(int x, int y) { 
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}

bool isMultiple(int gcd_value,int target) {
    if (target % gcd_value == 0)
        return true;
    else
        return false;
}

int printSolution(int smaller_jug,int larger_jug,int a,int b, int target){

    if (a == target || b == target) {
        cout << a << "," << b << endl;
        return 1;
    }
    
    if (a == 0) {
        a = smaller_jug;
        
    } 
    else if (b == larger_jug) {
        b = 0;

    }
    else {
        if (larger_jug - b >= a) {
            b += a;
            a = 0;
        }
        else {
            int c = b;
			b = b + a - (larger_jug - b);
            a = a - (larger_jug - c);

        }
    }

    cout << a << "," << b << endl;
    printSolution(smaller_jug, larger_jug, a, b, target);
}

int main()
{



    cout << "Enter the target amount of water : " << endl;
    cin >> target;

    }
   

    return 0;
}

