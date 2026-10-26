
void FUN_004ce270(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int in_ECX;
  undefined4 extraout_ECX;
  undefined4 uVar8;
  int *piVar9;
  undefined4 ****ppppuVar10;
  undefined1 auStack_94 [3];
  byte local_91;
  int local_90;
  int local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  int local_74;
  undefined4 ***local_70 [5];
  uint local_5c;
  undefined4 ***local_54 [5];
  uint local_40;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00940638;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_94;
  ExceptionList = &local_14;
  local_78 = in_ECX;
  local_7c = FUN_004c88f0(DAT_00d61f20 ^ (uint)&stack0xffffff60);
  if ((*(int *)(in_ECX + 0x424) != 0) &&
     (iVar6 = *(int *)(*(int *)(in_ECX + 0x424) + 0x24), iVar6 != 0)) {
    FUN_007bdf40(iVar6);
  }
  if (((*(int *)(in_ECX + 0x98) != 0) && (iVar6 = *(int *)(in_ECX + 0x9c), iVar6 != 0)) &&
     (*(int *)(in_ECX + 0x370) != 0)) {
    iVar2 = FUN_0040f060();
    local_74 = iVar6;
    FUN_008438c0(&local_74);
    if ((local_90 != *(int *)(iVar2 + 0x1c)) && (iVar6 = *(int *)(local_90 + 0x10), iVar6 != 0)) {
      FUN_004c97f0(&local_88,0x3f800000);
      local_91 = *(byte *)(iVar6 + 0x20);
      iVar2 = -1;
      iVar3 = FUN_004c9580(in_ECX);
      if (local_91 < 4) {
        if (iVar3 == 0x10) {
          iVar2 = FUN_00404ba0();
          iVar2 = (-(uint)(*(int *)(iVar2 + 0x5f50) != *(int *)(in_ECX + 0x9c)) & 0xff99ff01) - 1;
        }
        else if (iVar3 == 0x11) {
          iVar2 = -0xff0094;
        }
        else if (iVar3 == 0x12) {
          iVar2 = -0xffab;
        }
      }
      else {
        iVar2 = -0x5059c;
      }
      puVar4 = (undefined4 *)FUN_00891268(8);
      if (puVar4 != (undefined4 *)0x0) {
        uVar1 = *(ushort *)(iVar6 + 0x18);
        *puVar4 = TextDecorator_TeamRank::vftable;
        puVar4[1] = (uint)uVar1;
      }
      uVar5 = *(undefined4 *)(local_78 + 0x9c);
      FUN_00425330(uVar5,uVar5,local_88,local_84,local_80,iVar2,0xff000000,0);
      uVar5 = FUN_004f6a30(uVar5);
      FUN_004c9b60(uVar5);
      local_90 = 0;
      local_8c = 0;
      if (*(int *)(iVar6 + 0xc) != 0) {
        local_8c = -0x14;
        FUN_00402250(&DAT_00c07ac8);
        local_c = 0;
        uVar5 = *(undefined4 *)(iVar6 + 0xc);
        FUN_00425330(extraout_ECX,uVar5);
        iVar2 = FUN_004f7370(uVar5);
        if (iVar2 != 0) {
          FUN_00404420(local_70);
        }
        FUN_00404420(local_70);
        uVar5 = *(undefined4 *)(iVar6 + 0xc);
        FUN_0048a740(uVar5);
        iVar2 = FUN_006abae0(uVar5);
        puVar4 = (undefined4 *)FUN_00891268(8);
        if (puVar4 != (undefined4 *)0x0) {
          uVar5 = *(undefined4 *)(iVar6 + 0xc);
          *puVar4 = TextDecorator_GuildMark::vftable;
          puVar4[1] = uVar5;
        }
        if (iVar2 == 0) {
          uVar8 = 0xffff8000;
          uVar5 = 0xfffff020;
        }
        else if (iVar2 == 1) {
          uVar8 = 0xff606060;
          uVar5 = 0xffe0e0e0;
        }
        else if (iVar2 == 2) {
          uVar8 = 0xff664b36;
          uVar5 = 0xffcc966a;
        }
        else {
          uVar8 = 0xff000000;
          uVar5 = 0xfff0ffaa;
        }
        ppppuVar10 = (undefined4 ****)local_70[0];
        if (local_5c < 8) {
          ppppuVar10 = local_70;
        }
        FUN_004c9b60(ppppuVar10,local_88,local_84,local_80,uVar5,uVar8,&local_90);
        local_c = 0xffffffff;
        FUN_004fa440();
      }
      FUN_00489e00();
      iVar2 = FUN_00828ad0();
      if (iVar2 != 0) {
        local_8c = local_8c + -0x14;
        piVar9 = (int *)(iVar2 + 4);
        if (7 < *(uint *)(iVar2 + 0x18)) {
          piVar9 = (int *)*piVar9;
        }
        FUN_004c9b60(piVar9,local_88,local_84,local_80,*(undefined4 *)(iVar2 + 0x6c),0xff000000,
                     &local_90);
      }
      iVar2 = FUN_00404ba0();
      in_ECX = local_78;
      if (*(int *)(iVar2 + 0x5f4c) == 0x15) {
        if (*(char *)(iVar6 + 0x29) == '\0') {
          if (*(char *)(iVar6 + 0x28) == '\0') goto LAB_004ce79b;
          local_8c = local_8c + -0x1e;
          uVar5 = 0x32b;
          FUN_00585620(0x32b);
          uVar5 = FUN_00585330(uVar5);
          FUN_00402250(uVar5);
          local_c = 3;
          uVar7 = (uint)*(ushort *)(iVar6 + 0x14);
          FUN_0040f060(uVar7);
          iVar6 = FUN_004dfb00(uVar7);
          if (iVar6 != 0) {
            uVar5 = 0x32b;
            FUN_00585620(0x32b);
            uVar5 = FUN_00585330(uVar5);
            uVar5 = FUN_004cf650(L"{0} ({1}/{2})",uVar5);
            local_c._0_1_ = 4;
            FUN_00402800(uVar5);
            local_c = CONCAT31(local_c._1_3_,3);
            FUN_004fa440();
          }
          puVar4 = (undefined4 *)FUN_00891268(0xc);
          if (puVar4 != (undefined4 *)0x0) {
            *puVar4 = TextDecorator_BackPanel::vftable;
            puVar4[1] = 0xff0000c0;
            puVar4[2] = 0xff000000;
          }
          if (local_40 < 8) {
            local_54[0] = local_54;
          }
          FUN_004c9b60(local_54[0],local_88,local_84,local_80,0xffffffff,0xff0000c0,&local_90);
        }
        else {
          local_8c = local_8c + -0x1e;
          uVar5 = 0x11a;
          FUN_005854b0(0x11a);
          uVar5 = FUN_00585330(uVar5);
          FUN_00402250(uVar5);
          local_c = 1;
          uVar5 = *(undefined4 *)(iVar6 + 0x10);
          FUN_0040f060(uVar5);
          iVar6 = FUN_004dfb30(uVar5);
          if (iVar6 != 0) {
            uVar5 = 0x11a;
            FUN_005854b0(0x11a);
            uVar5 = FUN_00585330(uVar5);
            uVar5 = FUN_004cf650(L"{0} ({1}/{2})",uVar5);
            local_c._0_1_ = 2;
            FUN_00402800(uVar5);
            local_c = CONCAT31(local_c._1_3_,1);
            FUN_004fa440();
          }
          puVar4 = (undefined4 *)FUN_00891268(0xc);
          if (puVar4 != (undefined4 *)0x0) {
            *puVar4 = TextDecorator_BackPanel::vftable;
            puVar4[1] = 0xffc00000;
            puVar4[2] = 0xff000000;
          }
          if (local_5c < 8) {
            local_70[0] = local_70;
          }
          FUN_004c9b60(local_70[0],local_88,local_84,local_80,0xffffffff,0xffc00000,&local_90);
        }
        local_c = 0xffffffff;
        FUN_004fa440();
        in_ECX = local_78;
      }
    }
  }
LAB_004ce79b:
  if (((*(int *)(in_ECX + 0x428) != 0) && (*(int *)(in_ECX + 0x42c) != 0)) &&
     (*(int *)(*(int *)(in_ECX + 0x158) + 0x34) == 0)) {
    (**(code **)(**(int **)(in_ECX + 0x42c) + 8))();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_94);
  return;
}

