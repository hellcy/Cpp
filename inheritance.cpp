#include <iostream>
 
using namespace std;

// Base class
class Shape {
   public:
      static int id;
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }
      
   protected:
      int width;
      int height;
};

int Shape::id = 0;

// Derived class
class Rectangle: public Shape {
   public:
      int getArea() { 
         return (width * height); 
      }
};

int main(void) {
   Rectangle Rect;

   Rect.setWidth(5);
   Rect.setHeight(7);

   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   Shape T;
   T.id++;

   Rectangle &test = Rect;

   cout << T.id << endl;

   cout << Rectangle::id << endl;

   cout << Rect.id << endl;

   //cout << Shape.id << endl;

   //cout << test::id << endl;



   return 0;
}