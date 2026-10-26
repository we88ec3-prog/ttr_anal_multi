
void FUN_0084b700(uint param_1)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00904db0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 < 0x3333334) {
    if ((uint)((in_ECX[2] - *in_ECX) / 0x50) < param_1) {
      iVar1 = FUN_0084b800();
      local_8 = 0;
      FUN_0084bb60(in_ECX[1],param_1);
      iVar3 = *in_ECX;
      iVar2 = in_ECX[1] - iVar3;
      if (iVar3 != 0) {
        for (; iVar3 != in_ECX[1]; iVar3 = iVar3 + 0x50) {
        }
        FUN_0089120c(*in_ECX);
      }
      in_ECX[2] = param_1 * 0x50 + iVar1;
      in_ECX[1] = (iVar2 / 0x50) * 0x50 + iVar1;
      *in_ECX = iVar1;
    }
    ExceptionList = local_10;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("vector<T> too long");
}

