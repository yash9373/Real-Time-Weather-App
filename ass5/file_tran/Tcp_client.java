import java.io.*;
import java.net.*;

public class Tcp_client {
    public static void main(String[] args) {
        try {
            Socket clientSocket = new Socket("localhost", 12345);
            DataInputStream dis = new DataInputStream(clientSocket.getInputStream());
            FileOutputStream fos = new FileOutputStream("received_file.txt");
            byte[] buffer = new byte[1024];
            int bytesRead;

            while ((bytesRead = dis.read(buffer)) != -1) {
                fos.write(buffer, 0, bytesRead);
            }

            System.out.println("File received successfully.");
            fos.close();
            dis.close();
            clientSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
