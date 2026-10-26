
void FUN_00596830(int param_1)

{
  uint uVar1;
  int iVar2;
  int *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009475ae;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined1 *)(param_1 + 0xb8) = 0;
  if (unaff_ESI != (int *)0x0) {
    iVar2 = (**(code **)(*unaff_ESI + 4))(uVar1);
    if (iVar2 == 0x105bd) goto LAB_0059688b;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  unaff_ESI = (int *)0x0;
LAB_0059688b:
  if (unaff_ESI[5] == 0x6a7) {
    if ((DAT_00fb73b8 & 1) == 0) {
      DAT_00fb73b8 = DAT_00fb73b8 | 1;
      local_8 = 0;
      FUN_00560170();
      _atexit((_func_4879 *)&LAB_00bcd110);
      local_8 = 0xffffffff;
    }
    FUN_005624b0(1);
  }
  ExceptionList = local_10;
  return;
}

