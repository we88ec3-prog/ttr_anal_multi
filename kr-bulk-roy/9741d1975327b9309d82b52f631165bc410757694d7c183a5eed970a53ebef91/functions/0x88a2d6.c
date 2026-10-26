
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0088a2d6(undefined4 param_1,int param_2,undefined4 param_3,char param_4,int param_5)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  short sVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  int *piVar7;
  short ****ppppsVar8;
  short *psVar9;
  short ****ppppsVar10;
  short *psVar11;
  byte ****ppppbVar12;
  int iVar13;
  undefined1 local_1a4 [4];
  undefined1 local_1a0 [4];
  char local_19c [4];
  undefined1 local_198 [4];
  int local_194;
  int local_190;
  undefined4 local_18c;
  int local_188;
  uint local_184;
  int local_180;
  uint local_17c;
  int *local_178;
  char local_172;
  char local_171;
  undefined4 local_170;
  uint local_16c;
  char local_165;
  undefined1 local_164 [28];
  undefined1 local_148 [28];
  undefined1 local_12c [28];
  undefined1 local_110 [28];
  undefined1 local_f4 [28];
  undefined1 local_d8 [28];
  undefined1 local_bc [28];
  undefined1 local_a0 [28];
  byte ***local_84 [4];
  int local_74;
  uint local_70;
  undefined2 local_68 [8];
  int local_58;
  undefined4 local_54;
  undefined4 local_4c;
  uint local_3c;
  uint local_38;
  short ***local_30 [4];
  int local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x194;
  local_8 = 0x88a2e5;
  local_16c = 0;
  local_18c = param_1;
  local_170 = param_3;
  local_194 = param_5;
  if (param_4 == '\0') {
    uVar6 = FUN_004318d0(local_1a0);
    local_8 = 1;
    local_178 = (int *)use_facet<>(uVar6);
  }
  else {
    uVar6 = FUN_004318d0(local_198);
    local_8 = 0;
    local_178 = (int *)use_facet<>(uVar6);
  }
  FUN_004327c0();
  local_3c = 0;
  local_165 = '\0';
  local_171 = '\0';
  local_38 = 7;
  local_4c = (short *)((uint)local_4c._2_2_ << 0x10);
  local_58 = 0;
  local_54 = 7;
  local_68[0] = 0;
  local_8 = 3;
  (**(code **)(*local_178 + 0x24))(local_19c);
  local_184 = 0;
  do {
    piVar7 = local_178;
    if (3 < local_184) break;
    cVar3 = local_19c[local_184];
    if (cVar3 == ' ') {
LAB_0088a3f3:
      if (local_184 != 3) {
        uVar6 = FUN_004318d0(local_1a4);
        local_8._0_1_ = 0xd;
        piVar7 = (int *)FUN_00431790(uVar6);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004327c0();
        while (cVar3 = equal(local_170), cVar3 == '\0') {
          if (*(char *)(param_2 + 4) == '\0') {
            Peek();
          }
          cVar3 = (**(code **)(*piVar7 + 8))(0x48,*(undefined2 *)(param_2 + 6));
          if (cVar3 == '\0') break;
          Inc();
        }
      }
      goto LAB_0088ab81;
    }
    if (cVar3 == '$') {
      curr_symbol(local_30);
      local_8 = CONCAT31(local_8._1_3_,4);
      if (((*(byte *)(param_5 + 0x14) & 8) == 0) && (cVar3 = equal(local_170), cVar3 == '\0')) {
        if (*(char *)(param_2 + 4) == '\0') {
          Peek();
        }
        ppppsVar8 = (short ****)local_30[0];
        if (local_1c < 8) {
          ppppsVar8 = local_30;
        }
        if (*(short *)(param_2 + 6) == *(short *)ppppsVar8) goto LAB_0088aa77;
LAB_0088aab8:
        FUN_00402400(0,0xffffffff);
      }
      else {
LAB_0088aa77:
        if ((local_184 == 3) && (local_3c < 2)) {
          cVar3 = equal(local_170);
          if (cVar3 == '\0') {
            if (*(char *)(param_2 + 4) == '\0') {
              Peek();
            }
            ppppsVar8 = (short ****)local_30[0];
            if (local_1c < 8) {
              ppppsVar8 = local_30;
            }
            if (*(short *)(param_2 + 6) == *(short *)ppppsVar8) goto LAB_0088aac4;
          }
          goto LAB_0088aab8;
        }
      }
LAB_0088aac4:
      ppppsVar8 = (short ****)local_30[0];
      if (local_1c < 8) {
        ppppsVar8 = local_30;
      }
      while (cVar3 = equal(local_170), cVar3 == '\0') {
        ppppsVar10 = (short ****)local_30[0];
        if (local_1c < 8) {
          ppppsVar10 = local_30;
        }
        if (ppppsVar8 == (short ****)((int)ppppsVar10 + local_20 * 2)) break;
        if (*(char *)(param_2 + 4) == '\0') {
          Peek();
        }
        if (*(short *)(param_2 + 6) != *(short *)ppppsVar8) break;
        Inc();
        ppppsVar8 = (short ****)((int)ppppsVar8 + 2);
      }
      ppppsVar10 = (short ****)local_30[0];
      if (local_1c < 8) {
        ppppsVar10 = local_30;
      }
      if (ppppsVar8 != (short ****)((int)ppppsVar10 + local_20 * 2)) {
        local_165 = '\x01';
      }
LAB_0088ab3b:
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_00402a00(1,0);
    }
    else if (cVar3 == '+') {
      cVar3 = equal(local_170);
      if (cVar3 != '\0') goto LAB_0088ab81;
      iVar13 = positive_sign(local_12c);
      local_16c = local_16c | 1;
      local_8 = CONCAT31(local_8._1_3_,5);
      if (*(int *)(iVar13 + 0x10) == 0) {
LAB_0088a85f:
        local_172 = '\0';
      }
      else {
        psVar9 = (short *)positive_sign(local_f4);
        local_16c = local_16c | 2;
        local_8 = 6;
        if (7 < *(uint *)(psVar9 + 10)) {
          psVar9 = *(short **)psVar9;
        }
        if (*(char *)(param_2 + 4) == '\0') {
          Peek();
        }
        local_172 = '\x01';
        if (*psVar9 != *(short *)(param_2 + 6)) goto LAB_0088a85f;
      }
      if ((local_16c & 2) != 0) {
        local_16c = local_16c & 0xfffffffd;
        FUN_00402a00(1,0);
      }
      local_8 = 3;
      if ((local_16c & 1) != 0) {
        local_16c = local_16c & 0xfffffffe;
        FUN_00402a00(1,0);
      }
      if (local_172 != '\0') {
        Inc();
        uVar6 = positive_sign(local_164);
        local_8 = CONCAT31(local_8._1_3_,7);
        FUN_00402800(uVar6);
        goto LAB_0088ab3b;
      }
      iVar13 = negative_sign(local_d8);
      local_16c = local_16c | 4;
      local_8 = CONCAT31(local_8._1_3_,8);
      if (*(int *)(iVar13 + 0x10) == 0) {
LAB_0088a942:
        bVar2 = false;
      }
      else {
        psVar9 = (short *)negative_sign(local_148);
        local_16c = local_16c | 8;
        local_8 = 9;
        if (7 < *(uint *)(psVar9 + 10)) {
          psVar9 = *(short **)psVar9;
        }
        if (*(char *)(param_2 + 4) == '\0') {
          Peek();
        }
        if (*psVar9 != *(short *)(param_2 + 6)) goto LAB_0088a942;
        bVar2 = true;
      }
      if ((local_16c & 8) != 0) {
        local_16c = local_16c & 0xfffffff7;
        FUN_00402a00(1,0);
      }
      local_8 = 3;
      if ((local_16c & 4) != 0) {
        local_16c = local_16c & 0xfffffffb;
        FUN_00402a00(1,0);
      }
      if (bVar2) {
        Inc();
        uVar6 = negative_sign(local_bc);
        local_8._0_1_ = 10;
        FUN_00402800(uVar6);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00402a00(1,0);
LAB_0088aa20:
        local_171 = '\x01';
      }
      else {
        iVar13 = positive_sign(local_110);
        iVar13 = *(int *)(iVar13 + 0x10);
        FUN_00402a00(1,0);
        if (iVar13 != 0) {
          iVar13 = negative_sign(local_a0);
          iVar13 = *(int *)(iVar13 + 0x10);
          FUN_00402a00(1,0);
          if (iVar13 == 0) goto LAB_0088aa20;
        }
      }
    }
    else {
      if (cVar3 != 'v') {
        if (cVar3 == 'x') goto LAB_0088a3f3;
        goto LAB_0088ab81;
      }
      local_180 = 0;
      local_188 = (**(code **)(*local_178 + 0x1c))();
      local_17c = FUN_004303a0(0x30,0,local_190 + 8);
      local_17c = local_17c & 0xffff;
      grouping(local_84);
      local_8._0_1_ = 0xb;
      if ((local_74 == 0) || (sVar4 = (**(code **)(*piVar7 + 8))(), sVar4 == 0)) {
LAB_0088a6a8:
        while (cVar3 = equal(local_170), cVar3 == '\0') {
          if (*(char *)(param_2 + 4) == '\0') {
            Peek();
          }
          if (*(ushort *)(param_2 + 6) < (ushort)local_17c) break;
          if (*(char *)(param_2 + 4) == '\0') {
            Peek();
          }
          if ((local_17c & 0xffff) + 9 < (uint)*(ushort *)(param_2 + 6)) break;
          if (*(char *)(param_2 + 4) == '\0') {
            Peek();
          }
          FUN_00440010(1,*(undefined2 *)(param_2 + 6));
          Inc();
        }
LAB_0088a6b9:
        sVar4 = (**(code **)(*local_178 + 4))();
        cVar3 = equal(local_170);
        if ((cVar3 == '\0') && (sVar4 != 0)) {
          if (*(char *)(param_2 + 4) == '\0') {
            Peek();
          }
          if (*(short *)(param_2 + 6) == sVar4) {
            while( true ) {
              Inc();
              cVar3 = equal(local_170);
              if (cVar3 != '\0') break;
              if (local_188 <= local_180) goto LAB_0088a79e;
              if (*(char *)(param_2 + 4) == '\0') {
                Peek();
              }
              if (*(ushort *)(param_2 + 6) < (ushort)local_17c) break;
              if (*(char *)(param_2 + 4) == '\0') {
                Peek();
              }
              if ((local_17c & 0xffff) + 9 < (uint)*(ushort *)(param_2 + 6)) break;
              if (*(char *)(param_2 + 4) == '\0') {
                Peek();
              }
              FUN_00440010(1,*(undefined2 *)(param_2 + 6));
              local_180 = local_180 + 1;
            }
            if (local_180 < local_188) {
              local_165 = '\x01';
            }
          }
        }
LAB_0088a79e:
        if (local_58 == 0) {
          local_165 = '\x01';
        }
        else if (local_180 < local_188) {
          iVar13 = local_188 - local_180;
          do {
            FUN_00440010(1,local_17c);
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
      }
      else {
        ppppbVar12 = (byte ****)local_84[0];
        if (local_70 < 0x10) {
          ppppbVar12 = local_84;
        }
        if (0x7e < *(byte *)ppppbVar12) goto LAB_0088a6a8;
        iVar13 = 0;
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (short ***)((uint)local_30[0] & 0xffffff00);
        FUN_0046e1b0(1,0);
        local_8._0_1_ = 0xc;
        cVar3 = equal(local_170);
        if (cVar3 == '\0') {
          do {
            if (*(char *)(param_2 + 4) == '\0') {
              Peek();
            }
            if (*(ushort *)(param_2 + 6) < (ushort)local_17c) {
LAB_0088a550:
              ppppsVar8 = (short ****)local_30[0];
              if (local_1c < 0x10) {
                ppppsVar8 = local_30;
              }
              if (*(char *)((int)ppppsVar8 + iVar13) == '\0') break;
              if (*(char *)(param_2 + 4) == '\0') {
                Peek();
              }
              if (*(short *)(param_2 + 6) != sVar4) break;
              FUN_00429630(1,0);
              iVar13 = iVar13 + 1;
            }
            else {
              if (*(char *)(param_2 + 4) == '\0') {
                Peek();
              }
              if ((local_17c & 0xffff) + 9 < (uint)*(ushort *)(param_2 + 6)) goto LAB_0088a550;
              if (*(char *)(param_2 + 4) == '\0') {
                Peek();
              }
              FUN_00440010(1,*(undefined2 *)(param_2 + 6));
              ppppsVar8 = (short ****)local_30[0];
              if (local_1c < 0x10) {
                ppppsVar8 = local_30;
              }
              if (*(char *)((int)ppppsVar8 + iVar13) != '\x7f') {
                ppppsVar8 = (short ****)local_30[0];
                if (local_1c < 0x10) {
                  ppppsVar8 = local_30;
                }
                *(char *)((int)ppppsVar8 + iVar13) = *(char *)((int)ppppsVar8 + iVar13) + '\x01';
              }
            }
            Inc();
            cVar3 = equal(local_170);
          } while (cVar3 == '\0');
          if (iVar13 != 0) {
            ppppsVar8 = (short ****)local_30[0];
            if (local_1c < 0x10) {
              ppppsVar8 = local_30;
            }
            if (*(char *)((int)ppppsVar8 + iVar13) < '\x01') {
              local_165 = '\x01';
            }
            else {
              iVar13 = iVar13 + 1;
            }
          }
        }
        ppppbVar12 = (byte ****)local_84[0];
        if (local_70 < 0x10) {
          ppppbVar12 = local_84;
        }
        if (local_165 == '\0') {
          while ((iVar13 != 0 && (bVar1 = *(byte *)ppppbVar12, bVar1 != 0x7f))) {
            iVar13 = iVar13 + -1;
            if (iVar13 != 0) {
              ppppsVar8 = (short ****)local_30[0];
              if (local_1c < 0x10) {
                ppppsVar8 = local_30;
              }
              if (bVar1 == *(byte *)((int)ppppsVar8 + iVar13)) goto LAB_0088a5f5;
LAB_0088a612:
              local_165 = '\x01';
              goto LAB_0088a619;
            }
LAB_0088a5f5:
            if (iVar13 == 0) {
              ppppsVar8 = (short ****)local_30[0];
              if (local_1c < 0x10) {
                ppppsVar8 = local_30;
              }
              if ((char)bVar1 < *(char *)ppppsVar8) goto LAB_0088a612;
            }
            if ('\0' < (char)*(byte *)((int)ppppbVar12 + 1)) {
              ppppbVar12 = (byte ****)((int)ppppbVar12 + 1);
            }
          }
          local_8._0_1_ = 0xb;
          FUN_00402f30(1,0);
          goto LAB_0088a6b9;
        }
LAB_0088a619:
        FUN_00402f30(1,0);
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_00402f30(1,0);
    }
LAB_0088ab81:
    local_184 = local_184 + 1;
    param_5 = local_194;
  } while (local_165 == '\0');
  if (local_165 == '\0') {
    if (1 < local_3c) {
      psVar9 = local_4c;
      if (local_38 < 8) {
        psVar9 = (short *)&local_4c;
      }
      while( true ) {
        psVar11 = local_4c;
        if (local_38 < 8) {
          psVar11 = (short *)&local_4c;
        }
        psVar9 = psVar9 + 1;
        if ((psVar9 == psVar11 + local_3c) || (cVar3 = equal(local_170), cVar3 != '\0')) break;
        if (*(char *)(param_2 + 4) == '\0') {
          Peek();
        }
        if (*(short *)(param_2 + 6) != *psVar9) break;
        Inc();
      }
      psVar11 = local_4c;
      if (local_38 < 8) {
        psVar11 = (short *)&local_4c;
      }
      if (psVar9 != psVar11 + local_3c) goto LAB_0088ac0f;
    }
    if (local_171 != '\0') {
      uVar5 = FUN_004303a0(0x2d,0,local_190 + 8);
      FUN_004f0b60(0,1,uVar5);
    }
  }
  else {
LAB_0088ac0f:
    FUN_00402400(0,0xffffffff);
  }
  FUN_00402880(local_68);
  FUN_00402a00(1,0);
  FUN_00402a00(1,0);
  FUN_0089dbbc();
  return;
}

