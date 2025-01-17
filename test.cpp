#include<iostream>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<stdlib.h>
#include<vector>
#include<queue>
#include <thread>
#include <chrono>
#define ll long long
#define ull unsigned long long

using namespace std;


struct date{ // this data type belongs to generate_password_based_on_data() function
    string day , month , year;
};

struct name{// this data type belongs to generate_password_based_on_data() function
    string first;
    string last;
};

struct types{// this data type belongs to password_checker() function
    bool exist = false;
    ll count = 0;
};
 

// global variables
bool inside = true;
int operation;


void welcome(); 
/*
author : omar ibrahim

Date : 5 / 8 / 2024

Descreption :

here I wrote the welcome message
*/

void options(); 
/*
author : omar ibrahim

Date : 5 / 8 / 2024

Descreption :

here I showed the options in our programme to the user
*/

void log_out(); 
/*
author : omar ibrahim

Date : 5 / 8 / 2024

Descreption :

here I asked the user if he wants to log out from the programme
*/

void ask_and_save_after_creation(string s);
/*
    author : omar ibrahim

    Date : 30 / 8 / 2024

    Descreption : 

    it's function which ask user to if he want save the password which has been generated and save it if he wanted
*/

void password_generation_options();
/*
author : omar ibrahim

Date : 5 / 8 / 2024

Descreption :

this is function which show the types of password generation
*/


void generate_random_password(); 
/*
author : omar ibrahim

Date : 5 / 8 / 2024

Descreption :

it's the function which generate the random password
*/

void generate_password_based_on_data(); 
/*
author : omar ibrahim

Date : 5 / 8 / 2024

Descreption :

it's the function which generate password based on data
*/


void password_checker(); 
/*
author : omar ibrahim

Date : 6 / 8 / 2024

Descreption :

it's the function which check your password and till you if you must increase the strength of the password
*/

void welcome_to_saver_password(); 
/*
author : omar ibrahim

Date : 8 / 8 / 2024

Descreption :

 this function to show the user what can sav_pass() function do.
*/

void password_saver(); 
/*
author : yassin taher

Date : 7 / 8 / 2024

Descreption :

it's the function which let you save your password in file on your machine and you can get it back again

*/
void here();
/*
author : omar ibrahim

Date ; 30 / 8 / 2024

Descreption : adding some delaying to the outputs

*/
int main(){ // -> omar ibrahim , 5 / 8 / 2024 , main function
    welcome();
    this_thread::sleep_for(chrono::seconds(2));
    while(inside){
        options();
        system("CLS");
        if (operation == 1) {
            password_generation_options();
        } else if (operation == 2) {
                password_saver();
                log_out();
        } else if (operation == 3) {
                password_checker();
                log_out();
        } else if (operation == 4) {
            inside = false;
        } else {
            cout << "\n**** wrong input , please try again *****\n";
            options();
            system("CLS");
        }
    }
    if(!inside)
        cout<<"\nOk , let us see you again :(";
}


void welcome(){
    string intro = "*********** welcome sir, This is undisputed_password , the most efficient security_app in egypt ****";
    for(int i = 0 ; i < 100 ; i++)
        cout<<"*";
    cout<<endl;

    cout<<intro;

    cout<<endl;
    for(int i = 0 ; i < 100 ; i++)
        cout<<"*";
    cout<<endl<<endl<<endl;

}

void options(){
    operation = 0; 
    cout<<"We Have a Lot Of Services To Introduce It To You : \n";
     here();
    string options[4] = { "1 - Generate Password" , "2 - Save My Passwords" , "3 - Password Checker" , " \n\n\n4 - Log Out"};
    int answer;
    for(int i = 0 ; i < 4 ; i++){
        cout<<options[i]<<endl;
        here();
    }
    cout<<"Please Enter Number Of the Service Witch You Want -> \n";
    here();
    cout<<"The Service : ";cin>>answer;
    operation = answer;

}

void log_out(){
    char opinion;
    here();
    cout<<"\n\n do you want get out from programme ? ( y or n)\n";
    here();
    cout<<"enter : ";cin>>opinion;
    system("CLS");
    if(opinion == 'y'){
        inside = false;
    }
    else if (opinion != 'y' && opinion != 'n'){
        cout<<"\n**** wrong input , please try again *****\n";
        log_out();
     }
}

