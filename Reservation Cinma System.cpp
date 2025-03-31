#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;


struct stBook
{

    char Row;
    short Col;
    string ClientName;

};


string Line(short LineLength, char LineType = '=')
{

    string line = "";
    for (short i = 0; i < LineLength; i++)
        line += LineType;

    return line;

}



short ValidateNumber(short Number)
{
      cin >> Number;

    while (cin.fail() || Number <1 || Number > 10)
    {

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "\nInvalid Number Please Enter another one: ";
        cin >> Number;

    }
    return Number;
}



char ValidateChar(char Character)
{
    cin >> Character;

    while (cin.fail() || toupper(Character) < 'A' || toupper(Character) >'E')
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max()), '\n');

        cout << "Invalide Character Enter another one please: ";
        cin >> Character;

    }

    return Character;

}



void FillMatrixWithSetNumber(char Matrix[5][10])
{

    short RowSymbol = 65;

    for (short i = 0; i < 5; i++)
    {

        for (short j = 0 ;j < 10; j++)
            Matrix[i][j] = '-';

        RowSymbol++;
    }

}


void printSeat(char Matrix[5][10])
{


    char Ch = 65;


    cout << "\n" << Line(52, '-') << "\n";
    cout << "     ";
    for (short i = 1; i <= 10; i++)
        cout << left << setw(5) << i;


    cout <<"\n" << Line(52, '-') << "\n";

    for (short i = 0; i < 5; i++)
    {
        cout << left << (char)Ch << " |  ";
            for (short j = 0; j < 10; j++)
                cout << left << setw(5) << Matrix[i][j];
        cout << endl;
        Ch++;
    }

    cout << Line(52, '_') << "\n";


}



bool FindAvailablSeat(vector<stBook> vBookData,short Col,char Row)
{

    for (stBook Cl : vBookData)
        if (Cl.Col == Col && toupper( Cl.Row) == toupper(Row))
            return true;

    return false;

}


stBook ReadBookingData()
{

    stBook Client;

    cout << "\nEnter Your name Sir: ";
    getline(cin >> ws, Client.ClientName);

    cout << "Enter Row [A - E] : ";
     Client.Row = ValidateChar(Client.Row);

    cout << "Enter Col [1-10]: ";
     Client.Col = ValidateNumber(Client.Col);

    return Client;
}



void GetSeat(char Matrix[5][10],vector<stBook> &vBookData)
{

  

    stBook Client;
    char Answer;


    cout << "\nAvailable seat:\n";
    printSeat(Matrix);

    cout << "\nDo you want book a seat? (N/Y)...";
    cin >> Answer;


    if (toupper(Answer) == 'Y')
    {
        
        Client = ReadBookingData();


        while (FindAvailablSeat(vBookData, Client.Col, Client.Row))
        {
            cout << "\nSorry this seat is not Available Select Another one:\n";

            cout << "Enter Row [A - E] : ";
            Client.Row = ValidateChar(Client.Row);

            cout << "Enter Col [1-10]: ";
           Client.Col =  ValidateNumber(Client.Col);

        }
        vBookData.push_back(Client);


        cout << "\nSeat (" << Client.Row << Client.Col << ") booked Successfully for Mr/s (" << Client.ClientName << ").\n";

        Matrix[(short)toupper(Client.Row) - 65][Client.Col - 1] = 'X';


        cout << "\nYour Seat in Cinma Map:\n";

        printSeat(Matrix);

        cout << "\nDo you Want book Another Seat? (N/Y)...";
        cin >> Answer;

        if (tolower(Answer) == 'y')
        {
            system("cls");
            GetSeat(Matrix,vBookData);
        }
        else
        {
            system("cls");
            cout << "\n\t\tEnd Of Booking System\n";
        }

    }

    else
        cout << "\n\n\t\tThe request has been Canceld.\n\n";


}


int main()
{
    
    char Matrix[5][10];
    vector <stBook> vClients;
    FillMatrixWithSetNumber(Matrix);
    GetSeat(Matrix,vClients);
    
}

