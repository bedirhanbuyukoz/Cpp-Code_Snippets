
#include <iostream>
using namespace std;

//interface
class CFlyBehavior
{
public:
	virtual void Fly() = 0;
};



class CQuackBehavior
{
public:
	virtual void Quack() = 0;
};





class CDuck
{
	
public:
	
	CFlyBehavior  *p_fly_behavior;
	CQuackBehavior  *p_quack_behavior;
	
	virtual void Display() = 0;//every ducks is different
	
	
	void Swim()
	{
		printf("All duck able to swiming.\n");
	}
	
	void PerformFly()
	{
		p_fly_behavior->Fly();
	}
	
	
	
	void PerformQuack()
	{
		p_quack_behavior->Quack();
	}
	
	
	
	void SetFlyBehavior(CFlyBehavior  *p_fly_behavior)
	{
		this->p_fly_behavior = p_fly_behavior;
	}
	
	
	void SetQuackBehavior(CQuackBehavior  *p_quack_behavior)
	{
		this->p_quack_behavior = p_quack_behavior;
	}
	// Other methods of ducks...

};


// behavior object
class CFlyWithWings : public CFlyBehavior
{
public:
	 void Fly() override
	{
		printf("nazlii");
	}

};



class CFlyNoWay : public CFlyBehavior
{
public:
	void Fly() override
	{
		printf("I can't flying.\n");
	}

};


class CQuack : public CQuackBehavior
{
public:
	void Quack() override
	{
		printf("Quack quack quack ...\n");
	}

};


class CSQuack : public CQuackBehavior
{
public:
	void Quack() override
	{
		printf("Squack squack squack ...\n");
	}

};

class CMuteQuack : public CQuackBehavior
{
public:
	void Quack() override
	{
		
	}

};

//Duck object
//Green duck
class CMallarDuck : public CDuck
{
public:
	
	CMallarDuck()
	{
		this->p_fly_behavior = new CFlyNoWay();
		this->p_quack_behavior = new CQuack();
	}
	
	
	void Display() override
	{
		printf("I am MallarDuck.\n");
	}
};



//Rubber duck
class CRubberDuck : public CDuck
{
public:
	CRubberDuck()
	{
		this->p_fly_behavior = new CFlyNoWay();
		this->p_quack_behavior = new CSQuack();
	}
	
	void Display() override
	{
		printf("I am RubberrDuck.\n");
	}
	
};

int main()
{
	
	
	CDuck *p_mallar_duck = new CMallarDuck();
	
	CDuck *p_rubber_duck = new CRubberDuck();

	p_mallar_duck->Display();
	
	p_mallar_duck->Swim();
	
	
	p_mallar_duck->PerformFly();
	
	p_mallar_duck->PerformQuack();
	
	
	

	p_rubber_duck->Display();
	
	
	p_rubber_duck->Swim();
	
	
	p_rubber_duck->PerformFly();
	p_rubber_duck->PerformQuack();

	p_rubber_duck->SetFlyBehavior(new CFlyWithWings);
	
	
	p_rubber_duck->PerformFly();

	system("pause");
	return 0;
}

