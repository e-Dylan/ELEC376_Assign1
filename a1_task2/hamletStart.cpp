// Dylan Smith, 20265570
// ELEC376 Assignment 1

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
  // open file
  ifstream inputFile("hamlet.txt"); // Open the text file named "test.txt" for reading

  // call function to find the word provided by the user
  string userWord = "";
  cout << endl;
  cout << "Hi there! this outputs the number of times" << endl
       << "a word appears in Hamlet by William Shakespeare" << endl;
  cout << endl;
  cout << "Please enter the word to search for:" << endl;
  cin >> userWord;

  // check file is successfully open

  if (inputFile.is_open())
  {
    string line;
    int totalWordCount = 0;
    int wordCount = 0;

    // loop over every line in the file
    while (getline(inputFile, line))
    {
      stringstream ss(line);
      string word;

      while (ss >> word)
      {
        // convert both words to all lowercase to compare equality
        transform(word.begin(), word.end(), word.begin(), [](unsigned char c)
                  { return std::tolower(c); });
        transform(userWord.begin(), userWord.end(), userWord.begin(), [](unsigned char c)
                  { return std::tolower(c); });

        // increment total word count
        totalWordCount++;

        // if words match, increment counter
        if (word == userWord)
          wordCount++;
      }
    }

    // close file
    inputFile.close();

    // output to the console the total number of words searched, the word provided by the user and the number of occurrences of that word in the file
    cout << totalWordCount << " were searched and the word " << userWord << " was found " << wordCount << " times" << endl; // Outputting the total word count
  }
  else
  {
    cout << "Failed to open the file." << endl; // Display an error message if file opening failed
  }

  return 0; // Return 0 to indicate successful execution
}