#include "analizatorius.h"

int main() {
    std::map<std::string, int> dazniai;
    std::map<std::string, std::set<int>> xref;
    std::vector<std::string> urlai;

    std::string tekstas = "tekstas.txt";

    skaiciuotiZodzius(tekstas, dazniai, xref);
    rasytiDažniųAtaskaita("dazniai.txt", dazniai);
    rasytiXrefLentele("xref.txt", xref);
    ieskotiURL(tekstas, urlai);
    rasytiURLiFaila("urlai.txt", urlai);

    return 0;
}