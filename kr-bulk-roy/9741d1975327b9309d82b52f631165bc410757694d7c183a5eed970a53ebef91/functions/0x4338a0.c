
int * FUN_004338a0(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int unaff_EDI;
  _Lockit local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009067c9;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar1 = **(int **)(unaff_EDI + 0x30);
  *param_1 = iVar1;
  std::_Lockit::_Lockit(local_14,0);
  if (*(int *)(iVar1 + 4) != -1) {
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  }
  FUN_0087dd6f(uVar3);
  local_8 = 0;
  FUN_00433950(*(undefined4 *)(unaff_EDI + 0x30),param_2);
  for (puVar2 = *(undefined4 **)(unaff_EDI + 0x2c); puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)*puVar2) {
    (*(code *)puVar2[2])(1);
  }
  ExceptionList = local_10;
  return param_1;
}

