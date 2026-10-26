
void FUN_006392a0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094621e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(*(int *)(in_ECX + 4) + 0x84) == 0x2884) {
    if ((DAT_00fab29c & 1) == 0) {
      DAT_00fab29c = DAT_00fab29c | 1;
      local_8 = 0;
      FUN_004ffe60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bccf00);
    }
    local_8 = 0xffffffff;
    FUN_00501650(0xf);
  }
  puVar3 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar3 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(*(int *)(in_ECX + 4) + 0x84);
    uVar2 = *(undefined4 *)(*(int *)(in_ECX + 4) + 0x80);
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf42ea;
    *puVar3 = FoxUI::FXUIEventI2::vftable;
    puVar3[5] = uVar2;
    puVar3[6] = uVar1;
  }
  FUN_004072a0();
  ExceptionList = local_10;
  return;
}

