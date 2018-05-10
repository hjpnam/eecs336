///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 3 in homework assignmnet #4. 
//    2. Implement function GetStudentName.
//    3. Implement function MinMatching.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_4.h") and results ("solution_4.dat") 
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

//you can include standard C++ libraries here
using namespace std;

// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
  //replace the placeholders "Firstname" and "Lastname"
  //with you first name and last name 
  your_name.assign("Peter Nam");
}

int MinMatching (std::vector<int> x, std::vector<int> y)
{ 
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  int cost;
  
  while(!x.empty()) {
    cost += abs(x.back() - y.back());
    x.pop_back();
    y.pop_back();
  }
  
  return cost;
}

