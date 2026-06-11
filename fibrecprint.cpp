#include <iostream>
using namespace std;
int fibonacci(int n)
{
    if (n<2)
    {
        return 1;
    }
    else
    {
    return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    for (int i = 1; i < n+1; i++)
    {
        cout << fibonacci(i-1) << " ";
    }
    cout << endl;

    return 0;
}