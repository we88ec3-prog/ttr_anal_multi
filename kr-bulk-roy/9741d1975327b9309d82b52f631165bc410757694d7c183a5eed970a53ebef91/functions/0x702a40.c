
undefined4 FUN_00702a40(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int local_8;
  
  iVar1 = local_8;
  iVar2 = FUN_006f6210(param_1);
  iVar3 = FUN_006f6370(param_1,2);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1 + local_8;
  }
  puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x20);
  if (((puVar4 < *(undefined4 **)(param_1 + 8)) && (puVar4 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x28))) {
    iVar5 = FUN_006f6370(param_1,3);
    if (-1 < iVar5) goto LAB_00702aa8;
  }
  else {
    iVar5 = -1;
  }
  iVar5 = iVar5 + 1 + local_8;
LAB_00702aa8:
  local_8 = iVar3;
  if (iVar3 < 1) {
    local_8 = 1;
  }
  if (iVar1 < iVar5) {
    iVar5 = iVar1;
  }
  iVar3 = *(int *)(param_1 + 0x10);
  if (local_8 <= iVar5) {
    if (*(uint *)(iVar3 + 0x40) <= *(uint *)(iVar3 + 0x44)) {
      FUN_006fb3a0();
    }
    puVar4 = *(undefined4 **)(param_1 + 8);
    uVar6 = FUN_006fec70(param_1,local_8 + -1 + iVar2,(iVar5 - local_8) + 1);
    *puVar4 = uVar6;
    puVar4[2] = 4;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 1;
  }
  if (*(uint *)(iVar3 + 0x40) <= *(uint *)(iVar3 + 0x44)) {
    FUN_006fb3a0();
  }
  puVar4 = *(undefined4 **)(param_1 + 8);
  uVar6 = FUN_006fec70(param_1,&DAT_00bf2375,0);
  *puVar4 = uVar6;
  puVar4[2] = 4;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

