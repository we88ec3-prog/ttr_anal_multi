
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004bbc10(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined2 uStack_20;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined4 *apuStack_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094493d;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 0;
    FUN_00560170(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  local_c = 0xffffffff;
  FUN_005624b0(0);
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 1;
    FUN_00560170(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_c = 0xffffffff;
  }
  FUN_00562250();
  (**(code **)(*DAT_00fba7a4 + 0x14))();
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 2;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  FUN_004dfe90(&DAT_00fab130);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 3;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  DAT_00fab228 = 0;
  FUN_004e1070(&DAT_00fab148);
  if (DAT_00fba7a4 != (int *)0x0) {
    if (DAT_00fba7ac == 2) {
      FUN_00544f50();
      goto LAB_004bbdaa;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  apuStack_1c[0] = (undefined4 *)FUN_00891268(0xc0);
  local_c = 5;
  if (apuStack_1c[0] == (undefined4 *)0x0) {
    DAT_00fba7a4 = (int *)0x0;
  }
  else {
    DAT_00fba7a4 = (int *)FUN_00548540(apuStack_1c[0]);
  }
  local_c = 0xffffffff;
  (**(code **)(*DAT_00fba7a4 + 0x24))();
LAB_004bbdaa:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0xb;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  if (DAT_00faadec == 2) {
    FUN_0058a9a0();
  }
  else {
    _DAT_00faadf0 = 2;
  }
  puVar3 = (undefined4 *)FUN_00891268(0x18);
  puVar4 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[3] = 0;
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[4] = 0xf433b;
    *puVar3 = FoxUI::FXUIEventB1::vftable;
    *(undefined1 *)(puVar3 + 5) = 1;
    puVar4 = puVar3;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 0xc;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  apuStack_1c[0] = puVar4;
  FUN_00804260(apuStack_1c);
  uVar1 = *(undefined4 *)(DAT_00fe1aa0 + 0x18);
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  uStack_20 = 0x43;
  uStack_1e = (undefined1)uVar1;
  uStack_1d = 10;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_20,4);
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_c = 0xd;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
    local_c = 0xffffffff;
  }
  DAT_00fb8830 = DAT_00fb8830 & 0xfffffffe;
  FUN_0054c410(&DAT_00fbaaf8);
  ExceptionList = local_14;
  return 0;
}

