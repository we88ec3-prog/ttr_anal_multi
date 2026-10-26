
/* WARNING: Removing unreachable block (ram,0x00526762) */
/* WARNING: Removing unreachable block (ram,0x00526767) */
/* WARNING: Removing unreachable block (ram,0x005267ee) */

void FUN_00526200(undefined2 *param_1,undefined4 param_2)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  ushort ****ppppuVar7;
  ushort ****ppppuVar8;
  ushort ****ppppuVar9;
  ushort *puVar10;
  uint in_stack_0000001c;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b4;
  int local_b0;
  int local_ac;
  undefined1 local_a8 [28];
  undefined1 local_8c [12];
  undefined1 local_80 [16];
  undefined4 local_70;
  uint local_5c;
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  ushort ***local_38 [4];
  int local_28;
  uint local_24;
  undefined4 local_1c;
  undefined2 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b087;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  local_38[0] = (ushort ***)((uint)local_38[0] & 0xffff0000);
  local_24 = 7;
  local_28 = 0;
  FUN_004026e0(&param_2,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar4 = FUN_00466df0(local_38,&DAT_00c059b8,2);
  while (iVar4 != -1) {
    FUN_00402400(iVar4,2);
    iVar4 = FUN_00466df0(local_38,&DAT_00c059b8,2);
  }
  psVar5 = (short *)&local_1c;
  local_1c = 0xa000d;
  local_18 = 0;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  iVar6 = (int)psVar5 - ((int)&local_1c + 2) >> 1;
  iVar4 = FUN_00466df0(local_38,&local_1c,iVar6);
  while (iVar4 != -1) {
    FUN_00402400(iVar4,2);
    iVar4 = FUN_00466df0(local_38,&local_1c,iVar6);
  }
  local_1c = 10;
  iVar4 = FUN_00466df0(local_38,&local_1c,1);
  if (iVar4 != -1) {
    local_1c = 10;
    do {
      FUN_00402400(iVar4,1);
      if ((local_28 != 0) && (local_ac = local_28, local_28 != 0)) {
        ppppuVar8 = (ushort ****)local_38[0];
        if (local_24 < 8) {
          ppppuVar8 = local_38;
        }
        for (; ppppuVar7 = ppppuVar8, iVar4 = local_ac, local_ac != 0;
            local_ac = local_ac + (-1 - (iVar4 >> 1))) {
          while (*(ushort *)ppppuVar7 != 10) {
            ppppuVar7 = (ushort ****)((int)ppppuVar7 + 2);
            iVar4 = iVar4 + -1;
            if (iVar4 == 0) goto LAB_00526386;
          }
          if (ppppuVar7 == (ushort ****)0x0) break;
          iVar4 = 1;
          puVar10 = (ushort *)&local_1c;
          ppppuVar9 = ppppuVar7;
          while (*(ushort *)ppppuVar9 == *puVar10) {
            ppppuVar9 = (ushort ****)((int)ppppuVar9 + 2);
            puVar10 = puVar10 + 1;
            iVar4 = iVar4 + -1;
            if (iVar4 == 0) goto LAB_00526537;
          }
          if ((-(uint)(*(ushort *)ppppuVar9 < *puVar10) & 0xfffffffe) == 0xffffffff) {
LAB_00526537:
            ppppuVar8 = (ushort ****)local_38[0];
            if (local_24 < 8) {
              ppppuVar8 = local_38;
            }
            iVar4 = (int)ppppuVar7 - (int)ppppuVar8 >> 1;
            goto LAB_00526389;
          }
          iVar4 = (int)ppppuVar7 - (int)ppppuVar8;
          ppppuVar8 = (ushort ****)((int)ppppuVar7 + 2);
        }
      }
LAB_00526386:
      iVar4 = -1;
LAB_00526389:
    } while (iVar4 != -1);
  }
  iVar4 = 0;
  local_40 = 7;
  local_44 = 0;
  local_54 = (uint)local_54._2_2_ << 0x10;
  local_ac = 0;
  local_bc = 0;
  local_b4 = 0;
  local_8._0_1_ = 5;
  local_1c = local_28;
  if (0 < local_28) {
    local_c4 = 3;
    local_c0 = 8;
    local_b0 = 4;
    do {
      if (local_c0 < local_1c) {
        ppppuVar8 = (ushort ****)local_38[0];
        if (local_24 < 8) {
          ppppuVar8 = local_38;
        }
        if (*(ushort *)((int)ppppuVar8 + iVar4 * 2) != 0x3c) goto LAB_00526579;
        ppppuVar8 = (ushort ****)local_38[0];
        if (local_24 < 8) {
          ppppuVar8 = local_38;
        }
        if (*(ushort *)((int)ppppuVar8 + (iVar4 + 1) * 2) != 0x23) goto LAB_00526579;
        ppppuVar8 = (ushort ****)local_38[0];
        if (local_24 < 8) {
          ppppuVar8 = local_38;
        }
        if (*(ushort *)((int)ppppuVar8 + (iVar4 + 8) * 2) != 0x3e) goto LAB_00526579;
        if ((local_bc != 0) || (local_b4 != 0)) {
          FUN_0052ef90();
        }
        local_bc = local_ac;
        FUN_0043f3e0(local_38);
        uVar3 = local_5c;
        local_b4 = FUN_00528730();
        local_b0 = local_b0 + 0x10;
        local_c0 = local_c0 + 8;
        local_c4 = local_c4 + 8;
        iVar4 = iVar4 + 8;
        if (7 < uVar3) {
          FUN_0089120c(local_70);
        }
      }
      else {
LAB_00526579:
        if (local_c4 < local_1c) {
          ppppuVar8 = (ushort ****)local_38[0];
          if (local_24 < 8) {
            ppppuVar8 = local_38;
          }
          if (*(ushort *)((int)ppppuVar8 + iVar4 * 2) == 0x3c) {
            ppppuVar8 = (ushort ****)local_38[0];
            if (local_24 < 8) {
              ppppuVar8 = local_38;
            }
            if (*(ushort *)((int)ppppuVar8 + (iVar4 + 3) * 2) == 0x3e) {
              ppppuVar8 = (ushort ****)local_38[0];
              if (local_24 < 8) {
                ppppuVar8 = local_38;
              }
              uVar2 = *(ushort *)((int)ppppuVar8 + (iVar4 + 1) * 2);
              ppppuVar8 = (ushort ****)local_38[0];
              if (local_24 < 8) {
                ppppuVar8 = local_38;
              }
              sVar1 = *(short *)((int)ppppuVar8 + local_b0);
              if (((uVar2 == 0x62) || (uVar2 == 0x42)) && ((sVar1 == 0x72 || (sVar1 == 0x52)))) {
                if ((local_bc != 0) || (local_b4 != 0)) {
                  FUN_0052ef90();
                  local_bc = 0;
                  local_b4 = 0;
                }
                FUN_00440010(1,10);
                local_ac = local_ac + 1;
              }
              else {
                if ((uVar2 != 0x2f) || (sVar1 != 0x23)) goto LAB_005266d9;
                if ((local_bc != 0) || (local_b4 != 0)) {
                  FUN_0052ef90();
                  local_bc = 0;
                  local_b4 = 0;
                }
              }
              local_c0 = local_c0 + 3;
              local_c4 = local_c4 + 3;
              iVar4 = iVar4 + 3;
              local_b0 = local_b0 + 6;
              goto LAB_005266f2;
            }
          }
        }
LAB_005266d9:
        ppppuVar8 = (ushort ****)local_38[0];
        if (local_24 < 8) {
          ppppuVar8 = local_38;
        }
        FUN_00440010(1,*(ushort *)((int)ppppuVar8 + iVar4 * 2));
      }
LAB_005266f2:
      local_b0 = local_b0 + 2;
      local_c0 = local_c0 + 1;
      local_c4 = local_c4 + 1;
      local_ac = local_ac + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < local_1c);
  }
  FUN_00757200(local_a8);
  local_8._0_1_ = 6;
  FUN_00757f20();
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_004026e0(local_a8,0,0xffffffff);
  local_8._0_1_ = 7;
  FUN_00527300(param_1 + 0xe,local_8c);
  local_8._0_1_ = 8;
  FUN_00527570(param_1 + 0x14,local_80);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_00757640(local_a8);
  if (7 < local_40) {
    FUN_0089120c(local_54);
  }
  local_40 = 7;
  local_44 = 0;
  local_54 = local_54 & 0xffff0000;
  if (7 < local_24) {
    FUN_0089120c(local_38[0]);
  }
  local_24 = 7;
  local_28 = 0;
  local_38[0] = (ushort ***)((uint)local_38[0] & 0xffff0000);
  if (7 < in_stack_0000001c) {
    FUN_0089120c(param_2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

