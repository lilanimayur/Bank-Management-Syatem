#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;



void create_acc();
void display_details();
void display_details_admin();
void delete_account_admin();
void display_list();
void withdraw_deposit(char n[10], int choice);
void nou();
void total_money();
void admin();
void user();




class bank
{

    char name[30];
	char acc_no[10];
	char pass[10];
	char repass[10];
    char contact[10];
    string Aid;
    string Apass;
    int no_users;
    long long int total;
	long long int deposit;



	public:


    void new_acc();
    void withdraw(long long int x);
    void deleting_admin();
    void admin_login();
    void dep(long long int x);
    void no_of_users(int x);
    void total_cash(long long int v);



		friend void create_acc();
		friend void display_details();
		friend void display_details_admin();
		friend void delete_account_admin();
		friend void display_list();
		friend void withdraw_deposit(char n[10], int option);
		friend void nou();
		friend void total_money();
		friend void admin();
		friend void user();
};


void bank :: new_acc()
{
		cout<<"Enter your name :";
		cin>>name;
		cout<<"Create New Password :";
		cin.ignore();
		cin>>pass;
		z:
		cout<<"ReEnter Password :";
		cin.ignore();
		cin>>repass;
		if(strcmp(pass,repass))
		{
			cout<<"***Both Passwords Should Be Same***";
			goto z;
		}
		x:
		cout<<"Enter a 10 Digit Unique Account Number :";
		cin.ignore();
		cin>>acc_no;
		if(strlen(acc_no)!=10)
		{
			cout<<"***Please enter a valid account number***"<<endl;
			goto x;
		}
		y:
		cout<<"Enter your contact number :";
		cin>>contact;
		if(strlen(contact)!=10)
		{
			cout<<"***Please enter a valid contact number***"<<endl;
			goto y;
		}
		cout<<"enter the amount to deposit :";
		cin>>deposit;
}




void bank::dep(long long int x)
{
	deposit+=x;
}


void bank::withdraw(long long int x)
{
	deposit-=x;
}


void bank :: deleting_admin()
{
    	char t[30];
	    char p[10];
        ofstream fout;
		ifstream fin;
        fin.open("bankdetails.txt",ios::in);
        fout.open("temp.txt",ios::out|ios::app);
        cout<<"Enter Your Username :";
	    cin>>t;
        fin.read((char*)this,sizeof(*this));
        //fin>>name>>pass>>acc_no>>contact>>deposit;
        while(!fin.eof())
		{
            if(strcmp(name,t))
			{
            fout.write((char*)this,sizeof(*this));
            //fout<<name<<pass<<acc_no<<contact<<deposit<<endl;
            }
            fin.read((char*)this,sizeof(*this));
           // fin>>name>>pass>>acc_no>>contact>>deposit;
        }
            fin.close();
            fout.close();
            remove("bankdetails.txt");
            rename("temp.txt","bankdetails.txt");
}



void bank:: admin_login()
{
     Aid="admin";
     Apass="admin@123";

}


void bank:: no_of_users(int x)
{
	no_users=x;
	cout<<"\n\n\n\t\t"<<"Number Of Accounts In Bank Are :"<<no_users;
	getch();
}

void bank::total_cash(long long int v)
{
	total=v;
	cout<<"\n\n\n\t\t"<<"Total Money In Bank :"<<total;
	getch();
}



main()
{

    char c,cc;
    cout<<"\t\t"<<"**************************************************************************"<<endl;
    cout<<"\t\t"<<"--------------------------";
	cout<<"Bank Managemet System";
	cout<<"--------------------------"<<endl;
	cout<<"\t\t"<<"**************************************************************************"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"Press Any Key.....";
	getch();
	do
	{
	system("cls");
	cout<<"\t\t\t\t\t"<<"****"<<"Select An Option You Want"<<"****"<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"1. Admin Login"<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"2. Existing User"<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"3. New User"<<endl<<endl;
	cout<<"\t\t\t\t\t"<<"9. Exit"<<endl<<endl;
	cin>>cc;
    system("cls");
	switch(cc)
	    {
		case '1': admin();
		           break;
		case '2': user();
		           break;
		case '3': create_acc();
		           break;
		case '9': cout<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t"<<"Thanks For Using Bank Management System";
		            getch();
		            break;
	    default : cout<<"\a";
    	}
    	cin.ignore();
    	cin.get();
    }while(cc!='9');


}



