#include <iostream>
#include <string>
#include <cstdlib> // for random numbers
#include <ctime>   // for time (to seed random)
#include <iomanip> // for formatting output
using namespace std;

const int NUM_SUBJECTS = 3; // Constant for the number of subjects
const int MAX_STUDENTS = 100; // Maximum students allowed

//student information
struct Student {
    string name;
    int studentID;
    float grades[NUM_SUBJECTS]; // Fixed-size array to store grades for each subject
};

// Function to generate a random student ID
int generateRandomID() {
    return rand() % 9000 + 1000; // Generates a random 4-digit ID
}

// Function to input student details
void inputStudentDetails(Student& student) {
    cout << "Enter student name: ";
    cin >> student.name;
    student.studentID = generateRandomID();

    cout << "Enter grades for " << NUM_SUBJECTS << " subjects (0 - 100):\n";
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        do {
            cout << "Subject " << i + 1 << ": ";
            cin >> student.grades[i];

            // Boolean expression to ensure grade is valid
            if (student.grades[i] < 0 || student.grades[i] > 100) {
                cout << "Invalid grade! Please enter a value between 0 and 100.\n";
            }
        } while (student.grades[i] < 0 || student.grades[i] > 100); // Repeat until valid grade is entered
    }
}


// Function to calculate the average of a student's grades
float calculateStudentAverage(const Student& student) {
    float total = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        total += student.grades[i];
    }
    return total / NUM_SUBJECTS;
}

// Function to calculate the overall average for each subject across all students
void calculateOverallSubjectAverage(const Student students[], int numStudents) {
    float subjectTotals[NUM_SUBJECTS] = { 0 }; // Initialize totals for each subject to 0

    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            subjectTotals[j] += students[i].grades[j];
        }
    }

   cout << "\nOverall subject averages:\n";
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << "Subject " << i + 1 << ": "
            << subjectTotals[i] / numStudents << "\n";
    }
}


int main() {
    srand(time(0)); // Seed for random ID generation
    Student students[MAX_STUDENTS]; // Array to store multiple students
    int numStudents;

    cout << "How many students do you want to enter? ";
    cin >> numStudents;

    if (numStudents > MAX_STUDENTS) {
        cout << "Cannot enter more than " << MAX_STUDENTS << " students.\n";
        return 1;
    }

    // Input details for each student
    for (int i = 0; i < numStudents; i++) {
        cout << "\nEntering details for student " << i + 1 << ":\n";
        inputStudentDetails(students[i]);
    }

    // Calculate and display each student's average
    cout << "\nStudent Averages:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << students[i].name << " (ID: " << students[i].studentID << "): "
            << fixed << setprecision(2)
            << calculateStudentAverage(students[i]) << "\n";
    }

    
    calculateOverallSubjectAverage(students, numStudents);

    return 0;
}
