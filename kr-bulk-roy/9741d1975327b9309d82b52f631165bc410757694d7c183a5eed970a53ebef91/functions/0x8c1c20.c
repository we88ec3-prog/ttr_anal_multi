
undefined4 FUN_008c1c20(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 0x28) == 0) {
    FUN_008c13d0();
  }
  iVar1 = *param_1;
  iVar2 = param_1[1];
  FUN_008c1450();
  *(int *)(param_2 + 0x40) = iVar1 * 4;
  *(int *)(param_2 + 0x44) = iVar2 * 4;
  return 0;
}

