#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, choice;
    cout << "Enter the number of frames to be sent: ";
    cin >> n;

    vector<int> ack(n, 0); // Initialize acknowledgments to 0 for all frames

    int ackCount = 0;
    int retransmitFrame = -1; // Frame to retransmit (initially set to -1)

    while (ackCount < n) {
        for (int i = 0; i < n; i++) {
            if (ack[i] == 1) {
                cout << "Sending frame " << i + 1 << " ... Acknowledgment already received." << endl;
                continue;
            }

            int ackStatus;

            cout << "Sending frame " << i + 1 << " ... ";
            cout << "Enter acknowledgment (1 for Yes, 0 for No): ";
            cin >> ackStatus;

            if (ackStatus == 1) {
                ack[i] = 1; // Accept acknowledgment for frame i
                ackCount++;
            } else {
                cout << "Acknowledgment for frame " << i + 1 << " not received." << endl;
                retransmitFrame = i; // Set the frame to be retransmitted
                i--; // Reattempt transmission of the same frame
                cout << "Retransmitting frame " << retransmitFrame + 1 << endl;
                for (int j = i + 1; j < n; j++) {
                    cout << "Sending frame " << j + 1 << " ..." << endl;
                }
            }
        }
        
        if (retransmitFrame != -1) {
            retransmitFrame = -1; // Reset retransmit frame after retransmission
        }
    }

    cout << "All Frames successfully received" << endl;

    cout << "Do you want to continue? (1 for Yes, 0 for No): ";
    cin >> choice;

    if (choice == 1) {
        // You can add more code for further communication if needed.
    }

    return 0;
}
