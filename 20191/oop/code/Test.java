class Cha{
    public Cha(){
    
    }
    int a =12;


    void prin(){
        StringBuffer buffer = new StringBuffer("khanh");
        buffer.append("This is ") ;
        buffer.append("String") ;
        buffer.insert(7," a") ;
        buffer.append('.');
        System.out.println(buffer.length());
        // 17
        System.out.println(buffer.capacity());
        // 32
        String output = buffer.toString() ;
        System.out.println(output);    }
}

class Con{

    
    void prin(){
        System.out.println("day la lop con");
    }
}

public class Test{
public static void main(String[] args){
    Cha cha2 = new Cha();
    cha2.prin();

}
    
}