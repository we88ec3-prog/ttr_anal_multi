
undefined4 FUN_004e56f0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924d9e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((((*(uint *)(param_1 + 2) < 10) &&
       (iVar2 = *(uint *)(param_1 + 2) * 0x210 + *(int *)(in_ECX + 0x6924),
       *(int *)(iVar2 + 0x5c) != 0)) && (iVar2 != 0)) && (iVar2 != -500)) {
    ExceptionList = &local_10;
    FUN_0081a860(*(undefined1 *)(param_1 + 6));
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480(uVar1);
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    puVar3 = (undefined4 *)FUN_00891268(0x14);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf4417;
    }
    FUN_0058aa50(puVar3);
    ExceptionList = local_10;
    return 0;
  }
  return 0x80004005;
}

