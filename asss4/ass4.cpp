#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    string ipAddress, subnetMask;

    // Prompt the user to enter an IP address and a subnet mask.
    cout << "Enter an IP address (in the format xxx.xxx.xxx.xxx): ";
    cin >> ipAddress;
    cout << "Enter a subnet mask (in the format xxx.xxx.xxx.xxx): ";
    cin >> subnetMask;

    // Parse the IP address and subnet mask.
    int ip[4], mask[4];
    sscanf(ipAddress.c_str(), "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(subnetMask.c_str(), "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    // Check if the values are valid (0-255).
    for (int i = 0; i < 4; i++) {
        if (ip[i] < 0 || ip[i] > 255 || mask[i] < 0 || mask[i] > 255) {
            cout << "Invalid input. IP address and subnet mask components must be in the range 0-255." << endl;
            return 1;
        }
    }

    // Calculate the subnet address.
    int subnet[4];
    for (int i = 0; i < 4; i++) {
        subnet[i] = ip[i] & mask[i];
    }

    // Calculate the subnet + range, first host address, and last host address.
    int startRange[4], endRange[4], firstHost[4], lastHost[4];
   for (int i = 0; i < 4; i++) {
    startRange[i] = subnet[i] & mask[i]; // Calculate the network address
    endRange[i] = subnet[i] | (255 - mask[i]); // Calculate the broadcast address
    firstHost[i] = (i == 3) ? startRange[i] + 1 : subnet[i]; // Calculate the first host
    lastHost[i] = (i == 3) ? endRange[i] - 1 : endRange[i]; // Calculate the last host
}

    // Calculate the number of hosts and subnets.
    int prefixLength = 0;
    for (int i = 0; i < 4; i++) {
        prefixLength += bitset<8>(mask[i]).count();
    }
    int hostsPossible = (1 << (32 - prefixLength)) - 2;  // Subtract 2 for last hot bit 0 network and 1 broadcast resurve . 
    //determines how many bits are reserved for network identification.
    int subnetsPossible = 1 << (prefixLength - 16);

    // Display the results.
    cout << "Subnet Address: " << subnet[0] << "." << subnet[1] << "." << subnet[2] << "." << subnet[3] << endl;
    cout << "Subnet Address Range: " << startRange[0] << "." << startRange[1] << "." << startRange[2] << "." << startRange[3]
         << " - " << endRange[0] << "." << endRange[1] << "." << endRange[2] << "." << endRange[3] << endl;
    cout << "First Host Address: " << firstHost[0] << "." << firstHost[1] << "." << firstHost[2] << "." << firstHost[3] << endl;
    cout << "Last Host Address: " << lastHost[0] << "." << lastHost[1] << "." << lastHost[2] << "." << lastHost[3] << endl;
    cout << "Total Number of Hosts Possible: " << hostsPossible << endl;
    cout << "Total Number of Subnets Possible: " << subnetsPossible << endl;
    cout << prefixLength << endl;  // The number of fixed bits in the subnet mask.

    return 0;
}
