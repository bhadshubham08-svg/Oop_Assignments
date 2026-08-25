//Assignment No. 1 

#include <iostream>
using namespace std;

int cnt;

class bankacc
{
    int accno;
    float accbal;
    string name;

public:

    bankacc()
    {
        accno=2300;
        accbal=0;
        name="XYZ";
    }

    void accept()
    {
        cout<<"Enter the basic details of Accountholder\nName,Accno,Accbal";
        cin>>name>>accno>>accbal;
        cnt++;
    }

    void deposit()
    {
        int acno,amt;

        cout<<"Enter Accno and amt to deposit into\n";
        cin>>acno>>amt;

        if(acno==accno)
        {
            if(amt > 0)
            {
                accbal=accbal+amt;
                cout<<"Amt deposited Successfully";
                cout<<"Total bal="<<accbal;
            }
            else
            {
                cout<<"amt invalid";
            }
        }
        else
        {
            cout<<"Account invalid";
        }
    }

    void withdraw()
    {
        int wamt,acno;

        cout<<"Enter acno and amt to withraw";
        cin>>acno>>wamt;

        if(acno==accno)
        {
            if(wamt<accbal)
            {
                accbal=accbal-wamt;
                cout<<"Amount debitted succesfully \n Balance="<<accbal;
            }
            else
            {
                cout<<"Balance low";
            }
        }
        else
        {
            cout<<"Acc no. invlaid";
        }
    }

    void search(int ano)
    {
        if(accno==ano)
        {
            display();
        }
    }

    void minimumBalance(int ano)
    {
        if(accno==ano)
        {
            if(accbal>=1000)
            {
                cout<<"Minimum balance maintained";
            }
            else
            {
                cout<<"Minimum balance not maintained";
            }
        }
    }

    void display()
    {
        cout<<name<<"\t"<<accno<<"\t"<<accbal<<"\n\n";
    }

    ~bankacc()
    {
    }
};

int main()
{
    bankacc b[100];
    int ch,i,n=0;

    do
    {
        cout<<"\nWelcome";
        cout<<"\n========== BANK ACCOUNT ==========";
        cout<<"\n1. Create Account";
        cout<<"\n2. Deposit";
        cout<<"\n3. Withdraw";
        cout<<"\n4. Display All Accounts";
        cout<<"\n5. Search Account";
        cout<<"\n6. Minimum Balance Check";
        cout<<"\n7. Exit";

        cout<<"\n\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                b[n].accept();
                n++;
                break;

            case 2:
                for(i=0;i<n;i++)
                {
                    b[i].deposit();
                    break;
                }
                break;

            case 3:
                for(i=0;i<n;i++)
                {
                    b[i].withdraw();
                    break;
                }
                break;

            case 4:
                for(i=0;i<cnt;i++)
                {
                    b[i].display();
                }
                break;

            case 5:
            {
                int ano;

                cout<<"Enter acc no to search the account: ";
                cin>>ano;

                for(i=0;i<cnt;i++)
                {
                    b[i].search(ano);
                }
                break;
            }

            case 6:
            {
                int ano;

                cout<<"Enter acc no to check minimum balance: ";
                cin>>ano;

                for(i=0;i<cnt;i++)
                {
                    b[i].minimumBalance(ano);
                }
                break;
            }

            case 7:
                cout<<"Thank you!";
                break;

            default:
                cout<<"Invalid selection";
                break;
        }

    }while(ch!=7);

    return 0;
}
