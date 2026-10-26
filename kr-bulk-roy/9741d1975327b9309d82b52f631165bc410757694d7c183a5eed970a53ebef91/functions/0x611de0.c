
undefined4 * FUN_00611de0(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  undefined4 *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091a76e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  unaff_EDI[4] = 0;
  puVar2 = unaff_EDI;
  if (7 < (uint)unaff_EDI[5]) {
    puVar2 = (undefined4 *)*unaff_EDI;
  }
  *(undefined2 *)puVar2 = 0;
  if ((DAT_00fc0dc4 & 1) == 0) {
    DAT_00fc0dc4 = DAT_00fc0dc4 | 1;
    local_8 = 0;
    FUN_0052a3b0(uVar1);
    _atexit(FUN_00bcd980);
  }
  local_8 = 0xffffffff;
  FUN_0052a340(&param_1);
  if ((in_ECX != DAT_00fc0dcc) && (in_ECX != -0x10)) {
    FUN_004041f0(in_ECX + 0x30,0,0xffffffff);
    iVar3 = FUN_00529cf0();
    if (iVar3 != 0) {
      FUN_00404300(L"<br>",4);
      FUN_004041f0(iVar3 + 4,0,0xffffffff);
    }
  }
  if ((uint)unaff_EDI[5] < 8) {
    ExceptionList = local_10;
    return unaff_EDI;
  }
  ExceptionList = local_10;
  return (undefined4 *)*unaff_EDI;
}

