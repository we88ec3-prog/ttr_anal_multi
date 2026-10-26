
void FUN_004fc8b0(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009106a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x4444444 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)((in_ECX[2] - *in_ECX) / 0x3c) < param_1) {
    iVar3 = FUN_00513d80();
    local_8 = 0;
    FUN_004fced0(in_ECX[1],iVar3,param_1);
    iVar1 = *in_ECX;
    iVar2 = in_ECX[1];
    if (iVar1 != 0) {
      FUN_004fcc10(in_ECX[1],param_1);
      FUN_0089120c(*in_ECX);
    }
    in_ECX[2] = iVar3 + param_1 * 0x3c;
    in_ECX[1] = iVar3 + ((iVar2 - iVar1) / 0x3c) * 0x3c;
    *in_ECX = iVar3;
  }
  ExceptionList = local_10;
  return;
}

