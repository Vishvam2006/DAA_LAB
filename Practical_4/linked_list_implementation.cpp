#include <iostream>
#include <cmath>
using namespace std;
struct City
{
    string name;
    int x;
    int y;
};
struct Node
{
    City data;
    Node *next;
};

Node *head = NULL;

void insertCity()
{
    Node *temp = new Node;

    cout << endl
         << "Insert City:" << endl;
    cout << "Enter City Name: ";
    cin >> temp->data.name;

    cout << "Enter X Coordinate: ";
    cin >> temp->data.x;

    cout << "Enter Y Coordinate: ";
    cin >> temp->data.y;

    temp->next = head;
    head = temp;

    cout << "City Inserted Successfully!" << endl;
}

void deleteByName()
{
    if (head == NULL)
    {
        cout << "Database is Empty!" << endl;
        return;
    }

    string name;
    cout << endl
         << "Enter City Name to Delete: ";
    cin >> name;

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data.name == name)
        {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;

            cout << "City Deleted Successfully!" << endl;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "City Not Found!" << endl;
}

void deleteByCoordinate()
{
    if (head == NULL)
    {
        cout << "Database is Empty!" << endl;
        return;
    }

    int x, y;

    cout << "Enter X Coordinate: ";
    cin >> x;

    cout << "Enter Y Coordinate: ";
    cin >> y;

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data.x == x && temp->data.y == y)
        {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;

            cout << "City Deleted Successfully!" << endl;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "City Not Found!" << endl;
}

void searchByName()
{
    if (head == NULL)
    {
        cout << "Database is Empty!" << endl;
        return;
    }

    string name;

    cout << endl
         << "Enter City Name to Search: ";
    cin >> name;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data.name == name)
        {
            cout << "City Found!" << endl;
            cout << "Name: " << temp->data.name
                 << "  X: " << temp->data.x
                 << "  Y: " << temp->data.y << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "City Not Found!" << endl;
}

void searchByCoordinate()
{
    if (head == NULL)
    {
        cout << "Database is Empty!" << endl;
        return;
    }

    int x, y;

    cout << "Enter X Coordinate: ";
    cin >> x;

    cout << "Enter Y Coordinate: ";
    cin >> y;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data.x == x && temp->data.y == y)
        {
            cout << "City Found!" << endl;
            cout << "Name: " << temp->data.name << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "City Not Found!" << endl;
}

void printWithinDistance()
{
    if (head == NULL)
    {
        cout << "Database is Empty!" << endl;
        return;
    }

    int x, y;
    double d;

    cout << "Enter Reference X Coordinate: ";
    cin >> x;

    cout << "Enter Reference Y Coordinate: ";
    cin >> y;

    cout << "Enter Distance: ";
    cin >> d;

    cout << endl
         << "Cities within Distance " << d << ":" << endl;

    Node *temp = head;
    bool found = false;

    while (temp != NULL)
    {
        double dist = sqrt((temp->data.x - x) * (temp->data.x - x) +
                           (temp->data.y - y) * (temp->data.y - y));

        if (dist <= d)
        {
            cout << temp->data.name << " (X=" << temp->data.x << ", Y=" << temp->data.y << ")" << endl;

            found = true;
        }

        temp = temp->next;
    }

    if (!found)
        cout << "No Cities Found in Given Distance." << endl;
}

void display()
{
    if (head == NULL)
    {
        cout << "Database is Empty!" << endl;
        return;
    }

    cout << endl
         << "All Cities:" << endl;

    Node *temp = head;
    int count = 1;

    while (temp != NULL)
    {
        cout << count << ". " << temp->data.name << " (X=" << temp->data.x << ", Y=" << temp->data.y << ")" << endl;

        temp = temp->next;
        count++;
    }
}

int main()
{
    int ch;

    while (1)
    {
        cout << "List of choices:" << endl;
        cout << "1. Insert City" << endl;
        cout << "2. Delete by Name" << endl;
        cout << "3. Delete by Coordinate" << endl;
        cout << "4. Search by Name" << endl;
        cout << "5. Search by Coordinate" << endl;
        cout << "6. Print Cities within Distance" << endl;
        cout << "7. Display All Cities" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            insertCity();
            break;

        case 2:
            deleteByName();
            break;

        case 3:
            deleteByCoordinate();
            break;

        case 4:
            searchByName();
            break;

        case 5:
            searchByCoordinate();
            break;

        case 6:
            printWithinDistance();
            break;

        case 7:
            display();
            break;

        case 0:
            cout << "Exiting Program..." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}