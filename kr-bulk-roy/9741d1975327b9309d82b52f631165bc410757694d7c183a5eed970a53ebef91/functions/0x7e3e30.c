
void FUN_007e3e30(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009148b0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x3c3c3c3 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)((in_ECX[2] - *in_ECX) / 0x44) < param_1) {
    iVar3 = FUN_00788cc0();
    local_8 = 0;
    FUN_007e4170(in_ECX[1],iVar3,param_1);
    iVar1 = in_ECX[1];
    iVar2 = *in_ECX;
    if (iVar2 != 0) {
      FUN_007e40a0(param_1);
      FUN_0089120c(*in_ECX);
    }
    in_ECX[2] = iVar3 + param_1 * 0x44;
    in_ECX[1] = iVar3 + ((iVar1 - iVar2) / 0x44) * 0x44;
    *in_ECX = iVar3;
  }
  ExceptionList = local_10;
  return;
}

