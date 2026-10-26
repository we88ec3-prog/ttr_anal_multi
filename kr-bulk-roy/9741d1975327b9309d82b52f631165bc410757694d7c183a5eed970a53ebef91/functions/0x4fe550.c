
undefined4 FUN_004fe550(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined *puVar3;
  
  iVar1 = FUN_00404ba0();
  if (*(int *)(param_1 + 2) == *(int *)(iVar1 + 0x5f50)) {
    if (*(int *)(in_ECX + 0x5eac) == 1) {
      *(undefined4 *)(in_ECX + 0x5eac) = 4;
      uVar2 = *(undefined4 *)(param_1 + 6);
LAB_004fe5af:
      *(undefined4 *)(in_ECX + 0x6238) = uVar2;
      FUN_004054c0();
      FUN_0058aad0(0xf4263);
      return 0;
    }
    puVar3 = &DAT_00c0d95c;
  }
  else {
    iVar1 = FUN_00404ba0();
    if (*(int *)(param_1 + 6) == *(int *)(iVar1 + 0x5f50)) {
      if (*(int *)(in_ECX + 0x5eac) == 2) {
        *(undefined4 *)(in_ECX + 0x5eac) = 4;
        uVar2 = *(undefined4 *)(param_1 + 2);
        goto LAB_004fe5af;
      }
      puVar3 = &DAT_00c0d988;
    }
    else {
      puVar3 = &DAT_00c0d9b4;
    }
  }
  FUN_006edb60(puVar3);
  *(undefined4 *)(in_ECX + 0x5eac) = 3;
  FUN_00414680();
  FUN_004a3de0(0);
  return 0x80004005;
}

