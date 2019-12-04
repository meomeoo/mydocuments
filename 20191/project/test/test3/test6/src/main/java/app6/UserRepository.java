package app6;


import java.util.List;
import app6.User;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface UserRepository extends JpaRepository<User, Integer> {
    List<User> findAllByAge(int Age);
    List<User> findByEmail(String Email);
} 