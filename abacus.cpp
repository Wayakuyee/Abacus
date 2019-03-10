// Ted Lamson Liu
// Abacus display calculator
// March 10, 2019 @ TerribleHacks XIII

// DISCLAIMER: Only handles 2 error cases, answer too big for specified abacus or negative numbers, doesn't deal with overflow
// This code would be way more efficient if I knew how to pass a 2D array into a function

// Abacus reference used: https://www.wikihow.com/Use-an-Abacus
// ASCII abacus adapted from Christopher Johnson's ASCII Art Collection https://asciiart.website/index.php?art=objects/abacus

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
  // User input for abacus size/digits
  int digits = 7;
  int rows = 10;
  cout << "How many digits would you like on your abacus? ";
  cin >> digits;

  int x = 0;
  cout << "Please enter your first number: ";
  cin >> x;
  int y = 0;
  cout << "Please enter your second number: ";
  cin >> y;
  char op;
  cout << "Please enter the operation you want to perform: " << endl;
  cout << "('a' for addition, 's' for subtraction, 'm' for multiplication, 'd' for division, 'e' for exponent x^y) ";
  cin >> op;

  // Default answer
  int answer = 69;
  int r = 0;

  // Calculate the answer
  if(op == 'a'){
    answer = x + y;
    op = '+';
  }
  else if(op == 's'){
    answer = x - y;
    op = '-';
  }
  else if(op == 'm'){
    answer = x * y;
    op = '*';
  }
  else if(op == 'd'){
    answer = x / y;
    op = '/';
    r = x % y;
  }
  else if(op == 'e'){
    answer = pow(x,y);
    op = '^';
  }

  // Default 2D array for abacus
  // True (1) is no bead, False (0) is bead
  bool M[10][digits];
  int num = x;
  int count = 0;

  // cout << "x=" << x << "  y=" << y << " answer=" << answer << endl;

  //////////////////////////////////////////
  //
  // Massive loop to process input and print abacus
  //

  while(count < 3 || (count == 3 && r != 0)){

    // cout << "Number: " << num << endl;
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < digits; j++){
        M[i][j] = false;
      }
    }

    for(int j = 0; j < digits; j++){
      M[1][j] = true;
    }

    for(int i = 2; i < 6; i++){
      for(int j = 0; j < digits; j++){
        M[i][j] = true;
      }
    }

    // Figure out what the abacus will print out
    // Check if abacus is big enough
    if(num < pow(10,digits) && num >= 0){
      int j = digits - 1;

      // Evaluate abacus by column starting with least significant digit
      while(num > 0){
        int remainder = num % 10;
        num = num / 10;

        // Change values in the column
        if(remainder){
          // Upper beads, 4/5 exchange
          if(remainder / 5){
            M[0][j] = true;
            M[1][j] = false;
            remainder = remainder - 5;
          }

          // Lower beads
          int i = 2;
          while(remainder){
            M[i][j] = false;
            M[i + 4][j] = true;
            remainder = remainder - 1;
            i++;
          }
        }
        j--;
      }
    }

    // Else print "2 big" if too big
    else {

      int digitsv2 = 20;
      bool N[10][digitsv2];

      for(int i = 0; i < rows; i++){
        for(int j = 0; j < digitsv2; j++){
          N[i][j] = true;
        }
      }

      if (num >= pow(10,digits)){

        // "2"
        N[3][0] = false;
        N[2][1] = false;
        N[2][2] = false;
        N[3][3] = false;
        N[4][3] = false;
        N[5][2] = false;
        N[6][2] = false;
        N[7][1] = false;
        N[8][0] = false;
        N[9][0] = false;
        N[9][1] = false;
        N[9][2] = false;
        N[9][3] = false;

        // "B"
        for(int i = 2; i < rows; i++){
          N[i][7] = false;
        }
        N[2][8] = false;
        N[2][9] = false;
        N[3][10] = false;
        N[4][10] = false;
        N[5][9] = false;
        N[5][8] = false;
        N[6][10] = false;
        N[7][10] = false;
        N[8][10] = false;
        N[9][9] = false;
        N[9][8] = false;

        // "I"
        for(int i = 2; i < rows; i++){
          N[i][13] = false;
        }
        N[2][12] = false;
        N[2][14] = false;
        N[9][12] = false;
        N[9][14] = false;

        // "G"
        N[3][19] = false;
        N[2][18] = false;
        N[2][17] = false;
        N[3][16] = false;
        N[4][16] = false;
        N[5][16] = false;
        N[6][16] = false;
        N[7][16] = false;
        N[8][16] = false;
        N[9][17] = false;
        N[9][18] = false;
        N[9][19] = false;
        N[8][19] = false;
        N[7][19] = false;
        N[6][19] = false;
        N[6][18] = false;
      }

      // Print "-ve" if the answer is negative
      else if(num < 0){

        // "-"
        for(int i = 5; i < 7; i++){
          for(int j = 1; j < 7; j++){
            N[i][j] = false;
          }
        }

        // "v"
        N[5][8] = false;
        N[6][8] = false;
        N[7][9] = false;
        N[8][9] = false;
        N[9][10] = false;
        N[5][12] = false;
        N[6][12] = false;
        N[7][11] = false;
        N[8][11] = false;

        // "e"
        N[9][17] = false;
        N[9][16] = false;
        N[9][15] = false;
        N[8][14] = false;
        N[7][14] = false;
        N[6][14] = false;
        N[5][15] = false;
        N[5][16] = false;
        N[6][17] = false;
        N[7][17] = false;
        N[6][17] = false;
        N[7][16] = false;
        N[7][15] = false;
      }

      // Print the abacus
      cout << endl;
      cout << " ";
      for(int j = 0; j <= digitsv2; j++){
        cout << "___";
      }
      cout << endl;

      cout << "/";
      for(int j = 0; j <= digitsv2; j++){
        cout << "___";
      }
      cout << "\\" << endl;

      // Rows
      for(int i = 0; i < rows; i++){
        cout << "| |";
        if(i == 2){
          for(int j = 0; j < digitsv2; j++){
            cout << "~~~";
          }
          cout << "| |" << endl;
          cout << "| |";
        }
        for(int j = 0; j < digitsv2; j++){
          if(N[i][j] == true){
            cout << " | ";
          }
          else if(N[i][j] == false){
            cout << "(_)";
          }
        }
        cout << "| |" << endl;
      }

      // Bottom frame
      cout << "\\";
      for(int j = 0; j <= digitsv2; j++){
        cout << "___";
      }
      cout << "/" << endl;

      cout << endl;
      cout << "Abacus calculator doesn't like that number, sorry" << endl;
      cout << endl;

      return 0;
    }

    //////////////////////////////////////////////
    //
    // Print the abacus
    //

    // Top frame
    cout << " ";
    for(int j = 0; j <= digits; j++){
      cout << "___";
    }
    cout << endl;

    cout << "/";
    for(int j = 0; j <= digits; j++){
      cout << "___";
    }
    cout << "\\" << endl;

    // Rows
    for(int i = 0; i < rows; i++){
      cout << "| |";
      if(i == 2){
        for(int j = 0; j < digits; j++){
          cout << "~~~";
        }
        cout << "| |" << endl;
        cout << "| |";
      }
      for(int j = 0; j < digits; j++){
        if(M[i][j] == true){
          cout << " | ";
        }
        else if(M[i][j] == false){
          cout << "(_)";
        }
      }
      cout << "| |" << endl;
    }

    // Bottom frame
    cout << "\\";
    for(int j = 0; j <= digits; j++){
      cout << "___";
    }
    cout << "/" << endl;

    cout << endl;

    // Repeat loop if necessary
    if(count == 0){
      num = y;
      cout << op << endl;
    }
    else if(count == 1){
      num = answer;
      cout << "=" << endl;
    }
    else if(count == 2 && r != 0){
      num = r;
      cout << "Remainder: " << endl;
    }

    cout << endl;
    count++;
  }

  cout << "Thank you for using abacus calculator!" << endl;
  cout << endl;

  return 0;

}
