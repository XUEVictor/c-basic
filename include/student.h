#include <string>
#include <iostream>

class person
{
private:
    // money 參數不想被外部改到，或者被繼承的改到，可以設成隱私
    //透過方法做存取
    int money;

public:
    int GetMoney() { return this->money; }
    void SetMoney(int money) { this->money = money; }

    std::string name;
    int age;
    bool is_myopia = false;
    person(std::string name, int sex, std::string Security_ID);
    ~person();

protected:
    bool sex;
    std::string Security_ID;
};

person::person(std::string name, int sex, std::string Security_ID)
{
    this->name = name;
    this->sex = sex;
    this->Security_ID = Security_ID;
}

person::~person()
{
}

//公開繼承，延續person所設置的屬性(public 還是 public)
class student : public person
{
private:
    //成績不希望被物件改到(因為怕被改超過100)，因此宣告private，保護參數
    //如果要修改，須透過"方法"取得我資訊，或者給資訊
    u_int8_t score;

public:
    //透過方法
    int Get_score() { return this->score; };
    void Set_score(u_int8_t score) { this->score = score > 100 ? 100 : score; };

    //function定義宣告
    std::string score2GPA();

    // 繼承person後，還是沒有權限存取money，所以只能透過person類別內的function做存取
    int Get_personMoney() { return GetMoney(); }
    void Set_personMoney(int money) { SetMoney(money); }
    int num;
    student(std::string name, std::string Security_ID, int sex, int num);
    ~student();
};
// 建構子(由於有繼承person 因此要在後面打person的建構子)
student::student(std::string name, std::string Security_ID, int sex, int num) : person(name, sex, Security_ID)
{
    // this 作用在於，相同參數名稱時，this所代表的是此物件的參數
    this->name = name;
    this->num = num;
    this->sex = sex;
    this->Security_ID = Security_ID;
}

student::~student()
{
    printf("the student name : %s is been deleted.\n", this->name.c_str());
}