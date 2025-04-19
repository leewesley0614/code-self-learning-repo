import java.io.*;

public class Employee {
    private String name_;
    private int age_;
    private  String designation_;
    private double salary_;

    public Employee(String name){
        this.name_ = name;
    }

    public void SetAge(int age){
        this.age_ = age;
    }

    public int GetAge(){
        return this.age_;
    }

    public void SetDesignation(String designation){
        this.designation_ = designation;
    }

    public String GetDesignation(){
        return this.designation_;
    }

    public void SetSalary(double salary){
        this.salary_ = salary;
    }

    public double GetSalary(){
        return this.salary_;
    }

    public void PrintEmployee(){
        System.out.println(this);
    }

    @Override
    public String toString(){
        return "名字: " + name_ + "\n" +
                "年龄: " + age_ + "\n" +
                "职位: " + designation_ + "\n" +
                "薪水: " + salary_;
    }
}
