
undefined4 FUN_006dec90(void)

{
  int iVar1;
  int *unaff_EDI;
  
  if (unaff_EDI[0xb] != 0) {
    return 0x80004005;
  }
  iVar1 = FUN_006e01a0();
  if ((iVar1 != 0) && (iVar1 != 1)) {
    FID_conflict__wprintf(&DAT_00c41204,iVar1);
  }
  iVar1 = DAT_00fba7cc;
  if (DAT_00fba7cc != 0) {
    FUN_006e9ae0();
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    FUN_0089120c(iVar1);
    DAT_00fba7cc = 0;
  }
  (**(code **)(*unaff_EDI + 0x24))();
  return 0;
}

