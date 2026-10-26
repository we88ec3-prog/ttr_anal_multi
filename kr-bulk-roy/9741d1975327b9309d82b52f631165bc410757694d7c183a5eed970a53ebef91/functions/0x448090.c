
void FUN_00448090(uint param_1,int *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int *in_EAX;
  int *piVar3;
  int *piVar4;
  
  if (param_2 != (int *)0x0) {
    uVar2 = in_EAX[5];
    piVar3 = in_EAX;
    if (7 < uVar2) {
      piVar3 = (int *)*in_EAX;
    }
    if (piVar3 <= param_2) {
      piVar3 = in_EAX;
      if (7 < uVar2) {
        piVar3 = (int *)*in_EAX;
      }
      if (param_2 < (int *)((int)piVar3 + in_EAX[4] * 2)) {
        if (uVar2 < 8) {
          FUN_004481f0(param_1,in_EAX,(int)param_2 - (int)in_EAX >> 1);
          return;
        }
        FUN_004481f0(param_1,in_EAX,(int)param_2 - *in_EAX >> 1);
        return;
      }
    }
  }
  uVar2 = in_EAX[4];
  if (uVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  if (param_3 < -uVar2 - 1) {
    if (param_3 != 0) {
      uVar1 = uVar2 + param_3;
      if (0x7ffffffe < uVar1) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("string too long");
      }
      if ((uint)in_EAX[5] < uVar1) {
        FUN_00402490(uVar1,uVar2);
        if (uVar1 == 0) {
          return;
        }
      }
      else if (uVar1 == 0) {
        in_EAX[4] = 0;
        if ((uint)in_EAX[5] < 8) {
          *(undefined2 *)in_EAX = 0;
          return;
        }
        *(undefined2 *)*in_EAX = 0;
        return;
      }
      piVar4 = in_EAX;
      piVar3 = in_EAX;
      if (7 < (uint)in_EAX[5]) {
        piVar4 = (int *)*in_EAX;
        piVar3 = (int *)*in_EAX;
      }
      FUN_004027e0((int)piVar4 + (param_1 + param_3) * 2,(int)piVar3 + param_1 * 2,
                   in_EAX[4] - param_1);
      if (7 < (uint)in_EAX[5]) {
        in_EAX = (int *)*in_EAX;
      }
      FID_conflict__memcpy((void *)((int)in_EAX + param_1 * 2),param_2,param_3 * 2);
      FUN_004029e0(uVar1);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("string too long");
}

