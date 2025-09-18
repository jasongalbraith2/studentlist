#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include <cmath>
#include <iomanip>

const unsigned int FIRSTNAMEBUFFER = 11;
const unsigned int LASTNAMEBUFFER = 21;

struct Student {
  char firstName[FIRSTNAMEBUFFER];
  char lastName[LASTNAMEBUFFER];
  int studentID;
  float GPA;
};

int main() {
  // Constant buffer values
  const int BUFFER_COMMAND = 8;
  
  // Initialize the vector container for all student struct pointers
  std::vector<Student*> studentList;

  /* Main loop variables */
  bool running = true;
  char command[BUFFER_COMMAND];
  
  // Add variables
  char _firstName[FIRSTNAMEBUFFER];
  char _lastName[LASTNAMEBUFFER];
  int _studentID;
  float _GPA;
  
  // Delete variables
  size_t indexToDelete;
  bool foundID;

  // Main running loop
  while (running) {
    // Reset variables
    indexToDelete = 0;
    foundID = false;
    
    // First, read in and parse the command
    std::cout << "[COMMAND] >> ";
    std::cin.getline(command, BUFFER_COMMAND);
    
    if (strcmp(command, "ADD") == 0) {
        /* 
        Firstly, read in the variables.
        Each time they are read, confirm
        they are a valid input. Secondly,
        create and assign the new Student*
        struct to the vector array
        */
        
        std::cout << "[STUDENT FIRST NAME] >> ";
        std::cin.getline(_firstName, FIRSTNAMEBUFFER);
        
        std::cout << "[STUDENT LAST NAME] >> ";
        std::cin.getline(_lastName, LASTNAMEBUFFER);
        
        std::cout << "[STUDENT ID (6 FIGS)] >> ";
        std::cin >> _studentID;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cout << "Invalid Value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            continue;
        }
        else if (_studentID < 100000 or _studentID > 999999) {
            std::cout << "ID value is too large or too small.\n";
            
            continue;
        }
        
        std::cout << "[STUDENT GPA (5 or less)] >> ";
        std::cin >> _GPA;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cout << "Invalid Value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            continue;
        }
        else if (_GPA < 0.0f or _GPA > 5.0f) {
            std::cout << "GPA value is too large or too small.\n";
            
            continue;
        }
        
        Student* newStudent = new Student;
        strcpy(newStudent->firstName, _firstName); 
        strcpy(newStudent->lastName, _lastName); 
        newStudent->studentID = _studentID; 
        newStudent->GPA = _GPA;
        studentList.push_back(newStudent);
    }
    
    else if (strcmp(command, "PRINT") == 0) {
        /*
        Print all the current saved students
        in a specific format
        */
        
        if (studentList.size() > 0) {
            for (Student* givenStudent : studentList) {
                std::cout << "\nSTUDENT ID: " << givenStudent->studentID;
                std::cout << "\n\tLAST, FIRST: " << givenStudent->lastName << ", " << givenStudent->firstName;
                std::cout << "\n\tGPA: " << std::fixed << std::setprecision(2) << givenStudent->GPA;
            }
        
            std::cout << "\n\n";
        }
        else {
            std::cout << "Currently, there are no students in the vector.\n";
        }
    }
    
    else if (strcmp(command, "DELETE") == 0) {
        /*
        Ask for ID, then confirm that it is
        an applicable value. Then, check the
        vector list for that ID. If it does
        not exist, let the user know, and return
        to the command loop.
        */
        
        std::cout << "[STUDENT ID (6 FIGS)] >> ";
        std::cin >> _studentID;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cout << "Invalid Value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            continue;
        }
        else if (_studentID < 100000 or _studentID > 999999) {
            std::cout << "ID value is too large or too small.\n";
            
            continue;
        }
        
        // Check if the ID is in the vector list
        for (size_t i = 0; i < studentList.size(); ++i) {
            if(studentList[i]->studentID == _studentID) {
                indexToDelete = i;
                foundID = true;
                break;
            }
        }
        
        if (foundID) {
            delete studentList[indexToDelete];
            studentList.erase(studentList.begin() + indexToDelete);
        }
        else {
            std::cout << "Couldn\'t find that ID.\n";
        }
    }
    
    else if (strcmp(command, "QUIT") == 0) {
        running = false;
    }
    
    else {
        // give no-command error
        continue;
    }
  }
  
  // Clean up memory in student list vector
  for (Student* p : studentList) {
    delete p;
  }
  
  return 0;
}
