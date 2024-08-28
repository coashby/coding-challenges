#include <iostream>

#include "solution.h"

void runTest(std::vector<std::string>& logs, int& test_number) {
  const auto reordered_logs = Solution::reorderLogFiles(logs);
  std::cout << "Test #" << test_number << ": Sorted Logs = [" << std::endl;
  ;
  for (const auto& log : reordered_logs) {
    std::cout << "\t" << log << std::endl;
  }
  std::cout << "]" << std::endl;

  ++test_number;
}

int main() {
  int test_number = 0;
  {
    std::vector<std::string> logs = {
        "qi ir oo i", "cp vnzw i", "0 fkbikbts", "4 j trouka", "gn j q al",
        "5r w wgqc",  "m8 x haje", "fg 28694 6", "i gf mwdoa", "ao 0850716"};
    runTest(logs, test_number);
  }
  {
    std::vector<std::string> logs = {"dig1 8 1 5 1", "let1 art zero can",
                                     "dig2 3 6", "let2 own kit dig",
                                     "let3 art zero"};
    runTest(logs, test_number);
  }
  {
    std::vector<std::string> logs = {"a1 9 2 3 1", "g1 act car", "zo4 4 7",
                                     "ab1 off key dog", "a8 act zoo"};
    runTest(logs, test_number);
  }
  {
    std::vector<std::string> logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6",
                                     "let2 own kit dig", "let3 art zero"};
    runTest(logs, test_number);
  }
  return EXIT_SUCCESS;
}
