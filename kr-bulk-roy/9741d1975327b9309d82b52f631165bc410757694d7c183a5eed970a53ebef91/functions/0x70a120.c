
undefined4 FUN_0070a120(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar1 = FUN_006f6210(param_1);
  uVar2 = FUN_006f6210(param_1);
  iVar3 = FUN_0070a0a0(uVar1,uVar2);
  if (iVar3 == 0) {
    return 1;
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  FUN_006f52b0();
  puVar4 = &DAT_00c05a74;
  if (iVar3 != 1) {
    puVar4 = &DAT_00c43a28;
  }
  FUN_006f5510(puVar4);
  return 3;
}

