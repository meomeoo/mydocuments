import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
 
public class Client {
    public final static String SERVER_IP = "192.168.1.40";
    public final static int SERVER_PORT = 8082;
 
    public static void main(String[] args) throws IOException, InterruptedException {
        Socket socket = null;
        try {
            socket = new Socket(SERVER_IP, SERVER_PORT); // Connect to server
            System.out.println("Connected: " + socket);
 
            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();
                int i =1;
                os.write(i); // Send each number to the server
                
            
        } catch (IOException ie) {
            System.out.println("Can't connect to server");
        } finally {
            if (socket != null) {
                socket.close();
            }
        }
    }
}