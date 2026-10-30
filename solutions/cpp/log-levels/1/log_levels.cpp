#include <string>

namespace log_line {
std::string message(std::string line) {
  int colon_index = line.find(":");
  return line.substr(colon_index + 2);
}

std::string log_level(std::string line) {
  int opening_bracket_index = line.find("[") + 1;
  int closing_bracket_index = line.find("]");
  return line.substr(opening_bracket_index,
                     closing_bracket_index - opening_bracket_index);
}

std::string reformat(std::string line) {
  return message(line) + "(" + log_level(line) + ")";
}
}  // namespace log_line