void password_generation_options(){
    int ans;
    cout<<"\nOk , Now You Want Generate a Password , But Please till me if you want \n";
    here();
    cout<<"1 - generate it randomly.\n";
    here();
    cout<<"2 - generate it based on data witch you will enter.\n";
    here();
    cout<<"Please Enter 1 or 2 : ";cin>>ans;
    // read the answer from user
    system("CLS");
    if(ans == 1){
        generate_random_password();
        log_out();
    }
    else if(ans == 2) {
        generate_password_based_on_data();
        log_out();
    }
    else{
        cout<<"\n**** wrong input , please try again *****\n";
        password_generation_options();
    }
}

void  ask_and_save_after_creation(string s){
    char op;
    back_to_here:
    here();
    cout<<"\nWould you like save your password in our DataBase (y or n) : ";cin>>op;
    system("CLS");

    if(op != 'y' && op != 'n'){
        cout<<"wrong input Try again !!?";
        here();
        system("CLS");
        goto back_to_here;
    }

    else if (op == 'y') {
    cin.ignore(); // To ignore the newline character after the integer input 

    string password; // preparing the data to save
    here();
    cout<<"\nenter (name of web site) : ";
    cin>>password;
    password +=" "+s; 

    fstream file ; // saving data
    file.open("PasswordsandWebsites.txt" , ios::app);
    file<<password<<"\n" ;

    file.close();
    system("CLS");
    here();
    cout<<"\nDone , the password saved.\n";

    }

    else {
    here();
        cout << "ok,have a nice time :)";
        here();
        system("CLS");
    }

}

void generate_random_password(){ 

    srand(time(0));
    int ans , select , idx;
    string password = "";
    const char CHARS[7] = {'!' , '@' , '#' , '&' , '%' , '^' , '*'};
    vector<char>upper;
    vector<char>lower;
    vector<char>nums;
    for(int i = 65 ; i <= 90 ; i++)
        upper.push_back(char(i));
    for(int i = 97 ; i <= 122 ; i++)
        lower.push_back(char(i));
    for(int i = 48 ; i <= 57 ; i++)
        nums.push_back(char(i));
    cout<<"How difficult do you want the password to be ? (enter 1 or 2 or 3) \n\n";
     here();
    cout<<"1 - easy\n";
     here();
        cout<<"2 - medium\n";
        here();
        cout<<"3 - hard\n";
         here();
    cout<<"enter :";
    cin>>ans;
    system("CLS");
    // from here start generation
    if(ans == 1) {
        int limit = 12;
        while(limit--){
            select = 1 + rand() % 2;
            if(select == 1){
                idx = rand () % 26;
                password.push_back(upper[idx]);
            }
            else{
                idx = rand () % 26;
                password.push_back(lower[idx]);
            }
        }
         here();
        cout<<"your password is : "<<password;
        here();
         ask_and_save_after_creation(password);
    }
    else if(ans == 2){
        int limit = 14;
        while(limit--){
            select = 1 + rand() % 3;
            if(select == 1){
                idx = rand () % 26;
                password.push_back(upper[idx]);
            }
            else if (select == 2){
                idx = rand () % 26;
                password.push_back(lower[idx]);
            }
            else{
                idx = rand () % 10;
                password.push_back(nums[idx]);
            }
        }
         here();
        cout<<"your password is : "<<password;
         here();
        ask_and_save_after_creation(password);
    }
    else if(ans == 3){
        int limit = 16;
        while(limit--){
            select = 1 + rand() % 4;
            if(select == 1){
                idx = rand () % 26;
                password.push_back(upper[idx]);
            }
            else if (select == 2){
                idx = rand () % 26;
                password.push_back(lower[idx]);
            }
            else if(select == 3){
                idx = rand () % 10;
                password.push_back(nums[idx]);
            }
            else{
                idx = rand () % 7;
                password.push_back(CHARS[idx]);
            }
        }
         here();
        cout<<"your password is : "<<password;
        here();
         ask_and_save_after_creation(password);
         
    }
    else{
        cout << "\n**** wrong input , please try again *****\n";
         generate_random_password();
    }

}


