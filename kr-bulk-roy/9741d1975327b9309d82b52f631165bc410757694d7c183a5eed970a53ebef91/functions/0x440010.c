
void FUN_00440010(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = in_ECX[4];
  if (-iVar2 - 1U <= param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("string too long");
  }
  if (param_1 != 0) {
    uVar1 = iVar2 + param_1;
    if (0x7ffffffe < uVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("string too long");
    }
    if ((uint)in_ECX[5] < uVar1) {
      FUN_00402490(uVar1,iVar2);
      if (uVar1 == 0) {
        return;
      }
    }
    else if (uVar1 == 0) {
      in_ECX[4] = 0;
      if (7 < (uint)in_ECX[5]) {
        *(undefined2 *)*in_ECX = 0;
        return;
      }
      *(undefined2 *)in_ECX = 0;
      return;
    }
    FUN_004022e0(in_ECX[4],param_1,param_2);
    in_ECX[4] = uVar1;
    if (7 < (uint)in_ECX[5]) {
      *(undefined2 *)(*in_ECX + uVar1 * 2) = 0;
      return;
    }
    *(undefined2 *)((int)in_ECX + uVar1 * 2) = 0;
  }
  return;
}

