#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct information{
	string name;
	int password;
	int age;
	int balance=0;
};

void loadAccounts(vector<information>& userInformation,int& number_of_accounts){
	information t;
	ifstream valuefile("number_of_accounts.txt");
		valuefile>>number_of_accounts;
		valuefile.close();
		
	ifstream data("user_data.txt");
		for (int i=0;i<number_of_accounts;i++){
			if (i>0){
				data.ignore();
			}
			getline(data,t.name);
			data>>t.age;
			data>>t.password;
			data>>t.balance;
			userInformation.push_back(t);
		}
		data.close();
}

void saveAccounts(vector<information>& userInformation,int& number_of_accounts,int& deleteoption){
	ofstream writevalue("number_of_accounts.txt");
	deleteoption=deleteoption-1;
	if (deleteoption>0){
		number_of_accounts=number_of_accounts-1;
	    writevalue<<number_of_accounts;
    }
    else {
    	writevalue<<number_of_accounts;
	}
	writevalue.close();
	
	ofstream writedata("user_data.txt");
	for (int i=0;i<userInformation.size();i++){
		
		if (i!=deleteoption){
		information& t=userInformation[i];
		
		writedata<<t.name<<endl;
		writedata<<t.age<<endl;
		writedata<<t.password<<endl;
		writedata<<t.balance<<endl;
	    }
	}
	writedata.close();
	deleteoption=-1;
}

void withdrawal(information& userInformation){
	int choice;
	int amount;
	    do{
	    system("cls");
		cout<<"How much would you like to withdraw?\n";
		cout<<"1.1,000              4.50,000\n";
		cout<<"2.5,000              5.100,000\n";
		cout<<"3.10,000             6.Other Amount\n";
		cout<<"Your choice:";
		cin>>choice;
		cout<<endl;
		switch(choice){
			case 1:
				if (userInformation.balance<1000){
					system("cls");
					cout<<"\nInsufficient Funds!\n\n";
				}
				else{
					userInformation.balance-=1000;
					system("cls");
					cout<<"\nTransaction Successful!\n\n";
				}
				break;
			case 2:
				if (userInformation.balance<5000){
					system("cls");
					cout<<"\nInsufficient Funds!\n\n";
				}
				else{
					userInformation.balance-=5000;
					system("cls");
					cout<<"\nTransaction Successful!\n\n";
				}
				break;
			case 3:
				if (userInformation.balance<10000){
					system("cls");
					cout<<"\nInsufficient Funds!\n\n";
				}
				else{
					userInformation.balance-=10000;
					system("cls");
					cout<<"\nTransaction Successful!\n\n";
				}
				break;
			case 4:
				if (userInformation.balance<50000){
					system("cls");
					cout<<"\nInsufficient Funds!\n\n";
				}
				else{
					userInformation.balance-=50000;
					system("cls");
					cout<<"\nTransaction Successful!\n\n";
				}
				break;
			case 5:
				if (userInformation.balance<100000){
					system("cls");
					cout<<"\nInsufficient Funds!\n\n";
				}
				else{
					userInformation.balance-=100000;
					system("cls");
					cout<<"\nTransaction Successful\n\n";
				}
				break;
			case 6:
				cout<<"Enter your withdrawal amount:";
				cin>>amount;
				if (amount>userInformation.balance){
					system("cls");
					cout<<"\nInsufficient Funds!\n\n";
				}
				else{
					userInformation.balance-=amount;
					system("cls");
					cout<<"\nTransaction Successful!\n\n";
				}
				break;
			default:
				cout<<"That is not a valid option!\n\n";
		}
	}while(choice>6||choice<0);
}

