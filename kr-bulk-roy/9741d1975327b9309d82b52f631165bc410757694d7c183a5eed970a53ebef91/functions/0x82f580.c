
void FUN_0082f580(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909477;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar3 = (int *)(param_1 + 0x9c);
  local_14 = 0x20;
  do {
    iVar1 = piVar3[-0x20];
    if (iVar1 != 0) {
      FUN_00833050(iVar1);
      FUN_0089120c(iVar1);
      piVar3[-0x20] = 0;
    }
    iVar1 = *piVar3;
    if (iVar1 != 0) {
      FUN_00891d3d(*(undefined4 *)(iVar1 + 0x14),uVar2);
      FUN_0089120c(iVar1);
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  if (*(int *)(param_1 + 300) != 0) {
    FUN_00891d3d(*(int *)(param_1 + 300),uVar2);
    *(undefined4 *)(param_1 + 300) = 0;
  }
  local_8 = 1;
  FUN_008512c0(**(undefined4 **)(param_1 + 0x120),*(undefined4 **)(param_1 + 0x120));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x120));
  ExceptionList = local_10;
  return;
}

