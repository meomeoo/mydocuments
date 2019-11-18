package app;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import app.girl.Girl;


@SpringBootApplication
public class App {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(App.class, args);

        // Khi chạy xong, lúc này context sẽ chứa các Bean có đánh
        // dấu @Component.

        Girl girl = context.getBean(Girl.class);

        System.out.println("Girl Instance: " + girl);

        System.out.println("Girl Outfit: " + girl.outfit);

        girl.outfit.wear();
    }
}