import java.io.*;

public class Main{
    /* read a character*/
//    public static void main(String[] args) throws IOException{
//        char c;
//        /*使用System.in创建BufferedReader */
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        System.out.println("输入字符， 按下‘q’键退出");
//
//        do{
//            c = (char) br.read();
//            System.out.println(c);
//        }while(c != 'q');
//    }
    /* read a line*/
//    public static void main(String[] args) throws IOException{
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//
//        String str;
//        System.out.println("Enter lines of text.");
//        System.out.println("Enter 'end' to quit.");
//
//        do{
//            str = br.readLine();
//            System.out.println(str);
//        }while(!str.equals("end"));
//    }
    /* write usage*/
    public static void main(String args[]) throws IOException{
        int b;
        b = 'A';
        System.out.write(b);
        System.out.write('\n');
    }
}