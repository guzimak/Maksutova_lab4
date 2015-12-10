#include "sdt.h"
#include "binary_and_hex.h"

struct Student
{
    char name[16];
    short YearAdmission;
    short MeanScore;
    uint8_t Gender : 1;
    short Course;
    Student* warden;
};

int main()
{
    //����� 3.2 �������� � ��������� ������ �� 3 ��������
        Student stud[3]=
    {
        {"Polina", 2013, 4, 0, 2, nullptr},
        {"Mark", 2013, 5, 1, 2, &stud[0]},
        {"Serega",2013, 3, 1, 2, &stud[0]}

    };

    //����� 3.3
    //1)����� � ������ �������
    cout <<"Address stud: " <<&stud <<"\nRazmer stud: " <<sizeof(stud)<<endl;

    //2)������ � ������� ��������� �������
    for(int i=0; i<3; ++i)
    {
        cout <<"\nAddress stud["<<i<<"]: " <<&stud[i];
        cout <<"        Size stud["<<i<<"]: " <<sizeof(stud[i]);
    }
    //3) ��� ����� ������ �������� ������� ����������:
    //�����, �������� �� ������ ���������, ������, �������e � ����������������� �������������

    //��� name
    cout <<"\n\nAddress stud[1].name: " <<&stud[1].name;
    cout <<"\nOffset stud[1].name: " <<offsetof(struct Student, name);
    cout <<"\nSize stud[1].name: " <<sizeof(stud[1].name);
    cout <<endl<<"In binary: ";
    print_in_binaryA(&stud[1].name, sizeof(stud[1].name));
    cout <<endl<<"In hex: ";
    print_in_hexA(&stud[1].name, sizeof(stud[1].name));

    //��� YearAdmission
    cout <<"\n\nAddress stud[1].YearAdmission: " <<&stud[1].YearAdmission;
    cout <<"\nOffset stud[1].YearAdmission: " <<offsetof(struct Student, YearAdmission);
    cout <<"\nSize stud[1].YearAdmission: " <<sizeof(stud[1].YearAdmission);
    cout <<endl<<"In binary: ";
    print_in_binaryA(&stud[1].YearAdmission, sizeof(stud[1].YearAdmission));
    cout <<endl<<"In hex: ";
    print_in_hexA(&stud[1].YearAdmission, sizeof(stud[1].YearAdmission));

    //��� MeanScore
    cout <<"\n\nAddress stud[1].MeanScore: " <<&stud[1].MeanScore;
    cout <<"\nOffset stud[1].MeanScore: " <<offsetof(struct Student, MeanScore);
    cout <<"\nSize stud[1].MeanScore: " <<sizeof(stud[1].MeanScore);
    cout <<endl<<"In binary: ";
    print_in_binaryA(&stud[1].MeanScore, sizeof(stud[1].MeanScore));
    cout <<endl<<"In hex: ";
    print_in_hexA(&stud[1].MeanScore, sizeof(stud[1].MeanScore));

    //��� Course
    cout <<"\n\nAddress stud[1].Course: " <<&stud[1].Course;
    cout <<"\nOffset stud[1].Course: " <<offsetof(struct Student, Course);
    cout <<"\nSize stud[1].Course: " <<sizeof(stud[1].Course);
    cout <<endl<<"In binary: ";
    print_in_binaryA(&stud[1].Course, sizeof(stud[1].Course));
    cout <<endl<<"In hex: ";;
    print_in_hexA(&stud[1].Course, sizeof(stud[1].Course));

    //��� warden
    cout <<"\n\nAddress stud[1].warden: " <<stud[1].warden;
    cout <<"\nOffset stud[1].warden: " <<offsetof(struct Student, warden);
    cout <<"\nSize stud[1].warden: " <<sizeof(stud[1].warden);
    cout <<endl<<"In binary: ";
    print_in_binaryA(stud[1].warden, sizeof(stud[1].warden));
    cout <<endl<<"In hex: ";
    print_in_hexA(stud[1].warden, sizeof(stud[1].warden));

    //4) �������� ������� � ����������������� ����
    cout <<endl;
    for(int i=0; i<3; ++i)
    {
        cout <<"\nName                                            YearA MeanS Gend  Cours Warder\n";
        print_in_hexA(&stud[i].name, sizeof(stud[i]));
    };
    return 0;
}
