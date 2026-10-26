
void FUN_007a3650(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *in_EAX;
  int iVar5;
  
  do {
    if (param_1 == param_2) {
      return;
    }
    iVar1 = param_1[1];
    uVar2 = *param_1;
    if (iVar1 != 0) {
      iVar3 = *(int *)(iVar1 + 4);
      while (iVar3 != 0) {
        LOCK();
        iVar5 = *(int *)(iVar1 + 4);
        if (iVar3 == iVar5) {
          *(int *)(iVar1 + 4) = iVar3 + 1;
          iVar5 = iVar3;
        }
        UNLOCK();
        if (iVar5 == iVar3) {
          FUN_007a31c0(uVar2,iVar1);
          break;
        }
        iVar3 = *(int *)(iVar1 + 4);
      }
    }
    piVar4 = (int *)in_EAX[1];
    in_EAX[1] = 0;
    *in_EAX = 0;
    if (piVar4 != (int *)0x0) {
      LOCK();
      iVar1 = piVar4[1] + -1;
      piVar4[1] = iVar1;
      UNLOCK();
      if (iVar1 == 0) {
        (**(code **)*piVar4)();
        LOCK();
        iVar1 = piVar4[2] + -1;
        piVar4[2] = iVar1;
        UNLOCK();
        if (iVar1 == 0) {
          (**(code **)(*piVar4 + 4))();
        }
      }
    }
    param_1 = param_1 + 2;
    in_EAX = in_EAX + 2;
  } while( true );
}

