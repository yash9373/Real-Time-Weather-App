import java.net.*;
import java.io.*;

public class Tco_server {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(5000);
            System.out.println("Waiting for client...");

            Socket server = ss.accept();
            System.out.println("Server is connected");

            BufferedReader br = new BufferedReader(new InputStreamReader(server.getInputStream()));
            PrintWriter pw = new PrintWriter(server.getOutputStream(), true);

            while (true) {
                // Read two numbers from the client
                int num1 = Integer.parseInt(br.readLine());
                int num2 = Integer.parseInt(br.readLine());

                // Calculate the sum
                int sum = num1 + num2;

                // Send the sum back to the client
                pw.println("Sum: " + sum);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
