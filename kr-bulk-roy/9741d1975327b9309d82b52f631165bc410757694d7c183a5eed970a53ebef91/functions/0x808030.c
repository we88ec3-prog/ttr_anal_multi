
void FUN_00808030(int param_1)

{
  int *piVar1;
  uint uVar2;
  uint *in_EAX;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  
  piVar1 = (int *)in_EAX[1];
  piVar6 = (int *)*in_EAX;
  piVar4 = piVar1;
  if (piVar6 != piVar1) {
    do {
      piVar4 = piVar6;
      if (*(int *)(*piVar6 + 0x10) < *(int *)(param_1 + 0x10)) break;
      piVar6 = piVar6 + 1;
      piVar4 = piVar1;
    } while (piVar6 != piVar1);
  }
  if (piVar4 == piVar1) {
    if ((&param_1 < piVar1) && (piVar6 = (int *)*in_EAX, piVar6 <= &param_1)) {
      if (piVar1 == (int *)in_EAX[2]) {
        FUN_00797930();
      }
      if ((undefined4 *)in_EAX[1] != (undefined4 *)0x0) {
        *(undefined4 *)in_EAX[1] = *(undefined4 *)(*in_EAX + ((int)&param_1 - (int)piVar6 >> 2) * 4)
        ;
        in_EAX[1] = in_EAX[1] + 4;
        return;
      }
    }
    else {
      if (piVar1 == (int *)in_EAX[2]) {
        FUN_00797930();
      }
      if ((int *)in_EAX[1] != (int *)0x0) {
        *(int *)in_EAX[1] = param_1;
      }
    }
    in_EAX[1] = in_EAX[1] + 4;
  }
  else {
    uVar2 = *in_EAX;
    if (piVar1 == (int *)in_EAX[2]) {
      uVar3 = (int)((int)piVar1 - uVar2) >> 2;
      if (0x3ffffffe < uVar3) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long");
      }
      uVar3 = uVar3 + 1;
      uVar5 = (int)((int)in_EAX[2] - uVar2) >> 2;
      if (uVar5 < uVar3) {
        if (0x3fffffff - (uVar5 >> 1) < uVar5) {
          uVar5 = 0;
        }
        else {
          uVar5 = uVar5 + (uVar5 >> 1);
        }
        if (uVar5 < uVar3) {
          uVar5 = uVar3;
        }
        FUN_00797980(uVar5);
      }
    }
    if ((int *)in_EAX[1] != (int *)0x0) {
      *(int *)in_EAX[1] = param_1;
    }
    in_EAX[1] = in_EAX[1] + 4;
    uVar3 = in_EAX[1];
    uVar2 = *in_EAX + ((int)((int)piVar4 - uVar2) >> 2) * 4;
    if ((uVar2 != uVar3 - 4) && (uVar3 - 4 != uVar3)) {
      FUN_00474630(uVar2,uVar3);
      return;
    }
  }
  return;
}

