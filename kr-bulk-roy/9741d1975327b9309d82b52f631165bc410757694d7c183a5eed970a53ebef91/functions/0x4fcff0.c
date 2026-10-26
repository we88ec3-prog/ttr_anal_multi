
void FUN_004fcff0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  char *_Str1;
  int iVar7;
  undefined4 *puVar8;
  undefined1 auStack_14c [4];
  int iStack_148;
  uint uStack_144;
  undefined4 uStack_134;
  uint uStack_130;
  uint uStack_128;
  undefined4 uStack_118;
  uint uStack_114;
  uint uStack_10c;
  undefined4 uStack_fc;
  uint uStack_f8;
  undefined2 uStack_f0;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined2 uStack_d4;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_b8;
  undefined2 uStack_b4;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 uStack_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00924489;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_14c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffea8;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if ((((cVar1 != '\0') && (iVar3 = FUN_0072e2e0("SocialActionMessage"), iVar3 != 0)) &&
      (piVar4 = (int *)FUN_0072e360(uVar2), piVar4 != (int *)0x0)) &&
     (iVar3 = (**(code **)(*piVar4 + 0x14))(), iVar3 != 0)) {
    iVar5 = (**(code **)(*piVar4 + 0x14))();
    iVar3 = iVar5;
    while (iStack_148 = iVar3, iVar5 != 0) {
      uStack_dc = 7;
      uStack_c0 = 7;
      uStack_a0 = 7;
      uStack_e0 = 0;
      uStack_f0 = 0;
      uStack_c4 = 0;
      uStack_d4 = 0;
      uStack_a4 = 0;
      uStack_b4 = 0;
      local_c._1_3_ = (undefined3)((uint)local_c >> 8);
      local_c._0_1_ = 1;
      uStack_130 = 0xf;
      uStack_134 = 0;
      uStack_144 = uStack_144 & 0xffffff00;
      FUN_00402a70(&DAT_00bed1d0,2);
      local_c._0_1_ = 2;
      uVar6 = FUN_0072ecf0(&DAT_00bf2375);
      local_c._0_1_ = 3;
      uVar6 = FUN_004028b0(uVar6);
      local_c = CONCAT31(local_c._1_3_,4);
      FUN_00402800(uVar6);
      if (7 < uStack_114) {
        FUN_0089120c(uStack_128);
      }
      uStack_114 = 7;
      uStack_118 = 0;
      uStack_128 = uStack_128 & 0xffff0000;
      if (0xf < uStack_f8) {
        FUN_0089120c(uStack_10c);
      }
      local_c._0_1_ = 1;
      uStack_f8 = 0xf;
      uStack_fc = 0;
      uStack_10c = uStack_10c & 0xffffff00;
      if (0xf < uStack_130) {
        FUN_0089120c(uStack_144);
      }
      uStack_130 = 0xf;
      uStack_134 = 0;
      uStack_144 = uStack_144 & 0xffffff00;
      FUN_00402a70("chatKey",7);
      local_c._0_1_ = 5;
      uVar6 = FUN_0072ecf0(&DAT_00bf2375);
      local_c._0_1_ = 6;
      uVar6 = FUN_004028b0(uVar6);
      local_c = CONCAT31(local_c._1_3_,7);
      FUN_00402800(uVar6);
      if (7 < uStack_f8) {
        FUN_0089120c(uStack_10c);
      }
      uStack_f8 = 7;
      uStack_fc = 0;
      uStack_10c = uStack_10c & 0xffff0000;
      if (0xf < uStack_114) {
        FUN_0089120c(uStack_128);
      }
      local_c = CONCAT31(local_c._1_3_,1);
      uStack_114 = 0xf;
      uStack_118 = 0;
      uStack_128 = uStack_128 & 0xffffff00;
      if (0xf < uStack_130) {
        FUN_0089120c(uStack_144);
      }
      iVar5 = *(int *)(iVar3 + 0x94);
      if (iVar5 != iVar3 + 0x44) {
        do {
          _Str1 = (char *)(iVar5 + 0x14);
          if (0xf < *(uint *)(iVar5 + 0x28)) {
            _Str1 = *(char **)_Str1;
          }
          iVar7 = __stricmp(_Str1,"actionIdx");
          if (iVar7 == 0) {
            if (iVar5 != 0) {
              puVar8 = (undefined4 *)(iVar5 + 0x30);
              if (0xf < *(uint *)(iVar5 + 0x44)) {
                puVar8 = (undefined4 *)*puVar8;
              }
              if (puVar8 != (undefined4 *)0x0) {
                uStack_b8 = FUN_008917b4(puVar8);
                goto LAB_004fd2f4;
              }
            }
            break;
          }
          iVar5 = *(int *)(iVar5 + 0x50);
        } while (iVar5 != iVar3 + 0x44);
      }
      uStack_b8 = 0;
LAB_004fd2f4:
      uStack_130 = 0xf;
      uStack_134 = 0;
      uStack_144 = uStack_144 & 0xffffff00;
      FUN_00402a70("systemMsg",9);
      local_c._0_1_ = 8;
      uVar6 = FUN_0072ecf0(&DAT_00bf2375);
      local_c._0_1_ = 9;
      uVar6 = FUN_004028b0(uVar6);
      local_c = CONCAT31(local_c._1_3_,10);
      FUN_00402800(uVar6);
      if (7 < uStack_f8) {
        FUN_0089120c(uStack_10c);
      }
      uStack_f8 = 7;
      uStack_fc = 0;
      uStack_10c = uStack_10c & 0xffff0000;
      if (0xf < uStack_114) {
        FUN_0089120c(uStack_128);
      }
      local_c = CONCAT31(local_c._1_3_,1);
      uStack_114 = 0xf;
      uStack_118 = 0;
      uStack_128 = uStack_128 & 0xffffff00;
      if (0xf < uStack_130) {
        FUN_0089120c(uStack_144);
      }
      uStack_130 = 0xf;
      uStack_134 = 0;
      uStack_144 = uStack_144 & 0xffffff00;
      FUN_004fd5c0();
      iVar5 = FUN_0072e3c0();
      iStack_148 = iVar5;
      FUN_004c0590();
      iVar3 = iStack_148;
    }
  }
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
  }
  local_38 = 0xf;
  uStack_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_14c);
  return;
}

