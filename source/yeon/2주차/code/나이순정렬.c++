#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class List{
    public:
        char name[101];
        int age;
        int index;

        bool operator < (List & student){
            if(this->age == student.age)
                return this->index < student.index;
            return this->age < student.age;
        }
};

int main(void){
    int num =0;
    cin >> num;
    List * student = new List[num];
    for (int i = 0; i < num; i++){
        scanf("%d %s",&student[i].age, student[i].name);
        student[i].index = i;
    }

    sort(student, student + num);

    for (int i = 0; i < num; i++){
        printf("%d %s\n", student[i].age, student[i].name);
    }

    return 0;
}