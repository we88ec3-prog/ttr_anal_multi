
void FUN_00635730(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d40e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar1 = unaff_ESI;
  if ((*(byte *)(unaff_ESI + 10) & 0x10) == 0) {
    if (unaff_ESI[0x18] == 0) goto LAB_00635791;
    piVar1 = (int *)FUN_00745c20();
  }
  if ((((piVar1 != (int *)0x0) && (piVar1[0x18] != 0)) && (((uint)piVar1[10] >> 0xc & 1) == 0)) &&
     (piVar1[0x18] != 0)) {
    FUN_0074a010(piVar1);
  }
LAB_00635791:
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  iVar2 = FUN_005c7190();
  if (iVar2 != 0) {
    FUN_0082ef00(&param_1);
  }
  FUN_00745060();
  (**(code **)(*(int *)unaff_ESI[0x3d] + 200))();
  FUN_00749920(unaff_ESI);
  (**(code **)(*unaff_ESI + 200))();
  ExceptionList = local_10;
  return;
}

