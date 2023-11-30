import java.net.*; // Package for TCP socket programming
import java.io.*;
import java.util.*; // Scanner class

public class Tcp_server {
    public static void main(String[] args) {
        try {
            // Create a server socket on port 5000
            ServerSocket ss = new ServerSocket(5000);
            System.out.println("Waiting for client..."); // Server state: waiting for a client to connect

            // Accept a client connection
            Socket server = ss.accept();
            System.out.println("Server is connected"); // Server state: client connected

            // Send data from the server to the client
            Scanner sc = new Scanner(System.in);
            PrintWriter pw = new PrintWriter(server.getOutputStream());
//This line of code is creating a PrintWriter object named pw that is associated with the output stream of the Socket 
//named server. This allows you to write data to the output stream of the socket, which is the stream connecting your server 
//to the connected client.
            // Continuous loop to read data from the console and send it to the client
            while (true) {
                System.out.println("Enter data:");
                String data = sc.nextLine();
                
                // Send data to the client
                pw.println(data);
                pw.flush(); //The flush() function, in the context of PrintWriter, is used to flush the output buffer
            }
        } catch (Exception e) {
            // Handle any exceptions that may occur
            e.printStackTrace();
        }
    }
}
