#include "analizatorius.h"
#include <fstream>
#include <sstream>
#include <regex>
#include <iostream>

void skaiciuotiZodzius(const std::string& failoKelias, std::map<std::string, int>& dazniai, std::map<std::string, std::set<int>>& xref) {
    std::ifstream in(failoKelias);
    std::string eilute;
    int eilNr = 0;

    while (getline(in, eilute)) {
        ++eilNr;
        std::istringstream iss(eilute);
        std::string zodis;
        while (iss >> zodis) {
            std::regex filtras(R"([^a-zA-Z0-9ąčęėįšųūžĄČĘĖĮŠŲŪŽ])");
            zodis = std::regex_replace(zodis, filtras, "");
            if (!zodis.empty()) {
                std::transform(zodis.begin(), zodis.end(), zodis.begin(), ::tolower);
                ++dazniai[zodis];
                xref[zodis].insert(eilNr);
                std::cout << "ZODIS: [" << zodis << "]" << std::endl;
            }
        }
    }
}

void isvestiDaznius(const std::map<std::string, int>& dazniai, const std::string& isvestiesFailas) {
    std::ofstream out(isvestiesFailas);
    for (const auto& pora : dazniai) {
        if (pora.second > 1)
            out << pora.first << ": " << pora.second << "\n";
    }
}

void isvestiCrossReference(const std::map<std::string, std::set<int>>& xref, const std::string& isvestiesFailas) {
    std::ofstream out(isvestiesFailas);
    for (const auto& pora : xref) {
        if (pora.second.size() > 1) {
            out << pora.first << ": ";
            for (int nr : pora.second) {
                out << nr << " ";
            }
            out << "\n";
        }
    }
}

void rastiURL(const std::string& failoKelias, std::vector<std::string>& urlai, const std::string& isvestiesFailas) {
    std::ifstream in(failoKelias);
    std::string eilute;
    std::regex url_pattern(R"((https?:\/\/)?(www\.)?[\w\.-]+\.\w+)");
    std::smatch match;

    while (getline(in, eilute)) {
        std::string tekstas = eilute;
        while (std::regex_search(tekstas, match, url_pattern)) {
            urlai.push_back(match.str(0));
            tekstas = match.suffix();
        }
    }

    std::ofstream out(isvestiesFailas);
    for (const auto& url : urlai) {
        out << url << "\n";
    }
}