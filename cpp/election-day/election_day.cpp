#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

int vote_count(ElectionResult& candidate) { return candidate.votes; }

void increment_vote_count(ElectionResult& candidate, int number_of_votes) {
    candidate.votes += number_of_votes;
}

ElectionResult& determine_result(std::vector<ElectionResult>& final_counts) {
    int winner_idx = 0;
    for (int i = 0; i < final_counts.size(); ++i) {
        if (final_counts[i].votes > final_counts[winner_idx].votes) {
            winner_idx = i;
        }
    }
    ElectionResult& winner = final_counts[winner_idx];
    winner.name = "President " + final_counts[winner_idx].name;
    return winner;
}

}  // namespace election
