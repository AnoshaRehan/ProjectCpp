//The orignal code for this program : https://fahad-cprogramming.blogspot.com/2016/03/school-management-cpp-project-source-code.html


#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h> //for getch()
#include <windows.h>//for system calls
#include <stdio.h>
#include <cwchar> //for fontsize+fontstyle

using namespace std;

class person
{
	public:
		virtual void deleting()=0;
};

class student : public person
{
 public:
 string fname;//for student first name
 string lname;//for student last name
 string Registration;//for Registration No number
 string class_section;//for class info
 void deleting()
{
    string line, name;
    cout << "Please Enter the name of record you want to delete: ";
    cin >> name;
    ifstream f2;
    ofstream temp;
    f2.open("student.txt");
    temp.open("temp.txt");
    while (getline(f2, line))
    {
        if (line != name)
            temp << line << endl;
    }
    cout << "The record with the name " << name << " has been deleted if it exsisted" << endl;
    f2.close();
    temp.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");
}
};

class teacher
{
 public:
 string fst_name;//first name of teacher
 string lst_name;//last name of teacher
 string qualification;//Qualification of teacher
 string exp;//Experiance of the person
 string pay;//Pay of the Teacher
 string subj;//subject whos he/she teach
 string lec;//Lecture per Week
 string addrs;//Adders of teacher home
 string cel_no;//Phone number 
 string blod_grp;//Bool Group 
 string serves;//Number of serves in School

};


void deleting_T()
{
    string line, name;
    cout << "Please Enter the name of record you want to delete: ";
    cin >> name;
    ifstream f2;
    ofstream temp;
    f2.open("teacher.txt");
    temp.open("temp.txt");
    while (getline(f2, line))
    {
        if (line != name)
            temp << line << endl;
    }
    cout << "The record with the name " << name << " has been deleted if it exsisted" << endl;
    f2.close();
    temp.close();
    remove("teacher.txt");
    rename("temp.txt", "teacher.txt");
}