void generate_password_based_on_data(){
   srand(time(0));
    name nm;
    date birthday;
    string favouriteNum;
    int  string_idx , character_idx , string_size;
    string password = "";
    string favourite_color = "";
    vector<string>choose;

    cout
            << "\nOk , I need some data to generate the password , data like ( name , birthday , favourite color , favourite number) \n";
             here();
    cout
            << "\n---> warning , in this section the level of password does not depends on type of characters,\n but depends on the length of password,"
            <<" therefore the length of the password will be longer than the usual.\n\n";
            here();

return_to_here_if_user_entered_numbers_in_his_name: // label for goto statment
    cout << "enter your name (first and last seperated by only one ** space **) : ";
    cin >> nm.first >> nm.last;
    
       for(char i : nm.first){
            if(i>'z' || i < 'a' && i > 'Z' || i < 'A'){
             system("CLS");
                cout<<"\n*** wrong please enter numbers ***\n";
                goto  return_to_here_if_user_entered_numbers_in_his_name;
            }
        }

        for(char i : nm.last){
           if(i>'z' || i < 'a' && i > 'Z' || i < 'A'){
             system("CLS");
                cout<<"\n*** wrong please enter numbers ***\n";
                goto  return_to_here_if_user_entered_numbers_in_his_name;
            }
       }

system("CLS");
 here();
        return_to_here_if_user_didnot_enter_number_in_date: // label for goto statment
    cout << "\nenter your birthday (day month year) -> seperated by spaces : ";
    cin >> birthday.day >> birthday.month >> birthday.year;

       for(char i : birthday.day){
            if(i>'9' or i < '0'){
             system("CLS");
                cout<<"\n*** wrong please enter numbers ***\n";
                goto  return_to_here_if_user_didnot_enter_number_in_date;
            }
        }

        for(char i : birthday.month){
            if(i>'9' or i < '0'){
             system("CLS");
                cout<<"\n*** wrong please enter numbers ***\n";
                goto  return_to_here_if_user_didnot_enter_number_in_date;
            }
       }

        for(char i : birthday.year){
            if(i>'9' or i < '0'){
             system("CLS");
                cout<<"\n*** wrong please enter numbers ***\n";
                goto  return_to_here_if_user_didnot_enter_number_in_date;
            }
        }

system("CLS");
 here();
return_to_here_if_user_didnot_enter_number_in_favourite_number: // label for goto statment
    cout << "\nenter your favourite number : ";
    cin >> favouriteNum;
    for(char i : favouriteNum){
            if(i>'9' or i < '0'){
             system("CLS");
                cout<<"\n*** wrong please enter numbers ***\n";
                goto  return_to_here_if_user_didnot_enter_number_in_favourite_number;
            }
        }
system("CLS");
 here();
return_to_here_if_user_entered_numbers_in_his_favourite_color: // label for goto statment
    cout << "\nenter your favourite color : ";
    cin >> favourite_color;
    for(char i : favourite_color){
           if(i>'z' or i < 'a' and i > 'Z' or i < 'A'){
             system("CLS");
                cout<<"\n*** wrong please enter numbers ***\n";
                goto  return_to_here_if_user_entered_numbers_in_his_favourite_color;
            }
       }

system("CLS");

    choose.push_back(nm.first), choose.push_back(nm.last), choose.push_back(favourite_color) , choose.push_back(favouriteNum);
    choose.push_back(birthday.day), choose.push_back(birthday.month), choose.push_back(birthday.year);

    int ch_size = choose.size();

    int limit = 15; // start generation
    while (password.size() <= limit) {
        string_idx = rand() % ch_size;
        if(string_idx == 4){
            password+=choose[string_idx];
        }
        else if(string_idx == 5){
            password+=choose[string_idx];
        }
        else if(string_idx == 6){
            int end = 1 + rand() % 2;
            if(end == 1)
                password+=choose[string_idx].substr(0 , 2);
            else{
                password+=choose[string_idx].substr(2 , 2);
            }
        }
        else if(string_idx == 3){
            password+=choose[string_idx];
        }
        else {
            string_size = choose[string_idx].size();
            character_idx = rand() % string_size;
            password += choose[string_idx].substr(character_idx, 1);
        }
    }
     here();
    cout << "your password is : " << password;
     here();
     ask_and_save_after_creation(password);
}

