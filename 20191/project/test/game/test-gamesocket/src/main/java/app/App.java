package app;



import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;



@SpringBootApplication
public class App {
    public final static int SERVER_PORT = 8085;

   

    public static void main(String[] args) {
        SpringApplication.run(App.class, args);

    }
}
     
    