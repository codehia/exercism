#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
  std::vector<int> rounded_down_scores = {};
  for (int i = 0; i < student_scores.size(); ++i) {
    rounded_down_scores.emplace_back(static_cast<int>(student_scores.at(i)));
  }
  return rounded_down_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
  int number_of_failing_students{0};
  for (int i = 0; i < student_scores.size(); ++i) {
    if (student_scores.at(i) <= 40) number_of_failing_students++;
  }
  return number_of_failing_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
  std::array<int, 4> lower_letter_grades{};
  int diff = static_cast<int>((highest_score - 40) / 4);
  int idx = 3;
  while (highest_score >= 40 and idx >= 0) {
    highest_score -= diff;
    if (diff % 2 == 0) {
      lower_letter_grades[idx] = highest_score;

    } else {
      lower_letter_grades[idx] = highest_score + 1;
    }
    --idx;
  }
  return lower_letter_grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
  std::vector<std::string> student_ranking_strings{};
  for (int i = 0; i < student_scores.size(); ++i) {
    std::string rank = std::to_string(i + 1);
    std::string score = std::to_string(student_scores.at(i));
    student_ranking_strings.emplace_back(rank + ". " + student_names.at(i) +
                                         ": " + score);
  }
  return student_ranking_strings;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
  for (int i = 0; i < student_scores.size(); ++i) {
    if (student_scores.at(i) == 100) return student_names.at(i);
  }
  return "";
}
