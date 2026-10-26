
void FUN_0059cf60(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  int unaff_EDI;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009249de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX != (int *)0x0) {
    iVar2 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar2 == 0x105b9) goto LAB_0059cfb0;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_0059cfb0:
  (**(code **)(**(int **)(unaff_EDI + 0x17c) + 0x90))(1);
  if (in_ECX[5] == 1) {
    if (((uint)(*(int **)(unaff_EDI + 0x17c))[10] >> 8 & 1) != 0) {
      (**(code **)(**(int **)(unaff_EDI + 0x17c) + 0xd4))();
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058aad0(0xf4365);
    ExceptionList = local_10;
    return;
  }
  if (in_ECX[5] == 0) {
    local_14 = 0x13;
    iVar2 = FUN_005854b0();
    FUN_005740f0(&local_14);
    if (local_18 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar3 = (undefined4 *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    FUN_00404b10(0xca,puVar3,&DAT_00bed1fc,0,0);
  }
  ExceptionList = local_10;
  return;
}

