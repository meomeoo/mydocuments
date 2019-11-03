class MyClass{
    int i;
    
}

public class TestEquals{
    public static void main(String[] args){
        MyClass v1 = new MyClass();
        MyClass v2 = new MyClass();
        v1.i = v2.i = 100;
        System.out.println(v1.equals(v2));
        System.out.println(v1 == v2);
    }
}