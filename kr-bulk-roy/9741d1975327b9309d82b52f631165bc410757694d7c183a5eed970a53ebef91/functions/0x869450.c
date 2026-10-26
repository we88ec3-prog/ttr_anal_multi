
undefined4 FUN_00869450(int param_1)

{
  int *piVar1;
  int in_ECX;
  int unaff_ESI;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EDI;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_c = in_ECX;
  FUN_00784fd0(param_1);
  piVar1 = (int *)(in_ECX + 0x30);
  if (piVar1 != (int *)0x0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),piVar1,4,0);
  }
  local_10 = 0;
  if (0 < *piVar1) {
    local_18 = 0;
    do {
      puVar2 = (undefined4 *)(*(int *)(in_ECX + 0x34) + local_18);
      local_14 = puVar2[4];
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),&local_14,4,0);
      if (0xf < (uint)puVar2[5]) {
        puVar2 = (undefined4 *)*puVar2;
      }
      if ((puVar2 != (undefined4 *)0x0) && (unaff_ESI != 0)) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),puVar2,unaff_ESI,0);
      }
      (**(code **)(*(int *)(unaff_EDI + 0x34 + *(int *)(in_ECX + 0x34)) + 0x10))(param_1);
      iVar3 = unaff_EDI + 0x1c + *(int *)(in_ECX + 0x34);
      if (iVar3 != 0) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar3,4,0);
      }
      iVar3 = *(int *)(in_ECX + 0x34);
      iVar5 = unaff_EDI;
      if (*(int *)(unaff_EDI + 0x1c + iVar3) != 0) {
        iVar4 = *(int *)(iVar3 + 0x1c + unaff_EDI);
        iVar3 = *(int *)(iVar3 + 0x20 + unaff_EDI);
        if ((iVar3 != 0) && (0 < iVar4)) {
          do {
            local_14 = iVar4;
            FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar3,4,0);
            iVar3 = iVar3 + 4;
            iVar4 = local_14 + -1;
          } while (local_14 + -1 != 0);
          local_14 = 0;
          iVar5 = local_18;
        }
        iVar3 = *(int *)(iVar5 + 0x1c + *(int *)(in_ECX + 0x34));
        iVar4 = *(int *)(iVar5 + *(int *)(in_ECX + 0x34) + 0x24);
        if ((iVar4 != 0) && (0 < iVar3)) {
          do {
            local_14 = iVar3;
            FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar4,0xc,0);
            iVar4 = iVar4 + 0xc;
            iVar3 = local_14 + -1;
          } while (local_14 + -1 != 0);
          local_14 = 0;
          iVar5 = local_18;
        }
      }
      iVar3 = iVar5 + 0x28 + *(int *)(in_ECX + 0x34);
      if (iVar3 != 0) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar3,4,0);
      }
      iVar3 = *(int *)(in_ECX + 0x34);
      if (*(int *)(iVar5 + 0x28 + iVar3) != 0) {
        iVar4 = *(int *)(iVar3 + 0x28 + iVar5);
        iVar3 = *(int *)(iVar3 + 0x2c + iVar5);
        if ((iVar3 != 0) && (0 < iVar4)) {
          do {
            local_14 = iVar4;
            FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar3,4,0);
            iVar3 = iVar3 + 4;
            iVar4 = local_14 + -1;
          } while (local_14 + -1 != 0);
          local_14 = 0;
          iVar5 = local_18;
        }
        iVar3 = *(int *)(*(int *)(in_ECX + 0x34) + 0x28 + iVar5);
        iVar4 = *(int *)(*(int *)(in_ECX + 0x34) + 0x30 + iVar5);
        if ((iVar4 != 0) && (0 < iVar3)) {
          do {
            FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar4,0x10,0);
            iVar4 = iVar4 + 0x10;
            iVar3 = iVar3 + -1;
            in_ECX = local_c;
            iVar5 = local_18;
          } while (iVar3 != 0);
        }
      }
      local_10 = local_10 + 1;
      local_18 = iVar5 + 0x58;
    } while (local_10 < *(int *)(in_ECX + 0x30));
  }
  return 1;
}

