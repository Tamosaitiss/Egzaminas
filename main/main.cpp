#include "analizatorius.h"
#include <iostream>
#include <filesystem>

int main() {
    std::filesystem::create_directories("rezultatai");

    std::string failas = "duomenys/tekstas.txt";
    std::map<std::string, int> dazniai;
    std::map<std::string, std::set<int>> xref;
    std::vector<std::string> urlai;

    skaiciuotiZodzius(failas, dazniai, xref);
    isvestiDaznius(dazniai, "rezultatai/dazniai.txt");
    isvestiCrossReference(xref, "rezultatai/xref.txt");
    rastiURL(failas, urlai, "rezultatai/urlai.txt");

    std::cout << "Visi failai sugeneruoti sekmingai.\n";
    return 0;
}