void password_checker(){
    string password;
    types upper;
    types lower;
    types nums;
    types characters;
    cout << "\nwhen you enter the password , we will check and give you some tips to increase password strength\n";
     here();
    cout << "Enter your password : ";
    cin >> password;
    system("CLS");
    int sz = password.size();
    for (int i = 0; i < sz; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper.exist = true, upper.count++;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            lower.exist = true, lower.count++;
        } else if (password[i] >= '0' && password[i] <= '9') {
            nums.exist = true, nums.count++;
        } else {
            characters.exist = true, characters.count++;
        }
    }
        
    if (sz < 16) {
        if(upper.exist&&lower.exist&&nums.exist&&characters.exist&&upper.count>2&&lower.count>2&&nums.count>2&&characters.count>2){
                 here();
                cout<<"\n - your password is perfect :)\n";
        }
        else {
        if (upper.exist) {
            if (upper.count < 2) {
                 here();
                cout << " - You should increase the number of UPPER-CASE characters , make it more than 2\n";
            }
        } else {
             here();
            cout << " - Your password must contain UPPER-CASE characters\n";
        }
        if (lower.exist) {
            if (lower.count < 2) {
                 here();
                cout << " - You should increase the number of lower_case characters , make it more than 2\n";
            }
        } else {
             here();
            cout << " - Your password must contain lower_case characters\n";
        }
        if (nums.exist) {
            if (nums.count < 2) {
                 here();
                cout << " - You should increase the number of numbers characters , make it more than 2\n";
            }
        } else {
                here();
            cout << " - Your password must contain numbers characters\n";
        }
        if (characters.exist) {
            if (characters.count < 2) {
                here();
                cout << " - You should increase the number of special characters , make it more than 2\n";
            }
        } else {
            here();
            cout << " - Your password must contain special characters\n";
        }
        }
    }
    // best size for password is 16 characters so if it will consist of (upper , lower , nums , special chars) , the portion of every one is 4 elements from password ,
    // so if the password has been entered longer than 16 characters , count of every element should be more than 4
     else {
        if(upper.exist&&lower.exist&&nums.exist&&characters.exist&&upper.count>4&&lower.count>4&&nums.count>4&&characters.count>4){
            here();
            cout<<"\n - your password is perfect :)\n";
        }
        else{
        if (upper.exist) {
            if (upper.count < 4) {
                here();
                cout << " - You should increase the number of UPPER-CASE characters , make it more than 4\n";
            }
        } else {
            here();
            cout << " - Your password must contain UPPER-CASE characters\n";
        }
        if (lower.exist) {
            if (lower.count < 4) {
                here();
                cout << " - You should increase the number of lower_case characters , make it more than 4\n";
            }
        } else {
            here();
            cout << " - Your password must contain lower_case characters\n";
        }
        if (nums.exist) {
            if (nums.count < 4) {
                here();
                cout << " - You should increase the number of numbers characters , make it more than 4\n";
            }
        } else {
            here();
            cout << " - Your password must contain numbers characters\n";
        }
        if (characters.exist) {
            if (characters.count < 4) {
                here();
                cout << " - You should increase the number of special characters , make it more than 4\n";
            }
        }else {
            here();
            cout << " - Your password must contain special characters\n";
        }
        }
    }

}

void welcome_to_saver_password(){
    // to introduce the options to user without face problems with the stream
    cout<<"In this section you can save your passwords in file on your machine and you can get it back again when you want\n\n";
    here();
        cout<<"please select what do you want : \n";
         here();
        cout<<"1 - save new password\n";
         here();
        cout<<"2 - search about password\n";
         here();
        cout<<"enter (1 or 2) : ";

}

void password_saver(){ 
   welcome_to_saver_password();
     char n ;
    cin>>n;
    system("CLS");
    if(n=='1'){
    cin.ignore(); // To ignore the newline character after the integer input 
    string password ;
    here();
    cout<<"\nenter (name of web site and the password) *seperated space* : ";
    getline(cin,password) ;
    fstream PassFile ;
    PassFile.open("PasswordsandWebsites.txt" , ios::app) ;

    PassFile<<password<<"\n" ;

    PassFile.close();
    system("CLS");
    here();
    cout<<"\nDone , the password saved.\n";

    }
    else if(n=='2'){
    int idx;
    vector<string> passlist;
    string line, passwordFromFile, passwordToFind;
    fstream passFile("PasswordsandWebsites.txt");

    if (!passFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
    }
    here();
    cout<<"\nenter web site name : ";
    cin >> passwordToFind;

    // Read the file line by line
    while (getline(passFile, line)) {
        passlist.push_back(line);
    }

    // Search for the password
    bool found = false;
    for (int i = 0 ; i<passlist.size() ; i++) {
        stringstream ss(passlist[i]);
        ss >> passwordFromFile;

        if (passwordFromFile == passwordToFind) {
            system("CLS");
            here();
            cout<<"\nweb site & password : ";
            cout <<passlist[i]<< endl;
            found = true;
            break;
        }
    }

    if (!found) {
        here();
        cout << "Password not found." << endl;
    }

    passFile.close();

    }
    else{
        cout << "\n**** wrong input , please try again *****\n";
        password_saver();
    }

}

void here(){
    this_thread::sleep_for(chrono::seconds(1));
}
