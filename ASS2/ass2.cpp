#include<iostream>

using namespace std;

int main()
{
    int a[8], b[8], c1, c2, c3;
    int count=0;
    cout << "\nEnter the 4-bit number: ";
    cin >> a[3] >> a[5] >> a[6] >> a[7];

    // Calculate parity bits
    a[1] = a[3] ^ a[5] ^ a[7];
    a[2] = a[3] ^ a[6] ^ a[7];
    a[4] = a[5] ^ a[6] ^ a[7];

    cout << "\nHamming Code: ";
    for (int i = 1; i <= 7; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\nEnter the received 7-bit number: ";
    for (int i = 1; i <= 7; i++)
    {
        cin >> b[i];
    }

    // Calculate syndrome bits
    c1 = b[1] ^ b[3] ^ b[5] ^ b[7];
    c2 = b[2] ^ b[3] ^ b[6] ^ b[7];
    c3 = b[4] ^ b[5] ^ b[6] ^ b[7];

    int p = c1 + c2 * 2 + c3 * 4; //used to calculate the position of the erroneous

    if (p == 0)
    {
        cout << "\nNo error detected." << endl;
    }
    
    else
    {   


         cout << "\nError detected at possition  " << p << endl;
        b[p] = 1 - b[p]; // Flip the erroneous bit

        cout << "\nCorrected Code: ";
        for (int i = 1; i <= 7; i++)
        {
            cout << b[i] << " ";
        }

    //     for(int i = 0;i< 8;i++)
    // {
    //         if(a[i]!=b[i])
    //         {
    //             count ++;
    //         }
    // }   
    //     if(count == 1)
    //     {
    //     cout << "\nError detected at possition  " << p << endl;
    //     b[p] = 1 - b[p]; // Flip the erroneous bit

    //     cout << "\nCorrected Code: ";
    //     for (int i = 1; i <= 7; i++)
    //     {
    //         cout << b[i] << " ";
    //     }
    //     }
    //     else
    //     {
    //         cout<<"\n resive Wrong Data more than one possition ";
    //     }
    }

    return 0;
}
