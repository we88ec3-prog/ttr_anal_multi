
void FUN_006f3350(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *unaff_EDI;
  
  if (DAT_00fba80c == 0) {
    iVar1 = FUN_00891268(0x57c);
    if (iVar1 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  puVar2 = (undefined4 *)FUN_006f1c60(0);
  if (puVar2 != (undefined4 *)0x0) {
    if (unaff_EDI != (undefined4 *)0x0) {
      *unaff_EDI = *puVar2;
      unaff_EDI[1] = puVar2[1];
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = puVar2[2];
    }
  }
  if (DAT_00fba80c == 0) {
    iVar1 = FUN_00891268(0x57c);
    if (iVar1 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  iVar1 = FUN_006f1c60(1);
  if ((iVar1 != 0) && (param_1 != (undefined4 *)0x0)) {
    param_1[1] = *(undefined4 *)(iVar1 + 8);
  }
  return;
}

