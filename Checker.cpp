#include <iostream>
#include <cassert>

void EarlyWarning(float parameter, float minLimit, float maxLimit) {
    float tolerance = parameter * 0.05;

    if (parameter <= minLimit + tolerance) {
        std::cout << "Warning: Approaching discharge\n";
    } else if (parameter >= maxLimit - tolerance) {
        std::cout << "Warning: Approaching charge-peak\n";
    }
}

bool checkInRange(float parameter, float minLimit, float maxLimit, const std::string& warningMessage) {
    if (parameter < minLimit || parameter > maxLimit) {
        std::cout << warningMessage << " out of range!\n";
        return false;
    }
    EarlyWarning(parameter, minLimit, maxLimit);
    return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool tempOk = checkInRange(temperature, 0, 45, "Temperature");
    bool socOk = checkInRange(soc, 20, 80, "State of Charge");
    bool chargeRateOk = checkInRange(chargeRate, 0, 0.8, "Charge Rate");

    return tempOk && socOk && chargeRateOk;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7) == true);
    assert(batteryIsOk(50, 85, 0) == false);
    return 0;
}
