#include <iostream>

using namespace std;

int main()
{
    int length;
    cin >> length;

    int arr[length];
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    int soCapBangNhau = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] == arr[j])
            {
                soCapBangNhau++;
            }
        }
    }

    cout << soCapBangNhau << endl;

    return 0;
}