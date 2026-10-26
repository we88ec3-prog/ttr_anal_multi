
void FUN_0066de20(void)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  undefined1 local_7c [104];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00942e1e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  (**(code **)(**(int **)(unaff_EDI + 0xf0) + 0x90))(0,local_14);
  (**(code **)(**(int **)(unaff_EDI + 0xf4) + 0x90))(0);
  (**(code **)(**(int **)(unaff_EDI + 0xf8) + 0x90))(0);
  if (*(int *)(*(int *)(unaff_EDI + 0xf4) + 0x148) != 0) {
    FUN_006ee1f0();
    iVar1 = *(int *)(unaff_EDI + 0xf0);
    if (*(char *)(iVar1 + 0x141) != '\0') {
      FUN_006edb10("Not supported operation");
    }
    puVar4 = (undefined4 *)(iVar1 + 0x108);
    if (7 < *(uint *)(iVar1 + 0x11c)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    if ((DAT_00fbacd0 & 1) == 0) {
      DAT_00fbacd0 = DAT_00fbacd0 | 1;
      local_8 = 0;
      DAT_00fbacd4 = 0;
      DAT_00fbacd4 = FUN_006d6300();
      _atexit((_func_4879 *)&LAB_00bcd670);
      local_8 = 0xffffffff;
    }
    iVar1 = FUN_006d6400(puVar4,local_7c);
    iVar3 = 0x66;
    puVar2 = local_7c;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (iVar1 == 0) {
      (**(code **)(**(int **)(unaff_EDI + 0xf0) + 0x90))(1);
      (**(code **)(**(int **)(unaff_EDI + 0xf4) + 0x90))(1);
      (**(code **)(**(int **)(unaff_EDI + 0xf8) + 0x90))(1);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

