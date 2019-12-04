import java.util.ArrayList;
import java.util.List;

  
class Test 
{ 
    private static java.util.List<Integer> list =new ArrayList<>();

    void khoiTao(List<Integer> list){
        list.add(1);
        for(int i=0;i<5;i++){
            list.add(5);
        }
        list.add(1);
        for(int i=0;i<5;i++){
            list.add(5);
        }
    }

    void in1(List<Integer> list){
        for(int i =0; i<11 ;++i){
            System.out.println(list.get(i));
        }
    }
    void in2(){
        for(int i =0; i<11 ;++i){
            System.out.println(list.get(i));
        }
    }

    public static void main(String args[]) 
    { 
        Test test = new Test();
        test.khoiTao(list);
        test.in1(list);
        test.in2();
        
    } 
} 