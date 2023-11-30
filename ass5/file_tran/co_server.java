import java.io.*;
import java.net.*;

public class co_server {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(12345);
            System.out.println("Server waiting for client...");
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected.");

            DataOutputStream dos = new DataOutputStream(clientSocket.getOutputStream());
            File fileToSend = new File("file.txt");
            FileInputStream fis = new FileInputStream(fileToSend);
            byte[] buffer = new byte[1024];
            int bytesRead;

            while ((bytesRead = fis.read(buffer)) != -1) {
                dos.write(buffer, 0, bytesRead);
            }

            System.out.println("File sent successfully.");
            fis.close();
            dos.close();
            clientSocket.close();
            serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
