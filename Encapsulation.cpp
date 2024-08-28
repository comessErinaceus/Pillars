#include <string>
#include <iostream>
#include <stdexcept>

#include "Shape.h"

using namespace std;



// asset, the things in an org you are keeping track of
/** Encapsulation - Asset Encapsulates the details of an Asset
 * - Details can only be accessed through getters, and set through set_asset
 * 
 */
class Asset{
public:
    Asset(string i): id(i){}
    
    /**
     *  id = abcdef-1234; type_of_obj-number_aquired
     * type of obj might be: End-user-deviece == code: RG78, or Router == code: ROb
     */

    void set_asset(string id){
        this->id = id;
    }
    string get_asset(){
        return this->id;
    }
    string get_type(){
        size_t pos = this->id.find("-");
        try{
            if(pos != string::npos){
            return this->id.substr(0, pos);
            }
        }

        catch(...){
            std::cout << "Error: No ID" << endl;
            return "";
            
        }
        return "";
        
    }
    string get_asset_number(){
        try{
            size_t pos = this->id.find("-");
            if(pos != string::npos){
                return this->id.substr(pos+1,this->id.size());
            }
        }
        catch(...){
            std::cout << "Error: no asset number" << endl;
            return "";
        }
        return "";
        
    }

private:
    string id{""};
        
};


int main(){
    cout << "Encapsulation" << endl;
    Asset a("CHB4Y-893673");

    cout << "A Asset ID:" << a.get_type() << endl << "A asset Number: " << a.get_asset_number() << endl;

    Circle ci(5);
    ci.display();

    Rectangle r(4,5);
    r.display();
    //Shape s(10); This will throw error because Shape is pure abstract

}
/** Abstraction - encapsulating away the complicated implementation details
 * Shape class implements abstraction, because we don't need to know
 * formulas for shapes, only to call the shape name
 * 
 * i.e Rectangle(l,w);
 */