
void FUN_00841560(uint param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090e380;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x1a41a41 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)((in_ECX[2] - *in_ECX) / 0x9c) < param_1) {
    iVar2 = FUN_008417c0();
    local_8 = 0;
    FUN_00842af0(in_ECX[1],iVar2,param_1);
    local_8 = 0xffffffff;
    iVar1 = in_ECX[1];
    iVar4 = *in_ECX;
    iVar3 = iVar1 - iVar4;
    if (iVar4 != 0) {
      for (; iVar4 != iVar1; iVar4 = iVar4 + 0x9c) {
        FUN_0085a2f0(iVar4);
      }
      FUN_0089120c(*in_ECX);
    }
    in_ECX[2] = param_1 * 0x9c + iVar2;
    in_ECX[1] = (iVar3 / 0x9c) * 0x9c + iVar2;
    *in_ECX = iVar2;
  }
  ExceptionList = local_10;
  return;
}

