package app.girl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

import app.outfit.Outfit;

@Component
public class Girl {

    @Autowired
    @Qualifier("naked")
    public Outfit outfit;


    // GET
    // SET
}