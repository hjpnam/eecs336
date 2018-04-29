///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 2 in homework assignmnet #3. 
//    2. Implement function GetStudentName.
//    3. Implement function FindBestSchedule.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_3.h") and results ("solution_3.dat") 
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <vector>
#include <utility>
#include <queue>
#include <stack>

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

class Comparator {
  public: 
    bool operator()(pair<int,int> n1, pair<int, int> n2){
      return n1.second > n2.second;
    }
};

//you can implement this function (recommended) or the the next one
int FindBestSchedule (std::vector<std::pair<int,int>> availabilities, int T)
{   
  //your code goes here
  sort(availabilities.begin(), availabilities.end(), [](const pair<int,int> &left, const pair<int,int> &right) {return left.second<right.second;});
   
  int i = 0; 
  int count = 1;
  pair<int,int> ref = availabilities[i];
  
  for (i; i<availabilities.size(); ++i) {
    if(ref.second - availabilities[i].first < T) {
      ref = availabilities[i];
      ++count;
    }
  }
   
  return count; /* replace -1 with the correct value */
}

//if you choose to implement this function, you can replace the code with 
//your own code
int FindBestSchedule (const std::vector<int>& left, const std::vector<int>& right, int T)
{
  assert(left.size() == right.size());
  size_t size = left.size();

  std::vector<std::pair<int, int>> availabilities;
  availabilities.reserve (size);

  for (size_t i = 0; i < size; i++)
  {
    availabilities.push_back (std::make_pair(left[i], right[i]));
  }
  
  return FindBestSchedule (availabilities, T);
}
