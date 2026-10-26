
void FUN_006dfa50(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  HWND pHVar4;
  int *piVar5;
  tagRECT *ptVar6;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_006dfbe0();
  cVar1 = FUN_006ea3d0();
  if ((cVar1 == '\0') && (iVar2 != 0)) {
    if (DAT_00fba7cc == 0) {
      iVar3 = FUN_00891268(0x1380);
      if (iVar3 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    cVar1 = FUN_006df560(DAT_00fba7cc);
    if (cVar1 == '\0') {
      SetCursor((HCURSOR)0x0);
      piVar5 = (int *)FUN_006dfbe0();
    }
    else {
      SetCursor((HCURSOR)0x0);
      iVar3 = -0xc;
      pHVar4 = (HWND)FUN_006dfe70();
      GetClassLongW(pHVar4,iVar3);
      FUN_006df700(iVar2);
      piVar5 = (int *)FUN_006dfbe0();
    }
    (**(code **)(*piVar5 + 0x30))(piVar5,cVar1 != '\0');
  }
  cVar1 = FUN_006ea3d0();
  if (cVar1 == '\0') {
    if (DAT_00fba7cc == 0) {
      iVar2 = FUN_00891268(0x1380);
      if (iVar2 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar2 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    cVar1 = *(char *)(iVar2 + 0x2ff);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (cVar1 != '\0') {
      ptVar6 = &local_18;
      pHVar4 = (HWND)FUN_006dfe70();
      GetWindowRect(pHVar4,ptVar6);
      ptVar6 = &local_18;
      goto LAB_006dfb64;
    }
  }
  ptVar6 = (RECT *)0x0;
LAB_006dfb64:
  ClipCursor(ptVar6);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

