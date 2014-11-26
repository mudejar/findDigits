#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int numDigits(int n) {
    if (n < 0) return numDigits((n == INT_MIN) ? INT_MAX : -n);
    if (n < 10) return 1;
    return 1 + numDigits(n / 10);
}

int getCurrentDigit(int number, int digitPlace) {
    int currentDigit = number / digitPlace;
    currentDigit = currentDigit % 10;
    return currentDigit;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    // read in number of test cases
    int numTestCases;
    cin >> numTestCases;
    
    // read intput and store in array of int: N
    int N[numTestCases];
    for (int i = 0; i < numTestCases; i++) {
      cin >> N[i];
    }
   
    // iterate through array of test cases
    for (int j = 0; j < numTestCases; j++) {
      int digits = numDigits(N[j]); // number of digits
      
      // scan each digit in the number
      int digitsThatDivide = 0;
        
      for (int i = 0; i < digits; i++) {
   
          int digitPlace = (int)pow(10, i);
          int currentDigit = getCurrentDigit(N[j], digitPlace); // current digit
         
          // if the digit can divide N increment the number of digits that divide
          if (currentDigit != 0) {
                if (N[j] % currentDigit == 0) digitsThatDivide++;
          }
      }
      cout << digitsThatDivide << endl;
    }
    
    return 0;
}

