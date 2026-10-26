
void FUN_0082fc70(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ccab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = *(int *)(param_1 + 0x9c + param_2 * 4);
  if (iVar1 != 0) {
    FUN_00891d3d(*(undefined4 *)(iVar1 + 0x14),DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    FUN_0089120c(iVar1);
    *(undefined4 *)(param_1 + 0x9c + param_2 * 4) = 0;
  }
  iVar1 = FUN_00891268(0x24);
  local_8 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_00833440(param_1 + 0xc,param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x9c + param_2 * 4) = uVar2;
    ExceptionList = local_10;
    return;
  }
  *(undefined4 *)(param_1 + 0x9c + param_2 * 4) = 0;
  ExceptionList = local_10;
  return;
}

