
undefined4 * FUN_00763060(undefined4 *param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00911ba6;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fba828 = DAT_00fba828 + 1;
  param_1[1] = DAT_00fba828;
  *param_1 = FoxUI::FXUIImageSet::vftable;
  param_1[2] = 0;
  param_1[9] = 7;
  param_1[8] = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  param_1[0x10] = 7;
  param_1[0xf] = 0;
  *(undefined2 *)(param_1 + 0xb) = 0;
  local_8 = 2;
  uStack_7 = 0;
  param_1[0x14] = 0;
  iVar3 = FUN_00891268(0x18,uVar2);
  if (iVar3 != 0) {
    param_1[0x13] = iVar3;
    *(int *)iVar3 = iVar3;
    *(undefined4 *)(param_1[0x13] + 4) = param_1[0x13];
    *(undefined4 *)(param_1[0x13] + 8) = param_1[0x13];
    *(undefined1 *)(param_1[0x13] + 0x14) = 1;
    *(undefined1 *)(param_1[0x13] + 0x15) = 1;
    DAT_00fba828 = DAT_00fba828 + 1;
    param_1[0x19] = DAT_00fba828;
    param_1[0x20] = 7;
    param_1[0x1f] = 0;
    *(undefined2 *)(param_1 + 0x1b) = 0;
    param_1[0x25] = 0;
    param_1[0x24] = 0;
    param_1[0x23] = 0;
    param_1[0x22] = 0;
    param_1[0x1a] = 0;
    param_1[0x18] = FoxUI::FXUIImageSetItemRect::vftable;
    _local_8 = CONCAT31(uStack_7,4);
    psVar4 = param_2;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(param_2,(int)psVar4 - (int)(param_2 + 1) >> 1);
    param_1[0x16] = 0;
    param_1[0x17] = 0;
    *(undefined1 *)(param_1 + 0x26) = 0;
    param_1[0x1a] = param_1;
    param_1[0x27] = 0;
    param_1[3] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

