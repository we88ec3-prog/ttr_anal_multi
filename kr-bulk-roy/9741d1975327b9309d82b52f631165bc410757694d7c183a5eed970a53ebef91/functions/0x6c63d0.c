
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c63d0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int *in_ECX;
  int iStack_2c;
  undefined1 auStack_28 [4];
  undefined4 *puStack_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00935720;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX != (int *)0x0) {
    iVar2 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    if (iVar2 == 0x105bd) goto LAB_006c6429;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_006c6429:
  if (in_ECX[5] == 0x6a7) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    FUN_0051ab00(auStack_28,&DAT_00fab148);
    local_c = 1;
    FUN_008438c0(param_1 + 0xb4);
    uVar1 = *(undefined2 *)(*(int *)(iStack_2c + 0x10) + 0x14);
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    FUN_004a4240(uVar1);
    local_c = 2;
    FUN_005540c0(*puStack_24,puStack_24);
    FUN_0089120c(puStack_24);
  }
  ExceptionList = local_14;
  return;
}

