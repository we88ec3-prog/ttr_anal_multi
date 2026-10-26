
void FUN_005966c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009475f4;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(char *)(in_ECX + 0xb8) == '\0') {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if ((DAT_00f9392c != 4) && (iVar1 = FUN_00404ba0(), *(int *)(iVar1 + 0x5f4c) != 9)) {
      FUN_004054c0();
      puVar2 = (undefined4 *)FUN_00891268();
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf43dc;
      }
      FUN_00402250();
      local_c = 2;
      FUN_005854b0();
      uVar3 = FUN_00585330();
      FUN_00402250(uVar3);
      local_c = 0xffffffff;
      FUN_0058b270(0xcf);
      ExceptionList = local_14;
      return;
    }
    if ((DAT_00fb73b8 & 1) == 0) {
      DAT_00fb73b8 = DAT_00fb73b8 | 1;
      local_c = 1;
      FUN_00560170();
      _atexit((_func_4879 *)&LAB_00bcd110);
      local_c = 0xffffffff;
    }
    FUN_005624b0();
  }
  ExceptionList = local_14;
  return;
}

