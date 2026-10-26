
void FUN_0045d1a0(void)

{
  code *pcVar1;
  char cVar2;
  int *in_ECX;
  int iVar3;
  void *local_20;
  void *local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009416c8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  cVar2 = FUN_00509a00(in_ECX[0x59],&local_20,local_1c);
  if (cVar2 != '\0') {
    FUN_0068a1b0(in_ECX[0x3d],in_ECX[0x3e]);
    (**(code **)(*(int *)in_ECX[0x41] + 0x90))(0);
    (**(code **)(*in_ECX + 0x16c))(0);
    ExceptionList = local_1c[0];
    return;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 1;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    local_c = 0xffffffff;
  }
  local_20 = (void *)0x196;
  FUN_005740f0(&local_20);
  if (local_1c[0] != DAT_00fe5b10) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 2;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    local_1c[0] = (void *)0x12;
    FUN_005740f0(local_1c);
    if (local_20 != DAT_00fe5b10) {
      if (*(uint *)((int)local_20 + 0x24) < 8) {
        iVar3 = (int)local_20 + 0x10;
      }
      else {
        iVar3 = *(int *)((int)local_20 + 0x10);
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_c = 3;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_c = 0xffffffff;
      }
      FUN_007532b0(&DAT_00f94810,iVar3,0,0);
      ExceptionList = local_14;
      return;
    }
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

