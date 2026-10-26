
undefined4 FUN_004bc930(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936bba;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  if (DAT_00fab228 == 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 2;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c = 0xffffffff;
    puVar2 = (undefined4 *)FUN_00891268(0x18);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4269;
      *puVar2 = FoxUI::FXUIEventB1::vftable;
      *(undefined1 *)(puVar2 + 5) = 1;
      goto LAB_004bca6e;
    }
  }
  else {
    cVar1 = *(char *)(DAT_00fab228 + 0x28);
    if (cVar1 != '\0') {
      *(undefined4 *)(in_ECX + 0xbd54) = 1;
      *(undefined4 *)(in_ECX + 0xbd58) = 0x41200000;
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c = 0xffffffff;
    puVar2 = (undefined4 *)FUN_00891268(0x18);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4269;
      *puVar2 = FoxUI::FXUIEventB1::vftable;
      *(char *)(puVar2 + 5) = cVar1;
      goto LAB_004bca6e;
    }
  }
  puVar2 = (undefined4 *)0x0;
LAB_004bca6e:
  FUN_0058aa50(puVar2);
  ExceptionList = local_14;
  return 0;
}

