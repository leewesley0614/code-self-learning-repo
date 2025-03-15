#include "course.h"

int main()
{
    RoomMate *B = new RoomMate("B",
                               "sleeping",
                               "get dressed and run to classroom");
    RoomMate *C = new RoomMate("C",
                               "playing games",
                               "pay the fee and run to classroom");
    RoomMate *D = new RoomMate("D",
                               "shopping with girl friend",
                               "go bact to school and be worrid about gril friend's angry");

    QQGroup* qqgroup = new QQGroup();
    qqgroup->RegisterObser(B);
    qqgroup->RegisterObser(C);
    qqgroup->RegisterObser(D);

    qqgroup->NotifyObser("Not call the roll");
    qqgroup->NotifyObser("Call the roll");

    system("Pause");
    return 0;
}