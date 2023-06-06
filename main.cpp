// main branch 
// muktar and abdisa 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_BOOKS = 100;

struct Book
 {
    string title;
    string author;
    string category;
    int quantity;
    double price;
};

Book books[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void ownerMenu();
void customerMenu();
void login();
void addNewBook();
void showAvailableBooks();
void searchBooks();
void modifyBooks();
void deleteBooks();
void accounting();
void customerPurchase();
void searchBookForPurchase();
void orderBook();

// Function to display a menu and get the choice from the user
int getMenuChoice()
 {
    int choice;

    cout << "\nMenu:\n";
    cout << "1. Add new books\n";
    cout << "2. Show available books\n";
    cout << "3. Search books\n";
    cout << "4. Modify books\n";
    cout << "5. Delete books\n";
    cout << "6. Accounting\n";
    cout << "7. Logout\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Function to display the owner menu
void ownerMenu()
{
    int choice;
    do
	 {
        choice = getMenuChoice();
        switch (choice)
		{
            case 1:
                addNewBook();
                break;
            case 2:
                showAvailableBooks();
                break;
            case 3:
                searchBooks();
                break;
            case 4:
                modifyBooks();
                break;
            case 5:
                deleteBooks();
                break;
            case 6:
                accounting();
                break;
            case 7:
                cout << "Logged out as owner.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
	while (choice != 7);
}

// Function to display the customer menu
void customerMenu()
 {
    int choice;
    do
	{

        cout << "\nMenu:\n";
        cout << "1. Show book list\n";
        cout << "2. Purchase book\n";
        cout << "3. Search book\n";
        cout << "4. Order book\n";
        cout << "5. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
		 {
            case 1:
                showAvailableBooks();
                break;
            case 2:
                customerPurchase();
                break;
            case 3:
                searchBookForPurchase();
                break;
            case 4:
                orderBook();
                break;
            case 5:
                cout << "Logged out as customer.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
	while (choice != 5);
}

// Function to authenticate the owner
void login()
 {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Add your own authentication logic here
    // For simplicity, let's assume username: admin, password: admin
    if (username == "admin" && password == "admin")
	{
        cout << "Login successful!\n";
        ownerMenu();
    }
	else
	 {
        cout << "Login failed. Invalid username or password.\n";
    }
}

// Function to add new books
void addNewBook()
{
    fstream file;
    cin.ignore();
    if (bookCount == MAX_BOOKS)
	 {
        cout << "Maximum book limit reached.\n";
        return;
    }

    Book newBook;
    cout << "Enter book title: ";
    getline(cin, newBook.title);
    cout << "Enter author: ";
    getline(cin, newBook.author);
    cout << "Enter category: ";
    getline(cin, newBook.category);
    cout << "Enter quantity: ";
    cin >> newBook.quantity;
    cout << "Enter price: ";
    cin >> newBook.price;
    file.open("book_shop.txt",ios::out|ios::app);
    file<<"\n" <<newBook.title<<" \n "<<newBook.author<<" \n "<<newBook.category<<" \n "
	<<newBook.quantity<<"  \n "<<newBook.price<<"\n";
    books[bookCount] = newBook;
    bookCount++;

    cout << "Book added successfully!\n";
    file.close();
}

// Function to show available books
void showAvailableBooks()
{
 fstream file;
 Book newBook;
//file.open("book_shop.txt",ios::in|ios::app);
file.open("book_shop.txt", ios::in);

    if (!file)
	{
        cout << "file is not open\n";
    }
	 else
	  {
        cout << "\nAvailable Books:\n";
          file>> newBook.title>> newBook.author;
           file>> newBook.category>> newBook.quantity>> newBook.price;
       while (!file.eof())
	   {
	   	    cout << "Title: " ;cout << newBook.title << endl;
            cout << "Author: "; cout << newBook.author<< endl;
            cout << "Category:";cout << newBook.category  << endl;
            cout << "Quantity: ";cout << newBook.quantity << endl;
            cout << "Price: $";cout << newBook.price << endl;
            cout << "--------------------------\n";
            file>> newBook.title>> newBook.author;
            file>> newBook.category>> newBook.quantity>> newBook.price;
			file.close();
	   }
    }
}

// Function to search books
void searchBooks()
 {
 	fstream file;
 	cout<<"Cheak you want book \n";
 	file.open("book_shop.txt",ios::in|ios::app);
 	if (!file)
	 {
	 	cout<<"File openning erorr!!\n";
	 }
	 else
	 {
    Book newBook;
	int count=0;
    cin.ignore();
    string searchTerm;
    cout << "Enter the book title  to search: ";
    getline(cin, searchTerm);
    file>> newBook.title>> newBook.author;
	file>> newBook.category>> newBook.quantity>> newBook.price;
	while (!file.eof())
	{
		if (searchTerm==newBook.title)
		{
		cout<<"Your Specific cheak book is:\n";
        cout << "Title: " ;cout << newBook.title << endl;
        cout << "Author: "; cout << newBook.author<< endl;
        cout << "Category:";cout << newBook.category  << endl;
        cout << "Quantity: ";cout << newBook.quantity << endl;
        cout << "Price: $";cout << newBook.price << endl;
        cout << "--------------------------\n";
        count++;
        break;

		}
		 file>> newBook.title>> newBook.author;
	     file>> newBook.category>> newBook.quantity>> newBook.price;
	}
	file.close();
	if (count==0)
		cout<<"Book title is not found....\n";
	 }
}

// Function to modify books
void modifyBooks()
{
	fstream file,file1;
	int count=0;
	struct Book
{
    string title;
    string author;
    string category;
    int quantity;
    double price;
};
	struct Books
	{
    string title_new;
    string author_new;
    string category_new;
    int quantity_new;
    double price_new;
	};
	file1.open("book_shop1.txt",ios::app|ios::out);
 	file.open("book_shop.txt",ios::in|ios::app);
 	if (!file)
	 {
	 	cout<<"File openning erorr!!\n";
	 }
	 else
	 {
	Book newBook;
	Books modBooks;
    cout<<"modify you want book \n";
    cin.ignore();
    string searchTerm;
    cout << "Enter the book title or author to modify: ";
    getline(cin, searchTerm);
    file>>newBook.title>>newBook.author;
	file>>newBook.category>>newBook.quantity>>newBook.price;
	while (!file.eof())
	{
		if (searchTerm==newBook.title)
		{
		cout<<"Modifying a new book\n";
        cout << "Enter  new book title: ";
        getline(cin, modBooks.title_new);
        cout << "Enter  new author: ";
        getline(cin,modBooks. author_new);
        cout << "Enter  new category: ";
        getline(cin, modBooks.category_new);
        cout << "Enter  new quantity: ";
        cin >> modBooks.quantity_new;
        cout << "Enter new price: ";
        cin >> modBooks.price_new;
        file1<<"\n" <<modBooks.title_new<<" \n "<<modBooks.author_new<<" \n "<<modBooks.category_new<<" \n "
	     <<modBooks.quantity_new<<"  \n "<<modBooks.price_new<<"\n";
        cout << "Book added successfully!\n";
		count++;
		}
		else
		file1<<"\n" <<modBooks.title_new<<" \n "<<modBooks.author_new<<" \n "<<modBooks.category_new<<" \n "
        <<modBooks.quantity_new<<"  \n "<<modBooks.price_new<<"\n";
        file>> newBook.title>> newBook.author;
	    file>> newBook.category>> newBook.quantity>> newBook.price;

	}
    if (count==0)
	{
		cout<<"Book title is not found....\n";
	}
	 }
	 file.close();
    file1.close();
    remove("book_shop.txt");
    rename("book_shop1.txt","book_shop.txt");
}

// Function to delete books
void deleteBooks()
{
	fstream file,file1;
	int count=0;
		struct Book
{
    string title;
    string author;
    string category;
    int quantity;
    double price;
};
	struct Books
	{
    string title_new;
    string author_new;
    string category_new;
    int quantity_new;
    double price_new;
	};
	cout<<"Delat books record\n";
	file1.open("book_shop1.txt",ios::app|ios::out);
 	file.open("book_shop.txt",ios::in|ios::app);
	if (!file)
	{
		cout<<"File openning Eroe...\n";
	}
	else
	{
    Book newBook;
	Books modBooks;
	cin.ignore();
    string searchTerm;
    cout << "Enter the book title or author to delete: ";
    getline(cin, searchTerm);
	file>>newBook.title>>newBook.author;
	file>>newBook.category>>newBook.quantity>>newBook.price;
	while (!file.eof())
	{
		if (searchTerm==newBook.title)
		{
		cout<<"Delat book record\n";
		cout<<"The book was deleted sucssesfuly.....\n";
		count++;
		}
		else
	file1<<"\n" <<modBooks.title_new<<" \n "<<modBooks.author_new<<" \n "<<modBooks.category_new<<" \n "
    <<modBooks.quantity_new<<"  \n "<<modBooks.price_new<<"\n";
	file>> newBook.title>> newBook.author;
    file>> newBook.category>> newBook.quantity>> newBook.price;
	}
	if (count==0)
	{
		cout<<"File title is not found....\n";
	}
	}
	file.close();
    file1.close();
    remove("book_shop.txt");
    rename("book_shop1.txt","book_shop.txt");

}

// Function to calculate accounting information
void accounting()
{
    int soldBooks = 0;
    double income = 0.0;

    for (int i = 0; i < bookCount; i++)
	{
        int quantitySold;
        cout << "Enter the quantity of " << books[i].title << " sold: ";
        cin >> quantitySold;

        if (quantitySold <= books[i].quantity)
		{
            books[i].quantity -= quantitySold;
            soldBooks += quantitySold;
            income += quantitySold * books[i].price;
        }
		else
		{
            cout << "Invalid quantity. Cannot sell more books than available.\n";
        }
    }

    cout << "Total sold books: " << soldBooks << endl;
    cout << "Total income: $" << income << endl;
}

// Function for customer to purchase books
void customerPurchase()
{
	int x;
	cout<<"Welcome To Purchasing Menu \n";
	cout<<"Enter 1 .To show the aveliable books\n";
	cin>>x;
	if (x==1)
	{
	showAvailableBooks();
	}
    cin.ignore();
    string searchTerm;
    cout << "Enter the book title or author to purchase: ";
    getline(cin, searchTerm);

    bool found = false;
    for (int i = 0; i < bookCount; i++)
	{
        if (books[i].title.find(searchTerm) != string::npos || books[i].author.find(searchTerm) != string::npos) {
            if (books[i].quantity > 0)
			 {
                books[i].quantity--;
                cout << "Book purchased successfully!\n";
            }
			 else
			 {
                cout << "Book is out of stock.\n";
            }
            found = true;
        }
    }

    if (!found)
	{
        cout << "Book not found.\n";
    }
}

// Function for customer to search books for purchase
void searchBookForPurchase()
 {
  fstream file;
 	cout<<"Cheak you want book \n";
 	file.open("book_shop.txt",ios::in|ios::app);
 	if (!file)
	 {
	 	cout<<"File openning erorr!!\n";
	 }
	 else
	 {
    Book newBook;
	int pro=1, no,count=0;
    cin.ignore();
    string searchTerm;
    cout << "Enter the book title  to search: ";
    getline(cin, searchTerm);
    file>> newBook.title>> newBook.author;
	file>> newBook.category>> newBook.quantity>> newBook.price;
	while (!file.eof())
	{
		if (searchTerm==newBook.title)
		{
		cout<<"Your Specific cheak book is:\n";
        cout << "Title: " ;cout << newBook.title << endl;
        cout << "Author: "; cout << newBook.author<< endl;
        cout << "Category:";cout << newBook.category  << endl;
        cout << "Price: $";cout << newBook.price << endl;
        cout << "--------------------------\n";
        count++;
         cout<<"How many quantity do you want to purchease\n";
	     cin>>no;
	     pro= newBook.price*no;
	     cout<<"The total amount of Birr is:"<<pro<<endl;
	     cout<<"If you want to purches Enter 1 othrewaise Enter any key\n";
	     cin>>no;
	     if (no==1)
		 {
		 	int choice;
		 	cout<<"Welcome To our Purches Option\n";
		 	cout<<"1.To Purches throwh Tell birr\n";
		 	cout<<"2.To purchese throwh CBE bank\n";
		 	cout<<"3.To purchese throwh Cash \n";
		 	cin>>choice;
		 	switch (choice)
		 	{
			 	case 1:
			 		cout<<"Welcome To Tell birr purchese system\n";
			 		cout<<"Send this  "<<pro<<"  Birr to this phone no 0964002010\n";

			 }
		 }
        break;

		}
		 file>> newBook.title>> newBook.author;
	     file>> newBook.category>> newBook.price;

	}
	file.close();
	if (count==0)
		cout<<"Book title is not found....\n";
	 }
}

// Function for customer to order books
void orderBook()
 {
 	fstream file;
    cin.ignore();
    if (bookCount == MAX_BOOKS)
	 {
        cout << "Maximum book limit reached.\n";
        return;
    }

    Book newBook;
    cout << "Enter book title: ";
    getline(cin, newBook.title);
    cout << "Enter author: ";
    getline(cin, newBook.author);
    cout << "Enter category: ";
    getline(cin, newBook.category);
    cout << "Enter quantity: ";
    cin >> newBook.quantity;
    file.open("book_shop.txt",ios::out|ios::app);
    file<<"\n" <<newBook.title<<" \n "<<newBook.author<<" \n "<<newBook.category<<" \n "
	<<newBook.quantity<<"  \n "<<newBook.price<<"\n";
    books[bookCount] = newBook;
    bookCount++;

    cout << "Book ordered successfully!\n";
    file.close();
}

int main()
 {
    int choice;
    do
	 {
        cout<< R"(
     ____              _       _____ _                    _____           _                 
    |  _ \            | |     / ____| |                  / ____|         | |                
    | |_) | ___   ___ | | __ | (___ | |__   ___  _ __   | (___  _   _ ___| |_ ___ _ __ ___  
    |  _ < / _ \ / _ \| |/ /  \___ \| '_ \ / _ \| '_ \   \___ \| | | / __| __/ _ \ '_ ` _ \ 
    | |_) | (_) | (_) |   <   ____) | | | | (_) | |_) |  ____) | |_| \__ \ ||  __/ | | | | |
    |____/ \___/ \___/|_|\_\ |_____/|_| |_|\___/| .__/  |_____/ \__, |___/\__\___|_| |_| |_|
                                                | |              __/ |                      
                                                |_|             |___/                       
    )"<<endl;
        cout << "Welcome to the Book Shop Management System\n";
        cout << "1. Owner\n";
        cout << "2. Customer\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
		 {
            case 1:
                login();
                break;
            case 2:
                customerMenu();
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
	while (choice != 3);

    return 0;
}
