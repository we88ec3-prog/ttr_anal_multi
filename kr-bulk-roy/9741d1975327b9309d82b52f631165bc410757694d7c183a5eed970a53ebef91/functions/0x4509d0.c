
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004509d0(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093bb1e;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007445d0(param_1);
  if (*(int *)(param_1 + 0x10) != 0xcb) {
    if (*(int *)(param_1 + 0x10) == 0xcc) {
      (**(code **)(*in_ECX + 0x54))(uVar3);
    }
    ExceptionList = local_10;
    return;
  }
  (**(code **)(*in_ECX + 0x54))();
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010();
    _atexit((_func_4879 *)&LAB_00bcd6b0);
    local_8 = 0xffffffff;
  }
  uVar2 = DAT_00fc0c4c;
  if ((_DAT_00fbacd8 & 1) == 0) {
    _DAT_00fbacd8 = _DAT_00fbacd8 | 1;
    _DAT_00fbacdc = 0;
    _DAT_00fbace0 = 0;
    _atexit((_func_4879 *)&DAT_00bcd6c0);
  }
  iVar1 = *in_ECX;
  uVar4 = FUN_0047a000(0,uVar2,1);
  (**(code **)(iVar1 + 0x50))(uVar4);
  ExceptionList = local_10;
  return;
}

