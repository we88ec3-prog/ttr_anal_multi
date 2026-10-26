
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057dc20(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_1c;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00916b3e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (-1 < in_ECX) {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 0;
      FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bccc90);
    }
    local_8 = 0xffffffff;
    puVar1 = (undefined4 *)FUN_0051d700(in_ECX);
    if ((_DAT_00f8d8a8 & 1) == 0) {
      _DAT_00f8d8a8 = _DAT_00f8d8a8 | 1;
      FUN_005e93a0();
      _atexit((_func_4879 *)&DAT_00bccc40);
    }
    iVar2 = FUN_005e9420(&DAT_00f8d8b0,*puVar1,in_ECX,0,0,0,1,0,0,0);
    if ((iVar2 != 0) && (*(int *)(param_1 + 0x88) == 0)) {
      uVar3 = FUN_00404aa0();
      FUN_0074f980(uVar3);
      *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(iVar2 + 0x10);
      if (*(int *)(*(int *)(param_1 + 4) + 0xc) != 0) {
        (**(code **)(**(int **)(*(int *)(param_1 + 4) + 0xc) + 0x38))(0xffffffff,0xffffffff);
      }
      local_1c = 0x3f800000;
      local_18 = 0x3f800000;
      FUN_00748a20(0,0,&local_1c,0,0,0x400,0x400);
      if (*(int *)(*(int *)(param_1 + 4) + 0xc) != 0) {
        (**(code **)(**(int **)(*(int *)(param_1 + 4) + 0xc) + 0x3c))();
      }
      iVar2 = FUN_00404aa0();
      *(undefined4 *)(iVar2 + 0x13ec) = 0;
      *(undefined4 *)(param_1 + 0x88) = 1;
    }
  }
  ExceptionList = local_10;
  return;
}

