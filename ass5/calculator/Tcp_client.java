import java.net.*;
import java.io.*;

public class Tcp_client {
    public static void main(String[] args) {
        try {
            Socket client = new Socket("localhost", 5000);
            System.out.println("Client is connected");

            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
            BufferedReader br = new BufferedReader(new InputStreamReader(client.getInputStream()));
            PrintWriter pw = new PrintWriter(client.getOutputStream(), true);

            while (true) {
                // Input two numbers from the user
                System.out.println("Enter first number:");
                int num1 = Integer.parseInt(userInput.readLine());
                System.out.println("Enter second number:");
                int num2 = Integer.parseInt(userInput.readLine());

                // Send the numbers to the server
                pw.println(num1);
                pw.println(num2);

                // Receive and print the sum from the server
                String sumResult = br.readLine();
                System.out.println(sumResult);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
