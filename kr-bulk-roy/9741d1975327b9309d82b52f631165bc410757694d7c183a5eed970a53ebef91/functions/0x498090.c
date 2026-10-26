
void FUN_00498090(uint param_1,int *param_2,int *param_3,uint param_4)

{
  int *in_EAX;
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_3 != (int *)0x0) {
    uVar4 = in_EAX[5];
    piVar2 = in_EAX;
    if (7 < uVar4) {
      piVar2 = (int *)*in_EAX;
    }
    if (piVar2 <= param_3) {
      piVar2 = in_EAX;
      if (7 < uVar4) {
        piVar2 = (int *)*in_EAX;
      }
      if (param_3 < (int *)((int)piVar2 + in_EAX[4] * 2)) {
        piVar2 = in_EAX;
        if (7 < uVar4) {
          piVar2 = (int *)*in_EAX;
        }
        FUN_00498360(param_2,in_EAX,(int)param_3 - (int)piVar2 >> 1,param_4);
        return;
      }
    }
  }
  uVar4 = in_EAX[4];
  if (uVar4 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  uVar1 = uVar4 - param_1;
  uVar3 = (uint)param_2;
  if (uVar1 < param_2) {
    uVar3 = uVar1;
  }
  if (uVar4 - uVar3 < -param_4 - 1) {
    if (param_4 < uVar3) {
      piVar2 = in_EAX;
      param_2 = in_EAX;
      if (7 < (uint)in_EAX[5]) {
        param_2 = (int *)*in_EAX;
        piVar2 = (int *)*in_EAX;
      }
      FID_conflict__memcpy
                ((void *)((int)param_2 + (param_1 + param_4) * 2),
                 (void *)((int)piVar2 + (param_1 + uVar3) * 2),(uVar1 - uVar3) * 2);
    }
    if ((param_4 != 0) || (uVar3 != 0)) {
      uVar4 = (in_EAX[4] - uVar3) + param_4;
      if (0x7ffffffe < uVar4) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("string too long");
      }
      if ((uint)in_EAX[5] < uVar4) {
        FUN_00402490(uVar4,in_EAX[4]);
        if (uVar4 == 0) {
          return;
        }
      }
      else if (uVar4 == 0) {
        in_EAX[4] = 0;
        if ((uint)in_EAX[5] < 8) {
          *(undefined2 *)in_EAX = 0;
          return;
        }
        *(undefined2 *)*in_EAX = 0;
        return;
      }
      if (uVar3 < param_4) {
        piVar2 = in_EAX;
        param_2 = in_EAX;
        if (7 < (uint)in_EAX[5]) {
          param_2 = (int *)*in_EAX;
          piVar2 = (int *)*in_EAX;
        }
        FUN_004027e0((int)param_2 + (param_1 + param_4) * 2,(int)piVar2 + (uVar3 + param_1) * 2,
                     uVar1 - uVar3);
      }
      piVar2 = in_EAX;
      if (7 < (uint)in_EAX[5]) {
        piVar2 = (int *)*in_EAX;
      }
      FID_conflict__memcpy((void *)((int)piVar2 + param_1 * 2),param_3,param_4 * 2);
      in_EAX[4] = uVar4;
      if (7 < (uint)in_EAX[5]) {
        *(undefined2 *)(*in_EAX + uVar4 * 2) = 0;
        return;
      }
      *(undefined2 *)((int)in_EAX + uVar4 * 2) = 0;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("string too long");
}

