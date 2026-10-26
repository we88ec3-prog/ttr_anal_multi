
void FUN_007d1960(int param_1)

{
  int iVar1;
  int unaff_ESI;
  int *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00937bae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  FUN_0079b520(&DAT_00fb76a8,3);
  iVar1 = 0;
  if (param_1 == 0) {
    if (0 < *(int *)(unaff_ESI + 0xe018)) {
      do {
        (**(code **)(**(int **)(unaff_ESI + 0xc018 + iVar1 * 4) + 0xc))();
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(unaff_ESI + 0xe018));
    }
    *(undefined4 *)(unaff_ESI + 0xe018) = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb7704);
    iVar1 = 0;
    if (0 < *(int *)(unaff_ESI + 0x1001c)) {
      do {
        (**(code **)(**(int **)(unaff_ESI + 0xe01c + iVar1 * 4) + 0xc))();
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(unaff_ESI + 0x1001c));
    }
    *(undefined4 *)(unaff_ESI + 0x1001c) = 0;
    if (0 < *(int *)(unaff_ESI + 0x12020)) {
      iVar1 = 0;
      do {
        (**(code **)(**(int **)(unaff_ESI + 0x10020 + iVar1 * 4) + 0xc))();
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(unaff_ESI + 0x12020));
    }
    *(undefined4 *)(unaff_ESI + 0x12020) = 0;
    if (0 < *(int *)(unaff_ESI + 0x16028)) {
      iVar1 = 0;
      do {
        (**(code **)(**(int **)(unaff_ESI + 0x14028 + iVar1 * 4) + 0xc))();
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(unaff_ESI + 0x16028));
    }
    *(undefined4 *)(unaff_ESI + 0x16028) = 0;
    if (0 < *(int *)(unaff_ESI + 0x1c034)) {
      iVar1 = 0;
      do {
        (**(code **)(**(int **)(unaff_ESI + 0x1a034 + iVar1 * 4) + 0xc))();
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(unaff_ESI + 0x1c034));
    }
    *(undefined4 *)(unaff_ESI + 0x1c034) = 0;
    (**(code **)(*unaff_EDI + 0xc))(1,1,1);
    iVar1 = 0;
    if (0 < *(int *)(unaff_ESI + 0x1e038)) {
      do {
        (**(code **)(**(int **)(unaff_ESI + 0x1c038 + iVar1 * 4) + 0xc))();
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(unaff_ESI + 0x1e038));
    }
    *(undefined4 *)(unaff_ESI + 0x1e038) = 0;
    (**(code **)(*unaff_EDI + 0xc))(1,1,1);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb7704);
    iVar1 = 0;
    if (0 < *(int *)(unaff_ESI + 0x24044)) {
      do {
        (**(code **)(**(int **)(unaff_ESI + 0x22044 + iVar1 * 4) + 0xc))();
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(unaff_ESI + 0x24044));
    }
    *(undefined4 *)(unaff_ESI + 0x24044) = 0;
    (**(code **)(*unaff_EDI + 0xc))(1,1,1);
    iVar1 = 0;
    if (0 < *(int *)(unaff_ESI + 0x22040)) {
      do {
        (**(code **)(**(int **)(unaff_ESI + 0x20040 + iVar1 * 4) + 0xc))();
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(unaff_ESI + 0x22040));
    }
    *(undefined4 *)(unaff_ESI + 0x22040) = 0;
    (**(code **)(*unaff_EDI + 0xc))(1,1,1);
    ExceptionList = local_10;
    return;
  }
  if (0 < *(int *)(unaff_ESI + 0xe018)) {
    do {
      (**(code **)(**(int **)(unaff_ESI + 0xc018 + iVar1 * 4) + 0xc))();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(unaff_ESI + 0xe018));
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb7704);
  iVar1 = 0;
  if (0 < *(int *)(unaff_ESI + 0x1001c)) {
    do {
      (**(code **)(**(int **)(unaff_ESI + 0xe01c + iVar1 * 4) + 0xc))();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(unaff_ESI + 0x1001c));
  }
  iVar1 = 0;
  if (0 < *(int *)(unaff_ESI + 0x12020)) {
    do {
      (**(code **)(**(int **)(unaff_ESI + 0x10020 + iVar1 * 4) + 0xc))();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(unaff_ESI + 0x12020));
  }
  iVar1 = 0;
  if (0 < *(int *)(unaff_ESI + 0x16028)) {
    do {
      (**(code **)(**(int **)(unaff_ESI + 0x14028 + iVar1 * 4) + 0xc))();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(unaff_ESI + 0x16028));
  }
  (**(code **)(*unaff_EDI + 0xc))(1,1,1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb7704);
  ExceptionList = local_10;
  return;
}

