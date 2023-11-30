
import java.net.*;
import java.io.*;

public class Tcp_client {
    public static void main(String[] args) {
        try {
            // Create a socket to connect to the server on localhost and port 5000
            Socket client = new Socket("localhost", 5000);
            System.out.println("Client is connected");

            // Create a BufferedReader to read data from the server
            BufferedReader br = new BufferedReader(new InputStreamReader(client.getInputStream()));
//BufferedReader to read text data from the input stream of the Socket. 
            // Read data from the server continuously
            while (true) {
                // Read a line of data from the server
                String data = br.readLine();

                // Print the data received from the server
                System.out.println("Data from server: " + data);
            }
        } catch (Exception e) {
            // Handle any exceptions that may occur
            e.printStackTrace();
        }
    }
}   
