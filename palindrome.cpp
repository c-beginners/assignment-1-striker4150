#include <algorithm>
#include <iostream>
#include <string>

/*
 * Checks if a given character is a symbol (excluding numbers)
 */
int issymbol(int character) { return !std::isalnum(character); }

/*
 * Check if a given line of input is a palindrome.
 * Only accepts alphanumeric characters.
 */
int main() {
    std::string palindrome;

    std::cout << "Enter a string: ";

    // Read string input
    std::getline(std::cin, palindrome);

    // Remove symbols and change to lowercase
    palindrome.erase(
        std::remove_if(palindrome.begin(), palindrome.end(), ::issymbol),
        palindrome.end());

    // Iterate through first half of palindrome
    for (int i = 0; i < palindrome.length() / 2; i++) {
        // Compare lowercase first half to lowercase second half
        if (tolower(palindrome[i]) !=
            tolower(palindrome[palindrome.length() - i - 1])) {
            std::cout << "It's not a palindrome!" << std::endl;

            // Exit early if not a palindrome
            return 0;
        }
    }

    std::cout << "It's a palindrome!" << std::endl;

    return 0;
}