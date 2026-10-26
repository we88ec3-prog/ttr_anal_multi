
void FUN_0047b2b0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cedc;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = param_1 + 0x24c;
  *(undefined4 *)(param_1 + 0x248) = *in_ECX;
  FUN_004026e0(in_ECX + 2,0,0xffffffff);
  FUN_00757800(iVar3);
  if ((int)in_ECX[1] < 0x17) {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 1;
      FUN_005c3de0(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    param_1 = in_ECX[1];
    FUN_0082ef00(&param_1);
    iVar3 = *(int *)(iVar1 + 0x268);
    if ((*(char *)(iVar3 + 0xa4) == '\0') || (*(int *)(iVar3 + 0x94) == 0)) goto LAB_0047b425;
    iVar3 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))();
  }
  else {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 0;
      FUN_005c3de0(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    param_1 = in_ECX[1];
    FUN_0082ef00(&param_1);
    iVar3 = *(int *)(iVar1 + 0x268);
    if ((*(char *)(iVar3 + 0xa4) == '\0') || (*(int *)(iVar3 + 0x94) == 0)) goto LAB_0047b425;
    iVar3 = (**(code **)(**(int **)(iVar3 + 0x94) + 4))();
  }
  if (iVar3 == 0xbf6b) {
    FUN_0077b200();
  }
LAB_0047b425:
  (**(code **)(**(int **)(iVar1 + 0x268) + 200))();
  ExceptionList = local_10;
  return;
}

