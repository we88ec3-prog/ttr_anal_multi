
void FUN_0047c980(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093987c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
  if ((iVar2 != 0) && (piVar1 = *(int **)(iVar2 + 0xdc), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar2 != 0x12d) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      ExceptionList = local_10;
      return;
    }
    if ((char)piVar1[0x9b] != '\0') {
      if ((DAT_00fc0f80 & 1) == 0) {
        DAT_00fc0f80 = DAT_00fc0f80 | 1;
        local_8 = 0;
        FUN_0047aeb0();
        _atexit((_func_4879 *)&LAB_00bcdb70);
        local_8 = 0xffffffff;
      }
      FUN_004a8b90(&DAT_00fc0f84);
      if ((DAT_00fc0f80 & 1) == 0) {
        DAT_00fc0f80 = DAT_00fc0f80 | 1;
        local_8 = 1;
        FUN_0047aeb0();
        _atexit((_func_4879 *)&LAB_00bcdb70);
        local_8 = 0xffffffff;
      }
      if (DAT_00fc0fb8 == 0) {
        FUN_0047b6b0(piVar1);
        iVar2 = FUN_0040f060();
        uVar3 = *(undefined4 *)(iVar2 + 0x48);
        FUN_0047c300(uVar3);
        FUN_006d9430(uVar3);
      }
    }
  }
  ExceptionList = local_10;
  return;
}

