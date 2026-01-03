#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
class BankAccount{
	public:
		char name[200];
		char addrs[200],ans,branch[20];
		int balance,acc_no,pincode;
	
		void create_account();
		void deposit();
		void withdraw();
		void modify_account();
		void display();
		int returnacno() const;
		void report() const;
	
}; 
void BankAccount::create_account(){
	system("CLS");
	std::cout<<"\nEnter account number :\t";
	std::cin>>acc_no;
	std::cout<<"\n Enter full name of applicant:\t";
	cin.ignore();
	cin.getline(name,200);
	std::cout<<"\n Enter residential addresss of applicant:\n";
	cin.ignore();
	cin.getline(addrs,200);
	std::cout<<"\n Enter pincode: \t";
	
	std::cin>>pincode;
	std::cout<<"\n Enter Branch name : \t";
	cin.ignore();
	cin.getline(branch,20);
	
	std::cout<<"\n Enter account type: Savings (S) or Current (C) :";
	std::cin>>ans;
	ans=toupper(ans);
	
	std::cout<<"\n Enter starting deposit :";
	std::cin>>balance;
	std::cout<<"\n Congratulations! Your account has been created....\n";
	
}
void BankAccount::deposit(){
		int amount;
		std::cout<<"\n Enter amount to be deposited :";
		std::cin>>amount;
		
		balance+=amount;
		std::cout<<"\n Current Account balance is : Rs."<<balance<<endl;
	}
	
void BankAccount::display(){
	std::cout<<"\n Account Number :"<<acc_no;
	std::cout<<"\n Account holders Name:"<<name;
	std::cout<<"\n Residential Address of Account Holder: \n"<<addrs;
	std::cout<<"\n Pincode : "<<pincode;
	std::cout<<"\n Branch Name : "<<branch;
	std::cout<<"\n Account Type : "<<ans;
	std::cout<<"\n Total Account Balance : Rs."<<balance;
}

void BankAccount::modify_account(){
	std::cout<<"\n Account Number : "<<acc_no;
	std::cout<<"\n Modify Account Holders' name : ";
	cin.ignore();
	cin.getline(name,200);
	std::cout<<"\n Modify account type :";
	std::cin>>ans;
	ans=toupper(ans);
	std::cout<<"\n Modify branch :";
	std::cin>>branch;
	
	std::cout<<"\n Modify account balance :";
	std::cin>>balance;
	
	
}
void BankAccount::report() const{
	std::cout<<acc_no<<"        "<<name<<"          "<<pincode<<"       "<<ans<<"       "<<branch<<"            "<<balance<<endl;
}


void BankAccount::withdraw(){
	double w_amt;
	std::cout<<"\n Amount withdrawl process....\n";
	std::cout<<"Enter amount to be withdrawn : ";
	std::cin>>w_amt;
	if(balance-w_amt <0)
		std::cout<<"\n INSUFFICIENT BALANCE!!! \n";
	else
		balance-=w_amt;
	std::cout<<"\n Updated account balance : Rs."<<balance<<endl;
}

int  BankAccount:: returnacno() const {
	return acc_no;
}

void write_account();
void display_sp(int);
void modify_acc(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);



