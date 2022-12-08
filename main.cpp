#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

  // int data[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
  int data[2236];

  string myText;
  int myCal;
  int maxCal = 0;
  int i = 0;
  int biggestElfCalories = 0;
  int iBiggestElf = 0;

  ifstream numFile("aoc22day1.text"); // reading from input file

  cout << "Welcome to Elf carrying calories!\n"; // read data from file (disk)
                                                 // to array (memory)
  while (getline(numFile, myText)) {             // Elf until empty line
    if (myText != "") {
      myCal =
          stoi(myText); // convert string to integer (for mathematical addition)
      maxCal += myCal;  // keep adding calories
      cout << myCal << endl; //
    } else {
      data[i] = maxCal; // when new line empty, record one Elf's all calories
      cout << "**** Elf " + to_string(i) << " = " << to_string(maxCal) << endl;

      // If current Elf calories higher than previous higest, then record it as
      // highest
      if (biggestElfCalories < maxCal) {
        biggestElfCalories = maxCal;
        iBiggestElf = i;
      }
      maxCal = 0;
      i++;
    }
  }
  // If Last Elf calories higher than previous higest, then record it as highest
  data[i] = maxCal;

  if (biggestElfCalories < maxCal) {
    // stor ELf and Total Calories
    biggestElfCalories = maxCal;
    iBiggestElf = i;
  }

  cout << "**** Elf " + to_string(i) << " = " << to_string(maxCal) << endl;
  cout << "biggestElf = " << to_string(iBiggestElf)
       << ", calories = " << biggestElfCalories;
  // cout << endl;
  // cout << data[239];
  // cout << endl;
  // cout << data[240];

  return 0;
}
