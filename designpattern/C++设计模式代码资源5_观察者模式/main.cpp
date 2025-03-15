#include "concretesubject.h"
#include "concreteobserver.h"

int main(){

    Student *s1 = new Student("Lizheng", "eat KFC", "study");
    Student *s2 = new Student("FooQuinn", "sleep", "dance");

    ConcreteSubject* consub = new ConcreteSubject();

    consub->addObsvr(s1);
    consub->addObsvr(s2);

    string date = "Tuesday";
    consub->notifyObsvr(date);

    date = "Thursday";
    consub->notifyObsvr(date);

    date = "Wednesday";
    consub->notifyObsvr(date);
    
    consub->delObsvr(s1);
    consub->delObsvr(s2);

    return 0;
}