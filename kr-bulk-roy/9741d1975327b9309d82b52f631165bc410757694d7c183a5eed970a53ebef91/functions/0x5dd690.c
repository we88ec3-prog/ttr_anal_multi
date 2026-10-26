
void FUN_005dd690(void)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  
  switch(in_EAX) {
  case 1:
    uVar1 = 0x34e;
    break;
  case 2:
    uVar1 = 0x34f;
    break;
  case 3:
    uVar1 = 0x350;
    break;
  case 4:
    uVar1 = 0x351;
    break;
  case 5:
    uVar1 = 0x352;
    break;
  case 6:
    uVar1 = 0x353;
    break;
  case 7:
    uVar1 = 0x354;
    break;
  case 8:
    uVar1 = 0x355;
    break;
  default:
    goto switchD_005dd697_default;
  }
  FUN_00585620(uVar1);
  FUN_00585330(uVar1);
  FUN_00757710();
switchD_005dd697_default:
  return;
}

