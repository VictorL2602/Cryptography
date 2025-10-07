#include "caesar.h" // include your own header first
#include <ctype.h>  // for isalpha() and isupper()

// Encrypt plaintext using the Caesar cipher (shift by 3)
void caesar_encrypt(char plaintext[]) {
  for (int i = 0; plaintext[i] != '\0'; i++) { // Loop through each character
    char character = plaintext[i];             // Current character

    if (isalpha(character)) { // Only encrypt letters
      int shift = 3;          // Fixed shift of 3
      if (isupper(character)) // Uppercase letters
        character = ((character - 'A' + shift) % 26) + 'A';
      else // Lowercase letters
        character = ((character - 'a' + shift) % 26) + 'a';
    }

    plaintext[i] = character; // Store result back in string
  }
}

// Decrypt ciphertext using the Caesar cipher (shift by 3)
void caesar_decrypt(char ciphertext[]) {
  for (int i = 0; ciphertext[i] != '\0'; i++) { // Loop through each character
    char character = ciphertext[i];             // Current character

    if (isalpha(character)) { // Only decrypt letters
      int shift = 3;          // Fixed shift of 3
      if (isupper(character)) // Uppercase letters
        character = ((character - 'A' - shift + 26) % 26) + 'A';
      else // Lowercase letters
        character = ((character - 'a' - shift + 26) % 26) + 'a';
    }

    ciphertext[i] = character; // Store result back in string
  }
}
