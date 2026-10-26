
int FUN_008520c0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00906ec8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 8) = 0;
  uVar2 = FUN_006db770(uVar1);
  *(undefined4 *)(param_1 + 4) = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x34) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x35) = 1;
  local_8 = 0;
  if (param_1 != unaff_EDI) {
    FUN_00852180(*(undefined4 *)(*(int *)(param_1 + 4) + 4));
    *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
    *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
    *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
    *(undefined4 *)(param_1 + 8) = 0;
    uVar2 = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(unaff_EDI + 4);
    *(undefined4 *)(unaff_EDI + 4) = uVar2;
    uVar2 = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(unaff_EDI + 8);
    *(undefined4 *)(unaff_EDI + 8) = uVar2;
  }
  ExceptionList = local_10;
  return param_1;
}

