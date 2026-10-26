
undefined4 FUN_0050aad0(int param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933c0a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)(param_2 + 2) == '\x01') {
    *(uint *)(param_1 + 0x50b8) = (uint)*(ushort *)(param_2 + 3);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_0058aad0(0xf4364);
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    param_2 = 0xbc;
    FUN_005740f0(&param_2);
    if (param_1 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    if (*(uint *)(param_1 + 0x24) < 8) {
      param_1 = param_1 + 0x10;
    }
    else {
      param_1 = *(int *)(param_1 + 0x10);
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 2;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    FUN_007532b0(&DAT_00f94810,param_1,0,0);
  }
  else if (*(char *)(param_2 + 2) == '\0') {
    param_2 = 0xf;
    iVar3 = FUN_005854b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    FUN_005740f0(&param_2);
    if (param_1 == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    puVar4 = (undefined4 *)(param_1 + 0x10);
    if (7 < *(uint *)(param_1 + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    FUN_00404b10(0xca,puVar4,&DAT_00bed1fc,0,0);
  }
  ExceptionList = local_10;
  return 0;
}

