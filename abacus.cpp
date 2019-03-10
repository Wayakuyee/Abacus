// Ted Lamson Liu
// Abacus display calculator
// March 10, 2019 @ TerribleHacks XIII

// Abacus reference used: https://www.wikihow.com/Use-an-Abacus

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{

  int x = 0;
  cout << "Please enter your first number: ";
  cin >> x;
  int y = 0;
  cout << "Please enter your second number: ";
  cin >> y;
  char op;
  cout << "Please enter the operation you want to perform: " << endl;
  cout << "('a' for addition, 's' for subtraction, 'm' for multiplication, 'd' for division) ";
  cin >> op;

  // Default answer
  int answer = 69;
  int r = 0;


  // Calculate the answer
  if(op == 'a'){
    answer = x + y;
  }
  else if(op == 's'){
    answer = x - y;
  }
  else if(op == 'm'){
    answer = x * y;
  }
  else if(op == 'd'){
    answer = x / y;
    r = x % y;
  }

  // Maybe add user input for abacus size/digits
  int digits = 7;
  int rows = 10;
  cout << "How many digits would you like? ";
  cin >> digits;
  cout << endl;

  // int lim = pow(2,63);

  // Default 2D array for abacus
  // True (1) is no bead, False (0) is bead
  bool M[10][digits];

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

  // cout << "Answer: " << answer << endl;
  // cout << "Limit: " << pow(10,digits) << endl;

  // Figure out what the abacus will print out
  // Check if abacus is big enough
  if(answer < pow(10,digits) && answer >= 0){
    int j = digits - 1;

    // Evaluate abacus by column starting with least significant digit
    while(answer > 0){
/*      int digit = 1;
      for(int k = 0; k < digits - j; k++){
        digit = digit * 10;
      }

      cout << "Digit: " << digit << endl;
*/
      int remainder = answer % 10;
      answer = answer / 10;

      // cout << "Remainder: " << remainder << endl;
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

    if (answer >= pow(10,digits)){

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
    else if(answer < 0){

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

    return 0;
  }

  // Print the abacus

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

  // Remainder for division
  if(r){
    cout << "Remainder: " << r << endl;
  }

  cout << endl;
  cout << "Thank you for using abacus calculator!" << endl;

/*
  // Debug version
  for(int i = 0; i < rows; i++){
    cout << "[";
    if(i == 2){
      for(int j = 0; j < digits; j++){
        cout << "~";
      }
      cout << "]" << endl;
      cout << "[";
    }
    for(int j = 0; j < digits; j++){
      cout << M[i][j];
    }
    cout << "]" << endl;
  }

  // Print the abacus
  for(int i = 0; i < digits + 2; i++){
    cout << "~";
  }

  cout << endl;

  for(int row = 0; row < beads*2; row++){
    cout << "[";

    if(row == 0){
      for(int i = 0; i < digits; i++){
        cout << "O";
      }
    }
    else if(row == 1){
      for(int i = 0; i < digits; i++){
        cout << "|";
      }

      cout << "]" << endl;
      cout << "[";

      for(int i = 0; i < digits; i++){
        cout << "~";
      }
    }
    else if(row >= 2 && row <= 5){
      for(int i = 0; i < digits; i++){
        cout << "|";
      }
    }
    else if(row >= 6 && row <= 9){
      for(int i = 0; i < digits; i++){
        cout << "O";
      }
    }
    cout << "]" << endl;
  }

  for(int i = 0; i < digits + 2; i++){
    cout << "~";
  }

  cout << endl;

  cout << x << " " << op << " " << y << " = " << answer << endl;
*/
  return 0;

}
