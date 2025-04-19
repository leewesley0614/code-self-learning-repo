import java.io.*;

public class Main {
    public static void main(String[] args) {
        // 使用构造器创建两个对象
        Employee empOne = new Employee("RUNOOB1");
        Employee empTwo = new Employee("RUNOOB2");

        // 调用这两个对象的成员方法
        empOne.SetAge(26);
        empOne.SetDesignation("高级程序员");
        empOne.SetSalary(1000);
        empOne.PrintEmployee();

        empTwo.SetAge(21);
        empTwo.SetDesignation("菜鸟程序员");
        empTwo.SetSalary(500);
        empTwo.PrintEmployee();
    }
}