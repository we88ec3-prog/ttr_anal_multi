
undefined4 FUN_00709230(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  FUN_00709060();
  FUN_007091a0(FUN_00707c00);
  if (*(int *)(param_1 + 0x14) == *(int *)(param_1 + 0x28)) {
    FUN_006f8b60(param_1,"no calling environment");
  }
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(**(int **)(*(int *)(param_1 + 0x14) + 4) + 0xc);
  *(undefined4 *)(param_1 + 0x60) = 5;
  iVar4 = **(int **)(*(int *)(param_1 + 0x14) + 4);
  *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 8) + -0x10);
  if (((3 < *(int *)(*(int *)(param_1 + 8) + -8)) &&
      (iVar1 = *(int *)(*(int *)(param_1 + 8) + -0x10), (*(byte *)(iVar1 + 5) & 3) != 0)) &&
     ((*(byte *)(iVar4 + 5) & 4) != 0)) {
    FUN_006fb5a0(iVar1);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  FUN_006f6590(&DAT_00c42880,&PTR_s_close_00c0bac0);
  FUN_007091a0(FUN_00707af0);
  uVar3 = FUN_00894fab("stdin");
  FUN_007090e0(uVar3);
  iVar4 = FUN_00894fab("stdout");
  FUN_007090e0(iVar4 + 0x20);
  iVar4 = FUN_00894fab();
  piVar5 = (int *)FUN_00707a00();
  *piVar5 = iVar4 + 0x40;
  puVar2 = *(undefined4 **)(param_1 + 8);
  *puVar2 = puVar2[-8];
  puVar2[1] = puVar2[-7];
  puVar2[2] = puVar2[-6];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  FUN_006f59b0();
  iVar4 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,"stderr",6);
  local_10 = 4;
  FUN_006fb9a0(param_1,iVar4 + -0x30,local_18,*(int *)(param_1 + 8) + -0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x20;
  iVar4 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,"popen",5);
  local_10 = 4;
  FUN_006fb850(param_1,iVar4 + -0x10,local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  FUN_007091a0(FUN_00707b50);
  FUN_006f59b0();
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  return 1;
}

