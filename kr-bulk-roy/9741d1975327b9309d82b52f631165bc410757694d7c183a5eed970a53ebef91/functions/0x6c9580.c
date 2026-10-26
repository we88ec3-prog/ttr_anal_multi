
void FUN_006c9580(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  code *pcVar3;
  int unaff_ESI;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091233e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar3 = *(code **)(**(int **)(unaff_ESI + 0xf8) + 0x128);
  (*(int **)(unaff_ESI + 0xf8))[0x34] = 0;
  (*pcVar3)(uVar1);
  if (in_ECX == 0) {
    pcVar3 = *(code **)(**(int **)(unaff_ESI + 0xf0) + 0x1ac);
    uVar6 = 0;
    uVar5 = 0xffffffff;
    uVar4 = 0xffffffff;
  }
  else {
    *(undefined4 *)(unaff_ESI + 0x114) = *(undefined4 *)(in_ECX + 0xb);
    *(undefined4 *)(unaff_ESI + 0x11c) = *(undefined4 *)(in_ECX + 2);
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 0;
      FUN_0051c120();
      _atexit((_func_4879 *)&LAB_00bccc90);
      local_8 = 0xffffffff;
    }
    local_14 = *(undefined4 *)(in_ECX + 6);
    FUN_008438c0(&local_14);
    if (local_18 == DAT_00f8d91c) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(local_18 + 0x10);
    }
    *(int *)(unaff_ESI + 0x10c) = iVar2;
    uVar6 = *(undefined1 *)(in_ECX + 10);
    uVar5 = *(undefined4 *)(in_ECX + 6);
    uVar4 = *(undefined4 *)(iVar2 + 0x20);
    pcVar3 = *(code **)(**(int **)(unaff_ESI + 0xf0) + 0x1ac);
  }
  (*pcVar3)(uVar4,uVar5,0,0,uVar6);
  (**(code **)(**(int **)(unaff_ESI + 0xf0) + 200))();
  ExceptionList = local_10;
  return;
}

