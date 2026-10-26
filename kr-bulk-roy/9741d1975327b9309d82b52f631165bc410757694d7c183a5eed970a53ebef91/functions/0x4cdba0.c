
undefined4 FUN_004cdba0(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0094069a;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  uVar2 = FUN_004c7df0(in_ECX,0);
  (**(code **)(*in_ECX + 100))(uVar1);
  if (in_ECX[0x10b] != 0) {
    FUN_007be770(in_ECX[0x10b]);
  }
  if (in_ECX[0x10c] != 0) {
    FUN_007be770(in_ECX[0x10c]);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  if (DAT_00f9392c != 6) {
    if ((DAT_00fdf6dc & 1) == 0) {
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      uStack_c = 1;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
      uStack_c = 0xffffffff;
    }
    iVar4 = in_ECX[1];
    uVar3 = (**(code **)(*in_ECX + 0x4c))();
    FUN_00551b80(0xffffffff,0xffffffff);
    FUN_00551dd0(&DAT_00fdf680,(short)iVar4,uVar3,0,0x3f800000,1);
  }
  if (in_ECX[0x10d] != 0) {
    iVar4 = in_ECX[0x22];
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      uStack_c = 2;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      uStack_c = 0xffffffff;
    }
    iVar4 = FUN_006d6d80(&DAT_00fab200,in_ECX[0x10d],(short)iVar4);
    in_ECX[0x10e] = iVar4;
  }
  ExceptionList = local_14;
  return uVar2;
}

