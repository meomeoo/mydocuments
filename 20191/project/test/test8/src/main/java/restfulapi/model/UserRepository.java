package restfulapi.model;



import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.transaction.annotation.Transactional;



import restfulapi.model.User;


@Repository
public interface UserRepository extends JpaRepository <User, Integer> {

    

    @Modifying
    @Query(value = "update users set name = :name, age =:age , email = :email  where user_id = :id", nativeQuery = true)
    @Transactional
    void update(@Param("id") Integer id, @Param("name") String name, @Param("age") Integer age, @Param("email") String email);

} 