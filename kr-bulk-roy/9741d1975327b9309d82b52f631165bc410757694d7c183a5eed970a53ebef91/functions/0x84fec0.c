
uint * FUN_0084fec0(void)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint *in_EDX;
  uint *puVar5;
  int unaff_EDI;
  uint local_60 [6];
  int local_48 [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009181db;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar5 = *(uint **)(unaff_EDI + 4);
  if (*(char *)((int)puVar5[1] + 0x35) == '\0') {
    puVar2 = (uint *)puVar5[1];
    do {
      if (puVar2[3] < *in_EDX) {
        puVar3 = (uint *)puVar2[2];
      }
      else {
        puVar3 = (uint *)*puVar2;
        puVar5 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x35) == '\0');
  }
  if ((puVar5 == *(uint **)(unaff_EDI + 4)) || (*in_EDX < puVar5[3])) {
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_38 = 0;
    local_8 = 0;
    local_60[0] = *in_EDX;
    local_14 = local_60 + 1;
    local_60[1] = 0;
    FUN_0062d9b0(&local_34);
    local_8._0_1_ = 1;
    FUN_006dddf0(local_48,&local_24);
    local_8 = CONCAT31(local_8._1_3_,2);
    uVar4 = FUN_00853710(local_60);
    FUN_008526a0(puVar5,uVar4);
    puVar5 = local_14;
    if (local_48[0] != 0) {
      FUN_0089120c(local_48[0],uVar1);
    }
    local_48[0] = 0;
    local_48[1] = 0;
    local_48[2] = 0;
    if (local_60[2] != 0) {
      FUN_0089120c(local_60[2]);
    }
  }
  ExceptionList = local_10;
  return puVar5 + 4;
}

