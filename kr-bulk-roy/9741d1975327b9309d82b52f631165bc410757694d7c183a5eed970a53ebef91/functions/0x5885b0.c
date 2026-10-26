
void FUN_005885b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  int *piVar3;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00921956;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  local_8 = 0xffffffff;
  FUN_0058e790(&DAT_00faaf80);
  local_14 = *(undefined4 *)(in_ECX + 0x14);
  iVar1 = *(int *)(in_ECX + 0x2c);
  FUN_0082ef00(&local_14);
  if (local_18 == *(int *)(iVar1 + 8)) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(local_18 + 0x10);
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  FUN_0074e9d0();
  FUN_00761060(piVar3);
  FUN_00746780(piVar3);
  (**(code **)(*piVar3 + 0x10c))();
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 2;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  if (DAT_00f95bd4 != 0) {
    FUN_007486f0(0);
    DAT_00f95bd4 = 0;
  }
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 3;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  puVar2 = DAT_00faafa8;
  if (DAT_00faafbc < 8) {
    puVar2 = &DAT_00faafa8;
  }
  FUN_0058de20(puVar2);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 4;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0058e350(&DAT_00faaf80);
  ExceptionList = local_10;
  return;
}

