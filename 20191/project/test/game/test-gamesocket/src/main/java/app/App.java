package app;

import app.WebsocketServer;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;



@SpringBootApplication
public class App {

   

    public static void main(String[] args){

        new WebsocketServer().start();
        SpringApplication.run(App.class, args);
        
        
    }    
    
}
     
    