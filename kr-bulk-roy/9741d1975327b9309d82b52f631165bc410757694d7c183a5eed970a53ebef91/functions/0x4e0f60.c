
void FUN_004e0f60(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_EAX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *unaff_EDI;
  undefined4 local_c [2];
  
  uVar4 = 0;
  uVar3 = 0;
  if (local_c != in_EAX) {
    uVar3 = in_EAX[1];
    in_EAX[1] = 0;
    uVar4 = *in_EAX;
    *in_EAX = 0;
  }
  piVar1 = (int *)unaff_EDI[1];
  unaff_EDI[1] = uVar3;
  *unaff_EDI = uVar4;
  if (piVar1 != (int *)0x0) {
    LOCK();
    iVar2 = piVar1[1] + -1;
    piVar1[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)*piVar1)();
      LOCK();
      iVar2 = piVar1[2] + -1;
      piVar1[2] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)(*piVar1 + 4))();
      }
    }
  }
  return;
}

