
undefined4 FUN_004e6a90(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined2 local_17;
  undefined4 local_15;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009275ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faaf34 & 1) == 0) {
    DAT_00faaf34 = DAT_00faaf34 | 1;
    local_8 = 0;
    FUN_004073c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcccd0);
  }
  local_8 = 0xffffffff;
  cVar1 = *(char *)(param_1 + 2);
  uVar2 = *(undefined1 *)(param_1 + 3);
  uVar3 = *(undefined4 *)(param_1 + 4);
  DAT_00faaf44 = 1;
  if (DAT_00faaf38 == cVar1) {
    DAT_00faaf45 = 1;
  }
  else {
    local_17 = 0xea;
    local_15 = 0;
    if (DAT_00fba798 == 0) {
      local_11 = cVar1;
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_17,7);
    }
  }
  DAT_00faaf38 = cVar1;
  DAT_00faaf39 = uVar2;
  DAT_00faaf3c = uVar3;
  ExceptionList = local_10;
  return 0;
}

