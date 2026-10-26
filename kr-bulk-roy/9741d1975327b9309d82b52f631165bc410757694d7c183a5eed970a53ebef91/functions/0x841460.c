
void FUN_00841460(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00904f40;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x4ec4ec4 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)((in_ECX[2] - *in_ECX) / 0x34) < param_1) {
    iVar3 = FUN_00510f10();
    local_8 = 0;
    FUN_008429f0(in_ECX[1],iVar3,param_1);
    local_8 = 0xffffffff;
    iVar1 = in_ECX[1];
    iVar2 = *in_ECX;
    if (iVar2 != 0) {
      FUN_00841790();
      FUN_0089120c(*in_ECX);
    }
    in_ECX[2] = param_1 * 0x34 + iVar3;
    in_ECX[1] = ((iVar1 - iVar2) / 0x34) * 0x34 + iVar3;
    *in_ECX = iVar3;
  }
  ExceptionList = local_10;
  return;
}

