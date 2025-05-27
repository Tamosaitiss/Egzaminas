#ifndef ANALIZATORIAUS_H
#define ANALIZATORIAUS_H

#include <string>
#include <map>
#include <set>
#include <vector>

void skaiciuotiZodzius(const std::string& failoKelias, std::map<std::string, int>& dazniai, std::map<std::string, std::set<int>>& xref);
void isvestiDaznius(const std::map<std::string, int>& dazniai, const std::string& isvestiesFailas);
void isvestiCrossReference(const std::map<std::string, std::set<int>>& xref, const std::string& isvestiesFailas);
void rastiURL(const std::string& failoKelias, std::vector<std::string>& urlai, const std::string& isvestiesFailas);

#endif //ANALIZATORIAUS_H
