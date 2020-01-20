// C++ Code to implement the Hash Table as a Spell Checker

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// Searcher is used to store the word whose spelling is to be checked or which is to be found in the table
string searcher;

// Function to implement Linear Probing
int linearProbe(string[], int, int);

// Function to implement quadratic probing
int quadProbe(string[], int, int);
int main()
{
  // Variable to choose linear or quadratic probing
  int choice = 0;

  cout << "Enter the choice of the probing technique:\t 1: Linear Probing\t 2: Quadratic Probing" << endl;

  cin >> choice;
  // Initially starting with a hastable of size 53 as required by the problem definition
  int tablesize = 53;

  // The Start label is used to rehash the words again in case the load factor increases beyond 0.5
start:

  // The Hash Table by the name table, with a size of tablesize
  string table[tablesize];
  int s = 0;
  int sz = 0;

  // Variable to store the number of collisions
  int collisions = 0;

  // Variable which probes the table incase of a collision
  int location = 0;

  // File operation variable to read from the file
  ifstream f;
  int count = 0;
  // Varible to calculate the load factor
  double fac = 0;
  // Getting the currentWord from the file
  string currWord;

  // Opening the file containing all the 100 words as required
  f.open("words.txt");

  // Run the loop until the end of file is not reached
  while (f >> currWord)
  {

    // The Hash Function, calculates the key of each word by multiplying each ASCII value with it's location

    // Eg: in "abc": Hash Function: (Ascii(a) * 0 + Ascii(b) * 1 + Ascii(c) * 2 )
    for (int i = 0; i < currWord.length(); i++)
    {
      // Calculating the value of key for each word
      s += int(currWord[i]) * (i);
    }

    // Checking For collision of the word
    if (table[s % tablesize].length() > 0)
    {
      // Calculating the total number of collisions
      collisions += 1;
      if (choice == 1)
      {
        // Linear Probing for collision resolution
        location = linearProbe(table, s % tablesize, tablesize);
      }

      else if (choice == 2)
      {
        // Quadratic Probing for collision resolution
        location = quadProbe(table, s % tablesize, tablesize);
      }
    }
    else
    {
      // If No collision, Just add the word at the location, Key Modulo TableSize
      location = s % tablesize;
    }

    // Store the word at the location after probing
    table[location] = currWord;

    // Increase the number of words stored in table to calculate load factor
    count++;

    // Calculate Load Factor
    fac = static_cast<double>(count) / static_cast<double>(tablesize);

    if (fac > 0.5)
    {

      cout << "The Load Factor has exceeded 0.5" << endl;
      cout << "-------------------------------------------------------" << endl;

      cout << "Increasing the Table size" << endl;
      cout << "-------------------------------------------------------" << endl;
      tablesize = tablesize * 2;

      cout << "New Table Size is: " << tablesize << endl;
      f.close();
      cout << "-------------------------------------------------------" << endl;
      cout << "Rehashing all words again" << endl;
      cout << "-------------------------------------------------------" << endl;
      goto start;
    }

    s = 0;
  }

  // for (int j = 0; j < tablesize; j++)
  // {
  //   cout << table[j] << endl;
  // }

  if (choice == 1)
  {
    cout << "Number of Collisions in Linear Probing is:" << collisions << endl;
    cout << endl;
  }
  else
  {
    cout << "Number of Collisions in Quadratic Probing is:" << collisions << endl;
    cout << endl;
  }

  cout << "Final TableSize:" << tablesize << endl;
  cout << endl;

  // Varible to store the number of words you want to search/check
  int n1 = 0;
  cout << "Enter the number of words you want to search in the table" << endl;
  cin >> n1;
  while (n1 >= 0)
  {
    sz = 0;
    cout << "Enter a Word to search:" << endl;
    getline(cin, searcher);

    // Calculating the hash key for the word entered
    for (int i = 0; i < searcher.length(); i++)
    {
      sz += int(searcher[i]) * (i);
    }

    // Searching the table
    if (table[sz % tablesize] == searcher)
    {
      cout << "Your Word is in the table" << endl;
      cout << "The Spelling for the word you entered is correct" << endl;
      cout << endl;
    }
    else
    {
      // Else It may have happened that the word would have suffered a collision and would have been probed
      int y = sz;
      int qaz = 1;

      // Doing a quadratic probe for a maximum number of 20 successive collisions
      if (choice == 2)
      {

        while (qaz != 20)
        {
          y = sz + pow(qaz, 2);
          if (table[y % tablesize] == searcher)
          {
            cout << "Found the word, it is spelled correctly but suffered a collision" << endl;
            goto next;
          }
          else
          {
            qaz++;
          }
        }
        cout << "Your word is either not in the table or spelled incorrectly" << endl;

      next:

        n1--;
      }

      if (choice == 1)
      {
        int y = sz;
        int qaz = 1;

        // If linearly probed, the word has be within the next blank entry of the table
        while (table[y % tablesize].length() > 0)
        {
          y++;
          if (table[y % tablesize] == searcher)
          {
            cout << "Found the word, it is spelled correctly but suffered a collision" << endl;
            goto next1;
          }
        }

        cout << "Your word is either not in the table or spelled incorrectly" << endl;

      next1:

        n1--;
      }
    }
  }
}

int linearProbe(string table[], int i, int n)
{

  // Function to implement linear probing
  while (table[i].length() > 0)
  {
    i++;
    if (i > n)
    {
      i = i % n;
    }
  }
  return (i % n);
}

int quadProbe(string table[], int i, int n)
{
  int sq = 1;
  int j = i;
  // Function to implement Quadratic probing
  while (table[j].length() > 0)
  {
    j = i + pow(sq, 2);

    if (j > n)
    {
      j = j % n;
    }
    sq++;
  }
  return ((i + (sq * sq)) % n);
}
