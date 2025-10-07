# Cryptography Project

This program can encrypt and decrypt messages using two methods:
- **Caesar cipher** (moves each letter by 3)
- **Vigenere cipher** (uses a word as a secret key)


**main.c**  
This is the main file. It reads what you type in the terminal (the cipher, whether you want to encrypt or decrypt, your message, and maybe a key).  
It doesn’t do any math — it just calls the right function.

**src/caesar.c**  
This file has the code for the Caesar cipher.  
It always shifts letters by 3 (A→D, B→E, etc.).  
It has two functions: one to encrypt and one to decrypt.

**src/vigenere.c**  
This file has the code for the Vigenere cipher.  
It uses a word (like “KEY”) to decide how much each letter moves.  
It also has two functions: one for encrypt and one for decrypt.

**include/caesar.h** and **include/vigenere.h**  
These are the header files.  
They tell the computer what functions exist in each cipher file.  
They use a special comment style called *Doxygen*, which helps make documentation automatically.


## How to use it

When you build the project, you get a program called main.exe  
You run it in the terminal like this:

### Caesar examples
./main caesar encrypt Hello
Encrypted message: Khoor

./main caesar decrypt Khoor
Decrypted message: Hello
