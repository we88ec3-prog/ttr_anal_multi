
void FUN_0061c660(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EDI;
  int *local_34;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093de78;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = *(int *)(*(int *)(unaff_EDI + 0x114) + 0x24c);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 0xcc);
    if (iVar2 == 0) {
      local_34 = (int *)0x0;
    }
    else {
      local_34 = *(int **)(iVar2 + 0xdc);
    }
    if (local_34 != (int *)0x0) {
      iVar2 = (**(code **)(*local_34 + 4))(uVar1);
      if (iVar2 == 0x4b4) goto LAB_0061c6de;
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
  }
  local_34 = (int *)0x0;
LAB_0061c6de:
  if ((*(int *)(unaff_EDI + 0x218) != 0) && (local_34 != (int *)0x0)) {
    iVar2 = FUN_00404ba0();
    if ((*(uint *)(unaff_EDI + 0x218) < 10) &&
       ((iVar2 = *(uint *)(unaff_EDI + 0x218) * 0x210 + *(int *)(iVar2 + 0x6924),
        *(int *)(iVar2 + 0x5c) != 0 && (iVar2 != 0)))) {
      iVar2 = FUN_00404ba0();
      *(undefined4 *)(unaff_EDI + 0x220) = *(undefined4 *)(iVar2 + 0x6874);
      uVar3 = FUN_004068f0();
      local_8 = 0;
      FUN_00757800(uVar3);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      (**(code **)(**(int **)(unaff_EDI + 0x110) + 200))();
    }
    FUN_0061c7c0(unaff_EDI,*(undefined1 *)(unaff_EDI + 0x218),*(undefined1 *)((int)local_34 + 0x249)
                );
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

