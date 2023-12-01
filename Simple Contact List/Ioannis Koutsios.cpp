#include <iostream>
using namespace std;    //Ioannis Koutsios
#include <fstream>
#include<vector>
#include<stdlib.h>
int main()
{
    ofstream write;
    ifstream read;
    char termi;
    do
    {
        int choice;
        cout << "1.Add new Contact" << endl;
        cout << "2.Retrieve Contact" << endl;
        cout << "3.Print all Contacts" << endl;
        cout << "4.Total number of Contacts" << endl;
        cout << "5.Random Contact" << endl;
        cout << endl;
        cout << "Enter you choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {

        case 1:
        {

            cout << "first name ? ";
            string fnam;
            cin >> fnam;
            cout << "last name ? ";
            string lnam;
            cin >> lnam;
            cout << "telephone number ? ";
            string tel;
            cin >> tel;
            cout << "email ? ";
            string email;
            cin >> email;
            write.open("contacts.txt", ios::app);
            write << fnam << "\t" << lnam << "\t" << tel << "\t" << email << "\n";
            write.close();
            break;
        }
        case 2:
        {
            string lnam, F, L, T, E;
            cout << "Last Name ? ";
            cin >> lnam;
            read.open("contacts.txt");
            while (!read.eof())
            {
                read >> F >> L >> T >> E;
                if (lnam == L)
                {
                    cout << F << "\t" << L << "\t" << T << "\t" << E << endl;
                }
            }
            read.close();
            break;


        }
        case 3:
        {
            string contct;
            read.open("contacts.txt");
            while (getline(read, contct))
                cout << contct << endl;
            read.close();
            break;
        }
        case 4:
        {
            int count = 0;
            string contct;
            read.open("contacts.txt");
            while (getline(read, contct))
                ++count;

            cout << "The total number of contacts is : " << count << endl;
            read.close();
            break;
        }
        case 5:
        {
            vector<string> temp;
            int count = 0;
            string contct;
            read.open("contacts.txt");
            while (getline(read, contct))
            {
                ++count;

                temp.push_back(contct);
            }
            read.close();
            int randd = rand() % count;
            cout << temp[randd] << endl;
            break;
        }

        }
        cout << endl;
        cout << "Do you want to continue ( Y / N ) ? "; 
        cin >> termi;
    } while (termi != 'N');
    return 0;
}