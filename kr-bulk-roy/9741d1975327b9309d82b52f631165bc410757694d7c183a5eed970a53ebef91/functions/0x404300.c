
void FUN_00404300(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *unaff_ESI;
  
  if (param_1 != (int *)0x0) {
    uVar1 = unaff_ESI[5];
    piVar3 = unaff_ESI;
    if (7 < uVar1) {
      piVar3 = (int *)*unaff_ESI;
    }
    if (piVar3 <= param_1) {
      piVar3 = unaff_ESI;
      if (7 < uVar1) {
        piVar3 = (int *)*unaff_ESI;
      }
      if (param_1 < (int *)((int)piVar3 + unaff_ESI[4] * 2)) {
        piVar3 = unaff_ESI;
        if (7 < uVar1) {
          piVar3 = (int *)*unaff_ESI;
        }
        FUN_004041f0(unaff_ESI,(int)param_1 - (int)piVar3 >> 1,param_2);
        return;
      }
    }
  }
  iVar2 = unaff_ESI[4];
  if (-iVar2 - 1U <= param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if (param_2 != 0) {
    uVar1 = iVar2 + param_2;
    if (0x7ffffffe < uVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("string too long");
    }
    if ((uint)unaff_ESI[5] < uVar1) {
      FUN_00402490(uVar1,iVar2);
      if (uVar1 == 0) {
        return;
      }
    }
    else if (uVar1 == 0) {
      unaff_ESI[4] = 0;
      if (7 < (uint)unaff_ESI[5]) {
        *(undefined2 *)*unaff_ESI = 0;
        return;
      }
      *(undefined2 *)unaff_ESI = 0;
      return;
    }
    piVar3 = unaff_ESI;
    if (7 < (uint)unaff_ESI[5]) {
      piVar3 = (int *)*unaff_ESI;
    }
    FID_conflict__memcpy((void *)((int)piVar3 + unaff_ESI[4] * 2),param_1,param_2 * 2);
    unaff_ESI[4] = uVar1;
    if (7 < (uint)unaff_ESI[5]) {
      *(undefined2 *)(*unaff_ESI + uVar1 * 2) = 0;
      return;
    }
    *(undefined2 *)((int)unaff_ESI + uVar1 * 2) = 0;
  }
  return;
}

