
void FUN_00402c80(uint param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  int *piVar4;
  
  if ((uint)in_ECX[4] < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  uVar2 = in_ECX[4] - param_1;
  if (uVar2 < param_2) {
    param_2 = uVar2;
  }
  if (param_2 != 0) {
    piVar4 = in_ECX;
    piVar1 = in_ECX;
    if (0xf < (uint)in_ECX[5]) {
      piVar4 = (int *)*in_ECX;
      piVar1 = (int *)*in_ECX;
    }
    FID_conflict__memcpy
              ((void *)((int)piVar4 + param_1),(void *)((int)piVar1 + param_2 + param_1),
               uVar2 - param_2);
    iVar3 = in_ECX[4] - param_2;
    in_ECX[4] = iVar3;
    if (0xf < (uint)in_ECX[5]) {
      *(undefined1 *)(*in_ECX + iVar3) = 0;
      return;
    }
    *(undefined1 *)((int)in_ECX + iVar3) = 0;
  }
  return;
}

