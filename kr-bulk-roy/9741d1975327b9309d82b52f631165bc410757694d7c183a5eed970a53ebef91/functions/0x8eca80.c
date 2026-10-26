
void FUN_008eca80(void)

{
  int in_EAX;
  undefined1 in_CL;
  
  switch(in_CL) {
  case 0:
    *(code **)(in_EAX + 0x238) = FUN_008ec8f0;
    return;
  case 1:
    *(code **)(in_EAX + 0x238) = FUN_008ec8c0;
    return;
  case 2:
    *(code **)(in_EAX + 0x238) = FUN_008ec990;
    return;
  case 3:
    *(code **)(in_EAX + 0x238) = FUN_008ec930;
    return;
  case 4:
    *(code **)(in_EAX + 0x238) = FUN_008ec960;
    return;
  case 5:
    *(code **)(in_EAX + 0x238) = FUN_008ec890;
    return;
  case 6:
    *(code **)(in_EAX + 0x238) = FUN_008ec9c0;
    return;
  case 7:
    *(code **)(in_EAX + 0x238) = FUN_008eca20;
  }
  return;
}

