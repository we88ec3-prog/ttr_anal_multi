
undefined4 * FUN_007a3720(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_EAX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_10 [3];
  
  for (; in_EAX != param_1; in_EAX = in_EAX + 2) {
    uVar4 = 0;
    uVar3 = 0;
    if (local_10 != in_EAX) {
      uVar3 = in_EAX[1];
      in_EAX[1] = 0;
      uVar4 = *in_EAX;
      *in_EAX = 0;
    }
    piVar1 = (int *)param_2[1];
    param_2[1] = uVar3;
    *param_2 = uVar4;
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
    param_2 = param_2 + 2;
  }
  return param_2;
}

