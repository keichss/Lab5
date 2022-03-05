#include <iostream>
#include <memory>

using namespace std;

class Base
{
public:
    Base()
    {
        printf("Base()\n");
    }

    Base(Base* obj)
    {
        printf("Base(Base* obj)\n");
    }
    Base(Base& obj)
    {
        printf("Base(Base& obj)\n");
    }
    virtual ~Base()
    {
        printf("~Base()\n");
    }
    virtual void showName()
    {
        printf("It's Base\n");
    }
    virtual string classname()
    {
        printf("Base:: string classname()\n");
        return "Base";
    }
    virtual bool isA(string s)
    {
        printf("Base:: bool isA(string s)\n");
        return (s == classname());
    }
    void method_1()
    {
        printf("Base:: method_1()\n\n");
    }
    virtual void method_2()
    {
        printf("Base:: method_2()\n");
        method_1();
    }
    virtual void method_3()
    {
        printf("Base:: method_3()\n\n");
    }
    void method_4()
    {
        printf("Base:: method_4()\n");
        method_3();
    }
    void method_5()
    {
        printf("Base:: method_5()\n");
        method_3();
    }
};
class Desc : public Base
{
    int a;
public:
    Desc()
    {
        a = 0;
        printf("Desc() - %d\n", a);
    }
    Desc(int a)
    {
        this->a = a;
        printf("Desc(int a) - %d\n", this->a);
    }
    Desc(Desc* obj)
    {
        a = obj->a;
        printf("Desc(Desc* obj) - %d\n", a);
    }
    Desc(Desc& obj)
    {
        a = obj.a;
        printf("Desc(Desc& obj) - %d\n", a);
    }
    ~Desc()
    {
        printf("~Desc()\n");
    }
    void showName() override
    {
        printf("It's Desc\n");
    }
    string classname() override
    {
        printf("Desc:: string classname()\n");
        return "Desc";
    }
    bool isA(string s) override
    {
        printf("Desc:: bool isA(string s)\n");
        return (s == classname() || Base::isA(s));
    }
    void step()
    {
        a++;
        printf("Desc:: void step() - %d\n", a);
    }
    void method_1()
    {
        printf("Desc:: method_1()\n\n");
    }
    void method_2() override
    {
        printf("Desc:: method_2()\n");
        method_1();
    }

    void method_3() override
    {
        printf("Desc:: method_3()\n\n");
    }
    void method_4()
    {
        printf("Desc:: method_4()\n");
        method_3();
    }

    void showA()
    {
        printf("Desc:: void showA() - %d\n", a);
    }
};

class Masc : public Base
{
    int a;
public:
    Masc()
    {
        a = 0;
        printf("Masc() - %d\n", a);
    }
    Masc(int a)
    {
        this->a = a;
        printf("Masc(int a) - %d\n", this->a);
    }
    Masc(Masc* obj)
    {
        a = obj->a;
        printf("Masc(Masc* obj) - %d\n", a);
    }
    Masc(Masc& obj)
    {
        a = obj.a;
        printf("Desc(Masc& obj) - %d\n", a);
    }
    ~Masc()
    {
        printf("~Masc()\n");
    }
    void showName() override
    {
        printf("It's Masc\n");
    }
    string classname() override
    {
        printf("Masc:: string classname()\n");
        return "Masc";
    }
    bool isA(string s) override
    {
        printf("Masc:: bool isA(string s)\n");
        return (s == classname() || Base::isA(s));
    }
    void steps()
    {
        a += 2;
        printf("Masc:: void step() - %d\n", a);
    }
};

void func_1(Base b)
{
    printf("void func_1(Base b)\n");
    b.showName();
}
void func_2(Base* b)
{
    printf("void func_2(Base* b)\n");
    b->showName();
}
void func_3(Base& b)
{
    printf("void func_3(Base& b)\n");
    b.showName();
}
Base func_11(Base b)
{
    printf("Base func_11(Base b)\n");
    return b;
}
Base* func_22(Base* b)
{
    printf("Base* func_22(Base* b)\n");
    return b;
}