int settings(int& deleteoption,const int& option,information& userInformation){
	int choice;
	char choice2;
	int pass;
	do{
		system("cls");
		cout<<"\n1.Change name\n";
		cout<<"2.Change password\n";
		cout<<"3.Delete account\n";
		cout<<"4.Back\n";
		cout<<"Enter your choice(1-4):";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter password:";
				cin>>pass;
				if (pass==userInformation.password){
					cout<<"Enter new name:";
					cin.ignore();
					getline(cin,userInformation.name);
				}
				else{
					cout<<"Incorrect!";
				}
				break;
			case 2:
			    cout<<"Enter current password:";
				cin>>pass;
				if (pass==userInformation.password){
					cout<<"Enter new password:";
					cin>>userInformation.password;
				}
				else{
					cout<<"Incorrect!";
				}
				break;
			case 3:
				cout<<"Are you sure?(y/n):";
				cin>>choice2;
				if (choice2=='y'||choice2=='Y'){
				deleteoption=option;
				return deleteoption;
			    }
			    else if (choice2=='n'){
			    	break;
				}
				else {
					cout<<"That is not a valid option!";
					break;
				}
			case 4:
				break;
			default:
				cout<<"This is not a valid choice.";
				break;
	    }
	}while(choice!=4);
	system("cls");
	return deleteoption;
}

void accountMenu(information& userInformation,int& deleteoption,const int& option){
	int action;
	int amount;
	int temp=0;
	do{
		cout<<"========================="<<endl;
		cout<<" Bank Management System"<<endl;
		cout<<"========================="<<endl;
		cout<<"\n\n 1.Balance Inquiry\n";
		cout<<" 2.Cash Deposit\n";
		cout<<" 3.Cash Withdrawal\n";
		cout<<" 4.Settings\n";
		cout<<" 5.Log out\n\n";
		cout<<" Enter your action(1-5):";
		cin>>action;
		cout<<endl;
		
		switch(action){
			case 1:
				do{
				system("cls");
				cout<<"You currently have:";
				cout<<endl<<"$"<<userInformation.balance<<endl;
				cout<<"Enter \"1\" to continue:";
				cin>>action;
				system("cls");
			    }while(action!=1);
				break;
			case 2:
				cout<<"Enter your amount:$";
				cin>>amount;
				userInformation.balance=userInformation.balance+amount;
				system("cls");
				break;
			case 3:
			    withdrawal(userInformation);
			    break;
			case 4:
				settings(deleteoption,option,userInformation);
				if (deleteoption==option){
					return;
				}
				break;
			case 5:
				system("cls");
				return;
			default:
			    cout<<"This is not a valid option!\n\n";		
		}
	}while(action!=5||deleteoption!=option);
	system("cls");
}

int main(){
	int pass;
	vector<information> userInformation;
	int number_of_accounts=0;
	int option=0;
	int deleteoption=-1;
	
	loadAccounts(userInformation,number_of_accounts);
    do{
		cout<<"============================================="<<endl;
		cout<<" Welcome To The Basic Bank Management System"<<endl;
		cout<<"============================================="<<endl;
		cout<<"Please choose an account:\n\n";
		if(number_of_accounts>0){
		    for (int i=1;i<=userInformation.size();i++){
			    cout<<i<<". "<<userInformation[i-1].name<<endl;
		    }
	    }
	    cout<<number_of_accounts+1<<". Create New Account\n";
	    cout<<number_of_accounts+2<<". Exit\n\n";
		cout<<"Enter your choice:";
		cin>>option;
		if (option!=number_of_accounts+2){
		system("cls");
	    }
		if(option==number_of_accounts+1){
			information t;
			
			cout<<"Enter Name of Account:";
			cin.ignore();
			getline(cin,t.name);
			 
			cout<<"Enter your age:";
			cin>>t.age;
			
			cout<<"Enter Password:";
			cin>>t.password;
			
			userInformation.push_back(t);
			number_of_accounts++;
			
			saveAccounts(userInformation,number_of_accounts,deleteoption);
			
			system("cls");
		}
		else if(option==number_of_accounts+2){
			break;
		}
		else if(option<number_of_accounts+1&&option>0){
			cout<<"Enter Password:";
			cin>>pass;
			if(pass==userInformation[option-1].password){
				system("cls");
				accountMenu(userInformation[option-1],deleteoption,option);
				if (deleteoption==option){
					saveAccounts(userInformation,number_of_accounts,deleteoption);
					break;
				}
				saveAccounts(userInformation,number_of_accounts,deleteoption);
			}
			else{
				system("cls");
				cout<<"\nIncorrect Password!\n\n";
			}
		}
	    else{
	    	system("cls");
	    	cout<<"\nIncorrect option!\n\n";
		}
	}while (option!=number_of_accounts+2&&deleteoption!=option);
	system("cls");
	cout<<"Thank you for using the basic Bank Management System!";
    
	return 0;
}
