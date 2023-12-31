//  Project description
//  Your Name
//  Date starts the project

#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

int binary_to_decimal(string s);
// precondition: s is a string that consists of only 0s and 1s
// postcondition: the positive decimal integer that is represented by s

string decimal_to_binary(int n);
// precondition: n is a positive integer
// postcondition: n’s binary representation is returned as a string of 0s and 1s

string add_binaries(string b1, string b2);
// precondition: b1 and b2 are strings that consists of 0s and 1s, i.e.
//               b1 and b2 are binary representations of two positive integers
// postcondition: the sum of b1 and b2 is returned. For instance,
//  if b1 = “11”, b2 = “01”, then the return value is “100”

void menu();
// display the menu. Student shall not modify this function

int grade();
// returns an integer that represents the student’s grade of this projects.
// Student shall NOT modify

bool is_binary(string b);
// returns true if the given string s consists of only 0s and 1s; false otherwise

bool test_binary_to_decimal();
// returns true if the student’s implementation of binary_to_decimal function
// is correct; false otherwise. Student shall not modify this function

bool test_decimal_to_binary();
//  returns true if the student’s implementation of decimal_to_binary function is correct; false otherwise. Student shall not modify this function

bool test_add_binaries();
// which returns true if the student’s implementation of add_binaries function
// is correct; false otherwise. Student shall not modify this function


int main()
{
    int choice;
    string b1, b2;
    int x, score;
    do{
        // display menu
        menu();
        cout << "Enter you choice: ";
        cin >> choice;
        // based on choice to perform tasks
        switch(choice){
            case 1:
                cout << "Enter a binary string: ";
                cin >> b1;
                if(!is_binary(b1))
                    cout << "It is not a binary number\n";
                else
                    cout << "Its decimal value is: " << binary_to_decimal(b1) << endl;
                break;

            case 2:
                cout << "Enter a positive integer: ";
                cin >> x;
                if(x <= 0)
                    cout << "It is not a positive integer" << endl;
                else
                    cout << "Its binary representation is: " <<decimal_to_binary(x) << endl;
                break;

            case 3:
                cout << "Enter two binary numbers, separated by white space: ";
                cin >> b1 >> b2;
                if(!is_binary(b1) || !is_binary(b2))
                    cout << "At least one number is not a binary" << endl;
                else
                    cout << "The sum is: " << add_binaries(b1, b2) << endl;
                break;

            case 4:
                score = grade();
                cout << "If you turn in your project on blackboard now, you will get " << score << " out of 10" << endl;
                cout << "Your instructor will decide if one-two more points will be added or not based on your program style, such as good commnets (1 points) and good efficiency (1 point)" << endl;
                break;

            case 5:
                cout << "Thanks for using binary calculator program. Good-bye" << endl;
                break;
            default:
                cout << "Wrong choice. Please choose 1-5 from menu" << endl;
                break;
        }

    }while(choice != 5);
    return 0;
}

int binary_to_decimal(string s){
    int dec = 0;        // decimal int
    int bin = stoi(s);  // binary int = convert string s to int
    int remainder = 0;  // remainder from modulo
    if(bin == 0) {      // 0 in binary is also 0 in decimal
        return 0;
    }
    for(int i = 0;i < s.length();i++) { // for loop increasing int i to string s.length because the length of a binary string - 1 is the highest power of 2 in the binary string
        remainder = bin % 10;           // remainder from binary int modulo 10 (since decimal is base 10) which will be either 0 or 1
        dec += remainder * pow(2,i);    // multiply remainder by 2^i and add to decimal int
        bin = bin / 10;                 // divide binary int by 10 to move to the next binary value i.e. *(1(one's place) > 0(ten's place) > 1(hundred's place) > etc.)
    }
    return dec;
}

string decimal_to_binary(int n){
    int bin = 0;        // binary int
    int remainder = 0;  // remainder from modulo
    if(n == 0) {        // 0 in decimal is also 0 in binary
        return "0";
    }
    for(int i = 1;n != 0;i = i * 10) {  // for loop incrementing i by multiples of 10 to place binary values until n = 0
        remainder = n % 2;              // remainder from decimal n modulo 2 (since binary is base 2) which will be either 0 or 1
        bin += remainder * i;           // multiply remainder by i and add to binary int
        n = n / 2;                      // divide n by 2 to move to the next binary value i.e. (2^4(16) > 2^3(8) > 2^2(4) > etc.)
    }
    return to_string(bin);              // return binary int as string
}

string add_binaries(string b1, string b2){
    int a = binary_to_decimal(b1);  // convert string b1 to decimal as int a
    int b = binary_to_decimal(b2);  // convert string b2 to decimal as int b
    int c = a + b;                  // int c = sum of a and b
    return decimal_to_binary(c);    // return binary string of c
}                                   // could also make this 1 line (return decimal_to_binary(binary_to_decimal(b1) + binary_to_decimal(b2))) but harder to comment on the steps

void menu()
{
    cout << "******************************\n";
    cout << "*          Menu              *\n";
    cout << "* 1. Binary to Decimal       *\n";
    cout << "* 2. Decinal to Binary       *\n";
    cout << "* 3. Add two Binaries        *\n";
    cout << "* 4. Grade                   *\n";
    cout << "* 5. Quit                    *\n";
    cout << "******************************\n";
}

int grade(){
    int result = 0;
    // binary_to_decimal function worth 3 points
    if(test_binary_to_decimal()){
        cout << "binary_to_decimal function pass the test" << endl;
        result += 3;
    }
    else
        cout << "binary_to_decimal function failed" << endl;

    // decinal_to_binary function worth 2 points
    if(test_decimal_to_binary()){
        cout << "decimal_to_binary function pass the test" << endl;
        result += 2;
    }
    else
        cout << "decimal_to_binary function failed" << endl;
    // add_binaries function worth 3 points
    if(test_add_binaries()){
        cout << "add_binaries function pass the test" << endl;
        result += 3;
    }
    else
        cout << "add_binaries function pass failed" << endl;
    return result;
}

bool is_binary(string s){
    for(int i = 0; i < s.length(); i++)
        if(s[i] != '0' && s[i] != '1') // one element in s is not '0' or '1'
            return false;  // then it is not a binary nunber representation
    return true;
}

bool test_binary_to_decimal(){
    if(binary_to_decimal("0") != 0 || binary_to_decimal("1") != 1)
        return false;
    if(binary_to_decimal("010") != 2 || binary_to_decimal("10") != 2)
        return false;
    if(binary_to_decimal("01101") != 13 || binary_to_decimal("1101") != 13)
        return false;
    return true;
}

bool test_decimal_to_binary(){
    if(decimal_to_binary(0) != "0" || decimal_to_binary(1) != "1")
        return false;
    if(decimal_to_binary(2) != "10" || decimal_to_binary(13) != "1101")
        return false;
    return true;
}

bool test_add_binaries(){
    if(add_binaries("0", "0") != "0") return false;
    if(add_binaries("0", "110101") != "110101") return false;
    if(add_binaries("1", "110111") != "111000") return false;
    if(add_binaries("101", "111011") != "1000000") return false;
    return true;
}