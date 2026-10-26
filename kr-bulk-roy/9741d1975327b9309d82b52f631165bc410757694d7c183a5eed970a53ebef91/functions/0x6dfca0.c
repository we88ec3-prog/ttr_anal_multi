
int FUN_006dfca0(void)

{
  int iVar1;
  
  if (DAT_00fba7cc == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar1 = DAT_00fba7cc;
  if ((DAT_00d63d09 != '\0') &&
     (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8), DAT_00d63d09 != '\0')) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return iVar1 + 0x30;
}

