package hello;

import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;

@Data 
@NoArgsConstructor
@AllArgsConstructor
public class HelloMessage {
    private String name;

}