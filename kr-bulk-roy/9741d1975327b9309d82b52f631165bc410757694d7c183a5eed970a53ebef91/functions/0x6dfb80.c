
undefined4 FUN_006dfb80(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (DAT_00fba7cc == (undefined4 *)0x0) {
    iVar3 = FUN_00891268(0x1380);
    if (iVar3 == 0) {
      DAT_00fba7cc = (undefined4 *)0x0;
    }
    else {
      DAT_00fba7cc = (undefined4 *)FUN_006df3d0();
    }
  }
  puVar2 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  uVar1 = *puVar2;
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return uVar1;
}

