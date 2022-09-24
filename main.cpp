/*This Program is a mini library system that manages the loaning and returning of books.
  Written By: Michael Getu Kebede
              Abel Abraha Abebe
              Elbet Tedros Getahun
  Written due: September 17,2021*/
//Standard Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <ctime>

#define nos 21
#define nob 11

using namespace std;

char sep,ans, *ptr1, *ptr2;
bool valid=true, repin=false, same=false, renam=false,full=true, match=false, change=false, reent=false, reenta=false,
     book=false, rebook=false, rebd=false, repeat=false;
int signin, choicepin,  choicepina, epin, epina, sz, sza, a, ns=0, choicelogin, choiceloan, *ptr3, *ptr5;
time_t now = time(0);
//Functions
int login(), admin(), loan(), returnb(), online(), pinf(), bdconf(), pinrecovf(), loggedin(), loggedina();

//Variables Related with book loan and return
string ename, bookname, enamea,lname= "HiLcoe";
int numbookloaned[nos];
int available[nob];
string bookloaned[nos];

//Data base of admin
string namea="Abebe Kebede";
int  pina=1092,*ptr4;
int bdadmin[3]={12,02,1995};
int phnadmin=917625723;

//Data base of name
string names[nos]= {"Abel Abraha Abebe", "Abem Aklilu Membere", "Amanuel Tewdros Kassahun" ,
                    "Elbet Tedros Getahun" , "Henok Bekele Feleke" , "Kirubel Esayas Mulugeta" ,
                    "Michael Getu Kebede" , "Samuel Meseret Habteariam" , "Saron Elias Metaferia" ,
                    "Sebrina Abdulrezak Teka" , "Selihom Kidane Gile" , "Soliyana Damiel Assefa" ,
                    "Surafel Abera Degife" , "Tsedeke Shawel Hailu","Tsion Wondwossen Hailu" ,
                    "Yakob Solomon Hailegebriel" , "Yeabsra Fikre Yilma" , "Yisak Abraham Kenfe" ,
                    "Yoftahe Dereje Mekonen" , "Yohannes Negash Ali"};
 //Data base of pin
int pin[nos]={1401,1402,1403,1404,1405,1406,1407,1408,1409,1410,1411,1412,1413,1414,1415,1416,1417,1418,1419,1420};
//Data base of Birth date
int bd[nos][3]={{12,01,2001},{13,02,2003},{15,05,2002},{12,07,2002},
                {22,11,2003},{23,18,2003},{18,11,2001},{18,15,2001},
                {19,19,2004},{23,18,2003},{20,14,2002},{13,18,2002},
                {11,15,2001},{16,16,2000},{10,16,2001},{02,11,2001},
                {03,17,2000},{13,14,2000},{07,11,2003},{28,18,2002}};
//Data base of phone number
long phoneno[nos]={911262343, 987767687, 969528775, 939714763, 961248120, 931646329, 969648326, 984655541, 924768763, 902486273,
                   929147236, 950148263, 947512364, 902634762, 952183645, 993640263, 956552340, 963463472, 934765239, 947623945};
//Data base of books
string bonames[nob]={"To Kill a Mockingbird", "The Great Gatsby", "A Passage to India", "Invisible Man",
                    "Don Quixote", "Beloved", "One Hundred Years of Solitude", "Lord of the Rings",
                    "Pinocchio", "Slouching Towards Bethlehem",};
