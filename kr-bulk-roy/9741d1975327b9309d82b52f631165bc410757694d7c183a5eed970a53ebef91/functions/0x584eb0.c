
void FUN_00584eb0(int param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *****pppppuVar6;
  int *piVar7;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  undefined **local_120 [19];
  uint local_d4;
  undefined4 local_c4;
  uint local_c0;
  uint local_a4 [4];
  undefined4 local_94;
  uint local_90;
  uint local_88 [4];
  undefined4 local_78;
  uint local_74;
  uint local_6c;
  undefined4 local_5c;
  uint local_58;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  undefined4 ****local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922d89;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_124 = param_1;
  local_18 = uVar3;
  FUN_0072ee30(local_120);
  local_8 = 0;
  cVar2 = FUN_0072f110(0);
  if (cVar2 == '\0') {
    FUN_006edb60("Could not load locale file %s");
  }
  else {
    iVar4 = FUN_0072e2e0("Messages");
    if (iVar4 != 0) {
      local_128 = FUN_0072e360(uVar3);
      iVar4 = local_128;
      while (iVar4 != 0) {
        local_3c = 0xf;
        local_40 = 0;
        local_50 = local_50 & 0xffffff00;
        FUN_00402a70(&DAT_00c0f038,3);
        local_8._0_1_ = 1;
        FUN_0072ecf0(&DAT_00bf2375);
        local_8._0_1_ = 3;
        if (0xf < local_3c) {
          FUN_0089120c(local_50);
        }
        local_3c = 0xf;
        local_40 = 0;
        local_50 = local_50 & 0xffffff00;
        local_58 = 0xf;
        local_5c = 0;
        local_6c = local_6c & 0xffffff00;
        FUN_00402a70("value",5);
        local_8._0_1_ = 4;
        FUN_0072ecf0(&DAT_00bf2375);
        local_8._0_1_ = 6;
        if (0xf < local_58) {
          FUN_0089120c(local_6c);
        }
        local_58 = 0xf;
        local_5c = 0;
        local_6c = local_6c & 0xffffff00;
        FUN_004028b0(local_a4);
        iVar4 = local_124;
        local_8 = CONCAT31(local_8._1_3_,7);
        local_12c = FUN_00552550(local_34);
        if ((local_12c == *(int *)(iVar4 + 0x14)) || (cVar2 = FUN_0049ae30(), cVar2 != '\0')) {
          local_130 = *(int *)(iVar4 + 0x14);
          piVar5 = &local_130;
        }
        else {
          piVar5 = &local_12c;
        }
        if (*piVar5 == *(int *)(iVar4 + 0x14)) {
          pppppuVar6 = (undefined4 *****)local_34[0];
          if (local_20 < 0x10) {
            pppppuVar6 = local_34;
          }
          FUN_006edb60("StringMap: Couldn\'t find key \'%s\'",pppppuVar6);
        }
        else {
          FUN_004026e0(local_88,0,0xffffffff);
        }
        iVar4 = FUN_0072e3c0();
        local_128 = iVar4;
        if (7 < local_74) {
          FUN_0089120c(local_88[0]);
        }
        local_74 = 7;
        local_78 = 0;
        local_88[0] = local_88[0] & 0xffff0000;
        if (0xf < local_90) {
          FUN_0089120c(local_a4[0]);
        }
        local_8 = local_8 & 0xffffff00;
        local_90 = 0xf;
        local_94 = 0;
        local_a4[0] = local_a4[0] & 0xffffff00;
        if (0xf < local_20) {
          FUN_0089120c(local_34[0]);
        }
        local_20 = 0xf;
        local_24 = 0;
        local_34[0] = (undefined4 ****)((uint)local_34[0] & 0xffffff00);
      }
    }
    piVar5 = (int *)**(int **)(local_124 + 0x14);
    if (piVar5 != *(int **)(local_124 + 0x14)) {
      do {
        if (piVar5[10] != 0) {
          piVar7 = piVar5 + 3;
          iVar4 = FUN_0044df20(0,L"NOT DEFINED",0xb);
          if (iVar4 == 0) {
            if (0xf < (uint)piVar5[8]) {
              piVar7 = (int *)*piVar7;
            }
            FUN_006edb60("StringMap: Not loaded key \'%s\'",piVar7);
          }
        }
        if (*(char *)((int)piVar5 + 0x2d) == '\0') {
          piVar7 = (int *)piVar5[2];
          if (*(char *)((int)piVar7 + 0x2d) == '\0') {
            cVar2 = *(char *)(*piVar7 + 0x2d);
            piVar5 = piVar7;
            piVar7 = (int *)*piVar7;
            while (cVar2 == '\0') {
              cVar2 = *(char *)(*piVar7 + 0x2d);
              piVar5 = piVar7;
              piVar7 = (int *)*piVar7;
            }
          }
          else {
            cVar2 = *(char *)(piVar5[1] + 0x2d);
            piVar1 = (int *)piVar5[1];
            piVar7 = piVar5;
            while ((piVar5 = piVar1, cVar2 == '\0' && (piVar7 == (int *)piVar5[2]))) {
              cVar2 = *(char *)(piVar5[1] + 0x2d);
              piVar1 = (int *)piVar5[1];
              piVar7 = piVar5;
            }
          }
        }
      } while (piVar5 != *(int **)(local_124 + 0x14));
    }
  }
  local_8 = 0xffffffff;
  local_120[0] = TiXmlDocument::vftable;
  if (0xf < local_c0) {
    FUN_0089120c(local_d4);
  }
  local_c0 = 0xf;
  local_c4 = 0;
  local_d4 = local_d4 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

