#include <iostream>
#include <cstring>
#include <fstream>
#include <regex>

using namespace std;

class person_info
{
private :
    fstream users;
    string username;
    string birthdate;
    string first_name;
    string last_name;
    string password;


public :
    void setting_login_info(string username= " " ,string password= " "){
        this->username = username;
        this->password = password;
    }
    friend void accountPage();
    void register_user()
    {

        /*
        fstream MyFile("users1.txt" ,ios::app);
        fstream m*/
        ofstream myfile1("userpass.txt", ios::app);
		if (!myfile1.is_open()) {
			cout << "could not open file \n";
		}

		//Store other details in customer file
		ofstream myfile2("customer.txt", ios::app);
		if (!myfile2.is_open()) {
			cout << "could not open file \n";
		}

        cout<<"enter your first name:"<<endl;
        cin>>first_name;
        cout<<"enter your last name:"<<endl;
        cin>>last_name;
        cout<<"enter your birthdate:"<<endl;
        cin>>birthdate;
        myfile2 << first_name << "  " << last_name << "  " << birthdate <<endl;
        cout<<"enter username:"<<endl;
        cin>>username;
        cout<<"enter password:"<<endl;
        cin >> password;
        cout<<"registered successfully"<<endl;
        myfile1 <<username << "  "<< password << endl;
        myfile1.close();

    }

    //Log in page
	bool login()
	{
        string inUser;
        string inPass;
		do
		{
			cout << "\nUsername: ";
			cin >> inUser;
			cout << "Password: ";
			cin >> inPass;

			if (CheckCredentials(inUser, inPass) == true)
			{
				cout << "Welcome, " << inUser << endl;
				cout << endl;
				return true;
			}
			else
			cout << "\nInvalid username or password. " << endl;
		} while (CheckCredentials(inUser, inPass) != true);

		return CheckCredentials(inUser,inPass);
	}

    bool CheckCredentials(const string& inUser, const string& inPass)
    {
		string line = "  ";
		ifstream myfile1("userpass.txt");
		bool status = false;
		while (getline(myfile1,line)){
            stringstream iss(line);
            iss >> username >> password;

            if (inUser == username && inPass == password) {
                cout << "Login Successfully!"<< endl;
                status = true;
                break;
            }
        }

        if (!status) {
            cout << "InValid UserName And Password"<< endl;
        }

		return status;
    }



};


class library
{
	private:
	    string title;
	    string shelf_num;
	    string authors;
	    string edition;
	    string publisher;
	    string published_year;
	    string ISBN;
	    string length;
	    string subjects;


	public:


		void search()
		{
			int choice;
			string s;
			cout<<"Enter the feature of the book your searching for" << endl;
			cout<<"1.Title - 2-Authors - 3.Publisher - 4.Published_year";
			cin>>choice;
			string line = " ";
			ifstream myfile3("books.txt");
			bool status = false;
			if(choice==1)
			{
				cout << "Enter the title of the book you are looking for";
				cin >> s;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title;
                    if (s == title ) {
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

			if(choice==2)
			{
				cout << "Enter the name of the authors of book you are looking for";
				cin >> s;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >> authors;
                    if (s == authors ) {
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            if(choice==3)
			{
				cout << "Enter the publisher of the book you are looking for";
				cin >> s;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >> publisher;
                    if (s == publisher ) {
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            if(choice==4)
			{
				cout << "Enter the title of the book you are looking for";
				cin >> s;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >> published_year;
                    if (s == published_year ) {
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

		}




};

int main()
{

    person_info person;
    string ans;
    string login_username;
    string login_pass;

    int Choice1;
	bool t=false;
    cout << "Welcome to Cozy Homes!\n";
	cout << "Operating hours: 11am - 10pm Tuesday - Sunday\n\n\n\n";

	do {
		cout << "\n1. Register\n";
		cout << "2. Log In\n";
		cout << "3. Exit\n";
		cout << "please enter a number";
		cin >> Choice1;

		if (Choice1 == 1)
		{
			person.register_user();
		}

		else if (Choice1 == 2)
		{
			t = person.login();
			break;

		}

		else if (Choice1 == 3)
		{
			cout << "Exiting now...\n";
			return 0;
		}

		else if (Choice1 < 1 || Choice1 > 3)
		{
			cout << "Please choose a number from the menu!" << endl;
		}

	} while (Choice1 != 3);



    if(t)
	{
		library user;
	    int Choice2;
	    do
	    {
		    cout << "1. searching book\n";
		    cout << "2. reserve a book\n";
		    cout << "3. returning book\n";
		    cout << "4. Logout\n";
			cout << "please enter a number";
		    cin >> Choice2;

		    if (Choice2 == 1)
		    {
			    user.search();
		    }
		    else if (Choice2 == 2)
		    {
			    //user.reserve()
		    }
		    else if (Choice2 == 3)
		    {
			    //user.return()
		    }
		    else if (Choice2 == 4)
		    {
			    cout << "Logging out.....\n\n\n\n";
			    cout << endl;
		    }
	    } while (Choice2 != 4);
	}


}
