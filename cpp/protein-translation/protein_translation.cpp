#include "protein_translation.h"

#include <string>

namespace protein_translation {

std::vector<std::string> proteins(std::string rna) {
    std::vector<std::string> final_protiens{};
    std::map<std::string, std::string> codon_amino_map = {
        {"AUG", "Methionine"},    {"UUU", "Phenylalanine"},
        {"UUC", "Phenylalanine"}, {"UUA", "Leucine"},
        {"UUG", "Leucine"},       {"UCU", "Serine"},
        {"UCC", "Serine"},        {"UCA", "Serine"},
        {"UCG", "Serine"},        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},      {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},      {"UGG", "Tryptophan"},
        {"UAA", "STOP"},          {"UAG", "STOP"},
        {"UGA", "STOP"},
    };

    if (rna.size() == 0) {
        return final_protiens;
    };
    long unsigned int i = 0;
    while (i < rna.size()) {
        std::string amino_acid = codon_amino_map[rna.substr(i, 3)];
        if (amino_acid == "STOP") {
            break;
        } else {
            final_protiens.emplace_back(amino_acid);
        };
        i += 3;
    };
    return final_protiens;
}

}  // namespace protein_translation
