
void FUN_00484b40(int param_1,char param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093122c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_2 == '\0') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 2;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_00402160();
    local_8 = 3;
    uVar2 = 0xf;
    puVar1 = &DAT_00c03d98;
  }
  else {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_00402160();
    local_8 = 1;
    uVar2 = 0xe;
    puVar1 = &DAT_00c03d78;
  }
  FUN_00402160(puVar1,uVar2);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
  (**(code **)(**(int **)(param_1 + 0x108) + 0x90))();
  (**(code **)(**(int **)(param_1 + 0x108) + 200))();
  ExceptionList = local_10;
  return;
}

