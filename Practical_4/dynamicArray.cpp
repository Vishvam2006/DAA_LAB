#include <iostream>
#include <cmath>
using namespace std;

struct City
{
    string name;
    int x;
    int y;
};

class CityDatabase
{
    City *arr;
    int size;
    int capacity;

public:
    CityDatabase()
    {
        capacity = 1;
        size = 0;
        arr = new City[capacity];
    }

    void resize()
    {
        capacity = capacity * 2;
        City *newArr = new City[capacity];

        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    void insert(string name, int x, int y)
    {
        if (size == capacity)
            resize();

        arr[size].name = name;
        arr[size].x = x;
        arr[size].y = y;

        size++;

        cout << "City inserted" << endl;
    }

    void deleteByName(string name)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].name == name)
            {
                for (int j = i; j < size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }

                size--;
                cout << "City deleted" << endl;
                return;
            }
        }

        cout << "City not Present" << endl;
    }

    void deleteByCoordinate(int x, int y)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].x == x && arr[i].y == y)
            {
                for (int j = i; j < size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }

                size--;
                cout << "City deleted" << endl;
                return;
            }
        }

        cout << "City not present" << endl;
    }

    void searchByName(string name)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].name == name)
            {
                cout << "City Found: " << arr[i].name << " (" << arr[i].x << "," << arr[i].y << ")" << endl;
                return;
            }
        }

        cout << "City not present" << endl;
    }

    void searchByCoordinate(int x, int y)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].x == x && arr[i].y == y)
            {
                cout << "City Found: " << arr[i].name << " (" << arr[i].x << "," << arr[i].y << ")" << endl;
                return;
            }
        }

        cout << "City not present" << endl;
    }

    void printWithinDistance(int x, int y, double dist)
    {
        cout << "Cities within distance " << dist << ":\n";

        for (int i = 0; i < size; i++)
        {
            double d = sqrt(pow(arr[i].x - x, 2) + pow(arr[i].y - y, 2));

            if (d <= dist)
            {
                cout << arr[i].name << " (" << arr[i].x << "," << arr[i].y << ")" << endl;
            }
        }
    }

    void display()
    {
        cout << endl
             << "City Records:" << endl;

        for (int i = 0; i < size; i++)
        {
            cout << arr[i].name << " (" << arr[i].x << "," << arr[i].y << ")" << endl;
        }
    }
};

int main()
{
    CityDatabase db;
    int choice, x, y;
    string name;
    double dist;

    while (true)
    {
        cout << "\n1.Insert\n2.Delete by Name\n3.Delete by Coordinate\n";
        cout << "4.Search by Name\n5.Search by Coordinate\n";
        cout << "6.Print within Distance\n7.Display\n8.Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter city name: ";
            cin >> name;
            cout << "Enter x and y: ";
            cin >> x >> y;
            db.insert(name, x, y);
            break;

        case 2:
            cout << "Enter city name: ";
            cin >> name;
            db.deleteByName(name);
            break;

        case 3:
            cout << "Enter x and y: ";
            cin >> x >> y;
            db.deleteByCoordinate(x, y);
            break;

        case 4:
            cout << "Enter city name: ";
            cin >> name;
            db.searchByName(name);
            break;

        case 5:
            cout << "Enter x and y: ";
            cin >> x >> y;
            db.searchByCoordinate(x, y);
            break;

        case 6:
            cout << "Enter reference point (x y): ";
            cin >> x >> y;
            cout << "Enter distance: ";
            cin >> dist;
            db.printWithinDistance(x, y, dist);
            break;

        case 7:
            db.display();
            break;

        case 8:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}