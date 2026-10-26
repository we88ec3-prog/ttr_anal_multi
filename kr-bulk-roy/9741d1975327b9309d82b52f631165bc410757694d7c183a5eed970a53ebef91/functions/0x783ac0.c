
void FUN_00783ac0(void)

{
  int iVar1;
  undefined4 ****ppppuVar2;
  size_t sVar3;
  size_t _Count;
  int *unaff_EDI;
  int local_34;
  undefined4 ***local_30;
  undefined4 local_2c;
  undefined1 local_28;
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917e28;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((unaff_EDI[0x11] != 0) && (*(char *)((int)unaff_EDI + 0x49) != '\0')) &&
     (iVar1 = (**(code **)(*unaff_EDI + 0xc))(0xffffffff,local_14), iVar1 != -1)) {
    local_1c = 0xf;
    local_30 = (undefined4 ****)0x0;
    local_2c = 0;
    local_20 = 8;
    local_28 = 0;
    local_8 = 0;
    while( true ) {
      ppppuVar2 = (undefined4 ****)local_30;
      if (local_1c < 0x10) {
        ppppuVar2 = &local_30;
      }
      iVar1 = (**(code **)(*(int *)unaff_EDI[0x11] + 0x18))
                        (unaff_EDI + 0x13,ppppuVar2,(int)ppppuVar2 + local_20,&local_34);
      if (iVar1 != 0) break;
      *(undefined1 *)((int)unaff_EDI + 0x49) = 0;
LAB_00783b79:
      ppppuVar2 = (undefined4 ****)local_30;
      if (local_1c < 0x10) {
        ppppuVar2 = &local_30;
      }
      _Count = local_34 - (int)ppppuVar2;
      if (_Count != 0) {
        ppppuVar2 = (undefined4 ****)local_30;
        if (local_1c < 0x10) {
          ppppuVar2 = &local_30;
        }
        sVar3 = _fwrite(ppppuVar2,1,_Count,(FILE *)unaff_EDI[0x15]);
        if (_Count != sVar3) goto LAB_00783bcf;
      }
      if (*(char *)((int)unaff_EDI + 0x49) == '\0') goto LAB_00783bdb;
      if (_Count == 0) {
        FUN_00429630(8,0);
      }
    }
    if (iVar1 == 1) goto LAB_00783b79;
    if (iVar1 != 3) {
LAB_00783bcf:
      FUN_00402c50();
      goto LAB_00783be2;
    }
LAB_00783bdb:
    FUN_00402c50();
  }
LAB_00783be2:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