Base& func_33(Base& b)
{
    printf("Base& func_33(Base& b)\n");
    return b;
}

void c()
{
    cout << endl;
}
void cc()
{
    cout << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    printf("Конструкторы Base:\n");
    Base* b1 = new Base();
    Base* b2 = new Base(b1);
    Base* b3 = new Base(*b1);
    b3->showName();
    delete b1;
    delete b2;
    delete b3;

    printf("\n\n\nКонструкторы Desc - потомок Base:\n");
    Desc* d1 = new Desc();
    d1->step();
    Desc* d2 = new Desc(d1);
    Desc* d3 = new Desc(*d1);
    d1->step();
    d2->showA();
    d3->showA();
    d2->showName();
    delete d1;
    delete d2;
    delete d3;

    printf("\n\n\nМетоды:\nBase = new Base:\n");
    Base* a1 = new Base();
    printf("Desc = new Desc:\n");
    Desc* a2 = new Desc();
    printf("Base = new Desc:\n");
    Base* a3 = new Desc();
    printf("\nМетод2 виртуальный, метод1 - невиртуальный(имена одинаковые)(метод2 вызывает метод1):\n");
    a1->method_2();
    a2->method_2();
    a3->method_2();
    printf("\nМетод4 невиртуальный, метод3 - виртуальный(имена одинаковые)(метод4 вызывает метод3):\n");
    a1->method_4();
    a2->method_4();
    a3->method_4();
    printf("\nМетод5 - метод предка, вызывает виртуальный переопределенный метод3:\n");
    a1->method_5();
    a2->method_5();
    a3->method_5();
    printf("\nМетод1 - невиртуальный метод с одинаковыми именами:\n");
    a1->method_1();
    a2->method_1();
    a3->method_1();


    printf("\nПередача в функцию объектов:\n");
    func_1(a1);
    func_1(*a2);
    func_1(*a3);
    func_2(a1);
    func_2(a2);
    func_2(a3);
    func_3(*a1);
    func_3(*a2);
    func_3(*a3);
    printf("\nВозврат объектов из функции:\n");
    Base k1;
    k1 = func_11(a1);
    cc();
    Base* k2 = func_22(a2);
    c();
    Base* k3 = new Base(func_22(a3));
    cc();
    Base k4 = func_33(*a3);
    c();
    Base* k5 = new Base(func_33(*a2));
    cc();
    delete a1;
    delete a2;
    delete a3;
    delete k3;
    delete k5;

    printf("\n\n\nСоздание случайных объектов предка Base:\n");
    Base* b[5];
    for (int i = 0; i < 5; i++)
        if (rand() % 2)
            b[i] = new Desc();
        else b[i] = new Masc();
    printf("Вызов переопределенных методов:\n");
    for (int i1 = 0; i1 < 5; i1++)
        b[i1]->showName();
    //for (int i2 = 0; i2 < 5; i2++)
        //((Desc*)b[i2])->step(); - небезопасное приведение типов
    printf("\n\nПриведение типов вручную и вызов методов:\n");
    for (int i3 = 0; i3 < 5; i3++) //приведение типов вручную с помощью classname
        if (b[i3]->classname() == "Desc")
            ((Desc*)b[i3])->step();
    cout << endl;
    for (int i4 = 0; i4 < 5; i4++) //приведение типов вручную с помощью isA
        if (b[i4]->isA("Masc"))
            ((Masc*)b[i4])->steps();
    printf("\nПриведение типов с помощью dynamic_cast:\n");
    for (int i5 = 0; i5 < 5; i5++)
    {
        Desc* d = dynamic_cast<Desc*>(b[i5]);
        if (d != NULL)
            d->showA();
    }
    printf("\n\nУмные указатели:\n\tunique_ptr\n");
    {
        unique_ptr<Desc> f1(new Desc);
    }
    printf("\n\tshared_ptr:\n");
    {
        shared_ptr<Masc>f2 = make_shared<Masc>();
        shared_ptr<Masc> f3(f2);
    }
    cc();
}