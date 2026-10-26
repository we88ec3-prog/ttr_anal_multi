
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f44b0(void)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009132d2;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar7 = (int *)*DAT_00fb7574;
  piVar6 = DAT_00fb7574;
  if (piVar7 != DAT_00fb7574) {
    do {
      puVar2 = (undefined4 *)piVar7[4];
      if (puVar2 != (undefined4 *)0x0) {
        if (7 < (uint)puVar2[5]) {
          FUN_0089120c(*puVar2,uVar5);
        }
        puVar2[5] = 7;
        puVar2[4] = 0;
        *(undefined2 *)puVar2 = 0;
        FUN_0089120c(puVar2,uVar5);
        piVar6 = DAT_00fb7574;
      }
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar3 = (int *)piVar7[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar7 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar7 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x15);
          piVar4 = (int *)piVar7[1];
          piVar3 = piVar7;
          while ((piVar7 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x15);
            piVar4 = (int *)piVar7[1];
            piVar3 = piVar7;
          }
        }
      }
    } while (piVar7 != piVar6);
  }
  piVar7 = (int *)*DAT_00fb7594;
  piVar6 = DAT_00fb7594;
  if (piVar7 != DAT_00fb7594) {
    do {
      puVar2 = (undefined4 *)piVar7[4];
      if (puVar2 != (undefined4 *)0x0) {
        if (7 < (uint)puVar2[5]) {
          FUN_0089120c(*puVar2,uVar5);
        }
        puVar2[5] = 7;
        puVar2[4] = 0;
        *(undefined2 *)puVar2 = 0;
        FUN_0089120c(puVar2,uVar5);
        piVar6 = DAT_00fb7594;
      }
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar3 = (int *)piVar7[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar7 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar7 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x15);
          piVar4 = (int *)piVar7[1];
          piVar3 = piVar7;
          while ((piVar7 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x15);
            piVar4 = (int *)piVar7[1];
            piVar3 = piVar7;
          }
        }
      }
    } while (piVar7 != piVar6);
  }
  if (DAT_00fb75a0 != 0) {
    FUN_0089120c(DAT_00fb75a0,uVar5);
    piVar6 = DAT_00fb7594;
  }
  DAT_00fb75a0 = 0;
  _DAT_00fb75a4 = 0;
  _DAT_00fb75a8 = 0;
  local_8 = CONCAT31(local_8._1_3_,0x12);
  FUN_005540c0(*piVar6,piVar6);
  FUN_0089120c(DAT_00fb7594,uVar5);
  if (DAT_00fb7580 != 0) {
    FUN_0089120c(DAT_00fb7580);
  }
  DAT_00fb7580 = 0;
  _DAT_00fb7584 = 0;
  _DAT_00fb7588 = 0;
  local_8._0_1_ = 0x13;
  FUN_005540c0(*DAT_00fb7574,DAT_00fb7574);
  FUN_0089120c(DAT_00fb7574);
  local_8._0_1_ = 0x14;
  FUN_004f80a0(*DAT_00fb7564,DAT_00fb7564);
  FUN_0089120c(DAT_00fb7564);
  local_8._0_1_ = 0x15;
  FUN_004f80a0(*DAT_00fb7554,DAT_00fb7554);
  FUN_0089120c(DAT_00fb7554);
  local_8._0_1_ = 0x16;
  FUN_004f80a0(*DAT_00fb7544,DAT_00fb7544);
  FUN_0089120c(DAT_00fb7544);
  local_8._0_1_ = 0x17;
  FUN_004f7fe0(*DAT_00fb7534,DAT_00fb7534);
  FUN_0089120c(DAT_00fb7534);
  local_8._0_1_ = 0x18;
  FUN_004f7fe0(*DAT_00fb7524,DAT_00fb7524);
  FUN_0089120c(DAT_00fb7524);
  local_8._0_1_ = 0x19;
  FUN_004f7fe0(*DAT_00fb7514,DAT_00fb7514);
  FUN_0089120c(DAT_00fb7514);
  local_8._0_1_ = 0x1a;
  FUN_004f7fe0(*DAT_00fb7504,DAT_00fb7504);
  FUN_0089120c(DAT_00fb7504);
  local_8._0_1_ = 0x1b;
  FUN_004f7fe0(*DAT_00fb74f4,DAT_00fb74f4);
  FUN_0089120c(DAT_00fb74f4);
  local_8._0_1_ = 0x1c;
  FUN_004f7fe0(*DAT_00fb74e4,DAT_00fb74e4);
  FUN_0089120c(DAT_00fb74e4);
  local_8._0_1_ = 0x1d;
  FUN_004f7fe0(*DAT_00fb74d4,DAT_00fb74d4);
  FUN_0089120c(DAT_00fb74d4);
  local_8._0_1_ = 0x1e;
  FUN_004f7fe0(*DAT_00fb74c4,DAT_00fb74c4);
  FUN_0089120c(DAT_00fb74c4);
  local_8._0_1_ = 0x1f;
  FUN_004f7fe0(*DAT_00fb74b4,DAT_00fb74b4);
  FUN_0089120c(DAT_00fb74b4);
  local_8._0_1_ = 0x20;
  FUN_004f7fe0(*DAT_00fb74a4,DAT_00fb74a4);
  FUN_0089120c(DAT_00fb74a4);
  local_8._0_1_ = 0x21;
  FUN_004f7fe0(*DAT_00fb7494,DAT_00fb7494);
  FUN_0089120c(DAT_00fb7494);
  local_8 = CONCAT31(local_8._1_3_,0x22);
  FUN_004ffa40(*DAT_00fb7484,DAT_00fb7484);
  FUN_0089120c(DAT_00fb7484);
  local_8 = 0x23;
  FUN_004f7f40(*DAT_00fb7474,DAT_00fb7474);
  FUN_0089120c(DAT_00fb7474);
  ExceptionList = local_10;
  return;
}

