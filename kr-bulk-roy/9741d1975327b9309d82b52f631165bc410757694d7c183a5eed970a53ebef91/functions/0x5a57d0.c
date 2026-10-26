
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a57d0(void)

{
  int iVar1;
  int unaff_ESI;
  int *unaff_EDI;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093f80e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (unaff_EDI != (int *)0x0) {
    iVar1 = (**(code **)(*unaff_EDI + 4))(DAT_00d61f20 ^ (uint)&pvStack_18);
    if (iVar1 == 0x105c4) goto LAB_005a5825;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_EDI = (int *)0x0;
LAB_005a5825:
  if ((char)unaff_EDI[5] == '\0') {
    (**(code **)(**(int **)(unaff_ESI + 0x14c) + 0xd4))();
    (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x140) + 0x154) + 0xa0))(0);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      puStack_10 = (undefined1 *)0x0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    _DAT_00f942a0 = *(float *)(unaff_ESI + 0x160) * 100.0;
    ExceptionList = pvStack_18;
    return;
  }
  (**(code **)(**(int **)(unaff_ESI + 0x14c) + 0xd0))();
  ExceptionList = local_14;
  return;
}

