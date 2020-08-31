#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//int main() {
//    string x = "";
//    while (x != "exit") {
//        cout << "Enter something: ";
//        getline(cin, x);
//        cout << "You entered: \"" << x << '\"' << endl;
//    }
//}

//int main() {
//    ifstream fin("haiku.txt");
//    ofstream outfile("haiku2.txt");
//    while (!fin.eof()) {
//        string line;
//        getline(fin, line);
//        outfile << line;
//    }
//
//    return 0;
//
//}

//int main() {
//    string name;
//    cout << "Enter a thing: ";
//    getline(cin, name);
//    istringstream input(name);
//    while (!input.eof()) {
//        string word;
//        input >> word;
//        cout << word << endl;
//    }
//}

// Declaring global string variables that will keep their values outside of loops
string line1, longest_word;
// Declaring global int variables (and setting applicable ones to zero)
int max_length = 0;
int x = 0;
int long_word_line;

// Initializing main method
int main() {
    // Open the text file
    ifstream fin("lines.txt");
    // Get the first line from the text file and assign its values to line1
    getline(fin, line1);
    // Use istringstream to separate the strings in the first line
    istringstream numbers(line1);

    // Declare a while loop to continue to the end of the file
    while (!fin.eof()){
        // Declare the line variable
        string line;
        // Use getline to assign the line to a string
        getline(fin,line);
        // Use istringstream to take the string and parse the individual words
        istringstream words(line);
        // Add a counter that will increment every time getline is run
        x++;
        // Use another while loop to go to the end of the line and process each word
        while (!words.eof()){
            // Define the word string
            string word;
            // Assign each word to the word variable
            words >> word;
            // Assign the length variable
            int length = word.length();
            // This if statement will continuously assign new values to the variables
            // max_length, longest_word, and long_word_line to keep them stored as they
            // come across relevant values
            if (max_length < length)
            {
                max_length = length;
                longest_word = word;
                long_word_line = x;
            }

        }
    }
    // Print the results in a pretty manner
    cout << "The longest word is " << longest_word << " with a length of " << max_length << " on line " << long_word_line << endl;
}