#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <stdexcept> // Include for exceptions
#include "FileName.h"

using namespace std;

class Integral {
public:
    double result;
    int x1, x2;
    int formula;
    int n=1; // 1/n
    int s; // start value
    int f; // final value
	int startf; // final value in function;
	int starts; // initail value in function;
    double inte(int s, int f, int x) {
        if (s == f) {
            return false;
        }
        if (x < 1 || x > 4) {
            cout << "Error: Invalid formula , degree" << endl;
            return false;
        }

        // Calculate the integral based on the degree of x
		// if it was a number , then its intergral is x;
            x1 = s;
            x2 = f;
            if (x == 1) {
				formula = 2; //formula is the power.
            }
            else if (x == 2) {
                formula = 3;
            }
            else if (x == 3) {
                formula = 4;
            }
            else if (x == 4) {
				formula = 5;
            }
         // p is just a variable to delcrae the n value.
         // Divide by the appropriate factor based on the degree of x
            
           /* for (n = 1; n >= p; n++) {
                if ()
                    cout << "all good " << endl;
            }*/
            if (x == 1) {
					n=2;//n=2 
            }
            else if (x == 2) {
                    n=3; //n = 3
            }
            else if (x == 3) {
				n = 4; //n = 4
            }
            else if (x == 4) {
				n = 5; //n = 5
            }
            
            
		startf = pow(x2, formula);
		starts = pow(x1, formula);
		result = (startf + starts) / n; // x=1, ?^x =1, 2^2/2 + 4^2/2 = 10
        /*cout << "x1: " << x1 << ", x2: " << x2 << endl;
        cout << "formula: " << formula << ", n: " << n << endl;
        cout << "startf: " << startf << ", starts: " << starts << endl;*/
        return (s<f) ? result : -result;

    }
};

long double summation(int a, int b) {
    int choice;
    long long int k = 0; // k smaller than n, n is the end value (K<n).
    int n = b;

    cout << "What formula do you want?" << endl << "1. Linear\n2. Quadratic\n3. Cubic\n";
    cin >> choice;

    if (a == b) {
        return 0;
    }
    else {
        switch (choice) {
        case 1:
            k = (n * (n + 1)) / 2;
            break;
        case 2:
            k = (n * (n + 1) * (2 * n + 1)) / 6;
            break;
        case 3:
            k = pow((n * (n + 1)) / 2, 2);
            break;
        default:
            cout << "Error: Invalid formula" << endl;
            break;
        }
        return (a < b) ? k : -k;
    }
}

double sub(double a, double b) {
    return a - b;
}

double add(double a, double b) {
    return a + b;
}

double mul(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    if (b == 0) {
        throw invalid_argument("Error: Division by zero"); // Throw an exception
    }
    else {
        return a / b;
    }
}

int main() {
    try {
		// Display the menu and get the user's choice between FUNCTIONS AND SIMPLE MATH OPERATIONS.
        cout << "Select an operation number (1-6):" << endl;
        cout << "1. Subtraction" << endl;
        cout << "2. Addition" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Summation" << endl;
		cout << "6. limit" << endl; 
        cout << "7. Integral" << endl;
        double a, b;
        int operation;
        cin >> operation;
        cout << "Enter two numbers: " << endl;
            cin >> a >> b;
        
        if (operation == 5 || operation == 6) 
        {
          cout << "Enter \"first number\" as the beginning, smaller than the second number\n";
        }
        
       
        

        switch (operation) {
        case 1:
            cout << "Answer of Subtraction: " << sub(a, b) << endl;
            break;
        case 2:
            cout << "Answer of Addition: " << add(a, b) << endl;
            break;
        case 3:
            cout << "Answer of Multiplication: " << mul(a, b) << endl;
            break;
        case 4:
            cout << "Answer of Division: " << division(a, b) << endl;
            break;
        case 5:
            cout << "The answer of Summation: " << summation(a, b) << endl;
            break;
		case 6:
            cout << "the answer of limit: " << endl;
			break;
        case 7: {
            int s = static_cast<int>(a); // Convert double to int
            int f = static_cast<int>(b); // Convert double to int
            cout << "Enter the degree of x (1-4): ";
            int x;
            Integral integral;
            cin >> x;
            double result = integral.inte(s,f,x);
            cout << "The answer of Integral: " << result << endl;
            break;
        }
        default:
            cout << "Error: Invalid operation" << endl;
        }
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl; // Catch and display the exception message
    }

    return 0;
}

