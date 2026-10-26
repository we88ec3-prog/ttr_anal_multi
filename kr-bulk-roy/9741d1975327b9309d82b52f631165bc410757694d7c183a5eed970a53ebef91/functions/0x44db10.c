
void FUN_0044db10(int *param_1,int param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00931ad2;
  local_10 = ExceptionList;
  if (param_2 == 0) {
    ExceptionList = &local_10;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_00402160();
    local_8 = 1;
    FUN_00402160(&DAT_00bfc79c,0x13);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
    (**(code **)(*param_1 + 0xd4))();
    ExceptionList = local_10;
    return;
  }
  if (param_2 == 1) {
    ExceptionList = &local_10;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 2;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_00402160();
    uVar2 = 0x11;
    local_8 = 3;
    puVar1 = &DAT_00bfc7c4;
  }
  else {
    if (param_2 != 2) {
      return;
    }
    ExceptionList = &local_10;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 4;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_00402160();
    uVar2 = 0xf;
    local_8 = 5;
    puVar1 = &DAT_00bfc7e8;
  }
  FUN_00402160(puVar1,uVar2);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
  ExceptionList = local_10;
  return;
}

