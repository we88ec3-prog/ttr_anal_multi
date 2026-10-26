
void FUN_004deb10(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00904b20;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x33333333 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)((in_ECX[2] - *in_ECX) / 5) < param_1) {
    iVar3 = FUN_004dec00();
    local_8 = 0;
    FUN_00422900(param_1);
    iVar1 = *in_ECX;
    iVar2 = in_ECX[1];
    if (iVar1 != 0) {
      FUN_0089120c(iVar1);
    }
    in_ECX[2] = iVar3 + param_1 * 5;
    in_ECX[1] = iVar3 + ((iVar2 - iVar1) / 5) * 5;
    *in_ECX = iVar3;
  }
  ExceptionList = local_10;
  return;
}

