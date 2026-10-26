
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00560480(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ad9f;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 4;
  FUN_005623a0(&DAT_00fb73c0);
  iVar2 = DAT_00fb73f0;
  if (DAT_00fb73f0 != 0) {
    puVar1 = (undefined4 *)(DAT_00fb73f0 + 0x2c);
    if (0xf < *(uint *)(DAT_00fb73f0 + 0x40)) {
      FUN_0089120c(*puVar1,uVar3);
    }
    *(undefined4 *)(iVar2 + 0x40) = 0xf;
    *(undefined4 *)(iVar2 + 0x3c) = 0;
    *(undefined1 *)puVar1 = 0;
    FUN_0089120c(iVar2,uVar3);
    DAT_00fb73f0 = 0;
  }
  local_8._0_1_ = 5;
  FUN_004ca160(*DAT_00fb7438,DAT_00fb7438);
  FUN_0089120c(DAT_00fb7438,uVar3);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004ca160(*DAT_00fb7424,DAT_00fb7424);
  FUN_0089120c(DAT_00fb7424);
  if (0xf < DAT_00fb7418) {
    FUN_0089120c(DAT_00fb7404);
  }
  DAT_00fb7418 = 0xf;
  _DAT_00fb7414 = 0;
  DAT_00fb7404 = DAT_00fb7404 & 0xffffff00;
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_005540c0(*DAT_00fb73dc,DAT_00fb73dc);
  FUN_0089120c(DAT_00fb73dc);
  local_8 = 8;
  FUN_00565af0(*DAT_00fb73cc,DAT_00fb73cc);
  FUN_0089120c(DAT_00fb73cc);
  ExceptionList = local_10;
  return;
}

