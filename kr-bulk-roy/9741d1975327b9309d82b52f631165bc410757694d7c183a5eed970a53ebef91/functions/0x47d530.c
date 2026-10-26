
void FUN_0047d530(void)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int in_ECX;
  int in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00947e7e;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_EDX + 0x120) = *(undefined4 *)(in_ECX + 0x248);
  *(undefined4 *)(in_EDX + 0x11c) = *(undefined4 *)(in_ECX + 0x24c);
  if ((DAT_00fc0f64 & 1) == 0) {
    DAT_00fc0f64 = DAT_00fc0f64 | 1;
    local_8 = 0;
    FUN_0047dce0(uVar3);
    _atexit(FUN_00bcdaf0);
  }
  local_8 = 0xffffffff;
  uVar4 = FUN_0047e890(&DAT_00fc0f68,*(undefined4 *)(in_EDX + 0x120));
  FUN_0047b5c0(uVar4);
  FUN_0047cdf0(in_EDX);
  iVar1 = **(int **)(in_EDX + 0x100);
  uVar2 = FUN_0047d610();
  (**(code **)(iVar1 + 0x90))(uVar2);
  (**(code **)(**(int **)(in_EDX + 0x100) + 200))();
  FUN_0047d0b0();
  ExceptionList = local_10;
  return;
}

