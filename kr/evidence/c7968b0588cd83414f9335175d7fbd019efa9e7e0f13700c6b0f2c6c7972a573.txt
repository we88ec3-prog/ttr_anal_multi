
void FUN_0066f750(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint local_34;
  int local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00933008;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  FUN_0066ff70(&local_28,DAT_00fe1aa0 + 8);
  local_c = 0;
  uVar1 = *(undefined4 *)(DAT_00fe1aa0 + 0x1c);
  iVar6 = local_24 - local_28;
  local_34 = 0;
  iVar5 = local_28 + 0xc;
  piVar7 = (int *)(param_1 + 0x114);
  do {
    if (local_34 < (uint)(iVar6 / 0x28)) {
      *(undefined4 *)(*piVar7 + 0x248) = *(undefined4 *)(iVar5 + -0xc);
      FUN_0066f330(*(undefined4 *)(iVar5 + -8));
      iVar2 = *piVar7;
      FUN_00757710();
      (**(code **)(**(int **)(iVar2 + 0x250) + 200))();
      FUN_0066f3e0(*piVar7,*(undefined4 *)(iVar5 + -4));
      uVar3 = *(uint *)(*piVar7 + 0x28);
      if ((uVar3 & 4) != 0) {
        *(uint *)(*piVar7 + 0x28) = uVar3 ^ 4;
      }
    }
    else {
      *(uint *)(*piVar7 + 0x28) = *(uint *)(*piVar7 + 0x28) | 4;
      FUN_0066f590(uVar4);
    }
    iVar5 = iVar5 + 0x28;
    local_34 = local_34 + 1;
    piVar7 = piVar7 + 1;
  } while (local_34 < 10);
  FUN_007597b0(0);
  FUN_007597b0(1);
  (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
  if (local_28 != 0) {
    FUN_00508b90(uVar1);
    FUN_0089120c(local_28);
  }
  ExceptionList = local_14;
  return;
}

