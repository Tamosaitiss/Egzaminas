# Žodžių Dažnio, URL ir Cross-reference Analizatorius

## 📄 Aprašymas

Ši C++ programa atlieka lietuviško teksto analizę, suskaičiuoja kiek kartų pasikartoja kiekvienas žodis, nustato kuriose teksto eilutėse tie žodžiai panaudoti, bei išskiria visus URL adresus. Programa skirta dirbti su bet kokio dydžio tekstiniais failais `.txt` formatu.

### Funkcionalumas:
- Suskaičiuoja kiek kartų kiekvienas žodis pasikartojo (ignoruojant skyrybos ženklus).
- Sukuria cross-reference lentelę, kurioje nurodoma, kuriose teksto eilutėse žodis buvo paminėtas.
- Išskiria visus URL'us (https://, www., ar trumpesni formatai, pvz., vu.lt).
- Dirba su UTF-8 kodavimu (palaiko lietuviškas raides).

---

### 2. Programa sugeneruoja šiuos rezultatus:
- `dazniai.txt` – žodžiai, kurie pasikartojo daugiau nei 1 kartą ir jų kiekis.
- `xref.txt` – žodžiai, kurie pasikartojo daugiau nei vienoje eilutėje ir tos eilutės.
- `urlai.txt` – visi rasti URL'ai.

### 3. Failus galima atsidaryti tekstiniu redaktoriumi, pvz. VSCode ar Notepad++.

---

## 🛠 Reikalavimai

- C++17 arba naujesnė versija.
- UTF-8 tekstinis failas.
- Naudojama `std::map`, `std::set`, `std::regex`, `ifstream`, `ofstream`.

---

## 🔍 Pastabos

- Skyrybos ženklai automatiškai pašalinami, o raidės sumažinamos iki mažųjų.
- Skaitiniai "žodžiai" (pvz. `123`, `11th`, `10`) pagal nutylėjimą gali būti atfiltruoti (jei aktyvuotas `isdigit` filtras).
- Dideli tekstai apdorojami be problemų – skaitymas vyksta eilutė po eilutės.

---

## 🧪 Testavimas

**Rekomenduojama naudoti bent 1000 žodžių turintį failą**, pavyzdžiui, Vikipedijos straipsnį apie Vilnių, išsaugotą kaip `tekstas.txt` UTF-8 formatu.

---

## 📌 Autorius

Ignas Tamošaitis, VU 2025.



