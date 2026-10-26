
void FUN_0044c260(void)

{
  code *pcVar1;
  int iVar2;
  int *unaff_ESI;
  undefined1 auStack_18 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093f80e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)auStack_18);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  switch(DAT_00f9392c) {
  case 1:
    *(undefined1 *)(unaff_ESI + 0x50) = 1;
    break;
  default:
    goto switchD_0044c2cb_caseD_2;
  case 3:
  case 4:
  case 5:
  case 6:
  case 8:
  case 9:
    *(undefined1 *)(unaff_ESI + 0x50) = 0;
    break;
  case 7:
  case 0x15:
  case 0x17:
  case 0x18:
    iVar2 = FUN_0041a4d0();
    pcVar1 = *(code **)(*unaff_ESI + 0x128);
    if (*(int *)(iVar2 + 0x5ed8) == 0) {
      *(undefined1 *)(unaff_ESI + 0x50) = 2;
      (*pcVar1)();
      ExceptionList = local_14;
      return;
    }
    *(undefined1 *)(unaff_ESI + 0x50) = 0;
    (*pcVar1)();
    ExceptionList = local_14;
    return;
  }
  (**(code **)(*unaff_ESI + 0x128))();
switchD_0044c2cb_caseD_2:
  ExceptionList = local_14;
  return;
}

