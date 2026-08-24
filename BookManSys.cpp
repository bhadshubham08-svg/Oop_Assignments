#include <iostream>
using namespace std;

class books
{
    string *auth;
    string *title;
    float price;
    int stock;

public:

    books()
    {
        auth= new string;
        title = new string;

        *auth = "XYZ";
        *title = "ABC";
        price = 0;
        
        stock = 0;
    }

    void accept()
    {
        cout << "\nEnter the Book Details";

        cout << "\nAuthor: ";
        cin >> *auth;
        cout << "Title: ";
        cin >> *title;
        cout << "Price: ";
        cin >> price;
        cout << "Stock: ";
        cin >> stock;
    }

    void search()
    {
        string a, t;

        cout << "\nEnter Author and Title: ";
        cin >> a >> t;

        if(a == *auth && t == *title)
        {
            cout << "\nBook Available";

            cout << "\nAuthor: " << *auth;
            cout << "\nTitle: " << *title;
            cout << "\nPrice: " << price;
            cout << "\nStock: " << stock;
        }
        else
        {
            cout << "\nBook not available";
        }
    }

    void purchase()
    {
        string a, t;
        int copies;

        cout << "\nEnter Author and Title: ";
        cin >> a >> t;

        if(a == *auth && t == *title)
        {
            cout << "\nBook Available";

            cout << "\nAuthor: " << *auth;
            cout << "\nTitle: " << *title;
            cout << "\nPrice: " << price;
            cout << "\nAvailable Stock: " << stock;

            cout << "\n\nEnter number of copies required: ";
            cin >> copies;

            if(copies <= stock)
            {
                cout << "\nBook Sold Successfully";
                cout << "\nTotal Cost = " << price * copies;

                stock = stock - copies;

                cout << "\nRemaining Stock = " << stock;
            }
            else
            {
                cout << "\nRequired copies not in stock";
            }
        }
        else
        {
            cout << "\nBook not available";
        }
    }

    void display()
    {
        cout << *auth << "\t"<< *title << "\t"<< price << "\t"<< stock << "\n";
    }

    void dapprice(float p)
    {
        if(price == p)
        {
            cout << *auth << "\t"
                 << *title << "\t"
                 << price << "\t"
                 << stock << "\n";
        }

    }

    ~books()
    {
        delete auth;
        delete title;
    }
};

int main()
{
    books b[100];

    int ch, i, n = 0;
    float p;

    do
    {
        cout << "\n\n========== BOOK SHOP ==========";
        cout << "\n1. Add Book";
        cout << "\n2. Search Book";
        cout << "\n3. Buy Book";
        cout << "\n4. Display All Books";
        cout << "\n5. Display Books of Particular Price";
        cout << "\n6. Exit";

        cout << "\n\nEnter choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                b[n].accept();
                n++;
                break;

            case 2:
                for(i = 0; i < n; i++)
                {
                    b[i].search();
                }
                break;

            case 3:
                for(i = 0; i < n; i++)
                {
                    b[i].purchase();
                }
                break;

            case 4:
                cout << "\nAuthor\tTitle\tPrice\tStock\n";

                for(i = 0; i < 100; i++)
                {
                    b[i].display();
                }
                break;

            case 5:
                cout << "\nEnter Price: ";
                cin >> p;


                for(i = 0; i < 100; i++)
                {
                    b[i].dapprice(p);
                }
                break;

            case 6:
                cout << "\nThank you!";
                break;

            default:
                cout << "\nInvalid selection";
                break;
        }

    } while(ch != 6);

    return 0;
}