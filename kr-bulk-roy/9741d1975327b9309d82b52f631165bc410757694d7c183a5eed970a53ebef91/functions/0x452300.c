
void FUN_00452300(uint *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 auStack_a4 [4];
  undefined4 local_a0;
  int local_9c;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009227ab;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_a4;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xffffff50;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar2 = FUN_0072f110(0);
  if (cVar2 == '\0') {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  else {
    iVar6 = FUN_0072e360(uVar5);
    if (iVar6 != 0) {
      local_9c = FUN_0072e360(uVar5);
      while (local_9c != 0) {
        iVar6 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar6 == 0) {
LAB_0045242f:
          uVar4 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0045242f;
          uVar4 = FUN_008917b4(puVar7);
        }
        local_a0 = CONCAT22(local_a0._2_2_,uVar4);
        iVar6 = FUN_007300a0("LEVEL");
        if (iVar6 == 0) {
LAB_0045245e:
          uVar3 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar6 + 0x30);
          if (0xf < *(uint *)(iVar6 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0045245e;
          uVar3 = FUN_008917b4(puVar7);
        }
        local_a0._0_3_ = CONCAT12(uVar3,(undefined2)local_a0);
        puVar7 = (undefined4 *)param_1[1];
        if (&local_a0 < puVar7) {
          puVar1 = (undefined4 *)*param_1;
          if (&local_a0 < puVar1) goto LAB_004524a2;
          if (puVar7 == (undefined4 *)param_1[2]) {
            FUN_0068c010();
          }
          if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
            *(undefined4 *)param_1[1] =
                 *(undefined4 *)(*param_1 + ((int)&local_a0 - (int)puVar1 >> 2) * 4);
          }
        }
        else {
LAB_004524a2:
          if (puVar7 == (undefined4 *)param_1[2]) {
            FUN_0068c010();
          }
          if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
            *(undefined4 *)param_1[1] = local_a0;
          }
        }
        param_1[1] = param_1[1] + 4;
        local_9c = FUN_0072e3c0();
      }
      local_9c = 0;
    }
    local_98[0] = TiXmlDocument::vftable;
    local_c = 0xffffffff;
    if (0xf < local_38) {
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      FUN_0089120c(local_4c);
    }
  }
  local_3c = 0;
  local_38 = 0xf;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_a4);
  return;
}