int main(){
	//BankAccount bank;
	int num;
	char rep,x;
	std::cout<<"------------------------------------------"<<endl;
	std::cout<<"----------BANK MANAGEMENT SYSTEM----------"<<endl;
	std::cout<<"------------------------------------------"<<endl;
	do{
	
	std::cout<<"\n\t 1. Open Account\n";
	std::cout<<"\t 2. Deposit Amount\n";
	std::cout<<"\t 3. Withdraw Amount\n";
	std::cout<<"\t 4. Display Account\n";
	std::cout<<"\t 5. All Account Holders' list \n";
	std::cout<<"\t 6. Close Account \n";
	std::cout<<"\t 7. Modify Account\n";
	std::cout<<"\t 8. Exit \n";
	std::cout<<"\n\t Choose an option....\n";
	std::cin>>rep;
	switch(rep)
	{
		case '1':
		    system("CLS");
		    std::cout<<"\n\nChosen option - 1 :: Open Account \n";
		    write_account();
		    break;
		
		
		case '2':
		    system("CLS");
		    std::cout<<"\n\nChosen option - 2 :: Deposit Ammount \n";
		    std::cout<<"Enter account number : ";
		    std::cin>>num;
		    deposit_withdraw(num,1);
		    break;
		
		case '3':
		    system("CLS");
		    std::cout<<"\n\nChosen option - 3:: Withdraw Amount \n";
		    std::cout<<"Enter account number : ";
		    std::cin>>num;
		    deposit_withdraw(num,2);
		    break;
		
		case '4':
		    system("CLS");
		    std::cout<<"\n\nChosen option - 4:: Display Amount \n";
		    std::cout<<"Enter account number : ";
		    std::cin>>num;
		    display_sp(num);
		    break;
		
		case '5':
			system("CLS");
			std::cout<<"\n\nChosen option - 5 :: Display all Account Holders' list \n";
			display_all();
			break;
			
		case '6':
			system("CLS");
			std::cout<<"\n\nChosen option - 6 :: Close Account \n";
			std::cout<<"Enter account number : ";
			std::cin>>num;
			delete_account(num);
			break;
		
		
		
		case '7':
		 	system("CLS");
		 	std::cout<<"\n\nChosen option - 7 :: Modify Account \n";
			cout<<"Enter The account No. : "; cin>>num;
			modify_acc(num);
			break;
			
		case '8':
			system("CLS");
			std::cout<<"\n\n System Exit...\n\n";
			break;
			
		
			
	default:
		std::cout<<"\n Please select a legitimate option and try again.\n";		
	}
	}	while(rep!='8') ;

	return 0;
	
}

void write_account()
{
	BankAccount bank;
	ofstream outFile;
	outFile.open("BankAccount.dat",ios::binary|ios::app);
	bank.create_account();
	outFile.write(reinterpret_cast<char *> (&bank), sizeof(BankAccount));
	outFile.close();
}

void display_sp(int n)
{
	BankAccount bank;
	bool flag=false;
	ifstream inFile;
	inFile.open("BankAccount.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File doesnot exist !! Press any Key...";
		return;
	}
	cout<<"\n\t BALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&bank), sizeof(BankAccount)))
	{
		if(bank.returnacno()==n)
		{
			bank.display();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\ttAccount number does not exist";
}



void modify_acc(int n)
{
	bool found=false;
	BankAccount bank;
	fstream File;
    File.open("BankAccount.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&bank), sizeof(BankAccount));
		if(bank.returnacno()==n)
		{
			bank.display();
			cout<<"\n\n\tEnter The New Details of account"<<endl;
			bank.modify_account();
			int pos=(-1)*static_cast<int>(sizeof(BankAccount));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&bank), sizeof(BankAccount));
		    cout<<"\n\t\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\t Record Not Found ! ";
}



void delete_account(int n)
{
	BankAccount bank;
	ifstream inFile;
	ofstream outFile;
	inFile.open("BankAccount.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&bank), sizeof(BankAccount)))
	{
		if(bank.returnacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&bank), sizeof(BankAccount));
		}
	}
    inFile.close();
	outFile.close();
	remove("BankAccount.dat");
	rename("Temp.dat","BankAccount.dat");
	cout<<"\n Bank Record Deleted ..";
}


void display_all()
{
	system("CLS");
	BankAccount bank;
	ifstream inFile;
	inFile.open("BankAccount.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	else{
	
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"==================================================================================\n";
	cout<<"A/c no.      NAME            Pincode         Type        Branch          Balance\n";
	cout<<"==================================================================================\n";
	while(inFile.read(reinterpret_cast<char *>(&bank), sizeof(BankAccount)))
	{
		bank.report();
	
	}
	}
	inFile.close();
}


void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	BankAccount bank;
	fstream File;
    File.open("BankAccount.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press random Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&bank), sizeof(BankAccount));
		if(bank.returnacno()==n)
		{
			bank.display();
			if(option==1)
			{	bank.deposit();
			}
		    if(option==2)
			{
				bank.withdraw();
		      }
			int pos=(-1)*static_cast<int>(sizeof(bank));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&bank), sizeof(BankAccount));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\tRecord Not Found ";
}
