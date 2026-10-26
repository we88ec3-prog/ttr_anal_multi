
void FUN_0084a3a0(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00904dd0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x7ffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)(in_ECX[2] - *in_ECX >> 5) < param_1) {
    iVar3 = FUN_00527d70();
    local_8 = 0;
    FUN_005fef10(in_ECX[1],iVar3);
    iVar1 = *in_ECX;
    iVar2 = in_ECX[1];
    if (iVar1 != 0) {
      FUN_0089120c(iVar1);
    }
    in_ECX[2] = param_1 * 0x20 + iVar3;
    in_ECX[1] = (iVar2 - iVar1 & 0xffffffe0U) + iVar3;
    *in_ECX = iVar3;
  }
  ExceptionList = local_10;
  return;
}

