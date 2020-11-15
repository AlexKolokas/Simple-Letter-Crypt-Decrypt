
# SIMPLE LETTER ENCRYPTION & DECRYPTION (S.L.E.D)

**S.L.E.D.** is a command line project for easy and simple encryption and after that decryption of letters. 
You run the program and you decide if you want to encrypt a letter or decrypt a code.
If you want to encrypt a letter you giving the letter as input and you take as output the code and a key.
In the other hand if you have a code and a key(maybe someone send it to you) you can run the program give as input the code and the key and the program it will give you back the letter.

## Helping Terms
- NumberOfLetters= the number of letters each letter has in Greek language(based on his position ). 
But the Greek alphabet has 24 letters no 26 so the y and z they don't have a Greek letter so i spell them in Greek as they are.
- letterPosition = The position of the letter in the alphabet
- PositionOfL= if the number is bigger that 12 then his position became the position of L so 12. 

| English Letter| Greek Letter | Greek name |NumberOfLetters |letterPosition |
| ------------- | ------------- |------------- |------------- |------------- |
| A | A  | ΑΛΦΑ |4|1|
| B | B  |ΒΗΤΑ |4|2|
| C | Γ  |ΓΑΜΑ |4|3|
| D | Δ  |ΔΕΛΤΑ |5|4|
| E | Ε  |ΕΨΙΛΟΝ|6|5|
| F | Ζ  |ΖΗΤΑ|4|6|
| G | Η  |ΗΤΤΑ |4|7|
| H | Θ  |ΘΗΤΑ |4|8|
| I | Ι  |ΙΩΤΑ |4|9|
| J | Κ  |ΚΑΠΑ |4|10|
| K | Λ  |ΛΑΜΔΑ |5|11|
| L | Μ  |ΜΥ|2|12|
| M | Ν  |ΝΥ |2|13|
| N | Ξ  |ΞΙ |2|14|
| O | Ο  |ΟΜΙΚΡΟΝ |7|15|
| P | Π  |ΠΙ|2|16|
| Q | Ρ  |ΡΩ |2|17|
| R | Σ  |ΣΙΓΜΑ |5|18|
| S | Τ  |ΤΑΦ|3|19|
| T | Υ  |ΥΨΙΛΟΝ |6|20|
| U | Φ  |ΦΙ|2|21|
| V | Χ  |ΧΙ |2|22|
| W | Ψ  |ΨΙ |2|23|
| X | Ω  |ΩΜΕΓΑ |5|24|
| Y | -  |ΓΟΥΑΙ |5|25|
| Z | -  |ΖΕΝΤ |4|26|

## The Encryption Formula

 
- `The code of the letter` is : A-L= <a href="https://www.codecogs.com/eqnedit.php?latex=letterPosition!&plus;\sum_{0}^{NumberOfLetters}" target="_blank"><img src="https://latex.codecogs.com/svg.latex?letterPosition!&plus;\sum_{0}^{NumberOfLetters}" title="letterPosition!+\sum_{0}^{NumberOfLetters}" /></a>
L-Z =<img src="https://latex.codecogs.com/svg.latex?(PositionOfL)!&space;&plus;\sum_{0}^{NumberOfLetters}" title="Z=x! +\sum_{c}^{v}" /></a>
- `The Key of the letter` is :  A-L= NumberOfLetters , M-U = NumberOfLetters * 10+(letterPosition-12) , V-Z=NumberOfLetters * 100+(letterPosition-12)

## The Decryption Formula
- `A-L (the key is 1 digit)`= <a href="https://www.codecogs.com/eqnedit.php?latex=code&space;-\sum_{0}^{key}=&space;result" target="_blank"><img src="https://latex.codecogs.com/svg.latex?code&space;-\sum_{0}^{key}=&space;result" title="code -\sum_{0}^{key}= result" /></a>
then you divide the result with 2 and the result of the divide you divided it by 3 ...
until the result is equal to 1 .
 The divisor that gave the result equal to 1 is the factorial. The keyForTheLetter= Factrorial *10 +key. And from the key you found the letter.
- `M-U (the key is 2 digits)` = you isolate the first digit of the key. and the last digit of the key to a new variable( remain of the key). <a href="https://www.codecogs.com/eqnedit.php?latex=code&space;-\sum_{0}^{key}=&space;result" target="_blank"><img src="https://latex.codecogs.com/svg.latex?code&space;-\sum_{0}^{key}=&space;result" title="code -\sum_{0}^{key}= result" /></a> 
then you divide the result with 2 and the result of the divide you divided it by 3 ... until the result is equal to 1 .
 The divisor that gave the result equal to 1 +remain of the key is the factorial. The <a href="https://www.codecogs.com/eqnedit.php?latex=KeyForTheLetter=Factorial*10&plus;key" target="_blank"><img src="https://latex.codecogs.com/svg.latex?KeyForTheLetter=Factorial*10&plus;key" title="KeyForTheLetter=Factorial*10+key" /></a>. And from the key you found the letter.

- `V-Z (the key is 3 digits)` =  you isolate the first digit of the key. and the last 2 digits of the key to a new variable( remain of the key). <a href="https://www.codecogs.com/eqnedit.php?latex=code&space;-\sum_{0}^{key}=&space;result" target="_blank"><img src="https://latex.codecogs.com/svg.latex?code&space;-\sum_{0}^{key}=&space;result" title="code -\sum_{0}^{key}= result" /></a> 
then you divide the result with 2 and the result of the divide you divided it by 3 ... until the result is equal to 1 .
 The divisor that gave the result equal to 1 +remain of the key is the factorial. The <a href="https://www.codecogs.com/eqnedit.php?latex=KeyForTheLetter=Factorial*10&plus;key" target="_blank"><img src="https://latex.codecogs.com/svg.latex?KeyForTheLetter=Factorial*10&plus;key" title="KeyForTheLetter=Factorial*10+key" /></a>. And from the key you found the letter.

## Examples

- **Letter G** : `code`=5050 , `key`=4

- **Letter S** : `code`=479001606 , `key`=37

- **Letter Z** : `code`=479001610 , `key`=414

## Compile

Download and use the gcc compiler to compile the project. Depending on your operating system, type the following to compile:

#### Windows:

```bash
cd directory of the .cpp file
g++ CryptoV1.cpp -o crypto.exe
crypto.exe
```
crypto is just a name for the .exe you can give whatever you want.

#### Linux:

```bash
cd directory of the .cpp file
g++ CryptoV1.cpp 
./a.out
```
a.out is the default output of the g++ name of file.cpp command


