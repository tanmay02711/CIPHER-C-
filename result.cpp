#include<iostream>
#include<string>
using namespace std;


//Global Variable//

string result = ""; 

string encryptCaeser(string text, int shift) 
{ 
    
  
  
    for (int i=0;i<text.length();i++) 
    { 
        
        if (isupper(text[i])) 
            result += char(int(text[i]+shift-65)%26 +65); 
  
    // Encrypt Lowercase letters 
    else
        result += char(int(text[i]+shift-97)%26 +97); 
    } 


        return result; 
} 


string decryptCaeser(string text, int shift) 
{ 
   result.clear();

    for (int i=0;i<text.length();i++) 
    { 
 
        if (isupper(text[i])) 
            result += char(int(text[i]-shift-65)%26 +65); 
  
    else
        result += char(int(text[i]-shift-97)%26 +97); 
    } 
  
    return result; 
} 


string generateKey(string str, string key) 
{ 
    int x = str.size(); 
  
    for (int i = 0; ; i++) 
    { 
        if (x == i) 
            i = 0; 
        if (key.size() == str.size()) 
            break; 
        key.push_back(key[i]); 
    } 
    return key; 
} 

string encryptVigenre(string str ,string key) 
{ 
    string cipher_text; 
  
    for (int i = 0; i < str.size(); i++) 
    { 
        // converting in range 0-25 
        int x = (str[i] + key[i]) %26; 
  
        // convert into alphabets(ASCII) 
        x += 'A'; 
  
        cipher_text.push_back(x); 
    } 
    return cipher_text; 
} 

string decryptVigenre(string cipher_text ,string key) 
{ 
    string orig_text; 
  
    for (int i = 0 ; i < cipher_text.size(); i++) 
    { 
        // converting in range 0-25 
        int x = (cipher_text[i] - key[i] + 26) %26; 
  
        // convert into alphabets(ASCII) 
        x += 'A'; 
        orig_text.push_back(x); 
    } 
    return orig_text; 
} 






int main()

{
    char str_message[100];
  
    int choose, shift;
    
  
  std::cout<<"Choose what you want to do \n A.Press 1  for caeser cipher Encryption and Decryption together\nB.Press 2  for virgence Cipher Encryption and Decryption\n"<<std::endl;
 
  std::cin>>choose ;
   cin.ignore(256, '\n');
  
  std::cout << "Enter a message to encrypt:";

  std::cin.getline(str_message, 100);

  switch (choose) {
          case 1: 
                  std::cout << "Enter the shift amount by numbers ";
                  std::cin >> shift;
                  std::cout << "Meassage after Encryption by Caeser : "<<encryptCaeser(str_message , shift)  <<std::endl;
                  std::cout<<"Press 1 to Decrypt this message that you have entered"<<std::endl;

                   int inter_choice;
                   std::cin>>inter_choice;
                   if(inter_choice==1)
                   std::cout <<"Meassage after Decryption by Carser:"<< decryptCaeser(result , shift) <<std::endl;
                   result.clear();
                   break;
          case 2:
                 {
                  char str_replace[100];
                  std::cout <<"Enter the key for vigenres:";
                  std::cin.getline(str_replace, 100);
                  std::cout <<str_replace;
                  std::string key =generateKey(str_message ,str_replace);
                  std::cout <<"Meassage after Generating key : "<<key <<std::endl;
                  std::string cipher_text =encryptVigenre(str_message ,key);

                  std::cout <<"Meassage after Encryption by Vigenre : "<<cipher_text<<std::endl;
                  std::cout<<"Press 2 to Decrypt this message that you have entered"<<std::endl;

                   int inter_choice2;
                   std::cin>>inter_choice2;
                   if(inter_choice2==2)
                   std::cout <<"Meassage after Decryption by Vigenre:"<<decryptVigenre(cipher_text, key) <<std::endl;
                   result.clear();
                   break; 
                   }    
                  default:
                  cout << "invalid option" << endl << endl;
                  break;
          }

 

  return 0;

}
