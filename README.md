# Encryption
## Introduction
   A simple project using Vigenère cipher(slightly different) to encrypt/decrypt characters(numbers or English letters) in C++.
## Encryption method
   The Vigenère cipher is a method of encrypting alphabetic text. If you want to know the details, you can go to Wikipedia to read. Next we will talk about the difference between my encryption method and the Vigenère cipher.<br>
   Vigenère cipher uses the following form to transfer characters to numbers.<br>
![](https://github.com/jimmy258s/encryption/raw/master/pic/2.png)<br>
   In order to include uppercase and lowercase letters and numbers. I use the following homemade table to convert the input characters.      This's the difference between my encryption method and the Vigenère cipher.<br>
![](https://github.com/jimmy258s/encryption/raw/master/pic/3.png)<br>
   Then you need to enter the key you want to use to encrypt the file. The key will be converted to a number as shown in table and then added to the characters. After adding and converting to ASCII characters, the output is the encrypted file. This shows that decryption is the subtraction between the character and the key.<br>
   For example, we can encrypt the message "abcde" with the three-letter keyword "abc", the initial key stream is (36, 37, 38), and the key stream is repeated for this initial key stream. Then the encryption process works as shown in the figure below.
![](https://github.com/jimmy258s/encryption/raw/master/pic/1.png)<br>
## How to use
### Encryption
   1. Download the encrypt.cpp and decrypt.cpp in ./home.
   2. Create the file(.txt) you want to encrypt ./home.
   3. Use vim to open encrypt.cpp.
   >  $ vim encrypt.cpp
   4. Compile encrypt.cpp and execute that.
   >  $ g++ encrypt.cpp -o encrypt -Wall
   >  $ ./encrypt
   5. Enter the input filename, remember to add .txt.
   6. Enter the key you want to use to enpcrypt the file.
   7. The encryptResult.txt will be output to ./home.
### Decryption
   1. Use vim to open decrypt.cpp.
   >  $ vim decrypt.cpp
   2. Compile decrypt.cpp and execute that.
   >  $ g++ decrypt.cpp -o decrypt -Wall
   >  $ ./decrypt
   5. Enter the input filename(encryptResult.txt), remember to add .txt.
   6. Enter the key you use to enpcrypt the file.
   7. The deryptResult.txt will be output to ./home.
   
   
