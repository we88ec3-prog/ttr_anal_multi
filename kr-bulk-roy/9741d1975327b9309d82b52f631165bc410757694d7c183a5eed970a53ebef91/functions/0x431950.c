
void FUN_00431950(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  _Lockit local_18 [4];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090dec8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar3 = FUN_004318d0(&local_14);
  local_8 = 0;
  piVar4 = (int *)FUN_00431790(uVar3,uVar2);
  local_8 = 0xffffffff;
  if (local_14 != 0) {
    std::_Lockit::_Lockit(local_18,0);
    iVar1 = *(int *)(local_14 + 4);
    if ((iVar1 != 0) && (iVar1 != -1)) {
      *(int *)(local_14 + 4) = iVar1 + -1;
    }
    iVar1 = *(int *)(local_14 + 4);
    FUN_0087dd6f();
    puVar5 = (undefined4 *)(~-(uint)(iVar1 != 0) & local_14);
    if (puVar5 != (undefined4 *)0x0) {
      (**(code **)*puVar5)(1);
    }
  }
  (**(code **)(*piVar4 + 0x28))(0x20);
  ExceptionList = local_10;
  return;
}

