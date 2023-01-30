#include <iostream>
#include <cstring>
#include <fstream>
#include <regex>
#include <vector>

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
    //function for setting the username and pass
    //called when ever the user attends to login
    string setting_login_info(string loggedin_username= " " ,string loggedin_password= " "){
        this->username = loggedin_username;
        this->password = loggedin_password;
        return loggedin_username;
    }
    

    //function for registering the user info
    void register_user()
    {
        
        ofstream myfile1("userpass.txt", ios::app);
		if (!myfile1.is_open()) {
			cout << "could not open file \n";
		}

        cout<<"enter your first name:"<<endl;
        cin>>first_name;
        cout<<"enter your last name:"<<endl;
        cin>>last_name;
        cout<<"enter your birthdate:"<<endl;
        cin>>birthdate;
        cout<<"enter username:"<<endl;
        cin>>username;
        cout<<"enter password:"<<endl;
        cin >> password;
        cout<<"registered successfully"<<endl;
        myfile1 <<username<<"  "<<password<<"  "<<first_name<<"  "<<last_name<<"  "<<birthdate<<endl;
        myfile1.close();

    }



    //Log in page
	bool login(string inUser,string inPass)
	{
        bool status = false;
        ifstream myfile1("userpass.txt");
		if (CheckCredentials(inUser, inPass) == true)
		{
			cout << "Welcome, " <<inUser<< endl;
            setting_login_info(inUser,inPass);
			status = true;
		}

        return status;	
	}
    
    //this function takes the input username and pass
    //and checks if it matches with any of the database in our txt file.
    bool CheckCredentials(const string& inUser, const string& inPass)
    {
		string line = "  ";
		ifstream myfile1("userpass.txt");
		bool status = false;
		while (getline(myfile1,line)){
            stringstream iss(line);
            iss>>username>>password;
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
    //private attributes of class
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
        string status_book;
        string user_Id;


	public:
        
        //this function search for the book and checks if it exists in the library or not
		bool search()
		{

			int choice1=0;
			int choice2=0;
			int choice3=0;
			int choice4=0;
			string s;
			cout<<"Here is our Menu!\nTitle -Authors - Publisher - Published_year"<<endl;
            cout<<"If you don't want to search according to any feature put 0 and if you do put 1"<<endl;
            cout<<"For exp: if you want to search for title and published year, Enter 1 0 0 1"<<endl;
			cin>>choice1>>choice2>>choice3>>choice4;
			string line = " ";
			ifstream myfile3("books.txt");
			bool status = false;
			if(choice1==1 && choice2==0 && choice3==0 && choice4==0)
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

			if(choice2==1 && choice1==0 && choice3==0 && choice4==0)
			{
				cout << "Enter the name of the authors of book you are looking for";
				cin >> s;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors;
                    if (s == authors ) {
                        cout << "The title of the book is:" << title << endl;
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            if(choice3==1 && choice2==0 && choice1==0 && choice4==0)
			{
				cout << "Enter the publisher of the book you are looking for";
				cin >> s;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher;
                    if (s == publisher ) {
                        cout << "The title of the book is:" << title << endl;
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            if(choice4==1 && choice2==0 && choice3==0 && choice1==0)
			{
				cout << "Enter the title of the book you are looking for";
				cin >> s;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher >> published_year;
                    if (s == published_year ) {
                        cout << "The title of the book is:" << title << endl;
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            if(choice1==1 && choice2==1 && choice3==0 && choice4==0)
			{
				cout << "Enter the title of the book you are looking for: ";
				cin >> s;
				string s1;
				cout << "Enter the author's name: ";
				cin>>s1;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors;
                    if (s == title && s1 == authors ) {
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            if(choice1==1 && choice3==1 && choice2==0 && choice4==0)
			{
				cout << "Enter the title of the book you are looking for: ";
				cin >> s;
				string s1;
				cout << "Enter the publisher's name: ";
				cin>>s1;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher;
                    if (s == title && s1 == publisher ) {
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            if(choice1==1 && choice4==1 && choice3==0 && choice2==0)
			{
				cout << "Enter the title of the book you are looking for: ";
				cin >> s;
				string s1;
				cout << "Enter the published's year: ";
				cin>>s1;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher >> published_year;
                    if (s == title && s1 == published_year ) {
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            if(choice2==1 && choice3==1 && choice1==0 && choice4==0)
			{
				cout << "Enter the name of the authors of the book you are looking for: ";
				cin >> s;
				string s1;
				cout << "Enter the publisher's name: ";
				cin>>s1;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher;
                    if (s == authors && s1 == publisher ) {
                        cout << "The title of the book is:" << title << endl;
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            if(choice2==1 && choice4==1 && choice3==0 && choice1==0)
			{
				cout << "Enter the name of the authors of the book you are looking for: ";
				cin >> s;
				string s1;
				cout << "Enter the published year: ";
				cin>>s1;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher >> published_year;
                    if (s == authors && s1 == published_year ) {
                        cout << "The title of the book is:" << title << endl;
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            if(choice3==1 && choice4==1 && choice1==0 && choice2==0)
			{
				cout << "Enter the name of the publisher of the book you are looking for: ";
				cin >> s;
				string s1;
				cout << "Enter the published year: ";
				cin>>s1;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher>>published_year;
                    if (s == publisher && s1 == published_year ) {
                        cout << "The title of the book is:" << title << endl;
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            if(choice1==1 && choice2==1 && choice3==1 && choice4==0)
			{
				cout << "Enter the title of the book you are looking for: ";
				cin >> s;
				string s1;
				cout << "Enter the authors's name: ";
				cin>>s1;
				string s2;
				cout << "Enter the publisher's name: ";
				cin>>s2;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher;
                    if (s == title && s1 == authors && s2 == publisher ) {
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

			if(choice1==1 && choice2==1 && choice4==1 && choice3==0)
			{
				cout << "Enter the title of the book you are looking for: ";
				cin >> s;
				string s1;
				cout << "Enter the authors's name: ";
				cin>>s1;
				string s2;
				cout << "Enter the published year: ";
				cin>>s2;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher >> published_year;
                    if (s == title && s1 == authors && s2 == published_year ) {
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

			if(choice1==1 && choice3==1 && choice4==1 && choice2==0)
			{
				cout << "Enter the title of the book you are looking for: ";
				cin >> s;
				string s1;
				cout << "Enter the publisher's name: ";
				cin>>s1;
				string s2;
				cout << "Enter the published year: ";
				cin>>s2;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher >> published_year;
                    if (s == title && s1 == publisher && s2 == published_year ) {
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

			if(choice2==1 && choice3==1 && choice4==1 && choice1==0)
			{
				cout << "Enter the name of the authors of the book you are looking for: ";
				cin >> s;
				string s1;
				cout << "Enter the publisher's name: ";
				cin>>s1;
				string s2;
				cout << "Enter the published year: ";
				cin>>s2;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher >> published_year;
                    if (s == authors && s1 == publisher && s2 == published_year ) {
                        cout << "The title of the book is:" << title << endl;
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            if(choice1 == 1 && choice2==1 && choice3==1 && choice4==1)
			{
				cout << "Enter the title of the book you are looking for: ";
				cin >> s;
				string s1;
				cout << "Enter the authors name: ";
				cin>>s1;
				string s2;
				cout << "Enter the publisher's name: ";
				cin>>s2;
				string s3;
				cout << "Enter the published year: ";
				cin>>s3;
		        while (getline(myfile3,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher >> published_year;
                    if (s==title && s1 == authors && s2 == publisher && s3 == published_year ) {
                        cout << "The book was Successfully found!"<< endl;
                        status = true;
                        break;
                    }
                }

                if (!status) {
                    cout << "The book doesn't exist"<< endl;
                }

			}

            return status;

		}
        
        //this function reserves the book the user wants
        //if the user has 2 or more books borrowed in their account it doesnt reserves the book
        //it also changes the user id in the books.txt file to the logged in account
        //and changes the attribute status_book from free to reserved
        void reserve(string username_account)
        {
            library user;
            person_info a;
            string b;
            string n;
            bool d = false;
            cout<<"To continue reserving any book enter yes or no:(yes/no) "<<endl;
            cin>>b;
            cout << "Enter the title of the book you want to reserve: "<<endl;
            cin>>n;
            string line = " ";
			ifstream read_line;
            read_line.open("books.txt");
            vector<string> lines;
            while(getline(read_line,line))
            {
                lines.push_back(line);
            }

            if(b=="yes")
            {
                int line_num=0;
                string line1;
                ifstream read_line;
                read_line.open("books.txt");
                while (getline(read_line,line)){
                    stringstream iss(line);
                    iss >>title >>shelf_num>> authors >> edition >> publisher >> published_year >> ISBN >> length >> subjects >> status_book >> user_Id ;
                    if(n == title)
                    {
                        if (status_book == "free"){
                            d=maxbook(username_account);
                            if(d)
                            {
                                size_t pos1=line.find(status_book);
                                line1 = line.replace(pos1,4,"reserved");
                                size_t pos2=line.find(user_Id);
                                line1 = line.replace(pos2 ,4 ,username_account);
                                cout<<"the book has been reserved"<<endl;
                                break;
                    
                            }
                            else
                            {
                                cout <<"Sorry!"<<endl;
                                cout<<"The maximum number of book you could borrowed, reached!"<<endl;
                                cout<<"You can only borrow maximum of 2 books."<<endl;
                            }
                        }

                        else if(status_book == "reserved")
                        {
                            cout <<"Sorry!The book is borrowed by someone else";
                        }
                    }
                    line_num++;
                }
                
                //this if clause is written to check if anything has been changed so it changes the file
                //if no book has been borrowed so the file remains as it was
                if(d)
                {
                    ofstream output("books.txt");
                    for(int i=0;i<lines.size() ; i++)
                    {
            
                        if(i!=line_num)
                        {
                            output<<lines[i] << endl; 
                        }
                        else
                        {
                            output<<line1<< endl;
                        }

                    }
                    output.close();
                }
            }

        }
        

        //checks if the user had 2 or more books or not
        bool maxbook(string username_account)
        {
            int count=0;
            string line = " ";
			ifstream myfile3("books.txt");
            bool status=false;
            while (getline(myfile3,line)){
                stringstream iss(line);
                iss>>title >>shelf_num>> authors >> edition >> publisher >> published_year >> ISBN >> length >> subjects >> status_book >> user_Id ;
                if (user_Id == username_account){
                    count++;
                }
            }
            if (count < 2)
            {
                status=true;
            }
            return status;

        }


        //this function returns the book
        //it changes the user_id from the logged in user to Null
        //it also changes the status_book from reserved to free so that other people can borrow it
        void returning(string username_account)
        {
            int line_num=0;
            string s;
            cout<<"Enter the title of the book you want to return: "<<endl;
            cin>>s;
            string line = " ";
            string line1;
			ifstream myfile3("books.txt");
            bool status=false;
            ifstream read_line;
            read_line.open("books.txt");

            //here we put all the lines in the file into a vector
            //therefore we can use this vector to re-write on the file
            vector<string> lines;
            while(getline(read_line,line))
            {
                lines.push_back(line);
            }
            while (getline(myfile3,line)){
                stringstream iss(line);
                iss>>title >>shelf_num>> authors >> edition >> publisher >> published_year >> ISBN >> length >> subjects >> status_book >> user_Id ;
                if (s==title){            
                    size_t pos1=line.find(status_book);
                    line1 = line.replace(pos1,status_book.length(),"free");
                    size_t pos2=line.find(user_Id);
                    line1 = line.replace(pos2 ,user_Id.length() ,"NULL");
                    cout<<"thank you!\nThe book has been returned!"<<endl;
                    break;
                }
                line_num++;
            }

            ofstream output("books.txt");
            for(int i=0;i<lines.size() ; i++)
            {
            
                if(i!=line_num)
                {
                    output<<lines[i] << endl; 
                }
                else
                {
                    output<<line1<< endl;
                }

            }
            output.close();
    
        }

};

int main()
{
    library user;
    person_info person;
    string ans;
    string login_username;
    string login_pass;
    string inUser,inPass;
    int Choice1;
	bool t=false;
    bool d=false;
    cout << "Welcome to out library!\n";
	cout << "Operating hours: 11am - 10pm Tuesday - Sunday\n\n\n\n";

	do {
		cout << "\n1. Register\n";
		cout << "2. Log In\n";
		cout << "3. Exit\n";
		cout << "please enter a number"<<endl;
		cin >> Choice1;
    
		if (Choice1 == 1)
		{
			person.register_user();
		}

		else if (Choice1 == 2)
		{
            cout << "\nUsername: ";
			cin >> inUser;
			cout << "Password: ";
			cin >> inPass;
			t = person.login(inUser , inPass);
			if(t)
            {
                break;
            }

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
	    int Choice2;
        cout << "Remember,If you want to reserve any book,\nFirst check if the book exists in the library or not"<<endl;
	    do
	    {
            
		    cout << "1. searching book"<<endl;
		    cout << "2. reserve a book"<<endl;
		    cout << "3. returning book"<<endl;
		    cout << "4. Logout"<<endl;
			cout << "please enter a number"<<endl;
		    cin >> Choice2;

		    if (Choice2 == 1)
		    {
			    d = user.search();
		    }
		    else if (Choice2 == 2)
		    {
                if(d)
                {
                    user.reserve(inUser);
                }
		    }
		    else if (Choice2 == 3)
		    {
			    user.returning(inUser);
		    }
		    else if (Choice2 == 4)
		    {
			    cout << "Logging out.....\n\n";
			    cout << endl;
		    }
	    } while (Choice2 != 4);
	}


}
