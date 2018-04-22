///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 3 in homework assignmnet #2. 
//    2. Implement function GetStudentName.
//    3. Implement function MatchBracket.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_2.h") and results ("solution_2.dat") 
//       via Canvas.
//
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <map>
#include <stack>
//you can include standard C++ libraries here


// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
  //replace the placeholders "Firstname" and "Lastname"
  //with you first name and last name 
  your_name.assign("Peter Nam");
}


int MatchBracket (const std::string& str, int position)
{ 
  std::map <char, char> paran_dict;
  int i;
  paran_dict['('] = ')';
  paran_dict['['] = ']';
  paran_dict['{'] = '}';
  paran_dict[')'] = '(';
  paran_dict[']'] = '[';
  paran_dict['}'] = '{';

  char parans[6] = {'(',')','[',']','{','}'};
  char p = str[position];
  std::stack <char> p_stack;
  if (std::find(std::begin(parans), std::end(parans), p) == std::end(parans)) {
    return -1;
  }
  
  p_stack.push(paran_dict[p]);  
  
  if (p == '(' || p == '[' || p == '{') {
    for (i = position + 1; i<str.length() ; ++i) {
      if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
        p_stack.push(paran_dict[str[i]]);
      }
      else if(str[i] == ')' || str[i] == ']' || str[i] == '}') {
        if (str[i] == p_stack.top()){ 
          if (p_stack.size() > 1) {
            p_stack.pop();
          } 
          else {
            return i;
          }
        }
        else {
          return -1;
        }
      }
    }
  }
  
  else if (p == ')' || p == ']' || p == '}') {
    for (i = position - 1; i>-1; --i) {
      if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
        p_stack.push(paran_dict[str[i]]);
      }
      else if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
        if (str[i] == p_stack.top()) {
          if (p_stack.size() > 1) {
            p_stack.pop();
          }
          else {
            return i;
          }
        }
        else {
          return -1;
        }
      }
    }
  }
  
  return -1; /* return correct value here*/
}