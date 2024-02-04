// Dylan Smith, 20265570
// ELEC376 Assignment 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int calculateScore(string answerKey, string userAnswers)
{
    if (answerKey.empty() || answerKey == "" || userAnswers.empty() || userAnswers == "" || userAnswers.size() < answerKey.size())
    {
        // answers were incomplete or invalid, return -1
        return -1;
    }
    else
    {
        int sumScore = 0;
        // calculate how many answers were correct
        for (int i = 0; i < userAnswers.length(); i++)
        {
            if (userAnswers[i] == answerKey[i])
            {
                sumScore++;
            }
        }
        return sumScore;
    }
}

string calculateShouldRetake(int score)
{
    if (score < 3)
        return "yes";
    else
        return "no";
}

int calculateAvg()
{
}

int main()
{
    ifstream inputFile("QuizResponses.txt");
    ofstream outputFile;

    outputFile.open("output.txt");
    if (!outputFile.is_open())
    {
        cerr << "Error: Unable to open file 'output.txt' for writing." << std::endl;
        return 1; // Exit with error
    }

    outputFile << setw(6) << " "
               << "Employee Quiz Responses" << endl
               << endl;

    outputFile << setw(15) << std::left << "Employee ID" << setw(10) << "Score" << setw(15) << std::left << "Redo Quiz" << endl;
    outputFile << "-------------------------------------" << endl;

    // parallel vectors to store user id's and their answers at equal indices.
    vector<string> ids;
    vector<string> answers;

    int i = 0;
    string answerKey = "";
    // loop through every line of the input file and grab data
    for (string line; getline(inputFile, line);)
    {
        // skip the line if its an empty line
        if (line == "")
            continue;
        if (i == 0)
        {
            // first line, grab answer key
            answerKey = line;
            i++;
            continue;
        }

        if (i % 2 == 0)
        {
            // store answers
            answers.push_back(line);
        }
        else
        {
            // store id number
            ids.push_back(line);
        }

        i++;
    }

    // keep iterator i to index parallel vector ids and answers in same loop
    i = 0;
    int sumScores = 0;
    for (string str : ids)
    {
        int score = calculateScore(answerKey, answers[i]);
        sumScores += score; // keep track of total score sum for averaging
        string shouldRetakeTest = calculateShouldRetake(score);
        outputFile << std::left << setw(2) << i + 1 << std::left << setw(15) << ids[i] << setw(11) << score << setw(15) << std::left << shouldRetakeTest << endl;
        i++;
    }
    outputFile << "-------------------------------------" << endl;

    // calculate average score
    float avg = round(sumScores / (float)answers.size());

    outputFile << std::left << setw(17) << "Average" << setw(11) << std::fixed << std::setprecision(2) << avg << setw(15) << endl;

    // close file streams
    inputFile.close();
    outputFile.close();
    return 0;
}
