
void FUN_006905f0(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  int in_ECX;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 uVar4;
  undefined4 uVar5;
  void *pvStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093ca0a;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  *(undefined4 *)(in_ECX + 0x5a4) = param_1;
  *(undefined1 *)(in_ECX + 0x5a0) = 0;
  (**(code **)(**(int **)(in_ECX + 0x120) + 0x90))(0,uVar3);
  FUN_00690f10(*(undefined1 *)(in_ECX + 0x5a0));
  if (*(int *)(in_ECX + 0x5a4) == 1) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x134) + 0x24c);
    if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xcc), iVar1 != 0)) {
      FUN_006438f0(iVar1);
    }
    FUN_00757710();
    uVar5 = 2;
    uVar4 = 0x3e;
    FUN_00585620(0x3e,2);
    uVar4 = FUN_00585330(uVar4);
    FUN_00690d80(in_ECX,uVar4,uVar5);
    FUN_0075cd30(*(undefined4 *)(in_ECX + 0x134));
    *(undefined4 *)(in_ECX + 0x208) = 2;
    iVar1 = *(int *)(*(int *)(in_ECX + 0x134) + 0x24c);
    if (iVar1 != 0) {
      FUN_00749920(iVar1);
    }
    (**(code **)(**(int **)(in_ECX + 0x134) + 200))();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_14 = (void *)0x0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_14 = (void *)0xffffffff;
    }
    FUN_005740f0(&stack0xffffffdc);
    if (unaff_EDI == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  else {
    if (*(int *)(in_ECX + 0x5a4) != 2) {
      (**(code **)(**(int **)(in_ECX + 0x120) + 0x90))(1);
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_14 = (void *)0x2;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_14 = (void *)0xffffffff;
      }
      FUN_006908d0(DAT_00f9392c);
      goto LAB_006908ad;
    }
    iVar1 = *(int *)(*(int *)(in_ECX + 0x134) + 0x24c);
    if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xcc), iVar1 != 0)) {
      FUN_006438f0(iVar1);
    }
    FUN_00757710();
    uVar5 = 3;
    uVar4 = 0x3f;
    FUN_00585620(0x3f,3);
    uVar4 = FUN_00585330(uVar4);
    FUN_00690d80(in_ECX,uVar4,uVar5);
    FUN_0075cd30(*(undefined4 *)(in_ECX + 0x134));
    *(undefined4 *)(in_ECX + 0x208) = 3;
    iVar1 = *(int *)(*(int *)(in_ECX + 0x134) + 0x24c);
    if (iVar1 != 0) {
      FUN_00749920(iVar1);
    }
    (**(code **)(**(int **)(in_ECX + 0x134) + 200))();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_14 = (void *)0x1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_14 = (void *)0xffffffff;
    }
    FUN_005740f0(&stack0xffffffd8);
    if (unaff_ESI == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  FUN_00757710();
LAB_006908ad:
  FUN_00690b30();
  FUN_00691780();
  ExceptionList = pvStack_1c;
  return;
}

