
void ** FUN_007e3d00(void **param_1)

{
  void **ppvVar1;
  uint uVar2;
  void **ppvVar3;
  uint *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009148f2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ppvVar1 = (void **)unaff_EDI[1];
  ppvVar3 = ExceptionList;
  if ((param_1 < ppvVar1) && (ppvVar3 = (void **)*unaff_EDI, ppvVar3 <= param_1)) {
    if (ppvVar1 == (void **)unaff_EDI[2]) {
      FUN_007e3dc0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar2 = unaff_EDI[1];
    ppvVar3 = (void **)(*unaff_EDI + (((int)param_1 - (int)ppvVar3) / 0x44) * 0x44);
    local_8 = 0;
  }
  else {
    if (ppvVar1 == (void **)unaff_EDI[2]) {
      ppvVar3 = (void **)FUN_007e3dc0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar2 = unaff_EDI[1];
    local_8 = 1;
  }
  if (uVar2 != 0) {
    ppvVar3 = (void **)FUN_007e40e0();
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x44;
  ExceptionList = local_10;
  return ppvVar3;
}

