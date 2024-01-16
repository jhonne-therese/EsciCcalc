// EsciCcalc.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//Erika

#include <iostream>
#include <string>
#include <cmath>

// Fonction pour convertir un caractère en nombre en base 32
int charToNumber(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'V') {
        return c - 'A' + 10;
    }
    // Gérer d'autres caractères si nécessaire
    return -1; // Caractère non valide
}

// Fonction pour convertir un nombre en base 32 en caractère
char numberToChar(int num) {
    if (num >= 0 && num <= 9) {
        return '0' + num;
    }
    else if (num >= 10 && num <= 31) {
        return 'A' + num - 10;
    }
    // Gérer d'autres nombres si nécessaire
    return '?'; // Caractère non valide
}

// Fonction pour convertir une chaîne en base 32 en nombre décimal
int base32ToDecimal(const std::string& str) {
    int result = 0;
    int power = 0;
    for (int i = str.size() - 1; i >= 0; --i) {
        int digit = charToNumber(str[i]);
        if (digit == -1) {
            std::cerr << "Caractère non valide dans la chaîne en base 32." << std::endl;
            return -1; // Gérer l'erreur
        }
        result += digit * std::pow(32, power);
        ++power;
    }
    return result;
}

// Fonction pour convertir un nombre décimal en chaîne en base 32
std::string decimalToBase32(int num) {
    std::string result;
    while (num > 0) {
        int remainder = num % 32;
        result = numberToChar(remainder) + result;
        num /= 32;
    }
    return result;
}

// Fonctions pour les opérations en base 32
std::string addInBase32(const std::string& num1, const std::string& num2) {
    int decimalResult = base32ToDecimal(num1) + base32ToDecimal(num2);
    return decimalToBase32(decimalResult);
}

std::string subtractInBase32(const std::string& num1, const std::string& num2) {
    int decimalResult = base32ToDecimal(num1) - base32ToDecimal(num2);
    return decimalToBase32(decimalResult);
}

std::string multiplyInBase32(const std::string& num1, const std::string& num2) {
    int decimalResult = base32ToDecimal(num1) * base32ToDecimal(num2);
    return decimalToBase32(decimalResult);
}

std::string divideInBase32(const std::string& num1, const std::string& num2) {
    int denominator = base32ToDecimal(num2);
    if (denominator == 0) {
        std::cerr << "Division par zéro." << std::endl;
        return ""; // Gérer l'erreur
    }
    int decimalResult = base32ToDecimal(num1) / denominator;
    return decimalToBase32(decimalResult);
}

int main() {
    // Exemples d'utilisation
    std::string num1 = "1A"; // 26 en base 10
    std::string num2 = "B";  // 11 en base 10

    std::cout << "Addition : " << addInBase32(num1, num2) << std::endl;
    std::cout << "Soustraction : " << subtractInBase32(num1, num2) << std::endl;
    std::cout << "Multiplication : " << multiplyInBase32(num1, num2) << std::endl;
    std::cout << "Division : " << divideInBase32(num1, num2) << std::endl;

    return 0;
}

// Exécuter le;programme; : Ctrl + F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
