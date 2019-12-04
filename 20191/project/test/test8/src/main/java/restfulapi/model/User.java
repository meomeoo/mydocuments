package restfulapi.model;

import lombok.*;
import javax.persistence.*;

import java.io.Serializable;

@Entity
@Table(name = "users")
@Data 
public class User implements Serializable {
    private static final long serialVersionUID = -297553281792804396L;

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name =  "user_id")
    private Integer id;
    
    @Column(name =  "name")
    private String name;
    
    private int age;

    private String email;
    

}
