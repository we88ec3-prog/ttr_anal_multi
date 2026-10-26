
void FUN_006668d0(int *param_1)

{
  int iVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00922ade;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((param_1[4] == 0x70a) && (param_1[2] == *(int *)(*(int *)(in_ECX + 0xec) + 0x20))) {
    iVar1 = (**(code **)(*param_1 + 4))(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      param_1 = (int *)0x0;
    }
    iVar1 = param_1[6];
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      uStack_c = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      uStack_c = 0xffffffff;
    }
    FUN_0058aee0(0xf43df,*(undefined4 *)(iVar1 + 0x260),*(undefined4 *)(iVar1 + 0x264));
  }
  ExceptionList = local_14;
  return;
}

