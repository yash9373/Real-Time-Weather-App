#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of frames to be sent: ";
    cin >> n;
    
    vector<int> buffer(n, 0); // Initialize buffer to all 0s
    int scount = 0;
    
    while (scount < n) {
        for (int i = 0; i < n; i++) {
            if (buffer[i] == 0) {
                cout << "\nSending frame " << i + 1 << " ... ";
                int ackStatus;
                cout << "Enter acknowledgment (1 for positive, 0 for Nigative): ";
                cin >> ackStatus;
               
                if (ackStatus == 1) {
                    cout << "\nSending frame " << i + 1 << " positive  received." << endl;
                    buffer[i] = 1;
                    scount++;
                     cout<<endl;
                } else {
                    cout << "Acknowledgment for frame " << i + 1 << "resive negative" << endl;
                    buffer[i] = 0; // Store unacknowledged frame in the buffer
                }
            }
        }
    }
    cout << "All frames successfully processed." << endl;

    return 0;
}
