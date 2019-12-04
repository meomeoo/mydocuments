package app6; 

import app6.*;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

import lombok.RequiredArgsConstructor;

@SpringBootApplication
@RequiredArgsConstructor
public class App6 {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(App6.class, args);
        UserRepository userRepository = context.getBean(UserRepository.class);

       userRepository.findByEmail("anh").forEach(System.out::println);
       

    }

}