//Main Function
int main()
{
    //Giving address to pointers
    ptr1=&ans;
    ptr3=&choicepina;
    ptr4=&pina;
    ptr5=&choiceloan;

    do{ //Loop if the user want to logout
        system("cls");
        do{ //Loop to validate an invalid entry of signin
            valid = true;
            repin = false;
            same = false;
            renam = false;
            full = true;
            match=false;
            change=false;
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            cout<<"+                             Welcome to library of "<<lname<<"                            +"<<endl;
            cout<<"+                                    1. Login                                         +"<<endl;
            cout<<"+                                    2. Administrator login                           +"<<endl;
            cout<<"+                                    3. Exit                                          +"<<endl;
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            cout<<"                                  Enter your choice: ";
            cin>>signin;
            cout<<endl;
            if(!cin)
            {
                cout<<"\nERROR. Please enter a valid entry."<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
                valid = false;
            }
            else if (signin < 1 || signin > 3)
            {
                cout<<"\nERROR. Please enter between 1-3."<<endl;
                valid = false;
            }
        }while(valid == false);
        switch (signin) //Selection of input
        {
            case 1:
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<login();
            break;
            case 2:
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<admin();
            break;
            case 3:
            return 0;
            break;
        }
        cout<<"Want to go logout? (Y/y): "<<endl;
        cin>>*ptr1;
    }while(*ptr1=='Y' || *ptr1=='y');
    return 0;
}
//Function to login
int login()
{
    do{//loop after a forgotten PIN was viewed
        do{ //Loop to validate invalid name
            valid = true;
            repin = false;
            same = false;
            renam = false;
            full = true;
            change = false;
            ns=0;
            cout<<"Enter your name"<<endl;
            cout<<"(First Second Last name in A case sensitive format): ";
            getline(cin, ename);
            sz=ename.size();
            for (int i=0; i<sz; i++) //Counting number of space
            {
                        if (ename[i]==' ')
                        {
                            ns=ns+1;
                        }
            }
            if (ns<2) //To validate a full name which must contain 2 spaces
            {
                full = false;
                cout<<endl;
                cout<<"ERROR. Please enter your full name."<<endl;
            }
            for (int i=0; i<nos-1 && (full!=false && same!=true); i++) //Finding the users name in data base
            {
                if ((ename.compare(names[i]))==0)
                {
                    same = true;
                    a=i;
                }
                else if ((ename.compare(names[i]))!=0)
                {
                    same = false;
                }
            }
            if (same==true) //Leading to pin confirm
            {
                cout<< pinf();
            }
            else if (same == false) //Name not found in Data base
            {

                    valid = true;
                    cout<<endl;
                    if (full == true)
                    {cout<<"ERROR. User not found."<<endl;}
                    renam=true;
            }
            }while(renam==true);
    }while(change==true);
    system ("pause");
    return 0;
}
//Function to confirm PIN
int pinf()
{
   do{//Loop after a user view PIN through Forgot password
        do{ //Loop to validate an invalid entry of PIN to be only 4 digits
            repin=false;
            reent=false;
            cout<<"\nEnter your PIN (4 digit): ";
            cin>>epin;
            cout<<endl;
            if (epin/1000 > 9 || !cin) //PIN greater than 4 digit or not a number
            {
                cout<<"\nERROR. Please enter a valid PIN of 4 digit."<<endl;
                if (!cin)
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    reent=true;
                }
            }
            else if (epin/1000 < 1 ) //PIN less than 4 digits
            {
                cout<<"Error. PIN must be 4 digits. Re Enter"<<endl;
                reent=true;
            }
        }while(epin/1000 > 9 || reent==true);
        if (pin[a]== epin) //PIN confrirm
        {
            system ("cls");
            cout<<"\nLogin successful."<<endl;
            cout<<endl;
            renam=false;
            cout<<loggedin();
        }
        else if (pin[a]!= epin) //Incorrect PIN
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"ERROR. PIN and Name don't match. "<<endl;
            do{ //Loop to re enter incorrect PIN
                valid = true;
                cout<<"1. Re-enter a correct pin"<<endl;
                cout<<"2. Forgot PIN"<<endl;
                cout<<"Enter your choice: ";
                cin>>choicepin;
                cout<<endl;
                if (choicepin != 1 && choicepin != 2)
                {
                    valid = false;
                }
                if(!cin || valid == false)
                {
                    cout<<"\nERROR. Please enter a valid entry."<<endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
            }while (!cin || valid == false);
            switch (choicepin)
            {
                case 1:
                    repin = true;
                    break;
                case 2:
                    cout<<bdconf();
                    break;
            }
        }
    }while (repin == true);
    return 0;
}
//Function to confirm brthday
int bdconf()
{
    int d,m,y,l;
    char answer;
    char sep;
    ptr2=&sep;
    cout<<"OK to successfully recover your PIN, Please enter your date of birth: "<<endl;
    do{ //loop for unable to find birth date match
    match=false;
     cout<<"Birth Date (DD/MM/YYYY): ";
     cin>>d>>*ptr2>>m>>*ptr2>>y;
     //Validating input for an invalid date format
     while (!cin) //As long as input isnt cin type the following statements in the while loop are going to be executed
     {
      cout<<"Invalid date entry. Re-enter date."<<endl;
      cout<<"Birth Date(DD/MM/YYYY): ";
      cin.clear(); //Clear input buffer
      cin.ignore(100, '\n'); //Ignore anything the user has previously entered
      cin>>d>>*ptr2>>m>>*ptr2>>y;
     }
     while (*ptr2!='/') //As long as sep1!='/' || sep2!='/' is satisfied the following statements in the while loop are going to be executed
     {
      cout<<"Invalid date format. Re-enter date."<<endl;
      cout<<"Birth Date(DD/MM/YYYY): ";
      cin>>d>>*ptr2>>m>>*ptr2>>y;
     }
     //Validating input for an invalid month or day
     while (d<=0 || (m<=0||y<=0)) //As long as d<=0 || (m<=0||y<=0) is satisfied the following statements in the while loop are going to be executed
     {
      cout<<"Entry Can not be a negative number or zero."<<endl;
      cout<<"Enter Birth Date(DD/MM/YYYY): ";
      cin>>d>>*ptr2>>m>>*ptr2>>y;
     }
     while (d>31 || m>12) //As long as d>31 || m>12 is satisfied the following statements in the while loop are going to be executed
     {
      cout<<"Invalid Date entry. Re-enter date."<<endl;
      cout<<"Enter Birth Date(DD/MM/YYYY): ";
      cin>>d>>*ptr2>>m>>*ptr2>>y;
     }
     while(m==2 && d==29) //Validating dates of february ie leap year or not
     {
       l=y%4;
       if (l==0)
       {
        l=y%100;
        if (l==0)
        {
         l=y%400;
         if (l!=0)
         {
          cout<<"The month of february can not be 29 for the given year. Please Re enter." <<endl;
          cout<<"Enter Birth Date(DD/MM/YYYY): ";
          cin>>d>>sep>>m>>sep>>y;
         }
        }
       }
       else if(l!=0)
       {
        cout<<"The month of february can not be 29 for the given year. Please Re enter."<<endl;
        cout<<"Enter Birth Date(DD/MM/YYYY): ";
        cin>>d>>sep>>m>>sep>>y;
       }
      }
     while(m==2 && d>29)
     {
      cout<<"The month of february can not be above 29 days. Please Re enter."<<endl;
      cout<<"Enter Birth Date(DD/MM/YYYY): ";
      cin>>d>>sep>>m>>sep>>y;
     }
     //Validating input for months the day can't be 31
     while (d==31) //As long as d=31 is satisfied the following statements in the while loop are going to be executed
     {
      if (m<7 && (m%2)==0 ) //Selection via if for days that have only 30 days
      {
       cout<<"Date can not be 31 for the given month. Re-enter date."<<endl;
       cout<<"Enter Birth Date(DD/MM/YYYY): ";
       cin>>d>>sep>>m>>sep>>y;
      }
      else if (m>8 && (m%2)!=0) //Selection via if for days that have only 30 days
      {
       cout<<"Date can not be 31 for the given month. Re-enter date."<<endl;
       cout<<"Enter Birth Date(DD/MM/YYYY): ";
       cin>>d>>sep>>m>>sep>>y;
      }
     }
    cout<<endl;
    if (bd[a][2]==y)
    {
        if (bd[a][1]==m)
        {
            if (bd[a][0]==d)
            {
                match = true;
                cout<<pinrecovf();
            }
            else
            {
                match = false;
            }
        }
        else
        {
            match = false;
        }
    }
    else
    {
        match = false;
    }
    if (match == false)
    {
        cout<<"Birth date and name don't match. Re-enter Birthday."<<endl;
    }
    }while(match==false);
    return 0; //Successfully completed
}
//Function to recover forgotten PIN
int pinrecovf()
{
    cout<<"You're PIN is "<<pin[a]<<endl; //View PIN
    cin.clear();
    cin.ignore(1000,'\n');
    change=true;
    return 0;
}
//Function after logging in
int loggedin()
{
    bool keep=false;
    do{
    valid=true;
    keep=false;
    cout<<"Hi "<<ename<<" Hope everything is going well and great."<<endl;
    cout<<"1. Loan out a book"<<endl;
    cout<<"2. Return a book"<<endl;
    cout<<"3. On line Library"<<endl;
    cout<<"What do you wanna do this moment: ";
    cin>>choicelogin;
    cout<<endl;
    if (choicelogin <<1 && choicelogin >>2)
    {
        valid = false;
    }
    if(!cin || valid == false)
    {
        cout<<"\nERROR. Please enter a valid entry."<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }
    while (repeat==true || valid == false)
    {
        valid=true;
        repeat=false;
        cout<<"Hi "<<ename<<" Hope everything is going well and great."<<endl;
        cout<<"1. Loan out a book"<<endl;
        cout<<"2. Return a book"<<endl;
        cout<<"3. On line Library"<<endl;
        cout<<"What do you wanna do this moment: ";
        cin>>choicelogin;
        if (choicelogin <<1 && choicelogin >>2)
        {
            valid = false;
        }
        if(!cin || valid == false)
        {
            cout<<"\nERROR. Please enter a valid entry."<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            repeat=true;
        }
    }
    switch (choicelogin)
    {
        case 1:
            if(numbookloaned[a]==1 && bookloaned[a]!=" ") //Already loaned book
            {
                cout<<"You have already loaned book."<<endl;
                cout<<"Please return current loaned book to loan another."<<endl;
                do{
                cin.clear();
                cin.ignore(1000,'\n');
                reent=false;
                cout<<"1. Return book"<<endl;
                cout<<"2. Keep Book"<<endl;
                cin>>*ptr5;
                switch (choiceloan)
                {
                    case 1:
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cout<<returnb();
                    break;
                    case 2:
                    keep=true;
                    break;
                default:
                    cout<<"Invalid chice. Re-enter.";
                    reent=true;
                }
                }while(reent==true);
            }
            else if(numbookloaned[a]==0)
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<loan();
            }
            break;
        case 2:
            if(numbookloaned[a]==1 && bookloaned[a]!=" ")
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<returnb();
            }
            else
            {
                cout<<"You have not loaned any book yet."<<endl; //No book loaned to return
                keep=true;
            }
            break;
        case 3:
            cout<<endl;
            cout<<"Online Library is coming soon..."<<endl;;
            cout<<"Untill then use libgen.is to download any book you want."<<endl;
            cout<<"Thanks for your patience."<<endl;
            break;
    }
    }while (keep==true);
    return 0;
}
//Function to loan
int loan()
{
    do{
        rebook=false;
        cout<<"What book do you want to loan: ";
        getline(cin, bookname);
        for (int i=0; i<nos; i++)
        {
            if(bookloaned[i]==bookname) //Book already loaned by someone else
            {
                cout<<"Requested Book is already loaned out by "<<names[i]<<". Try another book."<<endl;
                book=true;
                rebook=true;
            }
        }
        for (int i=0; i<nob && book!=true; i++)
        {
            if ((bookname.compare(bonames[i]))==0)
            {
                book = true;
                rebook=false;
            }
            else if ((bookname.compare(bonames[i]))!=0)
            {
                book = false;
            }
        }
        if (book==true && rebook==false)
        {
            bookloaned[a]=bookname;
            numbookloaned[a]=1;
            available[a]=1;
            char* date_time = ctime(&now);
            cout<<endl;
            cout<<"Have a great time reading "<<bookloaned[a]<<endl;
            cout<<"Great choice. Don't forget to return book with in the coming 5 days."<<endl;
            cout<<endl;
            cout<<"You have currently loaned "<<numbookloaned[a]<<" book at "<<date_time<<endl;

        }
        else if (book == false)
        {
            cout<<endl;
            cout<<"ERROR. Book not found. Re-enter"<<endl;
        }
    }while(book == false || rebook==true);
    return 0;
}
//Function to loan returning
int returnb()
{
    do{ //loop for book not find in data base
    string rbookname;
    book=true;
    cout<<endl;
    cout<<"Hope you're reading was great."<<endl;
    cout<<"Whats the title of the book you want to return: ";
    getline(cin, rbookname);
    if (bookloaned[a]==rbookname) //Finding requested book match
    {
        for (int i=0; i<nob+1 && book!=true; i++)
    {
        if ((rbookname.compare(bonames[i]))==0)
        {
            book = true;
            a=i;
        }
        else if ((rbookname.compare(bonames[i]))!=0)
        {
            book = false;
        }
    }
    if (book==true ) //Found book match
    {
            bookloaned[a]=" ";
            numbookloaned[a]=0;
            available[a]=1;
            cout<<endl;
            cout<<"Have a great day "<<endl;
            cout<<endl;
            cout<<"You have currently loaned "<<numbookloaned[a]<<" book."<<endl;

    }
    else if (book == false) //Boook no match
    {
            cout<<endl;
            cout<<"ERROR. Book not found. Re-enter"<<endl;
    }
    }
    else //Book outside library
    {
        cout<<"Thats not the book the library loaned you."<<endl;
        book=false;
    }
    }while(book == false);
}
//Function for admin login
int admin()
{
    do{ //Loop for incorrect admin name
    do{
    full = true;
    ns=0;
    cout<<endl;
    cout<<"Enter your name "<<endl;
    cout<<"Fist and second name: ";
    getline(cin, enamea);
    sza=enamea.size();
    for (int i=0; i<sza; i++)
    {
        if (enamea[i]==' ') //Finding spaces
        {
            ns=ns+1;
        }
    }
    if (ns<1)
    {
        full = false;
        cout<<endl;
        cout<<"ERROR. Please enter your full name."<<endl;
    }
    }while(full==false);
    if ((enamea.compare(namea))==0)
    {
        same = true;
    }
    else if (enamea.compare(namea)!=0)
    {
        same = false;
    }
    if (same==true)
    {
        do{
        reenta=false;
        repin=false;
        cout<<endl;
        cout<<"Enter your PIN: ";
        cin>>epina;
        if (epina==*ptr4)
        {
            cout<<loggedina();
        }
        else
        {
            if (!cin)
            {
               cout<<"Enter a valid PIN."<<endl;
            }
            else if (epina/1000 < 1 || epina/1000 > 9 )
            {
                cout<<"Error. PIN must be 4 digits. Re Enter"<<endl;
            }
            else
            {
                cout<<"Error. PIN of Admin incorrect. Re Enter"<<endl;
            }
                do{
                repin = false;
                valid = true;
                cout<<"1. Re-enter a correct pin"<<endl;
                cout<<"2. Forgot PIN"<<endl;
                cout<<"Enter your choice: ";
                cin>>*ptr3;
                cout<<endl;
                if (*ptr3 != 1 && *ptr3 != 2)
                {
                    valid = false;
                }
                if(!cin || valid == false)
                {
                    cout<<"\nERROR. Please enter a valid entry."<<endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
            }while (!cin || valid == false);
            switch (choicepina)
            {
                case 1:
                    repin = true;
                    break;
                case 2:
                    do{
                    rebd=false;
                    int dd,mm,yy;
                    cout<<"Enter Birth date(dd/mm/yyyy): ";
                    cin>>dd>>sep>>mm>>sep>>yy;
                    if (!cin)
                    {
                        cout<<"Invalid or incorrect Birth day.";
                        rebd=true;
                        cin.clear();
                        cin.ignore(1000,'\n');
                    }
                    else if(dd==bdadmin[0])
                    {
                        if(mm==bdadmin[1])
                        {
                            if(yy==bdadmin[2])
                            {
                                cout<<"Your Pin is "<<*ptr4;
                            }
                            else
                            {
                                cout<<"Invalid or incorrect Birth day.";
                                rebd=true;
                            }
                        }
                        else
                        {
                            cout<<"Invalid or incorrect Birth day.";
                            rebd=true;
                        }
                    }
                    else
                    {
                        cout<<"Invalid or incorrect Birth day.";
                        rebd=true;
                    }
                    }while(rebd==true);
                    break;
            }
            cin.clear();
            cin.ignore(1000,'\n');
            reenta=true;
        }
        }while(repin==true);
    }
    else if (same == false)
    {
        reenta=true;
        cout<<endl;
        cout<<"Error. Admin name incorrect.Re enter."<<endl;

    }
    }while(reenta==true);
}
//Function after admin login to view inventory and loans
int loggedina()
{
    system ("cls");
    cout<<"Admin Log in Successful"<<endl;
    cout<<"Heres is the list of available books."<<endl;
    int n=1;
    for(int i=0;i<nob-1;i++) //Listing available books
    {
        if(available[i]==0)
        {
            cout<<n<<". "<<bonames[i]<<endl;
            n++;
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<"Heres the list of people with books loaned."<<endl;
    cout<<endl;
    cout<<"|  Name"<<setw(38)<<"| Book Loaned"<<setw(39)<<"| Phone Number"<<endl; //Listing Loaned books
    cout<<"______________________________________________________________________________________"<<endl;
    for(int i=0;i<nos-1;i++)
    {
        if(numbookloaned[i]!=0)
        {
            int szn=names[i].size();
            int szb=bookloaned[i].size();
            cout<<"|  "<<names[i]<<setw(30-szn)<<"|"<<bookloaned[i]<<setw(40-szb)<<"| 0"<<phoneno[i]<<endl;
        }
    }
    return 0;
}
