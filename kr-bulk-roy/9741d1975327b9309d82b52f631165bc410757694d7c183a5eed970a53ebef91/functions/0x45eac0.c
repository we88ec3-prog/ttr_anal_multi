
void FUN_0045eac0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int local_c;
  undefined4 local_8;
  
  piVar2 = DAT_00fba7a4;
  if (DAT_00fba7a4 != (int *)0x0) {
    iVar3 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if (iVar3 != 0) {
      iVar3 = (**(code **)(*piVar2 + 0x20))();
      uVar1 = *(undefined4 *)(iVar3 + 0x9c);
      iVar3 = FUN_0040f060();
      local_8 = uVar1;
      FUN_008438c0(&local_8);
      if (((local_c != *(int *)(iVar3 + 0x1c)) && (*(int *)(local_c + 0x10) != 0)) &&
         (4 < *(byte *)(*(int *)(local_c + 0x10) + 0x20))) {
        FUN_00757040();
        FUN_0045eb40();
      }
    }
  }
  return;
}

