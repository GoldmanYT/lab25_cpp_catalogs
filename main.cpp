#include <iostream>

using namespace std;

const int ROWS = 3, COLS = 4;

typedef bool *arr_str[COLS];
arr_str *arr[ROWS];
int row, col, value;


void print_arr();


int main()
{
    cout << "\tTask 16\n";
    cout << "\t1\t2\t3\t4\n";
    cout << "1\t(-)\t( )\t( )\t( )\n";
    cout << "2\t( )\t( )\t( )\t(*)\n";
    cout << "3\t(+)\t\t\t\n";
    cout << endl;
    cout << "Source array:\n";
    print_arr();

    cout << "Enter array:\n";
    for (col = 0; col < COLS; col++)
    {
        cout << '\t' << col;
    }
    cout << endl;
    for (row = 0; row < ROWS; row++)
    {
        cout << row << '\t';
        if (row < 2)
        {
            arr[row] = new arr_str[1];
            for (col = 0; col < COLS; col++)
            {
                (*arr[row])[col] = new bool;
                cin >> value;
                *(*arr[row])[col] = value;
            }
        }
        else
        {
            arr[row] = nullptr;
            cout << endl;
        }
    }
    cout << endl;

    cout << "Entered array:\n";
    print_arr();

    cout << "Enter component [2][0]: ";
    row = 2;
    arr[row] = new arr_str[1];
    for (col = 0; col < COLS; col++)
    {
        if (col == 0)
        {
            (*arr[row])[col] = new bool;
            cin >> value;
            *(*arr[row])[col] = value;
        }
        else
        {
            (*arr[row])[col] = nullptr;
        }
    }

    cout << "Array after addiction:\n";
    print_arr();

    cout << "Deleting component [0][0]:\n";
    row = 0;
    col = 0;
    delete (*arr[row])[col];
    (*arr[row])[col] = nullptr;
    
    cout << "Array after deleting:\n";
    print_arr();

    cout << "Enter new value of component [1][3]: ";
    row = 1;
    col = 3;
    cin >> value;
    *(*arr[row])[col] = value;
    
    cout << "Array after changing:\n";
    print_arr();

    for (row = 0; row < ROWS; row++)
    {
        if (arr[row] != nullptr)
        {
            for (col = 0; col < COLS; col++)
            {
                if ((*arr[row])[col] != nullptr)
                {
                    delete (*arr[row])[col];
                    (*arr[row])[col] = nullptr;
                }
            }
        }
        delete [] arr[row];
        arr[row] = nullptr;
    }

    cout << "Cleared array:\n";
    print_arr();

    return 0;
}


void print_arr()
{
    for (col = 0; col < COLS; col++)
    {
        cout << '\t' << col;
    }
    cout << endl;
    for (row = 0; row < ROWS; row++)
    {
        cout << row << '\t';
        if (arr[row] != nullptr)
        {
            for (col = 0; col < COLS; col++)
            {
                if ((*arr[row])[col] != nullptr)
                {
                    cout << "(" << *(*arr[row])[col] << ")\t";
                }
                else
                {
                    cout << "( )\t";
                }
            }
        }
        else
        {
            for (col = 0; col < COLS; col++)
            {
                cout << "\t"; 
            }
        }
        cout << endl;
    }
    cout << endl;
}