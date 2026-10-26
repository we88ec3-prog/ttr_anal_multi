
uint FUN_00712740(void)

{
  int iVar1;
  int *in_EAX;
  uint uVar2;
  int unaff_ESI;
  
  if (in_EAX[4] == in_EAX[5]) {
    FUN_007122a0();
  }
  else {
    FUN_007122a0();
    if (*in_EAX == 0xc) {
      if (in_EAX[4] != in_EAX[5]) {
        if (in_EAX[2] < (int)(uint)*(byte *)(unaff_ESI + 0x32)) goto LAB_0071277e;
        FUN_00712510();
      }
    }
    else {
LAB_0071277e:
      FUN_00712630();
    }
  }
  iVar1 = *in_EAX;
  switch(iVar1) {
  case 1:
  case 2:
  case 3:
  case 5:
    if (*(int *)(unaff_ESI + 0x28) < 0x100) {
      if ((iVar1 == 1) || (iVar1 != 5)) {
        uVar2 = FUN_00712090();
      }
      else {
        uVar2 = FUN_00712180(*(undefined8 *)(in_EAX + 2));
      }
      in_EAX[2] = uVar2;
      *in_EAX = 4;
LAB_0071280d:
      return uVar2 | 0x100;
    }
    break;
  case 4:
    uVar2 = in_EAX[2];
    if ((int)uVar2 < 0x100) goto LAB_0071280d;
  }
  FUN_007122a0();
  if (*in_EAX == 0xc) {
    if (in_EAX[4] == in_EAX[5]) {
      return in_EAX[2];
    }
    if ((int)(uint)*(byte *)(unaff_ESI + 0x32) <= in_EAX[2]) {
      FUN_00712510();
      return in_EAX[2];
    }
  }
  FUN_00712630();
  return in_EAX[2];
}

