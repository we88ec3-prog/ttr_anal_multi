
undefined4 FUN_0050a6f0(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  int in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933c4c;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)(in_EDX + 2) == '\0') {
    if ((*(char *)(in_EDX + 3) != '\x01') || (param_1 == -0x16f8)) {
      FUN_006edb60("InvUp: Invalid bag no %d",*(char *)(in_EDX + 3));
      ExceptionList = local_10;
      return 0x80004005;
    }
    *(uint *)(param_1 + 0x2398) = (uint)*(byte *)(in_EDX + 4);
    param_1 = 0xb8;
    iVar3 = FUN_005854b0(uVar2);
    FUN_005740f0(&param_1);
    if (in_ECX == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar5 = (*pcVar1)();
      return uVar5;
    }
    puVar4 = (undefined4 *)(in_ECX + 0x10);
    if (7 < *(uint *)(in_ECX + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    FUN_00404b10(0xca,puVar4,&DAT_00bed1fc,0,0);
  }
  else {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    local_8 = 0xffffffff;
    param_1 = 0xb9;
    FUN_005740f0(&param_1);
    if (in_ECX == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      uVar5 = (*pcVar1)();
      return uVar5;
    }
    if (*(uint *)(in_ECX + 0x24) < 8) {
      iVar3 = in_ECX + 0x10;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x10);
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 1;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    FUN_007532b0(&DAT_00f94810,iVar3,0,0);
  }
  ExceptionList = local_10;
  return 0;
}

