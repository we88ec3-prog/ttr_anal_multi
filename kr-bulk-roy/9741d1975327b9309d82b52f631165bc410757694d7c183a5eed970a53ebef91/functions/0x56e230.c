
void FUN_0056e230(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091773e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 0;
    FUN_00736880(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bce6f0);
  }
  local_8 = 0xffffffff;
  FUN_0056fd00();
  if ((unaff_ESI[7] == 0) && (unaff_ESI[4] != 0)) {
    puVar1 = unaff_ESI;
    if (0xf < (uint)unaff_ESI[5]) {
      puVar1 = (undefined4 *)*unaff_ESI;
    }
    uVar2 = FUN_00734330(puVar1,0);
    unaff_ESI[7] = uVar2;
  }
  ExceptionList = local_10;
  return;
}

