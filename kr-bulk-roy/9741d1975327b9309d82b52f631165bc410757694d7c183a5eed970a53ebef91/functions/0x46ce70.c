
void FUN_0046ce70(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  int *piStack_28;
  int *piStack_24;
  undefined4 uStack_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090dd60;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  iVar8 = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  FUN_0046df80(&local_38,param_1 + 0x520,local_3c);
  local_c = 0;
  if (local_38 != local_34) {
    FUN_0046dff0(local_38,local_34,uVar4);
  }
  piVar7 = (int *)(param_1 + 0xf4);
  do {
    iVar6 = *(int *)(local_38 + iVar8 * 4);
    iVar5 = *(int *)(param_1 + 0x1dc + iVar6 * 0x10);
    iVar1 = *piVar7;
    iVar6 = *(int *)(param_1 + 0x1d8 + iVar6 * 0x10) - *(int *)(iVar1 + 8);
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + iVar6;
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + iVar6;
    iVar5 = iVar5 - *(int *)(iVar1 + 0xc);
    *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + iVar5;
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + iVar5;
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(iVar1 + 0x14);
    if (*(int *)(iVar1 + 0x60) != 0) {
      iVar6 = *(int *)(*(int *)(iVar1 + 0x60) + 0x2c);
      *(int *)(iVar1 + 0x2c) = *(int *)(iVar1 + 0x2c) + iVar6;
      *(int *)(iVar1 + 0x34) = *(int *)(iVar1 + 0x34) + iVar6;
      iVar6 = *(int *)(*(int *)(iVar1 + 0x60) + 0x30);
      *(int *)(iVar1 + 0x30) = *(int *)(iVar1 + 0x30) + iVar6;
      *(int *)(iVar1 + 0x38) = *(int *)(iVar1 + 0x38) + iVar6;
    }
    puVar2 = *(undefined4 **)(iVar1 + 100);
    for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
      FUN_00746f70();
    }
    (**(code **)(*(int *)*piVar7 + 200))();
    iVar8 = iVar8 + 1;
    piVar7 = piVar7 + 1;
  } while (iVar8 < 0xe);
  piStack_28 = (int *)0x0;
  piStack_24 = (int *)0x0;
  uStack_20 = 0;
  FUN_0046df80(&piStack_28,param_1 + 0x5ac,local_3c);
  piVar7 = piStack_28;
  local_c = CONCAT31(local_c._1_3_,1);
  if (piStack_28 != piStack_24) {
    FUN_0046dff0(piStack_28,piStack_24);
  }
  piVar9 = (int *)(param_1 + 0x134);
  local_40 = 0x21;
  do {
    iVar8 = *piVar9;
    iVar6 = *(int *)(param_1 + 0x1dc + *piVar7 * 0x10);
    iVar5 = *(int *)(param_1 + 0x1d8 + *piVar7 * 0x10) - *(int *)(iVar8 + 8);
    *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + iVar5;
    *(int *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x10) + iVar5;
    iVar6 = iVar6 - *(int *)(iVar8 + 0xc);
    *(int *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) + iVar6;
    *(int *)(iVar8 + 0x14) = *(int *)(iVar8 + 0x14) + iVar6;
    *(undefined4 *)(iVar8 + 0x2c) = *(undefined4 *)(iVar8 + 8);
    *(undefined4 *)(iVar8 + 0x30) = *(undefined4 *)(iVar8 + 0xc);
    *(undefined4 *)(iVar8 + 0x34) = *(undefined4 *)(iVar8 + 0x10);
    *(undefined4 *)(iVar8 + 0x38) = *(undefined4 *)(iVar8 + 0x14);
    if (*(int *)(iVar8 + 0x60) != 0) {
      iVar6 = *(int *)(*(int *)(iVar8 + 0x60) + 0x2c);
      *(int *)(iVar8 + 0x2c) = *(int *)(iVar8 + 0x2c) + iVar6;
      *(int *)(iVar8 + 0x34) = *(int *)(iVar8 + 0x34) + iVar6;
      iVar6 = *(int *)(*(int *)(iVar8 + 0x60) + 0x30);
      *(int *)(iVar8 + 0x30) = *(int *)(iVar8 + 0x30) + iVar6;
      *(int *)(iVar8 + 0x38) = *(int *)(iVar8 + 0x38) + iVar6;
    }
    puVar2 = *(undefined4 **)(iVar8 + 100);
    for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
      FUN_00746f70();
    }
    (**(code **)(*(int *)*piVar9 + 200))();
    piVar7 = piVar7 + 1;
    piVar9 = piVar9 + 1;
    local_40 = local_40 + -1;
  } while (local_40 != 0);
  if (piStack_28 != (int *)0x0) {
    FUN_0089120c(piStack_28);
  }
  if (local_38 != 0) {
    FUN_0089120c(local_38);
  }
  ExceptionList = local_14;
  return;
}

