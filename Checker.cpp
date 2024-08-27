#include <assert.h>
#include <iostream>
using namespace std;

bool checkRange(float value, float min, float max, const string& message) {
  if (value < min || value > max) {
    cout << message << endl;
    return false;
  }
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool isTemperatureOk = checkRange(temperature, 0, 45, "Temperature out of range!");
  bool isSocOk = checkRange(soc, 20, 80, "State of Charge out of range!");
  bool isChargeRateOk = checkRange(chargeRate, 0, 0.8, "Charge Rate out of range!");

  return isTemperatureOk && isSocOk && isChargeRateOk;
}


int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
  assert(batteryIsOk(-1, 60, 0.3) == false);
  assert(batteryIsOk(35, 82, 0.3) == false);
  assert(batteryIsOk(42, 40, 0.9) == false);
  
}
