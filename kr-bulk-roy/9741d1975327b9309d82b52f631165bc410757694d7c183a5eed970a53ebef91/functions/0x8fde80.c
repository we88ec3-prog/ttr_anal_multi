
void FUN_008fde80(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int in_ECX;
  int *piVar2;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00921b75;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  FUN_008438c0();
  if ((local_14 != DAT_00f8d91c) && (piVar2 = *(int **)(local_14 + 0x10), piVar2 != (int *)0x0)) {
    *(undefined4 *)(in_ECX + 0x68) = param_1;
    *(undefined4 *)(in_ECX + 0x6c) = param_2;
    FUN_008fd880();
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_00402160();
    local_8 = 2;
    if (7 < (uint)piVar2[5]) {
      piVar2 = (int *)*piVar2;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 3;
      local_8._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    FUN_005740f0();
    if (local_14 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_00483f00(piVar2);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
  }
  ExceptionList = local_10;
  return;
}

