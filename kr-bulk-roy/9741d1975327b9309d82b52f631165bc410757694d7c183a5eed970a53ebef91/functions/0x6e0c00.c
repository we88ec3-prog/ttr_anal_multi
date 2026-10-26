
void FUN_006e0c00(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  bool bVar4;
  
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar4 = DAT_00d63d09 != '\0';
  uVar1 = *(undefined4 *)(unaff_EDI + 0x2e8);
  uVar2 = *(undefined4 *)(unaff_EDI + 0x2ec);
  *unaff_ESI = *(undefined4 *)(unaff_EDI + 0x2e4);
  uVar3 = *(undefined4 *)(unaff_EDI + 0x2f0);
  unaff_ESI[1] = uVar1;
  uVar1 = *(undefined4 *)(unaff_EDI + 0x2f4);
  unaff_ESI[2] = uVar2;
  uVar2 = *(undefined4 *)(unaff_EDI + 0x2f8);
  unaff_ESI[3] = uVar3;
  unaff_ESI[4] = uVar1;
  unaff_ESI[5] = uVar2;
  if (bVar4) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return;
}

