
uint FUN_006ea3d0(void)

{
  uint uVar1;
  int iVar2;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint uVar3;
  
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  uVar1 = DAT_00fba7cc;
  uVar3 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    uVar3 = extraout_EAX;
  }
  iVar2 = *(int *)(uVar1 + 0xc);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    uVar3 = extraout_EAX_00;
  }
  if (iVar2 == 0) {
    return uVar3 & 0xffffff00;
  }
  return (uint)(*(int *)(iVar2 + 0x30) != 0);
}

