
void FUN_006b3b80(void)

{
  code *pcVar1;
  int iVar2;
  char cVar3;
  int unaff_EBX;
  int unaff_EDI;
  undefined4 uVar4;
  int local_20 [2];
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009425ea;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if ((DAT_00fab228 == 0) || (*(char *)(DAT_00fab228 + 0x28) == '\0')) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  local_20[0] = CONCAT31(local_20[0]._1_3_,cVar3);
  (**(code **)(**(int **)(unaff_EDI + 0x88) + 0x90))(local_20[0]);
  if (cVar3 == '\0') {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      puStack_10 = (undefined1 *)0x2;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    if (DAT_00fb7258 == 0) {
      local_20[0] = 0x15c;
      iVar2 = FUN_00585620();
      FUN_005740f0(local_20);
      if (unaff_EBX == *(int *)(iVar2 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    else {
      iVar2 = FUN_00404ba0();
      iVar2 = FUN_00539aa0(*(undefined4 *)(iVar2 + 0x5f50));
      if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
        local_20[0] = 0x15c;
        iVar2 = FUN_00585620();
        FUN_005740f0(local_20);
        if (unaff_EBX == *(int *)(iVar2 + 4)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
      }
      else {
        uVar4 = 0x2e9;
        FUN_00585620(0x2e9);
        FUN_00585330(uVar4);
      }
    }
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      puStack_10 = (undefined1 *)0x1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    FUN_005740f0(&stack0xffffffdc);
    if (local_20[0] == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0x84) + 200))();
  ExceptionList = pvStack_18;
  return;
}

