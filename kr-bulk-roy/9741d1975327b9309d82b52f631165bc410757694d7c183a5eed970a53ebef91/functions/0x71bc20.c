
void FUN_0071bc20(void)

{
  int *piVar1;
  int *piVar2;
  int *unaff_ESI;
  
  piVar1 = (int *)((int)unaff_ESI + 0x27U & 0xffffffe0);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = 0;
    piVar1[5] = 0;
  }
  piVar2 = piVar1 + 6;
  piVar1[4] = 0x8000;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    *piVar2 = (int)piVar1;
    piVar1[7] = 0;
    piVar1[8] = 0;
    piVar1[9] = 0;
    piVar1[10] = 0;
    piVar1[0xb] = 0;
    piVar1[0xc] = 0;
    piVar1[0xd] = 0;
    piVar1[0xe] = (int)piVar1;
    piVar1[0xf] = piVar1[4];
    piVar1[0x10] = 0;
  }
  *unaff_ESI = (int)piVar2;
  piVar2[5] = (int)piVar2;
  if (*unaff_ESI != 0) {
    *piVar1 = *unaff_ESI + 0x20;
    return;
  }
  *piVar1 = 0;
  return;
}

