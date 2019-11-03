public class TestWrapperClass{
    public static void main(String[] args){
        Test n = new Test();
        n.a = 12;
        System.out.println(n.a);
        change(n);
        System.out.println(n.a);

    }

    private static void change(Test b){
        b.a = 14;

    }
}

class Test{
    public static int a;
}