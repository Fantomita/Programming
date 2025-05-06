#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char s[255], result[255] = ""; // `result` pentru textul final
    cin.getline(s, 255);           // Citim șirul de la tastatură

    char *token = strtok(s, " ");  // Împărțim textul în cuvinte
    while (token) {
        char cleanWord[255] = "";  // Cuvântul curățat de cifre

        // Dacă cuvântul este un număr, adăugăm direct la rezultat
        bool isNumber = true;
        for (int i = 0; i < strlen(token); ++i) {
            if (token[i] < '0' || token[i] > '9') {
                isNumber = false;
                break;
            }
        }

        if (isNumber) {
            strcat(result, token); // Adăugăm numărul la rezultat
        } else {
            // Curățăm cuvântul de cifre
            for (int i = 0; i < strlen(token); ++i) {
                if (token[i] < '0' || token[i] > '9') {
                    int len = strlen(cleanWord);
                    cleanWord[len] = token[i];
                    cleanWord[len + 1] = '\0';
                }
            }
            strcat(result, cleanWord); // Adăugăm cuvântul curățat la rezultat
        }
        strcat(result, " "); // Adăugăm spațiu între cuvinte
        token = strtok(nullptr, " "); // Trecem la următorul cuvânt
    }

    // Eliminăm spațiul în plus de la final, dacă există
    int len = strlen(result);
    if (len > 0 && result[len - 1] == ' ') {
        result[len - 1] = '\0';
    }

    // Afișăm rezultatul
    if (strcmp(s, result) == 0) {
        cout << "Sir corect";
    } else {
        cout << result;
    }

    return 0;
}
