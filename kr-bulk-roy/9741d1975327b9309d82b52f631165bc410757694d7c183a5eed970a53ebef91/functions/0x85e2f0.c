
void FUN_0085e2f0(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908e00;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0xfffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)(in_ECX[2] - *in_ECX >> 4) < param_1) {
    iVar2 = FUN_008517a0();
    local_8 = 0;
    FUN_0085fc50(in_ECX[1],iVar2,param_1);
    local_8 = 0xffffffff;
    puVar1 = (undefined4 *)in_ECX[1];
    puVar4 = (undefined4 *)*in_ECX;
    uVar3 = (int)puVar1 - (int)puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      for (; puVar4 != puVar1; puVar4 = puVar4 + 4) {
        (**(code **)*puVar4)(0);
      }
      FUN_0089120c(*in_ECX);
    }
    in_ECX[2] = param_1 * 0x10 + iVar2;
    in_ECX[1] = (uVar3 & 0xfffffff0) + iVar2;
    *in_ECX = iVar2;
  }
  ExceptionList = local_10;
  return;
}

