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

    // Only iterate through alphanumeric characters of palindrome
    int i = 0, j = palindrome.size() - 1;
    while (i < j) {
        // Skip symbol characters
        while (::issymbol(palindrome[i]) || ::issymbol(palindrome[j])) {
            if(::issymbol(palindrome[i])) {
                ++i;
            }
            if(::issymbol(palindrome[j])) {
                --j;
            }
        }
        // Compare lowercase first half to lowercase second half
        if (tolower(palindrome[i++]) != tolower(palindrome[j--])) {
            std::cout << "It's not a palindrome!" << std::endl;

            // Exit early if not a palindrome
            return 0;
        }
    }

    if (palindrome.size()) {
        std::cout << "It's a palindrome!" << std::endl;
    } else {
        std::cout << "Empty input" << std::endl;
    }

    return 0;
}