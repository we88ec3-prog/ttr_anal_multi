
void FUN_00509260(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912f8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX - 1U < 0x1e0) {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 0;
      FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bccc90);
    }
    local_8 = 0xffffffff;
    puVar2 = (undefined4 *)FUN_0051d700(unaff_EDI);
    puVar1 = (undefined4 *)(param_1 + in_ECX * 0x18);
    puVar1[2] = param_4;
    puVar1[3] = unaff_EDI;
    puVar1[4] = param_2;
    puVar1[5] = param_3;
    if (puVar2 != (undefined4 *)0x0) {
      *puVar1 = puVar2[2];
      puVar1[1] = *puVar2;
      ExceptionList = local_10;
      return;
    }
    FUN_006edb60("Invalid Item Product %d");
    *puVar1 = 0;
    puVar1[1] = 999999;
  }
  else {
    FUN_006edb60("Invalid slot idx %d");
  }
  ExceptionList = local_10;
  return;
}

