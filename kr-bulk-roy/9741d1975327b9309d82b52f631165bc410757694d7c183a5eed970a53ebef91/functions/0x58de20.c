
void FUN_0058de20(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 ****ppppuVar6;
  int *piVar7;
  undefined4 local_15c;
  int *local_158;
  undefined4 local_154;
  int local_150;
  undefined4 ***local_14c [4];
  undefined4 local_13c;
  uint local_138;
  undefined **local_130 [19];
  uint uStack_e4;
  undefined4 uStack_d4;
  uint uStack_d0;
  undefined1 local_b8 [156];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00920fbf;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_15c;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffe98;
  ExceptionList = &local_14;
  local_154 = param_1;
  FUN_0072ed80(local_130);
  local_c = 0;
  FUN_0072fc40(local_b8,&DAT_00c1a864);
  local_c = CONCAT31(local_c._1_3_,1);
  FUN_0072e1e0(uVar4);
  FUN_00764bb0();
  FUN_007649b0(1);
  FUN_0072e0d0();
  local_15c = FUN_00764bb0();
  FUN_00764bb0();
  FUN_0058d060(in_ECX + 4);
  FUN_0072e0d0();
  local_158 = *(int **)(in_ECX + 0x48);
  piVar7 = (int *)*local_158;
  if (piVar7 != local_158) {
    do {
      FUN_004297b0();
      local_c._0_1_ = 2;
      local_150 = FUN_00891268(0x98);
      local_c._0_1_ = 3;
      if (local_150 == 0) {
        uVar5 = 0;
      }
      else {
        ppppuVar6 = (undefined4 ****)local_14c[0];
        if (local_138 < 0x10) {
          ppppuVar6 = local_14c;
        }
        uVar5 = FUN_0072e420(local_150,ppppuVar6);
      }
      local_c = CONCAT31(local_c._1_3_,1);
      if (0xf < local_138) {
        FUN_0089120c(local_14c[0]);
      }
      local_138 = 0xf;
      local_13c = 0;
      local_14c[0] = (undefined4 ***)((uint)local_14c[0] & 0xffffff00);
      FUN_00764810(uVar5);
      FUN_0058d060(piVar7 + 10);
      FUN_0072e0d0();
      if (*(char *)((int)piVar7 + 0x3d) == '\0') {
        piVar1 = (int *)piVar7[2];
        if (*(char *)((int)piVar1 + 0x3d) == '\0') {
          cVar3 = *(char *)(*piVar1 + 0x3d);
          piVar7 = piVar1;
          piVar1 = (int *)*piVar1;
          while (cVar3 == '\0') {
            cVar3 = *(char *)(*piVar1 + 0x3d);
            piVar7 = piVar1;
            piVar1 = (int *)*piVar1;
          }
        }
        else {
          cVar3 = *(char *)(piVar7[1] + 0x3d);
          piVar2 = (int *)piVar7[1];
          piVar1 = piVar7;
          while ((piVar7 = piVar2, cVar3 == '\0' && (piVar1 == (int *)piVar7[2]))) {
            cVar3 = *(char *)(piVar7[1] + 0x3d);
            piVar2 = (int *)piVar7[1];
            piVar1 = piVar7;
          }
        }
      }
    } while (piVar7 != local_158);
  }
  FUN_0072e0d0();
  cVar3 = FUN_00764c50(local_130,local_154);
  local_c = local_c & 0xffffff00;
  if (cVar3 == '\0') {
    FUN_005902f0();
    local_c = 0xffffffff;
    local_130[0] = TiXmlDocument::vftable;
    if (0xf < uStack_d0) {
      FUN_0089120c(uStack_e4);
    }
    uStack_d0 = 0xf;
    uStack_d4 = 0;
    uStack_e4 = uStack_e4 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    FUN_005902f0();
    local_c = 0xffffffff;
    local_130[0] = TiXmlDocument::vftable;
    if (0xf < uStack_d0) {
      FUN_0089120c(uStack_e4);
    }
    uStack_d0 = 0xf;
    uStack_d4 = 0;
    uStack_e4 = uStack_e4 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_15c);
  return;
}

