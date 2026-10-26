
/* WARNING: Removing unreachable block (ram,0x0055292e) */
/* WARNING: Removing unreachable block (ram,0x00552930) */

void FUN_00552880(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090cf52;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = (int *)**(int **)(param_1 + 4);
  if (piVar3 != *(int **)(param_1 + 4)) {
    do {
      iVar1 = piVar3[9];
      local_14 = iVar1;
      if (iVar1 != 0) {
        local_8 = 0;
        FUN_005526a0(iVar1,uVar2);
        local_8 = 1;
        FUN_005540c0(**(undefined4 **)(iVar1 + 4),*(undefined4 **)(iVar1 + 4));
        local_8 = 0xffffffff;
        FUN_0089120c(*(undefined4 *)(iVar1 + 4));
        FUN_0089120c(iVar1);
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*(int *)(param_1 + 4));
  }
  FUN_00552640((int *)(param_1 + 4));
  local_14 = *(int *)(param_1 + 4);
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  FUN_007dcc90(*(int *)(param_1 + 0x10),&local_14);
  *(undefined4 *)(param_1 + 0x20) = 7;
  *(undefined4 *)(param_1 + 0x24) = 8;
  ExceptionList = local_10;
  return;
}

