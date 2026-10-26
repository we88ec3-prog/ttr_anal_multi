
void FUN_004d3750(uint param_1)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00904b40;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0xfffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)(in_ECX[2] - *in_ECX >> 4) < param_1) {
    iVar1 = FUN_008517a0();
    local_8 = 0;
    FUN_007eeed0(*in_ECX,iVar1);
    iVar2 = *in_ECX;
    uVar3 = in_ECX[1] - iVar2;
    if (iVar2 != 0) {
      for (; iVar2 != in_ECX[1]; iVar2 = iVar2 + 0x10) {
      }
      FUN_0089120c(*in_ECX);
    }
    in_ECX[2] = param_1 * 0x10 + iVar1;
    in_ECX[1] = (uVar3 & 0xfffffff0) + iVar1;
    *in_ECX = iVar1;
  }
  ExceptionList = local_10;
  return;
}

