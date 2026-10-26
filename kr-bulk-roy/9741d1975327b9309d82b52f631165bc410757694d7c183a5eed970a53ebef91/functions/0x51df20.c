
void FUN_0051df20(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912de0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x1fffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)(in_ECX[2] - *in_ECX >> 3) < param_1) {
    iVar3 = FUN_0071a0c0();
    local_8 = 0;
    FUN_0051df00(param_1);
    iVar1 = *in_ECX;
    iVar2 = in_ECX[1];
    if (iVar1 != 0) {
      FUN_0089120c(iVar1);
    }
    in_ECX[2] = iVar3 + param_1 * 8;
    in_ECX[1] = iVar3 + (iVar2 - iVar1 >> 3) * 8;
    *in_ECX = iVar3;
  }
  ExceptionList = local_10;
  return;
}

