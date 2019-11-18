# Tham khảo từ Series hướng dẫn Spring Boot căn bản, Zero to Hero 
[link bài viết ](https://kipalog.com/posts/Series-huong-dan-Spring-Boot-can-ban--Zero-to-Hero) 

## 9/11/2019

- Học về @Component @Autowired: được sử dụng để dùng để khởi tạo bác beans đưa vào trong context

- Spring đặt tên cho container là ApplicationContext và đặt tên cho các dependency là Bean
### @component 

@Component là một Annotation (chú thích) đánh dấu trên các Class để giúp Spring biết nó là một Bean.
```
/*
 Đánh dấu class bằng @Component
 Class này sẽ được Spring Boot hiểu là một Bean (hoặc dependency)
 Và sẽ được Spring Boot quản lý
*/
@Component
public class Bikini implements Outfit {
    @Override
    public void wear() {
        System.out.println("Mặc bikini");
    }
}

```
Spring Boot khi chạy sẽ dò tìm toàn bộ các Class cùng cấp hoặc ở trong các package thấp hơn so với class App mà bạn cung cấp cho Spring (Chúng ta có thể cấu hình việc tìm kiếm này, sẽ đề cập sau). Trong quá trình dò tìm này, khi gặp một class được đánh dấu @Component thì nó sẽ tạo ra một instance và đưa vào ApplicationContext để quản lý.

#### @Scope("prototype")
Các bean được đánh dấu băng @Component được khởi tạo duy nhất một lần, các lần gọi tới instance dùng duy nhất một instance được khởi tạo đầu tiên. 
@Scope("prototype") được dùng để đánh dấu cùng @component để hiểu là mỗi lần bean sẽ được khởi tảo mới mỗi khi instance được gọi từ context

### @Autowired - @Primary - @Qualifier 

- Annotation @Autowired. Điều này nói với Spring Boot hãy tự inject (tiêm) một instance khác vào thuộc tính của một class sau đó sẽ được khởi tạo được hiểu là bean (class được đánh dấu băngf @component )

```
@Component
public class Girl {

    @Autowired
    Outfit outfit;

    public Girl(Outfit outfit) {
        this.outfit = outfit;
    }
    
    // GET 
    // SET
}
```

## Ngày 10/11/2019
@Autowired 
 1. Nếu Class không có hàm Constructor hay Setter. Thì sẽ sử dụng `Java Reflection` để đưa đối tượng vào thuộc tính có đánh dấu @Autowired.
 2. Nếu có hàm Constructor thì sẽ inject Bean vào bởi tham số của hàm
 3. Nếu có hàm Setter thì sẽ inject Bean vào bởi tham số của hàm
 Sử dụng Java  Reflection: 
 ```
 @Component
public class Girl {
    // Đánh dấu để Spring inject một đối tượng Outfit vào đây
    @Autowired
    Outfit outfit;

    // public Girl(Outfit outfit) {
    //     this.outfit = outfit;
    // }

    // GET
    // SET
}
```
Sử dụng setter: 
```
@Component
public class Girl {

    // Đánh dấu để Spring inject một đối tượng Outfit vào đây
    @Autowired
    Outfit outfit;

    // Spring sẽ inject outfit thông qua Constructor trước
    public Girl() { }


    // Nếu không tìm thấy Constructor thoả mãn, nó sẽ thông qua setter
    public void setOutfit(Outfit outfit) {
        this.outfit = outfit;
    }

    // GET
    // SET
}
```
Sử dụng @Primary để dánh dấu bean sẽ được ưu tiên khi jnject nếu Beans kế thừa từ cùng class trong context.
```
@Component
@Primary
public class Naked implements Outfit {
    @Override
    public void wear() {
        System.out.println("Đang không mặc gì");
    }
}
```

Sử dụng @Qualifier để xác định cụ thể bean được jnject
```
@Component("bikini")
public class Bikini implements Outfit {
    @Override
    public void wear() {
        System.out.println("Mặc bikini");
    }
}

@Component("naked")
public class Naked implements Outfit {
    @Override
    public void wear() {
        System.out.println("Đang không mặc gì");
    }
}

@Component
public class Girl {

    Outfit outfit;

    // Đánh dấu để Spring inject một đối tượng Outfit vào đây
    public Girl(@Qualifier("naked") Outfit outfit) {
        // Spring sẽ inject outfit thông qua Constructor đầu tiên
        // Ngoài ra, nó sẽ tìm Bean có @Qualifier("naked") trong context để ịnject
        this.outfit = outfit;
    }

    // GET
    // SET
}
```
### @PostConstruct và @PreDestroy 
- 2 annotation này nằm trực tiếp trong bea, để thể hiện vòng đời của bean.
ex:
```
import org.springframework.stereotype.Component;
import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

@Component
public class Girl {

    @PostConstruct
    public void postConstruct(){
        System.out.println("\t>> Đối tượng Girl sau khi khởi tạo xong sẽ chạy hàm này");
    }

    @PreDestroy
    public void preDestroy(){
        System.out.println("\t>> Đối tượng Girl trước khi bị destroy thì chạy hàm này");
    }
}
```
### @Component, @Service, @Repository

- 3 Annotation hoạt động đều như @Component nhưng múc đích của chúng là dùng để phân biệt các moudl một cách dõ dàng: 
* @Service gắn cho các Bean đảm nhiệm xử lý logic
* @Repository gắn cho các Bean đảm nhiệm giao tiếp với DB
* @Component gắn cho các Bean khác.

Tôi tạo ra một model Girl.
```
public class Girl {
    private String name;

    public Girl(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Girl(" + this.name + ")";
    }
}
```
Tạo ra một interface GirlRepository để giao tiếp với DB.
```
public interface GirlRepository {
    /**
     * Tìm kiếm một cô gái trong database theo tên
     * @param name
     * @return
     */
    Girl getGirlByName(String name);
}
```
Kế thừa GirlRepository và đánh dấu nó là @Repository
```
@Repository
public class GirlRepositoryImpl implements GirlRepository {

    @Override
    public Girl getGirlByName(String name) {
        // Ở đây tôi ví dụ là database đã trả về
        // một cô gái với tên đúng như tham số

        // Còn thực tế phải query trong csđl nhé.
        return new Girl(name);
    }
}
```
Tạo ra một class GỉrlService để giải quyết các logic nghiệp vụ. Lớp GirlService sẽ giao tiếp với DB thông qua GirlRepository.
```
import org.apache.commons.lang3.RandomStringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class GirlService {
    @Autowired
    private GirlRepository girlRepository;

    public Girl getRandomGirl(){
        // Random 1 cái tên độ dài 10
        String name = randomGirlName(10);

        // Gọi xuông tầng repository để query lấy một cô gái tên là "name" trong database
        return girlRepository.getGirlByName(name);
    }

    public String randomGirlName(int length) {
        // Random một string có độ dài quy định
        // Sử dụng thư viện Apache Common Lang
        return RandomStringUtils.randomAlphanumeric(length).toLowerCase();
    }
}
```

###  @ComponentScan và scanBasePackages

Mặc định Spring sẽ tìm kiếm các bean ở tất các các package cùng cấp với main package trở xuống    
Nếu muốn tùy chỉnh mà bạn muốn tìm các bean thì có 2 cách: 

1. Sử dụng @ComponentScan
2. Sử dụng scanBasePackages tromg @SpringBootApplication.

- Cách 2: scanBasePackages
```
@ComponentScan("me.loda.spring.componentscan.others")
@SpringBootApplication
public class App {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(App.class, args);
        try {
            Girl girl = context.getBean(Girl.class);
            System.out.println("Bean: " + girl.toString());
        } catch (Exception e) {
            System.out.println("Bean Girl không tồn tại");
        }

        try {
            OtherGirl otherGirl = context.getBean(OtherGirl.class);
            if (otherGirl != null) {
                System.out.println("Bean: " + otherGirl.toString());
            }
        } catch (Exception e) {
            System.out.println("Bean Girl không tồn tại");
        }
    }
}
```

- Cách 2: scanBasePackages
```
@SpringBootApplication(scanBasePackages = "me.loda.spring.componentscan.others")
public class App {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(App.class, args);
        try {
            Girl girl = context.getBean(Girl.class);
            System.out.println("Bean: " + girl.toString());
        } catch (Exception e) {
            System.out.println("Bean Girl không tồn tại");
        }

        try {
            OtherGirl otherGirl = context.getBean(OtherGirl.class);
            if (otherGirl != null) {
                System.out.println("Bean: " + otherGirl.toString());
            }
        } catch (Exception e) {
            System.out.println("Bean Girl không tồn tại");
        }
    }
}
```

### Multiple package scan

Bạn có thể cấu hình cho Spring Boot Tìm kiếm các Bean ở nhiều package khác nhau bằng cách:
```
@ComponentScan({"me.loda.spring.componentscan.others2","me.loda.spring.componentscan.others"})
```
hoặc 
```
@SpringBootApplication(scanBasePackages = {"me.loda.spring.componentscan.others", "me.loda.spring.componentscan.others2"})
```

### @Configuration và @Bean 
- Annotation  dùng để đánh dấu các bean đưa vào contex

  * @Configuration là một Annotation đánh dấu trên một Class cho phép Spring Boot biết được đây là nơi định nghĩa ra các Bean.

  * @Bean là một Annotation được đánh dấu trên các method cho phép Spring Boot biết được đây là Bean và sẽ thực hiện đưa Bean này vào Context.
```
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class AppConfig {

    @Bean
    SimpleBean simpleBeanConfigure(){
        // Khởi tạo một instance của SimpleBean và trả ra ngoài
        return new SimpleBean("loda");
    }
}
```
- @Bean có tham số
Nếu method được đánh dấu bởi @Bean có tham số truyền vào, thì Spring Boot sẽ tự inject các Bean đã có trong Context vào làm tham số.

Ví dụ:
```
AppConfig.java

@Configuration
public class AppConfig {

    @Bean
    SimpleBean simpleBeanConfigure(){
        // Khởi tạo một instance của SimpleBean và trả ra ngoài
        return new SimpleBean("loda");
    }

    @Bean("mysqlConnector")
    DatabaseConnector mysqlConfigure(SimpleBean simpleBean) { // SimpleBean được tự động inject vào.
        DatabaseConnector mySqlConnector = new MySqlConnector();
        mySqlConnector.setUrl("jdbc:mysql://host1:33060/" + simpleBean.getUsername());
        // Set username, password, format, v.v...
        return mySqlConnector;
    }
}
```

## 11/11/2019

### ???
- Tại sao khi bỏ     ```<packaging>pom</packaging>``` trong file XML đi và sau đó chạy lệnh `mvn clean install` thì k bị lỗi không load được main class ???
- Tìm hiểu tại câu lệnh: `mvn clean install`











