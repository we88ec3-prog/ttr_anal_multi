
undefined4 FUN_00547240(void)

{
  DWORD DVar1;
  undefined4 *unaff_ESI;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092741e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = 0;
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 0;
    FUN_006d0750(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  switch(*unaff_ESI) {
  case 0:
    if ((DAT_00fb9014 == '\x01') || (DAT_00fb9014 == '\x02')) {
      DVar1 = timeGetTime();
      unaff_ESI[1] = DVar1;
      *unaff_ESI = 2;
      ExceptionList = local_10;
      return 1;
    }
    break;
  case 1:
    if (DAT_00fb9014 != '\0') {
      *unaff_ESI = 0;
      unaff_ESI[1] = 0;
      ExceptionList = local_10;
      return 0;
    }
    break;
  case 2:
    if ((DAT_00fb9014 == '\x03') || (DAT_00fb9014 == '\0')) {
      unaff_ESI[1] = 0;
      *unaff_ESI = 0;
      ExceptionList = local_10;
      return 2;
    }
    DVar1 = timeGetTime();
    if (500 < DVar1 - unaff_ESI[1]) {
      unaff_ESI[1] = 0;
      *unaff_ESI = 3;
      ExceptionList = local_10;
      return 3;
    }
    break;
  case 3:
    if ((DAT_00fb9014 == '\x03') || (DAT_00fb9014 == '\0')) {
      unaff_ESI[1] = 0;
      *unaff_ESI = 0;
      uVar2 = 4;
    }
  }
  ExceptionList = local_10;
  return uVar2;
}

