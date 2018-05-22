///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 2 in homework assignmnet #5. 
//    2. Implement function GetStudentName.
//    3. Implement function FindBestSchedule.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_5.h") and results ("solution_5.dat") 
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector> 

using namespace std;

//you can include standard C++ libraries here

// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
  //replace the placeholders "Firstname" and "Lastname"
  //with you first name and last name 
  your_name.assign("Peter Nam");
}


//you can use one of the following signatures

//int FindMeasure (const std::vector<std::pair<int,int>>& intervals, int coverage)
//or 
//int FindMeasure(std::vector<std::pair<int, int>> intervals, int coverage)


int FindMeasure (std::vector<std::pair<int,int>> intervals, int coverage)
{  
  int measure = 0;
  int count = 0;
  
  vector<pair<int,int>> times;
  for (const pair<int,int> x : intervals) {
    times.push_back(make_pair(x.first, 1));
    times.push_back(make_pair(x.second, -1));
  }
  
  sort(times.begin(), times.end());
  int start = NULL;
  
  for (const pair<int,int> t : times) {
    count += t.second;
    if (start != NULL) {
      measure += t.first - start;
      start = NULL;
    }
    if(count == coverage) {
      start = t.first;
    }
  }
  
  //your code goes here

  return measure;
}