void create_acc()
{
	bank a;
	ofstream o;
	o.open("bankdetails.txt",ios::app|ios::binary);
	a.new_acc();
	o.write((char*)&a,sizeof(bank));
	//o<<a.name<<"\t"<<a.pass<<"\t"<<a.acc_no<<"\t"<<a.contact<<"\t"<<a.deposit<<endl;
	o.close();
}





void display_details()
{
	char n[30];
	char p[10];
	bank a;
	ifstream i;
	i.open("bankdetails.txt");
	i.read((char*)&a,sizeof(bank));
	//i>>a.name>>a.pass>>a.acc_no>>a.contact>>a.deposit;
	cout<<"Enter Your Name :";
	cin>>n;
	q:
	cout<<"Enter Your Password :";
	cin>>p;
	while(!i.eof())
    {
    if(!strcmp(a.name,n))
        {
	        if(!strcmp(a.repass,p))
          {
        	cout<<"***Account Holder Name:"<<a.name<<endl<<endl<<endl;
        	cout<<"***Account Number:"<<a.acc_no<<endl<<endl<<endl;
        	cout<<"***Contact Number:"<<a.contact<<endl<<endl<<endl;
        	cout<<"***Account Balance:"<<a.deposit<<endl<<endl<<endl;
          }

	    }
       i.read((char*)&a,sizeof(bank));
	   //i>>a.name>>a.pass>>a.acc_no>>a.contact>>a.deposit;
    }
    i.close();
    getch();
}



void display_details_admin()
{
	char n[30];
	char p[10];
	bank a;
	ifstream i;
	i.open("bankdetails.txt");
	cout<<"Enter Your User Name :";
	cin>>n;
	i.read((char*)&a,sizeof(bank));
   // i>>a.name>>a.pass>>a.acc_no>>a.contact>>a.deposit;
	while(!i.eof())
    {
    if(!strcmp(a.name,n))
        {
    	cout<<endl<<endl<<"***Account Holder Name:"<<a.name<<endl<<endl;
    	cout<<"***Account Number:"<<a.acc_no<<endl<<endl;
    	cout<<"***Contact Number:"<<a.contact<<endl<<endl;
    	cout<<"***Account Balance:"<<a.deposit<<endl<<endl;
	    }
	    i.read((char*)&a,sizeof(bank));
	//i>>a.name>>a.pass>>a.acc_no>>a.contact>>a.deposit;
    }
    i.close();
    getch();
}



void delete_account_admin()
{
	bank a;
	a.deleting_admin();
}


void display_list()
{

	bank a;
	ifstream i;
	i.open("bankdetails.txt");
    cout<<"Name"<<"\t\t"<<"Account No."<<"\n";
	while(i.read((char*)&a,sizeof(bank)))
	{
    cout<<a.name<<"\t\t"<<a.acc_no<<"\n";
    }
    i.close();
    getch();

}

void withdraw_deposit(char n[10], int choice)
{
	int amt;
	int k=0;
	bank a;
	fstream file;
	file.open("bankdetails.txt", ios::binary|ios::in|ios::out);
	while(!file.eof() && k==0)
	{
		file.read((char*)&a,sizeof(bank));
		if(!strcmp(a.acc_no,n))
		{
			if(choice==1)
			{
				cout<<"\n\nEnter The Amount To Deposit";
				cin>>amt;
				a.dep(amt);
			}
			if(choice==2)
			{
				cout<<"\n\nEnter The Amount To Withdraw";
				cin>>amt;
				if(a.deposit<amt)
				{
					cout<<"Insufficient balance";
					getch();
				}
				else
				{
					a.withdraw(amt);
				}
			}
			int pos=(-1)*static_cast<int>(sizeof(a));
			file.seekp(pos,ios::cur);
			file.write((char*)&a,sizeof(bank));
			cout<<"\n\n\t Record Updated";
			k=1;
	       }
         }
	file.close();
	if(k==0)
	{
		cout<<"\n\n Record Not Found ";
		getch();
	}
}

