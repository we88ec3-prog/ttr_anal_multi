
void FUN_00484920(void)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00944f04;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = *(int *)(in_ECX + 0xf8);
  if (*(char *)(iVar1 + 0x141) != '\0') {
    FUN_006edb10();
  }
  if (*(int *)(iVar1 + 0x118) == 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_00402160();
    local_8 = 1;
    FUN_00402160(&DAT_00c03d60,0xb);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
    ExceptionList = local_10;
    return;
  }
  if (*(char *)(*(int *)(in_ECX + 0xf8) + 0x141) != '\0') {
    FUN_006edb10();
  }
  if ((DAT_00fbacd0 & 1) == 0) {
    DAT_00fbacd0 = DAT_00fbacd0 | 1;
    local_8 = 2;
    DAT_00fbacd4 = 0;
    DAT_00fbacd4 = FUN_006d6300();
    _atexit((_func_4879 *)&LAB_00bcd670);
    local_8 = 0xffffffff;
  }
  FUN_006d6590();
  ExceptionList = local_10;
  return;
}

