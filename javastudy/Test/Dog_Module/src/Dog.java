public class Dog {
    String name_;
    String type_;
    int age_;
    double size_;
    public Dog(String name, String type, int age, double size){
        name_ = name;
        type_ = type;
        age_ = age;
        size_ = size;
    }
    public void GetInfo(){
        System.out.println("Name: " + name_ + "; Type: " + type_ + "; Age: " + age_ + "; Size: " + size_);
    }
}