int main(void)
{
/* CONSOLE WINDOW COLOUR */
   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
/* FONT SIZE AND FONT STYLE */
   CONSOLE_FONT_INFOEX cfi;
   cfi.cbSize=sizeof(cfi);
   cfi.nFont=0;
   cfi.dwFontSize.X=0;
   cfi.dwFontSize.Y=24;
   cfi.FontFamily=FF_DONTCARE;
   cfi.FontWeight=FW_NORMAL;
   wcscpy(cfi.FaceName, L"Arial");
   SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

/* SCHOOL MANAGEMENT */
   int i=0,j;
   char choice;
   string find;
   string srch;
   student studentData;
   teacher tech[50];

   while(1)
{
    system("cls");

    cout<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
    cout<<"\n\n\t\t\t\t\t\tSCHOOL MANAGEMENT SYSTEM\n\n";
    cout<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
    cout<<"\n\n\t\t\t\t\t\t\tMAIN MENU\n\n";
    cout<<"Enter your choice: "<<endl;
    cout<<"1.Students information"<<endl;
    cout<<"2.Teacher information"<<endl;
    cout<<"3.Exit program"<<endl;
    cin>>choice;

    system("cls");
    switch(choice)
    {
    	/* STUDENT */
        case '1':
        {
            while(1)
            { 
                system("cls");

                cout<<"\t\t\tSTUDENTS INFORMATION AND BIO DATA SECTION\n\n\n";
                cout<<"Enter your choice: "<<endl;
                cout<<"1.Create new entry\n";
                cout<<"2.Find and display entry\n";
                cout<<"3.Delete a previous entry\n";
                cout<<"4.Jump to main\n";
                cin>>choice;
                
                switch (choice)
                {
                    case '1':
                    {  
					    ofstream f1("student.txt",ios::app);
                        for( i=0;choice!='n';i++)
                        {
                            if((choice=='y')||(choice=='Y')||(choice=='1'))
                            {
                                cout<<"Enter First name: ";
                                cin>>studentData.fname;
                                cout<<"Enter Last name: ";
                                cin>>studentData.lname;
                                cout<<"Enter Registration number: ";
                                cin>>studentData.Registration;
                                cout<<"Enter class: ";
                                cin>>studentData.class_section;
                                f1<<studentData.fname<<endl<<studentData.lname<<endl<<studentData.Registration<<endl<<studentData.class_section<<endl;
                                cout<<"Do you want to enter data: ";
                                cout<<"Press Y for Continue and N to Finish:  ";
                                cin>>choice;
                                exit(1);
                            }
                        } 
                        f1.close();
                    }

                    continue;
                    case '2':
                    {
					    ifstream f2("student.txt");
                        cout<<"Enter First name to be displayed: ";
                        cin>>find;
                        cout<<endl;
                        int notFound=0;
                        for( j=0;(j<i)||(!f2.eof());j++)
                        { 
                            getline(f2,studentData.fname);
                            if(studentData.fname==find)
                            {
                                notFound=1;
                                cout<<"First Name: "<<studentData.fname<<endl;
                                getline(f2,studentData.lname);
                                cout<<"Last Name: "<<studentData.lname<<endl;
                                getline(f2,studentData.Registration);
                                cout<<"Registration number: "<<studentData.Registration<<endl;
                                getline(f2,studentData.class_section);
                                cout<<"Class: "<<studentData.class_section<<endl<<endl;
                            }
                        }

                        if(notFound == 0)
						{
                            cout<<"No Record Found"<<endl;
                        }
                        f2.close();
                        cout<<"Press any key two times to proceed";
                        getch();
                        getch();
                    } 
                    continue;
                    case '3':
                    	{
                    		studentData.deleting();
						}
					continue;
                    case '4':
                    {
                        break;
                    }
                }
                break;
            }
            continue;  
        }
/* TEACHERS */
        case '2':
        {
            while(1)
        { 
            system("cls");

           cout<<"\t\t\tTEACHERS INFORMATION AND BIODATA SECTION\n\n\n";
           cout<<"Enter your choice: "<<endl;
           cout<<"1.Create new entry\n";
           cout<<"2.Find and display\n";
           cout<<"3.Delete a previous entry\n";
           cout<<"4.Jump to main\n";
           cin>>choice;
           switch (choice)
           {
                case '1':
                { 
                    ofstream t1("teacher.txt",ios::app);
                    for(i=0;choice!='n'&& choice!='N';i++)
                    {
                        if((choice=='y')||(choice=='Y')||(choice=='1'))
                        {
                            cout<<"Enter First name: ";
                            cin>>tech[i].fst_name;
                            cout<<"Enter Last name:: ";
                            cin>>tech[i].lst_name;
                            cout<<"Enter qualification: ";
                            cin>>tech[i].qualification;
                            cout<<"Enter experiance(year): ";
                            cin>>tech[i].exp;
                            cout<<"Enter number of year in this School: ";
                            cin>>tech[i].serves;
                            cout<<"Enter Course of teacher: ";
                            cin>>tech[i].subj;
                            cout<<"Enter Lecture(per Week): ";
                            cin>>tech[i].lec;
                            cout<<"Enter pay: ";
                            cin>>tech[i].pay;
                            cout<<"Enter Phone Number: ";
                            cin>>tech[i].cel_no;
                            cout<<"Enter Blood Group: ";
                            cin>>tech[i].blod_grp;
  
                            t1<<tech[i].fst_name<<endl<<tech[i].lst_name<<endl 
                            <<tech[i].qualification<<endl<<tech[i].exp<<endl
                            <<tech[i].serves<<endl<<tech[i].subj<<endl<<tech[i].lec
                            <<endl<<tech[i].pay<<endl<<tech[i].cel_no<<endl<<tech[i].blod_grp<<endl;
                            cout<<"Do you want to enter data: ";
                            cin>>choice;
                        }
                    }
                    system("cls");
                    t1.close();
                    }
                    
                    continue;
                    case '2':
                    { 
                        ifstream t2("teacher.txt");
                        cout<<"Enter name to be displayed: ";
                        cin>>find;
                        cout<<endl;
                        int notFound = 0;
                        for( j=0;((j<i)||(!t2.eof()));j++)
                        {
                            getline(t2,tech[j].fst_name); 
                            if(tech[j].fst_name==find)
                            {
                                notFound = 1;
                                cout<<"First name: "<<tech[j].fst_name<<endl;
                                getline(t2,tech[j].lst_name);
                                cout<<"Last name: "<<tech[j].lst_name<<endl;
                                getline(t2,tech[j].qualification);
                                cout<<"Qualification: "<<tech[j].qualification<<endl;
                                getline(t2,tech[j].exp);
                                cout<<"Experience: "<<tech[j].exp<<endl;
                                getline(t2,tech[j].serves);
                                cout<<" number of year in this School: "<<tech[j].serves<<endl;

                                getline(t2,tech[j].subj);
                                cout<<"Subject whos teach: "<<tech[j].subj<<endl;

                                getline(t2,tech[j].lec);
                                cout<<"Enter Lecture(per Week): "<<tech[j].lec<<endl;
                                getline(t2,tech[j].pay);
                                cout<<"pay: "<<tech[j].pay<<endl;

                                getline(t2,tech[j].addrs);
                                cout<<"Address: "<<tech[j].addrs<<endl;

                                getline(t2,tech[j].cel_no);
                                cout<<"Phone Number: "<<tech[j].cel_no<<endl;

                                getline(t2,tech[j].blod_grp);
                                cout<<"Bool Group: "<<tech[j].blod_grp<<endl;
                            }
 
                        }
                        t2.close();
                        if(notFound == 0)
						{
                            cout<<"No Record Found"<<endl;
                        }
                        cout<<"Press any key two times to proceed";
                        getch();
                        getch();
                    }//case 2
                    continue;
                    case '3':
                    {
                        deleting_T();
                    }//case 3
                    continue;
                    case '4': 
                    {
                        break;
                    }//case 4
                }
                break;
            }
            continue;
        }
        
        case '3':
        {
            break;
        }
    }
    break;
}
return 0;
}
