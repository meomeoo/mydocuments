package app2;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;


@SpringBootApplication
public class App2 {
    public static void main(String[] args) {

        ApplicationContext context = SpringApplication.run(App2.class, args);

        DatabaseConnector databaseConnector = context.getBean(DatabaseConnector.class);
        databaseConnector.connect();
    }
}

    
    
    
    

    

    

    
