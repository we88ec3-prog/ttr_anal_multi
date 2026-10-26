
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0053a9d0(undefined2 param_1)

{
  undefined2 uVar1;
  int unaff_ESI;
  undefined2 uStack00000006;
  undefined4 local_8;
  
  uVar1 = param_1;
  FUN_00826280(&param_1);
  if (local_8 != *(int *)(unaff_ESI + 0x5ecc)) {
    return *(undefined4 *)(local_8 + 0x10);
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  param_1 = 200;
  uStack00000006 = uVar1;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&param_1,4);
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_8 = CONCAT22(uVar1,0xc9);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,4);
  }
  return 0;
}

