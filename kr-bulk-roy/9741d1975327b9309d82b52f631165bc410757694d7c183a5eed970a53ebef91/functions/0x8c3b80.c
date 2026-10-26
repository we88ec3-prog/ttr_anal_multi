
undefined4 FUN_008c3b80(int param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  param_2[1] = 2;
  *param_2 = (uint)CONCAT11(*(undefined1 *)(iVar1 + 4),*(undefined1 *)(iVar1 + 5));
  return 0;
}

