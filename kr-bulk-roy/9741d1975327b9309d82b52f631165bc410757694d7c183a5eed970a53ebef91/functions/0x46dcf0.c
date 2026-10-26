
void FUN_0046dcf0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009179b7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = (undefined4 *)0x0;
  if (*(char *)(in_ECX + 0x141) == '\0') {
    puVar2 = (undefined4 *)FUN_00891268(0x30,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = 1;
    local_14 = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      if (*(char *)(in_ECX + 0x141) != '\0') {
        FUN_006edb10("Not supported operation");
      }
      puVar3 = (undefined4 *)FUN_00753d40(puVar2,in_ECX + 0x108);
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 2;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
    }
    local_8 = 0xffffffff;
    local_14 = puVar3;
  }
  else {
    local_14 = (undefined4 *)FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (local_14 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      uVar1 = *(undefined4 *)(in_ECX + 0x148);
      local_14[1] = 0xffffffff;
      local_14[2] = 0xffffffff;
      local_14[3] = 0;
      local_14[4] = 0xf4419;
      *local_14 = FoxUI::FXUIEventP1::vftable;
      local_14[5] = uVar1;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 0;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
  }
  FUN_00804260(&local_14);
  ExceptionList = local_10;
  return;
}

