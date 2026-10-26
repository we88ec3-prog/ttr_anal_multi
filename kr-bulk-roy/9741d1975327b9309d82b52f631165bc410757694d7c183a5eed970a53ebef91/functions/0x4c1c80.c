
void FUN_004c1c80(void)

{
  code *pcVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00933f58;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00fe1abc == '\0') {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    if (0xfffe01ff < DAT_00fb7984) {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 1;
        FUN_00798de0(uVar2);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
      }
      if (0xffff01ff < DAT_00fb7988) goto LAB_004c1ddd;
    }
    DAT_00fe1abc = '\x01';
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 2;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    local_8 = 0xffffffff;
    local_14 = 0x1c2;
    FUN_005740f0(&local_14);
    if (local_18 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(local_18 + 0x24) < 8) {
      iVar3 = local_18 + 0x10;
    }
    else {
      iVar3 = *(int *)(local_18 + 0x10);
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 3;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    FUN_007532b0(&DAT_00f94810,iVar3,0,0);
  }
LAB_004c1ddd:
  if (*(int *)(in_ECX + 0xbd5c) != 0) {
    DAT_00fba7d8 = 1;
  }
  ExceptionList = local_10;
  return;
}

