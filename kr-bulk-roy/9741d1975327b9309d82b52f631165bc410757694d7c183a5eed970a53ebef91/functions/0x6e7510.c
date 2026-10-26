
void FUN_006e7510(void)

{
  char cVar1;
  int iVar2;
  HWND hWnd;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  tagRECT *lpRect;
  undefined1 local_ac [72];
  undefined4 local_64 [4];
  undefined4 local_54;
  undefined4 local_50;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
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
  cVar1 = *(char *)(iVar2 + 0x29c);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
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
    cVar1 = *(char *)(iVar2 + 0x312);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (cVar1 != '\0') {
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
      iVar2 = *(int *)(iVar2 + 0xc);
      if (DAT_00d63d09 != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      if (*(int *)(iVar2 + 0x30) != 0) {
        lpRect = &local_18;
        hWnd = (HWND)FUN_006dfd60();
        GetClientRect(hWnd,lpRect);
        uVar3 = FUN_006df6d0();
        iVar2 = FUN_006e03c0(uVar3);
        if (local_18.right == *(int *)(iVar2 + 0x10)) {
          uVar3 = FUN_006df6d0();
          iVar2 = FUN_006e03c0(uVar3);
          if (local_18.bottom == *(int *)(iVar2 + 0x14)) goto LAB_006e76ae;
        }
        puVar4 = (undefined4 *)FUN_006ea4e0(local_ac);
        puVar5 = local_64;
        for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        local_54 = 0;
        local_50 = 0;
        FUN_006e4f90(local_64,0,0,0,0);
      }
    }
  }
LAB_006e76ae:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

