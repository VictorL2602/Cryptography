#include "vigenere.h" // include your own header first
#include <ctype.h>    // for isalpha(), isupper(), tolower()
#include <string.h>   // for strlen()

// Encrypt plaintext using the Vigenère cipher
void vigenere_encrypt(char plaintext[], char key[]) {
  int keyLength = strlen(key); // Get length of key

  for (int i = 0, j = 0; plaintext[i] != '\0'; i++) {
    char character = plaintext[i]; // Current character

    if (isalpha(character)) { // Only encrypt letters
      int shift =
          tolower(key[j % keyLength]) - 'a'; // Shift based on key letter

      if (isupper(character)) // Uppercase letters
        character = ((character - 'A' + shift) % 26) + 'A';
      else // Lowercase letters
        character = ((character - 'a' + shift) % 26) + 'a';

      j++; // Move to next key letter only when a letter was processed
    }

    plaintext[i] = character; // Store result back in string
  }
}

// Decrypt ciphertext using the Vigenère cipher
void vigenere_decrypt(char ciphertext[], char key[]) {
  int keyLength = strlen(key); // Get length of key

  for (int i = 0, j = 0; ciphertext[i] != '\0'; i++) {
    char character = ciphertext[i]; // Current character

    if (isalpha(character)) {                        // Only decrypt letters
      int shift = tolower(key[j % keyLength]) - 'a'; // Same shift as encryption

      // Add +26 before modulo to prevent negative results
      if (isupper(character))
        character = ((character - 'A' - shift + 26) % 26) + 'A';
      else
        character = ((character - 'a' - shift + 26) % 26) + 'a';

      j++; // Move to next key letter
    }

    ciphertext[i] = character; // Store result back in string
  }
}
