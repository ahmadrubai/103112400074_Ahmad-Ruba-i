#include <iostream>
using namespace std;

int main(){
    int n;
    int a = 1;
    cout << "input: ";
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--) 
        {
            cout << j;
        }
        
        cout << "*";
        for (int j = 1; j <= i; j++)
        {
            cout << j ;
        }

        cout << endl;
        for (int j = 1; j <= a; j++)
        {
           cout << " ";
        }
        a = a + 1;

    }
    cout << "*";
    
}