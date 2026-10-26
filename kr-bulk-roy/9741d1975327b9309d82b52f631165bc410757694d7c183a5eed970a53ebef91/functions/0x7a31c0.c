
void FUN_007a31c0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  
  piVar1 = (int *)unaff_ESI[1];
  if (piVar1 != (int *)0x0) {
    LOCK();
    iVar2 = piVar1[1] + -1;
    piVar1[1] = iVar2;
    UNLOCK();
    if (iVar2 != 0) {
      unaff_ESI[1] = param_2;
      *unaff_ESI = param_1;
      return;
    }
    (**(code **)*piVar1)();
    LOCK();
    iVar2 = piVar1[2] + -1;
    piVar1[2] = iVar2;
    UNLOCK();
    if (iVar2 != 0) {
      unaff_ESI[1] = param_2;
      *unaff_ESI = param_1;
      return;
    }
    (**(code **)(*piVar1 + 4))();
  }
  unaff_ESI[1] = param_2;
  *unaff_ESI = param_1;
  return;
}

