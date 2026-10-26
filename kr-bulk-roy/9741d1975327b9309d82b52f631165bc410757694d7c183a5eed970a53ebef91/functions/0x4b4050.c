
undefined4 FUN_004b4050(uint param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_0040f060();
  iVar1 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  param_1 = (uint)*(ushort *)(param_1 + 2);
  iVar2 = FUN_0040f060();
  FUN_0082ef00(&param_1);
  if (in_ECX == *(int *)(iVar2 + 0xc)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(in_ECX + 0x10);
  }
  if ((iVar1 != 0) && (iVar2 != 0)) {
    FUN_0054d580(&DAT_00fbaaf8);
  }
  iVar1 = FUN_0040f060();
  *(undefined4 *)(iVar1 + 0xac) = 0x40a00000;
  return 0;
}

