package app.bean;

import org.springframework.stereotype.Component;

import app.outfit.Outfit;

@Component("bikini")
class Bikini implements Outfit {
    @Override
    public void wear() {
        System.out.println("Mặc bikini");
    }
}

@Component("naked")
class Naked implements Outfit {
    @Override
    public void wear() {
        System.out.println("Đang không mặc gì");
    }
}