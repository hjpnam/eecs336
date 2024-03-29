////////////////////////////////////////////////////////////////////////////
// DO NOT EDIT THIS FILE
//

#include <string>
#include <vector>
#include "test_framework.h"
#include "student_code_3.h"

const char* inputFilename = "problem_set_3.in";
const char* outputFilename = "solution_3.dat";

const char* strNotice = "##################################\n"
                        "# Do not edit this file!\n"
                        "##################################\n";

constexpr int problem_set_id = 3;

struct ProblemN3 : public TestFramework::BasicProblem
{
   std::vector<int> left;
   std::vector<int> right;
   int T;
};

int main(int argc, char *argv[])
{
   using namespace TestFramework;
   
   static_assert (GetTestFrameworkVersion () == 4, "TestFramework version 4 is required. Please, update test_framework.h.");
   ExitIfConditionFails((argc == 1) || (argc == 2), "This program takes at most one parameter.");

   bool isDebugMode = (argc == 2);
   int problemToSolve = 0;

   if (isDebugMode)
   {
      problemToSolve = atoi(argv[1]);
      ExitIfConditionFails(problemToSolve != 0,
         "Invalid parameter. Please, specify the number of the problem you want to solve. The number of the first problem is 1.");
   }

   std::cout << std::endl << "Problem set #" << problem_set_id << ". ";

   ProblemSetHeader header;
   RecordAdapter<ProblemSetHeader> psAdapter(header); 
   AddDefaultProblemSetColumns(psAdapter);

   std::vector<ProblemN3> problems;
   TableAdapter<ProblemN3> prAdapter(problems);
   AddDefaultProblemColumns (prAdapter);
  
   AddColumn<ProblemN3>(prAdapter, "left", &ProblemN3::left);
   AddColumn<ProblemN3>(prAdapter, "right", &ProblemN3::right);
   AddColumn<ProblemN3>(prAdapter, "T", &ProblemN3::T, -1);
     
   BasicYamlParser parser(dynamic_cast<ITable*>(&psAdapter), dynamic_cast<ITable*>(&prAdapter));
   parser.ParseFile(inputFilename, true);

   GetStudentName(header.student_name);

   PreprocessProblemSet(problem_set_id, problems, header);

   if (!isDebugMode)
   {
      for (int i = 0; i < header.problem_count; i++)
      {
         ProblemN3& theProblem = problems[i];
         theProblem.student_answer = FindBestSchedule (theProblem.left, theProblem.right, theProblem.T);
      }

      ProcessResults(problems, header);

      TableAdapter<ProblemN3> prOutAdapter(problems);
      AddDefaultProblemColumnsForOutput(prOutAdapter);

      WriteTableToFile(outputFilename, &prOutAdapter, &psAdapter, false, strNotice);
      std::cout << "Don't forget to submit your source code and file '" << outputFilename << "' via Canvas.";
      std::cout << std::endl << std::endl;
   }
   else
   {
      std::cout << "Solving problem #" << problemToSolve << "." << std::endl;

      ExitIfConditionFails(problemToSolve <= header.problem_count, "The problem you specified does not exist.");
      ProblemN3& theProblem = problems[problemToSolve - 1];
      theProblem.student_answer = FindBestSchedule (theProblem.left, theProblem.right, theProblem.T);
      
      std::cout << "Correct answer: " << theProblem.correct_answer << "." << std::endl;
      std::cout << "Your answer: " << theProblem.student_answer << "." << std::endl;
      std::cout << std::endl;
   }

   return 0;
}

