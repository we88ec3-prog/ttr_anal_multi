
undefined4 FUN_008f34a0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_008ec350(param_1);
  if (iVar1 == 0) {
    return 0x99;
  }
  *(undefined4 *)(param_1 + 0x44) = 0x23;
  return 0;
}

