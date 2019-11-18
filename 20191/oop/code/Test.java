class Cha {
    static final int TUOI = 23;
    String ten = "khai";

    static int gettuoi() {
        return TUOI;
    }

    void getten() {
        System.out.println(ten);
    }
}

class Con extends Cha {
}

public class Test {
     public static void main(String[] args) {
            Con hue = new Con();
            hue.getten();

         
     
    }
    
}