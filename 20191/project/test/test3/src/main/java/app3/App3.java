package app3;
import app3.WebController;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class App3 {
    public static void main(String[] args) {
        new WebsocketServer().start();

        SpringApplication.run(App3.class, args);
    }
}