
void FUN_007fdce0(uint param_1)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905380;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 < 0x5555556) {
    if ((uint)((in_ECX[2] - *in_ECX) / 0x30) < param_1) {
      iVar1 = FUN_00788c60();
      local_8 = 0;
      FUN_007fdde0(in_ECX[1],param_1);
      iVar3 = *in_ECX;
      iVar2 = in_ECX[1] - iVar3;
      if (iVar3 != 0) {
        for (; iVar3 != in_ECX[1]; iVar3 = iVar3 + 0x30) {
        }
        FUN_0089120c(*in_ECX);
      }
      in_ECX[2] = param_1 * 0x30 + iVar1;
      in_ECX[1] = (iVar2 / 0x30) * 0x30 + iVar1;
      *in_ECX = iVar1;
    }
    ExceptionList = local_10;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("vector<T> too long");
}

