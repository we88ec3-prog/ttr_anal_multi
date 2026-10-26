
undefined4 FUN_008077b0(void)

{
  undefined4 *_Dst;
  undefined4 *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *unaff_ESI;
  uint unaff_EDI;
  
  lpCriticalSection = (LPCRITICAL_SECTION)*unaff_ESI;
  EnterCriticalSection(lpCriticalSection);
  if ((-1 < (int)unaff_EDI) && (unaff_EDI <= (uint)unaff_ESI[0x1403])) {
    iVar2 = unaff_ESI[0x1403] - unaff_EDI;
    unaff_ESI[0x1403] = iVar2;
    if (iVar2 == 0) {
      unaff_ESI[0x1401] = unaff_ESI + 1;
    }
    else {
      puVar1 = unaff_ESI + 0x1401;
      _Dst = unaff_ESI + 1;
      puVar3 = (undefined4 *)(unaff_ESI[0x1401] - unaff_EDI);
      if (((_Dst < puVar1) && (_Dst <= puVar3)) && (puVar3 < puVar1)) {
        *puVar1 = puVar3;
        FID_conflict__memcpy
                  (_Dst,(void *)(unaff_EDI + 4 + (int)unaff_ESI),(int)puVar3 + (-4 - (int)unaff_ESI)
                  );
        LeaveCriticalSection(lpCriticalSection);
        return 1;
      }
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}

