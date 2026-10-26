
undefined4 FUN_007064d0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((puVar1 < *(undefined4 **)(param_1 + 8)) && (puVar1 != &DAT_00c0bfc8)) &&
     (0 < (int)puVar1[2])) {
    FUN_006f6210(param_1);
  }
  iVar2 = FUN_006f6e60();
  if (iVar2 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    FUN_006f52b0();
    return 2;
  }
  return 1;
}

