
undefined4 FUN_005007d0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined2 extraout_var;
  undefined2 uVar5;
  undefined4 in_ECX;
  uint uVar6;
  undefined4 in_EDX;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int local_28;
  int local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00906a08;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  uVar8 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_c = 0;
  FUN_00500950(in_EDX,in_ECX,&local_28);
  uVar9 = local_24 - local_28 >> 2;
  if (uVar9 != 0) {
    do {
      iVar2 = *(int *)(local_28 + uVar8 * 4);
      uVar6 = 0;
      uVar4 = *(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0x10) >> 2;
      if (uVar4 != 0) {
        piVar7 = *(int **)(iVar2 + 0x10);
        do {
          if (*piVar7 == param_1) {
            uVar1 = **(undefined2 **)(local_28 + uVar8 * 4);
            uVar5 = 0;
            if (local_28 != 0) {
              FUN_0089120c(local_28,uVar3);
              uVar5 = extraout_var;
            }
            ExceptionList = local_14;
            return CONCAT22(uVar5,uVar1);
          }
          uVar6 = uVar6 + 1;
          piVar7 = piVar7 + 1;
        } while (uVar6 < uVar4);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar9);
  }
  if (local_28 != 0) {
    FUN_0089120c(local_28,uVar3);
  }
  ExceptionList = local_14;
  return 0;
}

