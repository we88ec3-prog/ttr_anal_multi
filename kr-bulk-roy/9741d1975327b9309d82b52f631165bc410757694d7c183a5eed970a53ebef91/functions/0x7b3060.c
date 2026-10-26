
undefined1 * FUN_007b3060(undefined1 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_009056d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_00403040(param_2,0,0xffffffff);
  puVar1 = (undefined4 *)(param_1 + 0x1c);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (puVar1 != unaff_EDI) {
    *puVar1 = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *puVar1 = *unaff_EDI;
    *(undefined4 *)(param_1 + 0x20) = unaff_EDI[1];
    *(undefined4 *)(param_1 + 0x24) = unaff_EDI[2];
    *unaff_EDI = 0;
    unaff_EDI[1] = 0;
    unaff_EDI[2] = 0;
  }
  ExceptionList = local_10;
  return param_1;
}

