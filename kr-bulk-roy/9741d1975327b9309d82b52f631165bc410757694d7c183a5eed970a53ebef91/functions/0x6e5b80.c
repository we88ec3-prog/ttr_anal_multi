
LRESULT FUN_006e5b80(int param_1,uint param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  HHOOK pHVar3;
  LRESULT LVar4;
  int iVar5;
  
  if ((param_1 < 0) || (param_1 != 0)) {
    if (DAT_00fba7cc == 0) {
      iVar5 = FUN_00891268(0x1380);
      if (iVar5 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar5 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    pHVar3 = *(HHOOK *)(iVar5 + 0x2cc);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    LVar4 = CallNextHookEx(pHVar3,param_1,param_2,(LPARAM)param_3);
    return LVar4;
  }
  if ((0xff < param_2) && (param_2 < 0x102)) {
    uVar2 = FUN_006df6d0();
    cVar1 = FUN_006e0b50(uVar2);
    if ((cVar1 == '\0') && ((*param_3 == 0x5b || (*param_3 == 0x5c)))) {
      return 1;
    }
  }
  iVar5 = 0;
  uVar2 = FUN_006df6d0();
  pHVar3 = (HHOOK)FUN_006e0a90(uVar2);
  LVar4 = CallNextHookEx(pHVar3,iVar5,param_2,(LPARAM)param_3);
  return LVar4;
}

