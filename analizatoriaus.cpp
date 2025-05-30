#include "analizatorius.h"
#include <fstream>
#include <sstream>
#include <regex>
#include <iostream>
#include <algorithm>

void skaiciuotiZodzius(const std::string& failoKelias, std::map<std::string, int>& dazniai, std::map<std::string, std::set<int>>& xref) {
    std::ifstream in(failoKelias);
    if (!in) {
        return;
    }

    std::string eilute;
    int eilNr = 0;

    while (getline(in, eilute)) {
        ++eilNr;
        std::istringstream iss(eilute);
        std::string zodis;
        while (iss >> zodis) {
            std::regex filtras(R"([^a-zA-Z0-9ąčęėįšųūžĄČĘĖĮŠŲŪŽ])");
            zodis = std::regex_replace(zodis, filtras, "");

            std::transform(zodis.begin(), zodis.end(), zodis.begin(), [](unsigned char c) {
                return std::tolower(c);
            });

            if (!zodis.empty()) {
                ++dazniai[zodis];
                xref[zodis].insert(eilNr);
            }
        }
    }
}

void rasytiDažniųAtaskaita(const std::string& failas, const std::map<std::string, int>& dazniai) {
    std::ofstream out(failas);
    if (!out) return;

    for (const auto& [zodis, kiekis] : dazniai) {
        if (kiekis > 1) {
            out << zodis << ": " << kiekis << "\n";
        }
    }
}

void rasytiXrefLentele(const std::string& failas, const std::map<std::string, std::set<int>>& xref) {
    std::ofstream out(failas);
    if (!out) return;

    for (const auto& [zodis, eilutes] : xref) {
        if (eilutes.size() > 1) {
            out << zodis << ": ";
            for (int nr : eilutes)
                out << nr << " ";
            out << "\n";
        }
    }
}

void ieskotiURL(const std::string& failas, std::vector<std::string>& urlai) {
    std::ifstream in(failas);
    if (!in) return;

    std::string eilute;
    std::regex urlRegex(R"((https?:\/\/[^\s]+|www\.[^\s]+|\b[a-z0-9.-]+\.[a-z]{2,}\b))");

    while (getline(in, eilute)) {
        std::sregex_iterator it(eilute.begin(), eilute.end(), urlRegex);
        std::sregex_iterator end;
        while (it != end) {
            urlai.push_back(it->str());
            ++it;
        }
    }
}

void rasytiURLiFaila(const std::string& failas, const std::vector<std::string>& urlai) {
    std::ofstream out(failas);
    if (!out) return;

    for (const auto& url : urlai) {
        out << url << "\n";
    }
}