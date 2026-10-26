
void FUN_00579090(LONG param_1,LONG param_2,int param_3)

{
  char cVar1;
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  int *piVar2;
  BOOL BVar3;
  int iVar4;
  int *piVar5;
  char *****pppppcVar6;
  int iVar7;
  int in_ECX;
  undefined1 local_388 [12];
  undefined4 uStack_37c;
  undefined1 auStack_35c [3];
  char local_359;
  int local_358;
  int *piStack_354;
  undefined4 *local_350;
  undefined4 *puStack_34c;
  char ****local_348 [4];
  undefined4 local_338;
  uint local_334;
  RECT local_310;
  uint uStack_300;
  undefined4 uStack_2f0;
  uint uStack_2ec;
  int iStack_2e4;
  int iStack_2e0;
  undefined4 uStack_2dc;
  undefined4 uStack_2d8;
  undefined4 uStack_2cc;
  undefined4 uStack_2c8;
  undefined4 uStack_2c4;
  undefined4 uStack_2c0;
  undefined4 uStack_2bc;
  uint local_2b4;
  undefined4 uStack_2a4;
  uint uStack_2a0;
  uint local_298;
  int local_288;
  uint local_284;
  undefined4 local_27c;
  undefined4 local_278;
  undefined4 local_274;
  undefined4 local_270;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091fd8e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_35c;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x70) == 0) goto LAB_00579b55;
  *(LONG *)(in_ECX + 0xd8) = param_1;
  *(LONG *)(in_ECX + 0xdc) = param_2;
  local_284 = 0xf;
  local_288 = 0;
  local_298 = local_298 & 0xffffff00;
  local_358 = in_ECX;
  FUN_00402a70();
  local_264 = 0;
  local_260 = 0;
  local_25c = 0;
  local_258 = 0;
  local_254 = 0;
  local_27c = 0;
  local_278 = 0;
  local_274 = 0;
  local_270 = 0;
  local_c = 0;
  switch(*(undefined4 *)(in_ECX + 200)) {
  case 1:
    local_350 = (undefined4 *)local_388;
    FUN_00402b70("StartButton");
    FUN_0057e5a0(&local_310);
    uStack_37c = 0x5791b8;
    pt.y = param_2;
    pt.x = param_1;
    BVar3 = PtInRect(&local_310,pt);
    if (BVar3 == 0) {
      FUN_0040b3c0();
      local_c._0_1_ = 8;
      iVar4 = FUN_005731d0();
      local_359 = iVar4 == 3;
      local_c = (uint)local_c._1_3_ << 8;
      FUN_007cf450();
      if (local_359 != '\0') {
        FUN_0040b3c0();
        local_c._0_1_ = 9;
        FUN_00573170();
        local_c = (uint)local_c._1_3_ << 8;
        FUN_007cf450();
      }
    }
    else {
      FUN_0040b3c0();
      local_c._0_1_ = 1;
      iVar4 = FUN_005731d0();
      local_359 = iVar4 == 2;
      local_c._0_1_ = 0;
      FUN_007cf450();
      if (local_359 != '\0') {
        FUN_0040b3c0();
        local_c = CONCAT31(local_c._1_3_,2);
        FUN_0040b3f0();
        piVar5 = (int *)FUN_0080ab00();
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 0x14))();
        }
        local_c._0_1_ = 0;
        FUN_007cf450();
      }
      FUN_0040b3c0();
      local_c._0_1_ = 3;
      FUN_00573170();
      local_c._0_1_ = 0;
      FUN_007cf450();
      if (param_3 == 0) {
        FUN_0040b3c0();
        local_c._0_1_ = 6;
        iVar4 = FUN_005731d0();
        local_359 = iVar4 == 4;
        local_c = (uint)local_c._1_3_ << 8;
        FUN_007cf450();
        if (local_359 != '\0') {
          FUN_0040b3c0();
          local_c._0_1_ = 7;
          FUN_00573170();
          local_c = (uint)local_c._1_3_ << 8;
          FUN_007cf450();
        }
      }
      else {
        FUN_0040b3c0();
        local_c._0_1_ = 4;
        FUN_00573170();
        local_c._0_1_ = 0;
        FUN_007cf450();
        *(undefined4 *)(local_358 + 200) = 2;
        FUN_0040b3c0();
        local_c = CONCAT31(local_c._1_3_,5);
        FUN_0040b3f0();
        piVar5 = (int *)FUN_0080ab00();
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 0x14))();
        }
        local_c = local_c & 0xffffff00;
        FUN_007cf450();
        param_3 = 0;
      }
    }
    break;
  case 2:
  case 3:
    FUN_0040b3c0();
    local_c._0_1_ = 10;
    FUN_00572fd0();
    local_c._0_1_ = 0;
    FUN_007cf450();
    FUN_0040b3c0();
    local_c._0_1_ = 0xb;
    FUN_00573170();
    local_c._0_1_ = 0;
    FUN_007cf450();
    FUN_0040b3c0();
    local_c._0_1_ = 0xc;
    FUN_00573170();
    local_c = (uint)local_c._1_3_ << 8;
    FUN_007cf450();
    break;
  case 5:
  case 6:
  case 7:
    if (*(int *)(in_ECX + 0x6c) == 0) {
      FUN_0040b3c0();
      local_c._0_1_ = 0xe;
      FUN_00572fd0();
      local_c = (uint)local_c._1_3_ << 8;
      FUN_007cf450();
      if (local_288 != 0) {
        local_350 = (undefined4 *)local_388;
        FUN_00402b70("StopButton");
        FUN_0057e5a0(&local_310);
        uStack_37c = 0x579566;
        pt_00.y = param_2;
        pt_00.x = param_1;
        BVar3 = PtInRect(&local_310,pt_00);
        if (BVar3 == 0) {
          FUN_0040b3c0();
          local_c._0_1_ = 0x16;
          iVar4 = FUN_005731d0();
          local_359 = iVar4 == 3;
          local_c = (uint)local_c._1_3_ << 8;
          FUN_007cf450();
          if (local_359 != '\0') {
            FUN_0040b3c0();
            local_c._0_1_ = 0x17;
            FUN_00573170();
            local_c = (uint)local_c._1_3_ << 8;
            FUN_007cf450();
          }
        }
        else {
          FUN_0040b3c0();
          local_c._0_1_ = 0xf;
          iVar4 = FUN_005731d0();
          local_359 = iVar4 == 2;
          local_c._0_1_ = 0;
          FUN_007cf450();
          if (local_359 != '\0') {
            FUN_0040b3c0();
            local_c = CONCAT31(local_c._1_3_,0x10);
            FUN_0040b3f0();
            piVar5 = (int *)FUN_0080ab00();
            if (piVar5 != (int *)0x0) {
              (**(code **)(*piVar5 + 0x14))();
            }
            local_c._0_1_ = 0;
            FUN_007cf450();
          }
          FUN_0040b3c0();
          local_c._0_1_ = 0x11;
          FUN_00573170();
          local_c = (uint)local_c._1_3_ << 8;
          FUN_007cf450();
          if (param_3 == 0) {
            FUN_0040b3c0();
            local_c._0_1_ = 0x14;
            iVar4 = FUN_005731d0();
            local_359 = iVar4 == 4;
            local_c = (uint)local_c._1_3_ << 8;
            FUN_007cf450();
            if (local_359 != '\0') {
              FUN_0040b3c0();
              local_c._0_1_ = 0x15;
              FUN_00573170();
              local_c = (uint)local_c._1_3_ << 8;
              FUN_007cf450();
            }
          }
          else if (*(int *)(local_358 + 0x94) != 0) {
            *(undefined4 *)(local_358 + 0x6c) = 1;
            FUN_0040b3c0();
            local_c = CONCAT31(local_c._1_3_,0x12);
            FUN_0040b3f0();
            piVar5 = (int *)FUN_0080ab00();
            if (piVar5 != (int *)0x0) {
              (**(code **)(*piVar5 + 0x14))();
            }
            local_c = local_c & 0xffffff00;
            FUN_007cf450();
            param_3 = 0;
            FUN_0040b3c0();
            local_c._0_1_ = 0x13;
            FUN_00573170();
            local_c = (uint)local_c._1_3_ << 8;
            FUN_007cf450();
          }
        }
      }
    }
    else {
      FUN_0040b3c0();
      local_c._0_1_ = 0xd;
      FUN_00573170();
      local_c = (uint)local_c._1_3_ << 8;
      FUN_007cf450();
    }
    break;
  case 0xc:
    if (param_3 != 0) {
      *(undefined4 *)(in_ECX + 200) = 10;
      *(undefined4 *)(in_ECX + 0xf4) = 0;
      *(undefined4 *)(in_ECX + 0x70) = 0;
      *(undefined4 *)(in_ECX + 0x74) = 0;
      *(undefined4 *)(in_ECX + 0x8c) = 0;
      *(undefined4 *)(in_ECX + 0x114) = 0;
      FUN_0057e750();
      FUN_0057d540();
    }
  }
  if (*(int *)(local_358 + 200) != 0xc) {
    local_350 = (undefined4 *)local_388;
    local_388[0] = 0;
    FUN_00402a70("HelperButton",0xc);
    FUN_0057e5a0(&local_310);
    uStack_37c = 0x579857;
    pt_01.y = param_2;
    pt_01.x = param_1;
    BVar3 = PtInRect(&local_310,pt_01);
    local_334 = 0xf;
    local_338 = 0;
    local_348[0] = (char ****)((uint)local_348[0] & 0xffffff00);
    if (BVar3 == 0) {
      FUN_0040b310();
      local_c._0_1_ = 0x1f;
      iVar4 = FUN_005731d0();
      local_359 = iVar4 == 3;
      local_c = (uint)local_c._1_3_ << 8;
      if (0xf < local_334) {
        FUN_0089120c();
      }
      if (local_359 != '\0') {
        FUN_0040b3c0();
        local_c = CONCAT31(local_c._1_3_,0x20);
LAB_00579aa5:
        FUN_00573170();
        goto LAB_00579aae;
      }
    }
    else {
      FUN_0040b310();
      local_c._0_1_ = 0x18;
      iVar4 = FUN_005731d0();
      local_359 = iVar4 == 2;
      local_c._0_1_ = 0;
      if (0xf < local_334) {
        FUN_0089120c();
      }
      if (local_359 != '\0') {
        FUN_0040b3c0();
        local_c = CONCAT31(local_c._1_3_,0x19);
        FUN_0040b3f0();
        piVar5 = (int *)FUN_0080ab00();
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 0x14))();
        }
        local_c._0_1_ = 0;
        FUN_007cf450();
      }
      local_334 = 0xf;
      local_338 = 0;
      local_348[0] = (char ****)((uint)local_348[0] & 0xffffff00);
      FUN_0040b310();
      local_c._0_1_ = 0x1a;
      FUN_00573170();
      local_c = (uint)local_c._1_3_ << 8;
      if (0xf < local_334) {
        FUN_0089120c();
      }
      FUN_0040b3c0();
      if (param_3 == 0) {
        local_c._0_1_ = 0x1d;
        iVar4 = FUN_005731d0();
        local_359 = iVar4 == 4;
        local_c = (uint)local_c._1_3_ << 8;
        FUN_007cf450();
        if (local_359 != '\0') {
          FUN_0040b3c0();
          local_c = CONCAT31(local_c._1_3_,0x1e);
          goto LAB_00579aa5;
        }
      }
      else {
        local_c._0_1_ = 0x1b;
        FUN_00573170();
        local_c._0_1_ = 0;
        FUN_007cf450();
        *(uint *)(local_358 + 0x84) = (uint)(*(int *)(local_358 + 0x84) == 0);
        FUN_0040b3c0();
        local_c = CONCAT31(local_c._1_3_,0x1c);
        FUN_0040b3f0();
        piVar5 = (int *)FUN_0080ab00();
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 0x14))();
        }
