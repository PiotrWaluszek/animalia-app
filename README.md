
# Aplikacja Quizowa

Jest to prosta aplikacja quizowa działająca w konsoli, napisana w języku C++. Aplikacja ładuje pytania quizowe z pliku JSON, prezentuje je użytkownikowi, zapisuje jego wynik i zapisuje wyniki. Umożliwia również użytkownikom przeglądanie poprzednich wyników.

## Struktura Folderów

```
QUIZ
├── .vscode
│   └── settings.json
├── json.hpp
├── main.cpp
├── questions.json
├── quiz
└── results.txt
```

## Pliki

- **.vscode/settings.json**: Zawiera ustawienia dla edytora Visual Studio Code.
- **json.hpp**: Plik nagłówkowy dla biblioteki JSON (nlohmann/json).
- **main.cpp**: Główny plik źródłowy aplikacji quizowej.
- **questions.json**: Plik JSON zawierający pytania i odpowiedzi do quizu.
- **quiz**: Plik wykonywalny aplikacji quizowej.
- **results.txt**: Plik tekstowy, w którym zapisywane są wyniki quizów.

## Pierwsze Kroki

### Wymagania

- Kompilator C++ (np. g++)
- Biblioteka JSON for Modern C++ (nlohmann/json)

### Kompilacja Projektu

1. **Sklonuj repozytorium:**
    ```sh
    git clone <repository_url>
    cd quiz_application
    ```

2. **Skompiluj projekt:**
    ```sh
    g++ -o quiz main.cpp
    ```

### Uruchamianie Quizu

1. **Uruchom quiz:**
    ```sh
    ./quiz
    ```

2. **Opcje menu:**
    - **1. Rozpocznij nowy quiz**: Rozpocznij nowy quiz.
    - **2. Wyświetl wyniki**: Wyświetl poprzednie wyniki.
    - **3. Zakończ**: Zakończ aplikację.

### Dodawanie Pytań

Aby dodać więcej pytań do quizu, edytuj plik `questions.json`. Każde pytanie powinno być w następującym formacie:

```json
[
    {
        "question": "Jakie jest najszybsze zwierzę lądowe?",
        "answer": "gepard"
    },
    {
        "question": "Ile nóg ma pająk?",
        "answer": "8"
    }
]
```

### Przykładowy Plik Pytań (questions.json)

```json
[
    {"question": "Jakie jest najszybsze zwierzę lądowe?", "answer": "gepard"},
    {"question": "Ile nóg ma pająk?", "answer": "8"},
    {"question": "Jakie zwierzę jest największe na świecie?", "answer": "wieloryb"},
    {"question": "Jakie zwierzę jest największym ssakiem lądowym?", "answer": "słoń"},
    {"question": "Które zwierzę jest najszybszym ptakiem?", "answer": "sokół"},
    {"question": "Ile żyją papugi?", "answer": "60"},
    {"question": "Jakie jest najbardziej inteligentne zwierzę?", "answer": "delfin"},
    {"question": "Ile żyją żółwie?", "answer": "100"},
    {"question": "Jakie zwierzę żyje najdłużej?", "answer": "meduza"},
    {"question": "Jakie zwierzę może zmienić kolor?", "answer": "kameleon"}
]
```

### Przeglądanie Wyników

Wyniki quizów są zapisywane w pliku `results.txt` w następującym formacie:

```
username wynik/całkowita liczba pytań data i czas
```

### Przykład

```
PiotrW 7/10 Tue Jun 07 14:22:15 2024
TomekA 9/10 Wed Jun 08 10:11:12 2024
```

## Zależności

- [JSON for Modern C++](https://github.com/nlohmann/json)


