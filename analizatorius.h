#pragma once
#include <string>
#include <map>
#include <set>
#include <vector>

void skaiciuotiZodzius(const std::string& failoKelias, std::map<std::string, int>& dazniai, std::map<std::string, std::set<int>>& xref);

void rasytiDažniųAtaskaita(const std::string& failas, const std::map<std::string, int>& dazniai);

void rasytiXrefLentele(const std::string& failas, const std::map<std::string, std::set<int>>& xref);

void ieskotiURL(const std::string& failas, std::vector<std::string>& urlai);

void rasytiURLiFaila(const std::string& failas, const std::vector<std::string>& urlai);