
void FUN_0049ee10(int *param_1,uint param_2)

{
  int iVar1;
  uint in_EAX;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *unaff_ESI;
  
  if ((uint)param_1[4] < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  uVar2 = param_1[4] - param_2;
  if (uVar2 < in_EAX) {
    in_EAX = uVar2;
  }
  iVar1 = unaff_ESI[4];
  if (-iVar1 - 1U <= in_EAX) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if (in_EAX != 0) {
    uVar2 = iVar1 + in_EAX;
    if (uVar2 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("string too long");
    }
    if ((uint)unaff_ESI[5] < uVar2) {
      FUN_00402dc0(uVar2,iVar1);
      if (uVar2 == 0) {
        return;
      }
    }
    else if (uVar2 == 0) {
      unaff_ESI[4] = 0;
      if ((uint)unaff_ESI[5] < 0x10) {
        *(undefined1 *)unaff_ESI = 0;
        return;
      }
      *(undefined1 *)*unaff_ESI = 0;
      return;
    }
    piVar3 = unaff_ESI;
    piVar4 = unaff_ESI;
    if (0xf < (uint)unaff_ESI[5]) {
      piVar3 = (int *)*unaff_ESI;
      piVar4 = (int *)*unaff_ESI;
    }
    FID_conflict__memcpy((void *)((int)piVar3 + in_EAX),piVar4,unaff_ESI[4]);
    if (unaff_ESI == param_1) {
      if (param_2 != 0) {
        param_2 = param_2 + in_EAX;
      }
      if ((uint)unaff_ESI[5] < 0x10) {
        FID_conflict__memcpy(unaff_ESI,(undefined1 *)((int)unaff_ESI + param_2),in_EAX);
      }
      else {
        FID_conflict__memcpy((void *)*unaff_ESI,(void *)(*unaff_ESI + param_2),in_EAX);
      }
    }
    else {
      if (0xf < (uint)param_1[5]) {
        param_1 = (int *)*param_1;
      }
      piVar4 = unaff_ESI;
      if (0xf < (uint)unaff_ESI[5]) {
        piVar4 = (int *)*unaff_ESI;
      }
      FID_conflict__memcpy(piVar4,(undefined1 *)((int)param_1 + param_2),in_EAX);
    }
    unaff_ESI[4] = uVar2;
    if (0xf < (uint)unaff_ESI[5]) {
      *(undefined1 *)(*unaff_ESI + uVar2) = 0;
      return;
    }
    *(undefined1 *)((int)unaff_ESI + uVar2) = 0;
  }
  return;
}

