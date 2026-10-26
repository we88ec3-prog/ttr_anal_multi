
undefined4 FUN_0080eb90(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = param_1;
  iVar1 = **(int **)(in_ECX + 0x14);
  uVar2 = FUN_008fed10();
  (**(code **)(iVar1 + 0x20))(uVar2);
  return 0;
}

