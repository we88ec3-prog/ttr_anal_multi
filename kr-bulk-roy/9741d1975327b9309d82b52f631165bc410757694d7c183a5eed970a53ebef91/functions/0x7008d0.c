
undefined4 FUN_007008d0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  puVar2 = *(undefined4 **)(param_1 + 8);
  *puVar2 = *(undefined4 *)(iVar1 + 0x60);
  puVar2[1] = *(undefined4 *)(iVar1 + 100);
  puVar2[2] = *(undefined4 *)(iVar1 + 0x68);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

