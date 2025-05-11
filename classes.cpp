#include <iostream>
#include <string>

using namespace std;

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
        float getTotal(){return (cost * quantity);};
        string getMaterial(){
            return this->material;
        }
        int getQuantity(){
            return this->quantity;
        }
        float getCost(){
            return this->cost;
        }
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
        void addUnit(Unit U){ //Change the parameters to accept a Unit Instance? ------------
                              //Also change the addUnit() to just add the Unit Instance to the Estimate Classes Unit List? --------
            
            units[currentIndex++] = U;
        };
        
        float getEstimate(){
            setEstimate();
            return totalEstimate;
        };

        Unit getUnits(int i){
            return units[i];
        }
};