LAB_00579aae:
        local_c = local_c & 0xffffff00;
        FUN_007cf450();
      }
    }
  }
  iVar4 = local_358;
  if (*(int *)(local_358 + 0x84) != 0) {
    local_334 = 0xf;
    local_338 = 0;
    local_348[0] = (char ****)((uint)local_348[0] & 0xffffff00);
    FUN_0040b310();
    local_c._0_1_ = 0x21;
    FUN_00572fd0();
    local_c = (uint)local_c._1_3_ << 8;
    if (0xf < local_334) {
      FUN_0089120c();
    }
    *(undefined4 *)(iVar4 + 0xcc) = 0;
    piVar5 = *(int **)(iVar4 + 0x11c);
    piStack_354 = (int *)*piVar5;
    if (piStack_354 != piVar5) {
      do {
        puStack_34c = *(undefined4 **)piStack_354[4];
        if (puStack_34c != *(undefined4 **)(piStack_354[4] + 4)) {
          do {
            local_350 = (undefined4 *)*puStack_34c;
            FUN_0057e820();
            local_c._0_1_ = 0x22;
            uStack_2ec = 0xf;
            uStack_2f0 = 0;
            uStack_300 = uStack_300 & 0xffffff00;
            FUN_00402a70();
            uStack_2cc = 0;
            uStack_2c8 = 0;
            uStack_2c4 = 0;
            uStack_2c0 = 0;
            uStack_2bc = 0;
            iStack_2e4 = 0;
            iStack_2e0 = 0;
            uStack_2dc = 0;
            uStack_2d8 = 0;
            local_c._0_1_ = 0x23;
            pppppcVar6 = (char *****)local_348[0];
            if (local_334 < 0x10) {
              pppppcVar6 = local_348;
            }
            uStack_2a0 = 0xf;
            uStack_2a4 = 0;
            local_2b4 = local_2b4 & 0xffffff00;
            do {
              cVar1 = *(char *)pppppcVar6;
              pppppcVar6 = (char *****)((int)pppppcVar6 + 1);
            } while (cVar1 != '\0');
            FUN_0040b310();
            local_c._0_1_ = 0x24;
            FUN_00572fd0();
            local_c = CONCAT31(local_c._1_3_,0x23);
            if (0xf < uStack_2a0) {
              FUN_0089120c();
            }
            iVar4 = FUN_008fed10();
            iStack_2e4 = iVar4;
            iVar7 = FUN_008fed10();
            local_310.left = iVar4;
            local_310.top = iVar7;
            iStack_2e0 = iVar7;
            local_310.right = FUN_008fed10();
            local_310.right = local_310.right + iVar4;
            local_310.bottom = FUN_008fed10();
            local_310.bottom = local_310.bottom + iVar7;
            uStack_37c = 0x579d4f;
            pt_02.y = param_2;
            pt_02.x = param_1;
            BVar3 = PtInRect(&local_310,pt_02);
            if (BVar3 != 0) {
              *(undefined4 *)(local_358 + 0xcc) = *local_350;
              *(undefined4 *)(local_358 + 0x88) = 0;
              if (0xf < uStack_2ec) {
                FUN_0089120c();
              }
              uStack_2ec = 0xf;
              uStack_2f0 = 0;
              uStack_300 = uStack_300 & 0xffffff00;
              if (0xf < local_334) {
                FUN_0089120c();
              }
              local_334 = 0xf;
              local_338 = 0;
              local_348[0] = (char ****)((uint)local_348[0] & 0xffffff00);
              if (local_284 < 0x10) goto LAB_00579b55;
              goto LAB_00579b4d;
            }
            if (0xf < uStack_2ec) {
              FUN_0089120c();
            }
            local_c = local_c & 0xffffff00;
            uStack_2ec = 0xf;
            uStack_2f0 = 0;
            uStack_300 = uStack_300 & 0xffffff00;
            if (0xf < local_334) {
              FUN_0089120c();
            }
            puStack_34c = puStack_34c + 1;
          } while (puStack_34c != *(undefined4 **)(piStack_354[4] + 4));
        }
        if (*(char *)((int)piStack_354 + 0x15) == '\0') {
          piVar5 = (int *)piStack_354[2];
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar5 + 0x15);
            piStack_354 = piVar5;
            piVar5 = (int *)*piVar5;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar5 + 0x15);
              piStack_354 = piVar5;
              piVar5 = (int *)*piVar5;
            }
          }
          else {
            cVar1 = *(char *)(piStack_354[1] + 0x15);
            piVar2 = (int *)piStack_354[1];
            piVar5 = piStack_354;
            while ((piStack_354 = piVar2, cVar1 == '\0' && (piVar5 == (int *)piStack_354[2]))) {
              cVar1 = *(char *)(piStack_354[1] + 0x15);
              piVar2 = (int *)piStack_354[1];
              piVar5 = piStack_354;
            }
          }
        }
      } while (piStack_354 != *(int **)(local_358 + 0x11c));
    }
  }
  if (0xf < local_284) {
LAB_00579b4d:
    FUN_0089120c();
  }
LAB_00579b55:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_35c);
  return;
}

