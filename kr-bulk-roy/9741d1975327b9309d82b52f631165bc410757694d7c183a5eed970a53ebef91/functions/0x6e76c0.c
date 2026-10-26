
int FUN_006e76c0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined4 uVar6;
  
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
  cVar1 = *(char *)(iVar2 + 0x318);
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
    cVar1 = *(char *)(iVar2 + 0x319);
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
      iVar3 = DAT_00fba7cc;
      bVar5 = DAT_00d63d09 != '\0';
      *(undefined1 *)(iVar2 + 0x319) = 1;
      if (bVar5) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
        iVar3 = DAT_00fba7cc;
      }
      if (iVar3 == 0) {
        iVar2 = FUN_00891268(0x1380);
        if (iVar2 == 0) {
          iVar3 = 0;
          DAT_00fba7cc = iVar3;
        }
        else {
          iVar3 = FUN_006df3d0();
          DAT_00fba7cc = iVar3;
        }
      }
      cVar1 = FUN_006e0e20(iVar3);
      if (cVar1 == '\0') {
        uVar4 = FUN_006df6d0();
        cVar1 = FUN_006e0e60(uVar4);
        if (cVar1 != '\0') {
          uVar4 = FUN_006df6d0();
          iVar2 = FUN_006df5e0(uVar4);
          if (iVar2 != 0) {
            uVar4 = FUN_006df6d0();
            iVar2 = FUN_006df5e0(uVar4);
            if (iVar2 != 0xb) {
              return -0x7fffbffb;
            }
          }
          uVar6 = 1;
          uVar4 = FUN_006df6d0(1);
          FUN_006e0ce0(uVar4,uVar6);
          return -0x7fffbffb;
        }
        iVar2 = FUN_006e2850(0,0,0,0,0);
        if (iVar2 < 0) {
          uVar4 = FUN_006df6d0();
          iVar3 = FUN_006df5e0(uVar4);
          if (iVar3 != 0) {
            uVar4 = FUN_006df6d0();
            iVar3 = FUN_006df5e0(uVar4);
            if (iVar3 != 0xb) {
              return iVar2;
            }
          }
          uVar6 = 1;
          uVar4 = FUN_006df6d0(1);
          FUN_006e0ce0(uVar4,uVar6);
          return iVar2;
        }
      }
      uVar4 = FUN_006df6d0();
      cVar1 = FUN_006e0d20(uVar4);
      if (cVar1 != '\0') {
        uVar4 = FUN_006df6d0();
        cVar1 = FUN_006e0da0(uVar4);
        if (cVar1 != '\0') {
          uVar4 = FUN_006df6d0();
          cVar1 = FUN_006e0e20(uVar4);
          if (cVar1 != '\0') {
            DAT_00d63d84 = 1;
            do {
              iVar2 = FUN_006e7a60();
              if (iVar2 == 0) {
                FUN_006e7ab0();
              }
            } while (DAT_00d63d84 != 0);
            uVar6 = 0;
            uVar4 = FUN_006df6d0(0);
            FUN_006e0ee0(uVar4,uVar6);
            return 0;
          }
        }
      }
      uVar4 = FUN_006df6d0();
      iVar2 = FUN_006df5e0(uVar4);
      if (iVar2 != 0) {
        uVar4 = FUN_006df6d0();
        iVar2 = FUN_006df5e0(uVar4);
        if (iVar2 != 0xb) {
          return -0x7fffbffb;
        }
      }
      uVar6 = 1;
      uVar4 = FUN_006df6d0(1);
      FUN_006e0ce0(uVar4,uVar6);
      return -0x7fffbffb;
    }
  }
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
  iVar2 = *(int *)(iVar2 + 0x30c);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (iVar2 != 0) {
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
    iVar2 = *(int *)(iVar2 + 0x30c);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (iVar2 != 0xb) {
      return -0x7fffbffb;
    }
  }
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
  bVar5 = DAT_00d63d09 != '\0';
  *(undefined4 *)(iVar2 + 0x30c) = 1;
  if (bVar5) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return -0x7fffbffb;
}

