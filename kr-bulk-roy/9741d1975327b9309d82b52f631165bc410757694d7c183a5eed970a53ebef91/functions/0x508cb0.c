
void FUN_00508cb0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912fbe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX - 1U < 100) {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 0;
      FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bccc90);
    }
    local_8 = 0xffffffff;
    puVar1 = (undefined4 *)FUN_0051d700(unaff_EDI);
    puVar2 = (undefined4 *)(in_ECX * 0x20 + param_1);
    puVar2[2] = param_4;
    puVar2[4] = param_2;
    puVar2[3] = unaff_EDI;
    puVar2[5] = param_3;
    *(undefined1 *)(puVar2 + 6) = param_5;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar2 = puVar1[2];
      puVar2[1] = *puVar1;
      ExceptionList = local_10;
      return;
    }
    FUN_006edb60("Invalid Item Product %d");
    *puVar2 = 0;
    puVar2[1] = 999999;
  }
  else {
    FUN_006edb60("Invalid slot idx %d");
  }
  ExceptionList = local_10;
  return;
}

