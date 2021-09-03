#include<iostream>
using namespace std;
enum VehicleType {
  VT_Twowheeler, VT_ThreeWheeler, VT_FourWheeler
};
class Vehicle {
public:
virtual void printVehicle()=0;
static Vehicle*create(VehicleType type);
};
class Twowheeler:public Vehicle{
  void printVehicle() {
    cout<<" IM TWO WHEELER !!";
  }
};
class Threewheeler:public Vehicle{
  void printVehicle() {
    cout<<"IM THREE WHEELER @@";
  }
};
class Fourwheeler:public Vehicle{
  void printVehicle() {
    cout<<" IM FOUR WHEELER 44444444";
  }
};
Vehicle* Vehicle::create(VehicleType type) {
  if(type==VT_Twowheeler)
  return new Twowheeler();
  else if(type==VT_ThreeWheeler)
  return new Threewheeler();
  else if (type==VT_FourWheeler)
  return new Fourwheeler();
  else return NULL;
}
class Client {
  public:
  Client() {
    VehicleType type=VT_ThreeWheeler;
    pVehicle=Vehicle ::create(type);
  }
~Client(){
  if (pVehicle){
    delete [] pVehicle;
    pVehicle=NULL;
  }
}
Vehicle*getVehicle() {
  return pVehicle;
}
private:
Vehicle *pVehicle;
};
int main () {
  Client*pClient= new Client();
  Vehicle *pVehicle=pClient->getVehicle();
  pVehicle->printVehicle();
return 0;
}