void nou()
{
	int z=0;
	bank a;
		ifstream i;
		i.open("bankdetails.txt",ios::in);
		while(i.read((char*)&a,sizeof(bank)))
       {
	     z++;
       }
       a.no_of_users(z);
}


void total_money()
{
	bank a;
	long long int z=0;
	ifstream i;
	i.open("bankdetails.txt",ios::in);
		while(i.read((char*)&a,sizeof(bank)))
       {
	     z=z+a.deposit;
       }
	   a.total_cash(z);
}

void admin()
{
	string admin_id;
	string admin_pass;
	bank a;
	char c;
	a.admin_login();
	s:
	cout<<"Enter Admin Id(admin) :";
	cin>>admin_id;
	cout<<"Enter Password(admin@123) :";
	cin>>admin_pass;
	if(admin_id!=a.Aid||admin_pass!=a.Apass)
	{
		cout<<"Incorrect Credentials"<<endl;
		goto s;
	}
	else if(admin_id==a.Aid&&admin_pass==a.Apass)
	{
     do
	         {
	            system("cls");
             	cout<<"\t\t\t\t\t"<<"****"<<"Main Menu"<<"****"<<endl<<endl;
            	cout<<"\t\t\t\t\t"<<"1. Account Details"<<endl<<endl;
            	cout<<"\t\t\t\t\t"<<"2. Users List"<<endl<<endl;
             	cout<<"\t\t\t\t\t"<<"3. Delete Account"<<endl<<endl;
             	cout<<"\t\t\t\t\t"<<"4. Numbers Of Accounts In Our Bank"<<endl<<endl;
             	cout<<"\t\t\t\t\t"<<"5. Total Money In Our Bank"<<endl<<endl;
            	cout<<"\t\t\t\t\t"<<"9. Exit";
            	cin>>c;
            	system("cls");
                	switch(c)
	                    {
		                    case '1': display_details_admin();
		                              break;
		                    case '2': display_list();
		                              break;
		                    case '3': delete_account_admin();
		                              break;
		                    case '4': nou();
							          break;
							case '5': total_money();
							          break;          
	                    	case '9': cout<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t"<<"Signing Out Admin";
		                    getch();
		                    break;
	                    	default : cout<<"\a";
	                    }

            }while(c!='9');
	}
}




void user()
{
	char n[30];
	char c;
	char p[10];
	char num[10];
	int k;
	bank a;
	ifstream i;
	i.open("bankdetails.txt",ios::in);
	i.read((char*)&a,sizeof(bank));
	//i>>a.name>>a.pass>>a.acc_no>>a.contact>>a.deposit;
	cout<<"Enter Your Name :";
	cin>>n;
	q:
	cout<<"Enter Your Password :";
	cin>>p;
    while(!i.eof())
    {

     // if(a.name==n&&p!=a.pass)
     	//{
		//cout<<"***Incorrect Credentials***"<<endl;
		//goto q;
    	//}
     if(!strcmp(a.name,n))
    	{

           do
	         {
	            system("cls");
             	cout<<"\t\t\t\t\t"<<"****"<<"Main Menu"<<"****"<<endl<<endl;
            	cout<<"\t\t\t\t\t"<<"1. Account Details"<<endl<<endl;
             	cout<<"\t\t\t\t\t"<<"2. Deposit Cash"<<endl<<endl;
            	cout<<"\t\t\t\t\t"<<"3. Withdraw Cash"<<endl<<endl;
				cout<<"\t\t\t\t\t"<<"9. Exit";
            	cin>>c;
            	system("cls");
                	switch(c)
	                    {
	                    	if(k==0)
	                    	{
		                    case '1': display_details();
		                              break;
		                    case '2': cout<<"\n\n\tEnter The account No. : ";
							          cin>>num;
			                          withdraw_deposit(num, 1);
			                          break;
		                    case '3': cout<<"\n\n\tEnter The account No. : ";
							          cin>>num;
			                          withdraw_deposit(num, 2);
			                          break;
	                    	case '9': cout<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t"<<"Signing Out User";
		                              getch();
		                              break;
	                    	default : cout<<"\a";
	                        }
	                    }

            }while(c!='9');
		}
	        i.read((char*)&a,sizeof(bank));
	//i>>a.name>>a.pass>>a.acc_no>>a.contact>>a.deposit;
    }
    i.close();
}
