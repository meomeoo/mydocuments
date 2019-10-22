class test{
    
public static void main(String[] args){
    StringBuffer buffer = new StringBuffer(15);
    System.out.println(buffer.length());
    System.out.println(buffer.capacity());


    buffer.append("This is ") ;
    buffer.append("String") ;
    buffer.insert(7," a") ;
    buffer.append('.');
    System.out.println(buffer.length());
    // 17
    System.out.println(buffer.capacity());
    // 32
    String output = buffer.toString() ;
    System.out.println(output);
}  

}