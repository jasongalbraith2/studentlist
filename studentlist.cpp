#include <iostream>
#include <vector>

struct Student {
  char firstName[11];
  char lastName[21];
  int studentID;
  float GPA;
};

int main() {
  // Constant buffer values
  const int BUFFER_COMMAND = 8;
  
  // Initialize the vector container for all student struct pointers
  std::vector<Student*> studentList;

  // Main loop variables
  bool running = true;
  char command[COMMAND_LEN];

  // Main running loop
  while (running) {
    // Get a command
    std::cin.getline(command, BUFFER_COMMAND);
    //switch (command) { } 
  }
  
  // Clean up memory in student list vector
  for (Student* p : studentList) {
    delete p;
  }
  
  return 0;
}
