#include <iostream>
#include "student.h"

//類別可以當作function的回傳,用法都與int一樣
student init_stu(std::string name)
{
    student temp = student(name, "R124XXXXXX", true, 1);
    return temp;
}
int main()
{
    student John = student("John_norl", "R124XXXXXX", true, 1);
    printf("Name : %s \nnum : %d \n", John.name.c_str(), John.num);
    John.Set_score(101);
    printf("score : %d \n", John.Get_score());
    //宣告一個指標
    //new 的作用是實體化一個地址
    //作用很像 student *John_ptr = &John
    printf("---------------use pointer---------------------------\n");
    student *John_ptr = new student("John", "R124XXXXXX", true, 1);
    printf("John_ptr 的位址：%p\n", John_ptr);
    //指標呼叫成員都是用箭頭
    printf("Name : %s \nnum : %d \n", John_ptr->name.c_str(), John_ptr->num);
    John_ptr->Set_score(101);
    printf("score : %d \n", John_ptr->Get_score());

    //編譯器只會釋放該指標所指向的記憶體空間，而不會刪除這個指標本身，會變成野指標。
    delete John_ptr;
    // 下面打開註解後，就不會發生同指標指向同一個地方
    John_ptr = nullptr;
    printf("---------------Marry pointer---------------------------\n");

    student *Marry_ptr = new student("Marry", "R124XXXXXX", true, 1);
    printf("Marry_ptr 的位址：%p\n", John_ptr);
    printf("由此可發現，Marry_ptr 與 John_ptr 所指向同一個地方\n");
    if (John_ptr != nullptr)
        John_ptr->name = "John";
    printf("對John_ptr做操作，Marry 也會被改變\n");
    printf("Marry Name : %s \nnum : %d \n", Marry_ptr->name.c_str(), Marry_ptr->num);
    delete Marry_ptr;
    Marry_ptr = nullptr;

    printf("-------------class in funct-------------------------------\n");
    student josh = init_stu("josh");

    //危險的使用方法(沒有delete把指向的記憶體空間釋放，就把指標為空，這樣記憶體空間不會被釋放也無法被釋放)
    //在需要一直執行的程式會很危險，因為會到後面沒有空間使用
    student *Hack_ptr = new student("Marry", "R124XXXXXX", true, 1);
    Hack_ptr = nullptr;

    printf("---------------一般創建的物件生命週期結束會進行解構---------------------------\n");

    return 0;
}