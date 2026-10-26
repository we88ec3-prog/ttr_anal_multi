
void FUN_0082f0a0(uint param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009094d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x4924924 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)((in_ECX[2] - *in_ECX) / 0x38) < param_1) {
    if (param_1 == 0) {
      local_18 = 0;
    }
    else {
      local_18 = FUN_006db770();
    }
    local_8 = 0;
    FUN_0082f320(in_ECX[1],local_18,param_1);
    iVar1 = *in_ECX;
    iVar2 = in_ECX[1];
    if (iVar1 != 0) {
      FUN_0082f1c0(in_ECX[1]);
      FUN_0089120c(*in_ECX);
    }
    in_ECX[2] = local_18 + param_1 * 0x38;
    in_ECX[1] = local_18 + ((iVar2 - iVar1) / 0x38) * 0x38;
    *in_ECX = local_18;
  }
  ExceptionList = local_10;
  return;
}

