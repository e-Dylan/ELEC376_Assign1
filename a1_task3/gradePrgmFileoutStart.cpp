#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile( "QuizResponses.txt" );
    ofstream outputFile;

    outputFile.open("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open file 'output.txt' for writing." << std::endl;
        return 1; // Exit with error
    }

    // outputFile << "TEST!" << endl;
    // outputFile << "new line" << endl;
    outputFile << setw(6) << " " << "Employee Quiz Responses" << endl << endl;

    outputFile << setw(15) << std::left << "Employee ID" << setw(10) << "Score" << setw(15) << std::left << "Redo Quiz" << endl;
    outputFile << "-------------------------------------" << endl;

    vector<string> ids;
    vector<string> answers;

    int i = 0;
    string answerKey = "";
    for( string line; getline( inputFile, line ); )
    {
        if (line == "") continue;
        if (i == 0) {
            // first line, answer key
            answerKey = line;
            i++;
            continue;
        }


        if (i % 2 == 0) {
            // answers
            cout << "pushing answers: " << line << endl;
            answers.push_back(line);
        } else {
            // id number
            cout << "pushing ids: " << line << endl;
            ids.push_back(line);
        }

        i++;
    }

    // keep iterator i to index parallel vector ids and answers in same loop
    i = 0;
    for (string str : ids) {
        outputFile << std::left << setw(2) << i+1 << std::left << setw(15) << ids[i] << setw(11) << 0 << setw(15) << std::left << "yes" << endl;
        // outputFile << i+1 << " " << ids[i] << "\t\t\t" << 0 << "\t\t" << "yes" << endl;
        i++;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
    


  
 



