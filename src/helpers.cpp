#include "main.h"

void setCombine(int combinePower) 
{
    combine.move(combinePower);
    combine2.move(combinePower);
}
void setFlap(int flapPower)
{
  flap.move(flapPower);
}


void clampSwitch()
{
 if (clamp1.is_extended())
  {
    clamp1.retract();
  }
 else
  {
    clamp1.extend();
  }
}

void armSwitch()
{
 if (arm.is_extended())
  {
    arm.retract();
  }
 else
  {
    arm.extend();
  }
}