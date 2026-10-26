
void FUN_007a1850(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a1d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x1fffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)(in_ECX[2] - *in_ECX >> 3) < param_1) {
    iVar3 = FUN_0071a0c0();
    local_8 = 0;
    FUN_007a3ae0(param_1);
    local_8 = 0xffffffff;
    iVar1 = in_ECX[1];
    iVar2 = *in_ECX;
    if (iVar2 != 0) {
      FUN_007a37a0(iVar1,param_1);
      FUN_0089120c(*in_ECX);
    }
    in_ECX[2] = iVar3 + param_1 * 8;
    in_ECX[1] = iVar3 + (iVar1 - iVar2 >> 3) * 8;
    *in_ECX = iVar3;
  }
  ExceptionList = local_10;
  return;
}

