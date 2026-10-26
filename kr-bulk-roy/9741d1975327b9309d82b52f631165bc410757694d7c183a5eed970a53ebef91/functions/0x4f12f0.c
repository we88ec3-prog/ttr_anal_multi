
undefined4 FUN_004f12f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092f87e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  switch(*(undefined1 *)(param_1 + 2)) {
  case 0:
    FUN_00425330();
    FUN_004f6950();
    iVar1 = FUN_004f2610();
    FUN_00425330();
    uVar2 = FUN_004f6a30();
    *(undefined4 *)(iVar1 + 4) = uVar2;
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 0;
    uVar2 = 0xa2;
    FUN_005854b0(0xa2);
    FUN_00585330(uVar2);
    FUN_004ed610();
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
    FUN_00414680();
    FUN_004a4040();
    goto switchD_004f1328_default;
  case 1:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 1;
    break;
  case 2:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 2;
    break;
  case 3:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 3;
    break;
  case 4:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 4;
    break;
  case 5:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 5;
    break;
  default:
    goto switchD_004f1328_default;
  }
  FUN_005854b0();
  uVar2 = FUN_00585330();
  FUN_00402250(uVar2);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
switchD_004f1328_default:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 6;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058ac30();
  ExceptionList = local_10;
  return 0;
}

