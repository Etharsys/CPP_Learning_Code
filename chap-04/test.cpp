#include <iostream>

class A
{
    public:
        virtual int  fcn1(int p1, int p2) const { return p1 * p2; }
        virtual void fcn2(const char* str) = 0;
        virtual void fcn3(bool) {}
        const char*  fcn4() { return "artichaut"; }
};

class B : public A
{
    public:
        int fcn1(int p1, int p2) const override { return p1 + p2; }

        void fcn2(const char*) override { std::cout << "yo" << std::endl; }

        void fcn3(bool b) override
        {
            if (b)
            {
                A::fcn3(b);
            }
            std::cout << "yo3" << std::endl;
        }
        
        const char* fcn4() { return "sopalin"; }
};


class SharedStuff 
{
  protected:
    SharedStuff (int value)
      : _value { value }
    { }
  protected: //comme en java, c'est bien de mettre ici private et des getter / setter protected modifiant ce champ ?
    int _value;
};

class MoreStuff : public SharedStuff
{
  public:
    MoreStuff (int value1, int value2)
      : SharedStuff { value1 }
      , _value2     { value2 }
    { }
    void printer () 
    {
      std::cout << _value << ", " << _value2 << std::endl;
    }

  private:
    int  _value2;
};

class Food
{
  public :
    virtual void miam_miam() = 0;
};

class Nutella : public Food
{
  public :
    void miam_miam() override { std::cout << "Nutella !" << std::endl; }
};

int main()
{
    A* a = new B();

    auto b = a->fcn1(1, 3);
    a->fcn2("la la la");
    a->fcn3(false);
    auto e = a->fcn4();

    std::cout << b << ", " << e << std::endl;

    return 0;
}
