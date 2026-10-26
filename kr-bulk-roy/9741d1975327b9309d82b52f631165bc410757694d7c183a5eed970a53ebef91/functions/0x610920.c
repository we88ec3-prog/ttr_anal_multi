
undefined4 * FUN_00610920(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091266e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  unaff_ESI[4] = 0;
  puVar2 = unaff_ESI;
  if (7 < (uint)unaff_ESI[5]) {
    puVar2 = (undefined4 *)*unaff_ESI;
  }
  *(undefined2 *)puVar2 = 0;
  if ((DAT_00fab230 & 1) == 0) {
    DAT_00fab230 = DAT_00fab230 | 1;
    local_8 = 0;
    FUN_005292c0(uVar1);
    _atexit(FUN_00bcce40);
  }
  local_8 = 0xffffffff;
  param_1 = (param_1 & 0xff) * 10000 + (param_2 & 0xff);
  FUN_00529250(&param_1);
  if ((param_2 != DAT_00fab238) && (param_2 != 0xfffffff0)) {
    FUN_004026e0(param_2 + 0x30,0,0xffffffff);
  }
  if ((uint)unaff_ESI[5] < 8) {
    ExceptionList = local_10;
    return unaff_ESI;
  }
  ExceptionList = local_10;
  return (undefined4 *)*unaff_ESI;
}

