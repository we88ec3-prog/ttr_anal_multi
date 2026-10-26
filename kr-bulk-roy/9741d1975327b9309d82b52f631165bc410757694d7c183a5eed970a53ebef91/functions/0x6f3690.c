
void FUN_006f3690(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  if (DAT_00fba80c == (undefined4 *)0x0) {
    iVar2 = FUN_00891268(0x57c);
    if (iVar2 == 0) {
      DAT_00fba80c = (undefined4 *)0x0;
    }
    else {
      DAT_00fba80c = (undefined4 *)FUN_006f1370();
    }
  }
  piVar3 = (int *)FUN_006f1640(DAT_00fba80c);
  if (piVar3 != (int *)0x0) {
    if (DAT_00fba80c == (undefined4 *)0x0) {
      iVar2 = FUN_00891268(0x57c);
      if (iVar2 == 0) {
        DAT_00fba80c = (undefined4 *)0x0;
      }
      else {
        DAT_00fba80c = (undefined4 *)FUN_006f1370();
      }
    }
    puVar1 = DAT_00fba80c;
    (**(code **)(*piVar3 + 0x14))();
    (**(code **)(*piVar3 + 0x10))(*puVar1,puVar1[1]);
  }
  return;
}

