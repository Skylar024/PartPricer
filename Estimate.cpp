#include <iostream>
#include <string>

using namespace std;

//REMOVE ONCE REAL UNIT CLASS IS IN PLACE
class Unit{
    private:
        string material;
        int quantity;
        float cost;
        float total = 0;

    public:
        void setUnit(string material, int quantity, float cost){
          this->material = material;
          this->quantity = quantity;
          this->cost = cost;
        };
        float getTotal(){return cost;};
}; 

class Estimate{
    private:
        Unit units[500];
        int currentIndex = 0;
        float totalEstimate = 0.0;

        void setEstimate(){
            for (Unit u : units){
                if (u.getTotal() != 0){
                    totalEstimate += u.getTotal();
                }
            };
        };

    public:
        void addUnit(string material, int quantity, float cost){
            Unit tempUnit;
            tempUnit.setUnit(material, quantity, cost);
            units[currentIndex++] = tempUnit;
        };
        
        float getEstimate(){
            setEstimate();
            return totalEstimate;
        };
};