
void FUN_007a0da0(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  undefined4 *in_EAX;
  undefined4 *unaff_EDI;
  
  uVar1 = *in_EAX;
  iVar2 = in_EAX[1];
  if (iVar2 != 0) {
    cVar4 = FUN_0047c250();
    if (cVar4 != '\0') {
      FUN_007a31c0(uVar1,iVar2);
    }
  }
  piVar3 = (int *)unaff_EDI[1];
  unaff_EDI[1] = 0;
  *unaff_EDI = 0;
  if (piVar3 != (int *)0x0) {
    LOCK();
    iVar2 = piVar3[1] + -1;
    piVar3[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)*piVar3)();
      LOCK();
      iVar2 = piVar3[2] + -1;
      piVar3[2] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)(*piVar3 + 4))();
      }
    }
  }
  return;
}

