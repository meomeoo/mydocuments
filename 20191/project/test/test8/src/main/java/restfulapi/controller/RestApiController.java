package restfulapi.controller;

import java.util.List;
import restfulapi.model.UserRepository;
import restfulapi.model.User;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.http.*;


/**
 * Copyright 2019 {@author Loda} (https://loda.me).
 * This project is licensed under the MIT license.
 *
 * @since 5/25/2019
 * Github: https://github.com/loda-kun
 */

/**
 * Lưu ý, @RequestMapping ở class, sẽ tác động tới tất cả các RequestMapping ở
 * bên trong nó.
 *
 * Mọi Request ở trong method sẽ được gắn thêm prefix /api/v1
 */
@RestController
@RequestMapping("/api/v1")
public class RestApiController {

    @Autowired
    private UserRepository userrepository;

    // bạn còn nhớ @PostConstruct dùng để làm gì chứ?
    // nếu không nhớ, hãy coi lại bài viết Spring Boot #3 nhé

    @GetMapping("/user")
    public List<User> getUserList() {
        List<User> user = userrepository.findAll();
        return user;
    }

    /*
     * phần path URL bạn muốn lấy thông tin sẽ để trong ngoặc kép {}
     */
    @GetMapping("/user/{userId}")
    public User getUser(@PathVariable(name = "userId") Integer userId) {
        // @PathVariable lấy ra thông tin trong URL
        // dựa vào tên của thuộc tính đã định nghĩa trong ngoặc kép /todo/{todoId}
        User user = userrepository.findById(userId).get();
        return user;
    }

    /*
     * @RequestBody nói với Spring Boot rằng hãy chuyển Json trong request body
     * thành đối tượng Todo
     */
    @PutMapping("/user/{userId}")
    public User editUser(@PathVariable(name = "userId") Integer userId, @RequestBody User u) {
        userrepository.update(userId, u.getName(), u.getAge(), u.getEmail());
        User user = userrepository.findById(userId).get();
        System.out.println((user.getName()).equals(u.getName()));
        System.out.println(user.getAge()==u.getAge());
        System.out.println((user.getEmail()).equals(u.getEmail()));

        if ((user.getName()).equals(u.getName()) && user.getAge()==u.getAge() && (user.getEmail()).equals(u.getEmail()))
            return user;
        else   
            return u;
        
    }

    @DeleteMapping("/user/{userId}")
    public ResponseEntity deleteUser(@PathVariable(name = "userId") Integer userId) {
        userrepository.deleteById(userId);
        if (userrepository.existsById(userId))
            return ResponseEntity
            .status(HttpStatus.FORBIDDEN)
            .body("Error Message");

        else
            return ResponseEntity.ok().body("dalate success!");
    }

    @PostMapping("/user")
    public ResponseEntity addUser(@RequestBody User user) {
        // Trả về response với STATUS CODE = 200 (OK)
        // Body sẽ chứa thông tin về đối tượng todo vừa được tạo.
        User u = new User();
        u.setName(user.getName());
        u.setAge(user.getAge());
        u.setEmail(user.getEmail()); 
        User u1 = userrepository.save(u);
        if (u1 != null)
            return ResponseEntity.ok().body(u);
        else   
            return ResponseEntity.status(HttpStatus.EXPECTATION_FAILED).body(u);
    }
}
