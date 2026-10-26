
void FUN_0049ecd0(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int *in_EAX;
  int *piVar3;
  int *piVar4;
  
  if (param_1 != (int *)0x0) {
    uVar1 = in_EAX[5];
    piVar4 = in_EAX;
    if (0xf < uVar1) {
      piVar4 = (int *)*in_EAX;
    }
    if (piVar4 <= param_1) {
      piVar4 = in_EAX;
      if (0xf < uVar1) {
        piVar4 = (int *)*in_EAX;
      }
      if (param_1 < (int *)(in_EAX[4] + (int)piVar4)) {
        if (uVar1 < 0x10) {
          FUN_0049ee10(in_EAX,(int)param_1 - (int)in_EAX);
          return;
        }
        FUN_0049ee10(in_EAX,(int)param_1 - *in_EAX);
        return;
      }
    }
  }
  iVar2 = in_EAX[4];
  if (-iVar2 - 1U <= param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if (param_2 != 0) {
    uVar1 = iVar2 + param_2;
    if (uVar1 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("string too long");
    }
    if ((uint)in_EAX[5] < uVar1) {
      FUN_00402dc0(uVar1,iVar2);
      if (uVar1 == 0) {
        return;
      }
    }
    else if (uVar1 == 0) {
      in_EAX[4] = 0;
      if ((uint)in_EAX[5] < 0x10) {
        *(undefined1 *)in_EAX = 0;
        return;
      }
      *(undefined1 *)*in_EAX = 0;
      return;
    }
    piVar3 = in_EAX;
    piVar4 = in_EAX;
    if (0xf < (uint)in_EAX[5]) {
      piVar3 = (int *)*in_EAX;
      piVar4 = (int *)*in_EAX;
    }
    FID_conflict__memcpy((void *)((int)piVar3 + param_2),piVar4,in_EAX[4]);
    piVar4 = in_EAX;
    if (0xf < (uint)in_EAX[5]) {
      piVar4 = (int *)*in_EAX;
    }
    FID_conflict__memcpy(piVar4,param_1,param_2);
    in_EAX[4] = uVar1;
    if (0xf < (uint)in_EAX[5]) {
      *(undefined1 *)(*in_EAX + uVar1) = 0;
      return;
    }
    *(undefined1 *)((int)in_EAX + uVar1) = 0;
  }
  return;
}

