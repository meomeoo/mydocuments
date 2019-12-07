import java.util.Arrays;

public class test {

    public static void main(String[] args) {

        int a[] = { 1, 2, 3 };
        String b = Arrays.toString(a);
        System.out.println(b);
        char c[] = b.toCharArray();

        int[] d = new int[3];
        int n = 0;

        for (int i = 0; i < c.length; i++) {
            if (c[i] <= '9' && c[i] >= '0') {
                d[n] = c[i] - 48;
                System.out.println(d[n]);
                n++;

            }
        }

    }

}