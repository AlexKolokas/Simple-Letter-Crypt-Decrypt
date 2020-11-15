#include <iostream>
#include <map>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

//FUNCTION TO PRINT THE MAP (if necessary)
//template<typename K, typename V>
//void print_map(map<K,V> const &m);


int factorialfun(int ); //FUNCTION THAT RETURN THE FACTORIAL OF THE NUMBER BUT IF THE NUMBER IS BIGGER THAT 12 RETURNS THE 12 FACTROIAL
int Sumfun(int );//FUNCTION TO FIND SUM
int findfactrorialdefun(int );//FUNCTION THAT FINDS THE REVERSE FACTORIAL
int Lettertonum(char,double,double );   //FUNCTION THAT THAKE A LETTER AND RETURN THE CODE FOR IT
int Getdecryptkeyfun();//FUNCTION THAT GETS THE KEY FOR THE DECRYPTION
int Getdecryptcodefun();//FUNCTION THAT GETS THE INPUT CODE FOR THE DECRYPTION
char TakeLetter();//FUNCTION THAT GETS THE INPUT (LETTER)FROM THE USER. AND RETURN ONLY UPPER LETTERS
bool CryptOrDecrypt();//FUNCTION TO ASK THE USER IF WANTS TO ENCRYPT OR DECRYPT

