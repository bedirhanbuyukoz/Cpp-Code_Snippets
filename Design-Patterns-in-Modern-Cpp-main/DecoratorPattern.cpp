#include<iostream>
#include<string>

using namespace std ;

//*******************
//beverage class
//*******************


class Beverage {

protected:
       string description ; // alt sýnýflarda tekrar tanýmlamamak için protected 

public :

       Beverage()
       {
             description="Unknown Beverage";
       }


       virtual string getDescription()
       {
             return description ;
       }

       virtual double cost() =0;

};
//*******************
//Esspresso class
//*******************
class Esspresso:public Beverage {

public :

       string getDescription()
       {
             return "Espresso";
       }

       double cost ()
       {
             return 4.5 ;
       }
};


//*******************
//House Blend class
//*******************

class HouseBlend:public Beverage {

public :

       string getDescription()
       {
             return "House Blend";
       }

       double cost ()
       {
             return 6.5 ;
       }
};


//*******************
//decorator class
//*******************
class Decorator:public Beverage {

public :                      // decorator class ekleme yapacaðýmýz nesnelere ulaþmamýzý saðlýyacak ...

       virtual string getDescription()
       {
             return " decorator  ";
       }

};



class Mocha : public Decorator {

       Beverage *beverage ;  //dekorasyonu yapýlacak olan nesne 
       
public :
       Mocha(Beverage * p )
       {
             this->beverage = p ;
       }

       string getDescription()
       {
             return beverage->getDescription() + ", Mocha ";
       }

       double cost ()
       {
              return beverage->cost()+ 0.50 ;
       }
};

//*******************
//Latte class
//*******************
class Latte :public Decorator {

       Beverage *beverage ;

public :
       Latte(Beverage * p )
       {
             this->beverage = p ;
       }

       string getDescription()
       {
             return beverage->getDescription() + " with Milk ";
       }

       double cost ()
       {
             return beverage->cost()+ 0.75 ;
       }
};

//*******************
//Americano class
//*******************
class Americano:public Decorator {

       Beverage *beverage ;

public :
       Americano(Beverage * p )
       {
             this->beverage = p ;
       }

       string getDescription()
       {
             return beverage->getDescription() + ", Roasted seed ";
       }

       double cost ()
       {
             return beverage->cost()+ 0.75 ;
       }
};


//*******************
//main
//*******************
int main ()
{
	
       Beverage * beverage = new Esspresso() ;
       
       cout<<beverage->getDescription()<<beverage->cost()<<" tl "<<endl;

       Beverage *beverage2 = new Esspresso();
      
       beverage2=new Mocha(beverage2);
       beverage2=new Latte(beverage2);
       beverage2=new Americano(beverage2);
       
       
       
       cout<<beverage2->getDescription()<<beverage2->cost()<<" tl "<<endl;
      
       cout<<endl <<"***********************************************"<<endl <<endl;
      
       Beverage * beverage3 = new HouseBlend() ;
       cout<<beverage3->getDescription()<<beverage3->cost()<<" tl "<<endl;
       Beverage *beverage4 = new HouseBlend();
      
       beverage4=new Mocha(beverage4);
       cout<<beverage4->getDescription()<<beverage4->cost()<<" tl "<<endl;
       system("pause " );
       return 0 ;
}

