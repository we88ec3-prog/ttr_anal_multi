
void FUN_006f8ba0(void)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  int local_8;
  
  if ((in_EAX == 0) || (in_EAX + 0x10 == 0)) {
    local_8 = 0;
    if (unaff_ESI[4] == 0) {
      uVar1 = (*(code *)unaff_ESI[1])(*unaff_ESI,&local_8,4,unaff_ESI[2]);
      unaff_ESI[4] = uVar1;
    }
  }
  else {
    local_8 = *(int *)(in_EAX + 0xc) + 1;
    if (unaff_ESI[4] == 0) {
      uVar1 = (*(code *)unaff_ESI[1])(*unaff_ESI,&local_8,4,unaff_ESI[2]);
      unaff_ESI[4] = uVar1;
      if (unaff_ESI[4] == 0) {
        uVar1 = (*(code *)unaff_ESI[1])(*unaff_ESI,in_EAX + 0x10,local_8,unaff_ESI[2]);
        unaff_ESI[4] = uVar1;
        return;
      }
    }
  }
  return;
}

