#pragma once

#include <algorithm>
#include <vector>

class Solution {
 public:
  static bool lexiconLtCompare(const std::string& lhs, const std::string& rhs) {
    auto lhs_id_end_pos = lhs.find(' ');
    auto lhs_words_pos = lhs_id_end_pos + 1;
    auto rhs_id_end_pos = rhs.find(' ');
    auto rhs_words_pos = rhs_id_end_pos + 1;

    const size_t kMinWordLength =
        std::min((lhs.size() - lhs_words_pos), (rhs.size() - rhs_words_pos));

    while (lhs_words_pos <= kMinWordLength) {
      if (lhs[lhs_words_pos] < rhs[rhs_words_pos]) {
        return true;
      } else if (rhs[rhs_words_pos] < lhs[lhs_words_pos]) {
        return false;
      }
      ++lhs_words_pos;
      ++rhs_words_pos;
    }
    // The words share the same prefix. Return the lexicographically smaller
    // word.
    if ((lhs.size() - lhs_words_pos) < (rhs.size() - rhs_words_pos)) {
      return true;
    } else {
      // The words are the same. Return the lexicographically smaller
      // identifiers.
      const size_t kMinIdLength = std::min(lhs_id_end_pos, rhs_id_end_pos);
      for (size_t i = 0; i < kMinIdLength; ++i) {
        if (lhs[i] < rhs[i]) {
          return true;
        } else if (rhs[i] < lhs[i]) {
          return false;
        }
      }
    }
    // The identifiers share the same prefix. Return the lexicographically
    // smaller identifier.
    return (lhs_id_end_pos < rhs_id_end_pos);
  }

  static std::vector<std::string> reorderLogFiles(
      std::vector<std::string>& logs) {
    std::vector<std::string> reordered_logs;
    reordered_logs.reserve(logs.size());
    const char kMaxNumericChar = '9';
    auto logs_iter = logs.begin();
    while (logs_iter != logs.end()) {
      // Find the fist word in the log.
      auto pos = logs_iter->find(' ') + 1;
      // Move all letter-logs to the sorted logs vector.
      if ((*logs_iter)[pos] > kMaxNumericChar) {
        std::move(logs_iter, (logs_iter + 1),
                  std::back_inserter(reordered_logs));
        logs.erase(logs_iter);
        continue;
      }
      ++logs_iter;
    }
    // Sort the letter-logs.
    std::sort(reordered_logs.begin(), reordered_logs.end(), lexiconLtCompare);
    // Concatenate the letter-logs and digit-logs.
    std::move(logs.begin(), logs.end(), std::back_inserter(reordered_logs));
    logs.clear();
    return reordered_logs;
  }
};
