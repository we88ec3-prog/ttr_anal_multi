
undefined4 FUN_008c5c10(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  param_2[1] = 0xd;
  *param_2 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar1 + 8),*(undefined1 *)(iVar1 + 9)),
                               *(undefined1 *)(iVar1 + 10)),*(undefined1 *)(iVar1 + 0xb));
  return 0;
}