int main()
{
    map<char,int> m;

    char ab[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; //alphabetic table
    int KsH[26] = {4,4,4,5,6,4,4,4,4,4,5,2,2,2,7,2,2,5,3,6,2,2,2,5,5,4}; //table with the number of letters that each letter has

//in the loop we make pair of the letter and the key
    for(int i=0; i<26; i++)
    {
        m.insert(make_pair(ab[i],((i+1)*10+KsH[i]))); // i is the counter for the loop but also the first half of the key
    }
    // cout<<"map with the key : "<<endl;
    //print_map(m);

    if(CryptOrDecrypt()) // IF THE CHOICE WAS ENCRYPT
    {
        char letter;
        int numcode,thesiletter,arithmosgram;
        int  helpforkeybigger13,keyy;

        letter=TakeLetter();
        for(int i=0; i<26; i++)
        {
            if(letter==ab[i])
            {
                thesiletter=i+1;
                arithmosgram=KsH[i];
            }

        }

        numcode=Lettertonum(letter,thesiletter,arithmosgram);
        cout<<"The code is: " <<numcode<<endl;
        helpforkeybigger13=thesiletter-12;
        if (thesiletter>=13 &&thesiletter<22 )
        {
            keyy=(m.at(letter)%10)*10+helpforkeybigger13;//The key for the big letters
            cout << "The key is: "<< keyy << endl;
        }
        else if(thesiletter>=22)
        {
            keyy=(m.at(letter)%10)*100+helpforkeybigger13; //The key for the big letters
            cout << "The key  is: "<< keyy << endl;
        }
        else
        {
            cout << "The key is:"<< m.at(letter)%10<< endl ;

        }

    }


    // for decryption
    else
    {
        int key,athrisma,newcode=0,code,fact,KeyofLetter,thesi ;
        code= Getdecryptcodefun();
        key=Getdecryptkeyfun();
        int remainofthekey=0;
        bool foundthekeysize=false;
        if(key/100>=1) //key/100>=1 it means that the key have 3 digit so the letter is between v-z
        {
            remainofthekey= key%100;//returns the 2 digits at the end of the key
            while (key >= 10)
                key/= 10;
            athrisma =Sumfun(key);
            newcode=code-athrisma;
            fact=findfactrorialdefun(newcode)+remainofthekey;
            foundthekeysize=true;
        }

        else if(key/10>=1 && foundthekeysize!=true)
        {
            remainofthekey= key%10;
            while (key >= 10)
                key/= 10;
            athrisma =Sumfun(key);
            newcode=code-athrisma;
            fact=findfactrorialdefun(newcode)+remainofthekey;
        }
        else
        {
            athrisma =Sumfun(key);
            newcode=code-athrisma;
            fact=findfactrorialdefun(newcode);

        }
        KeyofLetter=fact*10+key;
        for_each(m.begin(),m.end(),[&KeyofLetter](const pair<char, int> &p)
        {

            if (p.second == KeyofLetter)
            {

                cout <<"The letter is: "<< p.first <<endl;

            }
        });

    }

    system("pause");

}
//-------------------FUNCTIONS--------------------------------------

//FUNCTION TO PRINT THE MAP (if necessary)
/*template<typename K, typename V>
void print_map(map<K,V> const &m)
{
    for (auto const& pair: m)
    {
        cout << "{" << pair.first << ":" << pair.second << "}\n";
    }
}
*/

//FUNCTION THAT RETURN THE FACTORIAL OF THE NUMBER BUT IF THE NUMBER IS BIGGER THAT 12 RETURNS THE 12 FACTROIAL
int factorialfun(int n)
{
    int factorial = 1;
    if(n>=13)
    {
        //   cout<<"Factorial bigger that 12 "<<endl;
        factorial =1;
        n=12;
    }

    for(int i = 1; i <=n; ++i)
    {
        factorial =factorial * i;
    }
    return factorial;
}

//FUNCTION TO FIND SUM
int Sumfun(int z)
{
    int sum=0;
    for(int i=0; i<=z; i++)
        sum=sum+i;
    return sum;
}

//FUNCTION THAT THAKE A LETTER AND RETURN THE CODE FOR IT
int Lettertonum(char gramma,double thesigramma,double arithmosgram)
{
    double fackt,sumer,codeofletter;

    fackt= factorialfun(thesigramma);

    sumer=Sumfun(arithmosgram);

    return codeofletter=fackt+sumer;
}

//FUNCTION THAT GETS THE INPUT (LETTER)FROM THE USER. AND RETURN ONLY UPPER LETTERS
char TakeLetter()
{
    char letterinfun;
    cout<<"Give the letter"<<endl;
    cin>>letterinfun;
    if(islower(letterinfun))
        letterinfun= toupper(letterinfun);
    return letterinfun;
}

//FUNCTION TO ASK THE USER IF WANTS TO ENCRYPT OR DECRYPT
bool CryptOrDecrypt()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // for the console to print the lines green
    bool encrypt;
    char choice;
    SetConsoleTextAttribute(hConsole, 2);// for the console to print the lines green
    cout<<"_________________________"<<endl;
    SetConsoleTextAttribute(hConsole, 15) ;// for the console to print the lines back to normal
    cout<<"You want to encrypt(e) or Decrypt(d)? "<<endl;
    do
    {
        cin>>choice;
        if(choice=='E'|| choice=='e')
        {
            encrypt=true ;
            cout<<endl;
            cout<<"Ok lets Encrypt" <<endl;
        }
        else if(choice=='D'||choice=='d')
        {
            encrypt=false;
            cout<<endl;
            cout<<"lets decrypt "<<endl;
        }

        SetConsoleTextAttribute(hConsole, 2);// for the console to print the lines green
        cout<<"_________________________"<<endl;
        SetConsoleTextAttribute(hConsole, 15) ;// for the console to print the lines back to normal

    }
    while( choice!='E' && choice!='e' &&choice!='D'&& choice!='d' );
    return encrypt;
}

//FUNCTION THAT GETS THE INPUT CODE FOR THE DECRYPTION
int Getdecryptcodefun()
{
    int codefordecrypt;
    cout<<"Give the code for decryption : ";
    cin>>codefordecrypt;
    return codefordecrypt;

}

//FUNCTION THAT GETS THE KEY FOR THE DECRYPTION
int Getdecryptkeyfun()
{
    int key;
    cout<<"Give the key : ";
    cin>>key;
    return key;
}

//FUNCTION THAT FINDS THE REVERSE FACTORIAL
int findfactrorialdefun(int x)
{
    for(int i=1; i<12; i++)
    {
        x /=i;
        if(x==1)
        {
            return i;
            break;
        }
    }
}
