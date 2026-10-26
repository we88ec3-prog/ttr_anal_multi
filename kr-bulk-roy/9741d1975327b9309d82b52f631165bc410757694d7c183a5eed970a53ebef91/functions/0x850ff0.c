
void FUN_00850ff0(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009113a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0xaaaaaaa < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)((in_ECX[2] - *in_ECX) / 0x18) < param_1) {
    iVar3 = FUN_007e0030();
    local_8 = 0;
    FUN_00853d60(in_ECX[1],iVar3,param_1);
    iVar1 = *in_ECX;
    iVar2 = in_ECX[1];
    if (iVar1 != 0) {
      FUN_008510f0(in_ECX[1]);
      FUN_0089120c(*in_ECX);
    }
    in_ECX[2] = iVar3 + param_1 * 0x18;
    in_ECX[1] = iVar3 + ((iVar2 - iVar1) / 0x18) * 0x18;
    *in_ECX = iVar3;
  }
  ExceptionList = local_10;
  return;
}

