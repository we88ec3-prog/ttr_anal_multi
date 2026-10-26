
/* WARNING: Removing unreachable block (ram,0x005b1a5a) */

void FUN_005b1860(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094947e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005c2b20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_005b1cb0();
  FUN_005a9f40(in_ECX + 0x2fc);
  FUN_005b1d90();
  FUN_005a9f40(in_ECX + 0x300);
  FUN_005b1e70();
  FUN_005a9f40(in_ECX + 0x304);
  FUN_005b1f50();
  FUN_005a9f40(in_ECX + 0x30c);
  FUN_0040b670(in_ECX);
  (**(code **)(**(int **)(in_ECX + 0x2fc) + 0xd0))();
  FUN_00596d70(in_ECX,*(undefined4 *)(in_ECX + 0x300),1,0,0,0,0);
  FUN_00596d70(in_ECX,*(undefined4 *)(in_ECX + 0x30c),1,1,1,0,0);
  FUN_00596d70(in_ECX,*(undefined4 *)(in_ECX + 0x304),0,0,1,0,0);
  local_14 = *(int *)(in_ECX + 0x240);
  iVar1 = *(int *)(in_ECX + 0x304);
  *(int *)(local_14 + 0x70) = iVar1;
  local_18 = *(int *)(iVar1 + 0x74);
  iVar3 = FUN_0074d700(local_18,*(undefined4 *)(local_18 + 4),&local_14);
  if (*(int *)(iVar1 + 0x78) != 0x3ffffffe) {
    *(int *)(iVar1 + 0x78) = *(int *)(iVar1 + 0x78) + 1;
    *(int *)(local_18 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
    local_18 = *(int *)(in_ECX + 0x1c0);
    iVar1 = *(int *)(in_ECX + 0x304);
    *(int *)(local_18 + 0x70) = iVar1;
    iVar3 = *(int *)(iVar1 + 0x74);
    iVar4 = FUN_0074d700(iVar3,*(undefined4 *)(iVar3 + 4),&local_18);
    if (*(int *)(iVar1 + 0x78) != 0x3ffffffe) {
      uVar2 = DAT_00faaf7c & 1;
      *(int *)(iVar1 + 0x78) = *(int *)(iVar1 + 0x78) + 1;
      *(int *)(iVar3 + 4) = iVar4;
      **(int **)(iVar4 + 4) = iVar4;
      if (uVar2 == 0) {
        DAT_00faaf7c = DAT_00faaf7c | 1;
        local_8._0_1_ = 2;
        FUN_0058d410();
        _atexit((_func_4879 *)&LAB_00bccdc0);
        local_8 = CONCAT31(local_8._1_3_,1);
      }
      FUN_0058e1c0(*(undefined4 *)(in_ECX + 0x2fc));
      ExceptionList = local_10;
      return;
    }
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}

