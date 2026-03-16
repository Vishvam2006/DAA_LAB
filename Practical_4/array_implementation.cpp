#include <iostream>
#include <cmath>
using namespace std;

struct City
{
    string name;
    int x;
    int y;
    City* next;
};

City* head = NULL;


void insertCity(string name, int x, int y)
{
    City* newCity = new City();
    newCity->name = name;
    newCity->x = x;
    newCity->y = y;
    newCity->next = head;

    head = newCity;

    cout << "City inserted successfully."<<endl;
}


void deleteByName(string name)
{
    City *temp = head, *prev = NULL;

    while(temp != NULL)
    {
        if(temp->name == name)
        {
            if(prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            cout << "City deleted."<<endl;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "City not found."<<endl;
}


void deleteByCoordinate(int x, int y)
{
    City *temp = head, *prev = NULL;

    while(temp != NULL)
    {
        if(temp->x == x && temp->y == y)
        {
            if(prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            cout << "City deleted."<<endl;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "City not found."<<endl;
}


void searchByName(string name)
{
    City* temp = head;

    while(temp != NULL)
    {
        if(temp->name == name)
        {
            cout << "City Found: " << temp->name << " (" << temp->x << "," << temp->y << ")"<<endl;
            return;
        }
        temp = temp->next;
    }

    cout << "City not found."<<endl;
}


void searchByCoordinate(int x, int y)
{
    City* temp = head;

    while(temp != NULL)
    {
        if(temp->x == x && temp->y == y)
        {
            cout << "City Found: " << temp->name << " (" << temp->x << "," << temp->y << ")"<<endl;
            return;
        }
        temp = temp->next;
    }

    cout << "City not found."<<endl;
}


void printWithinDistance(int x, int y, double distance)
{
    City* temp = head;

    cout << "Cities within distance " << distance << ":"<<endl;

    while(temp != NULL)
    {
        double d = sqrt(pow(temp->x - x, 2) + pow(temp->y - y, 2));

        if(d <= distance)
        {
            cout << temp->name << " (" << temp->x << "," << temp->y << ")"<<endl;
        }

        temp = temp->next;
    }
}


void display()
{
    City* temp = head;

    cout << "C<<endlity Records:"<<endl;
    while(temp != NULL)
    {
        cout << temp->name << " (" << temp->x << "," << temp->y << ")"<<endl;
        temp = temp->next;
    }
}


int main()
{
    int choice, x, y;
    string name;
    double dist;

    while(true)
    {
        cout << "-<<endl-- City Database Menu ---"<<endl;
        cout << "1. Insert City"<<endl;
        cout << "2. Delete by Name"<<endl;
        cout << "3. Delete by Coordinate"<<endl;
        cout << "4. Search by Name"<<endl;
        cout << "5. Search by Coordinate"<<endl;
        cout << "6. Print Cities within Distance"<<endl;
        cout << "7. Display All Cities"<<endl;
        cout << "8. Exit"<<endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter city name: ";
                cin >> name;
                cout << "Enter x and y coordinates: ";
                cin >> x >> y;
                insertCity(name, x, y);
                break;

            case 2:
                cout << "Enter city name: ";
                cin >> name;
                deleteByName(name);
                break;

            case 3:
                cout << "Enter x and y coordinates: ";
                cin >> x >> y;
                deleteByCoordinate(x, y);
                break;

            case 4:
                cout << "Enter city name: ";
                cin >> name;
                searchByName(name);
                break;

            case 5:
                cout << "Enter x and y coordinates: ";
                cin >> x >> y;
                searchByCoordinate(x, y);
                break;

            case 6:
                cout << "Enter reference point (x y): ";
                cin >> x >> y;
                cout << "Enter distance: ";
                cin >> dist;
                printWithinDistance(x, y, dist);
                break;

            case 7:
                display();
                break;

            case 8:
                return 0;

            default:
                cout << "Invalid choice."<<endl;
        }
    }
}