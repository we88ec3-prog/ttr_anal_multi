
/* WARNING: Type propagation algorithm not settling */

void FUN_0056e790(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  char *_Str1;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  short *******pppppppsVar10;
  int iVar11;
  int in_ECX;
  short *******pppppppsVar12;
  char *_Str1_00;
  float10 fVar13;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_108;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 *local_ec;
  int local_e8;
  undefined **local_e4 [6];
  int *local_cc;
  uint local_98;
  undefined4 local_88;
  uint local_84;
  uint local_68;
  undefined4 local_58;
  uint local_54;
  undefined4 local_4c [5];
  uint local_38;
  short *******local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009385a9;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_e8 = in_ECX;
  FUN_0056fb70(local_14);
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  FUN_0072ee30(local_e4);
  local_8 = 0;
  iVar4 = FUN_00714550(param_1);
  if ((iVar4 == 0) || (cVar3 = FUN_0072f110(0), cVar3 == '\0')) {
    FUN_0056e330(local_e8,param_2);
    local_8 = 0xffffffff;
    local_e4[0] = TiXmlDocument::vftable;
    if (0xf < local_84) {
      FUN_0089120c(local_98);
    }
    local_84 = 0xf;
    local_88 = 0;
    local_98 = local_98 & 0xffffff00;
    FUN_0072e040();
    goto LAB_0056ee31;
  }
  bVar2 = false;
  if ((local_cc != (int *)0x0) && (iVar4 = (**(code **)(*local_cc + 0x34))(), iVar4 != 0)) {
    _Str1_00 = (char *)(iVar4 + 0x60);
    _Str1 = _Str1_00;
    if (0xf < *(uint *)(iVar4 + 0x74)) {
      _Str1 = *(char **)_Str1_00;
    }
    iVar5 = __stricmp(_Str1,"utf-8");
    if (iVar5 != 0) {
      if (0xf < *(uint *)(iVar4 + 0x74)) {
        _Str1_00 = *(char **)_Str1_00;
      }
      iVar4 = __stricmp(_Str1_00,"utf8");
      if (iVar4 != 0) goto LAB_0056e895;
    }
    bVar2 = true;
  }
LAB_0056e895:
  piVar6 = (int *)FUN_0072e2e0("Minimap");
  if ((piVar6 == (int *)0x0) || (iVar4 = (**(code **)(*piVar6 + 0x14))(), iVar4 == 0)) {
    local_8 = 0xffffffff;
    FUN_00407fb0();
  }
  else {
    fVar13 = (float10)FUN_0072e690(0);
    *(float *)(local_e8 + 100) = (float)fVar13;
    FUN_007300a0("TextureFile");
    FUN_0056e330(local_e8,0);
    iVar4 = FUN_0072e2e0("StaticMarker");
    while (iVar4 != 0) {
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (short *******)((uint)local_30[0] & 0xffff0000);
      local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
      local_8._0_1_ = 1;
      iVar4 = FUN_0072e360();
      local_ec = (undefined4 *)FUN_0072e360();
      iVar5 = FUN_0072e360();
      if (iVar4 != 0) {
        iVar4 = FUN_007300a0(&DAT_00c06928);
        if (iVar4 == 0) {
LAB_0056e9bf:
          iVar4 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0056e9bf;
          iVar4 = FUN_008917b4(puVar7);
        }
        iVar8 = FUN_007300a0(&DAT_00c0692c);
        if (iVar8 == 0) {
LAB_0056e9fb:
          iVar8 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar8 + 0x30);
          if (0xf < *(uint *)(iVar8 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0056e9fb;
          iVar8 = FUN_008917b4(puVar7);
        }
        FUN_0056f730((int)(float)iVar4,(int)(float)iVar8);
        local_f4 = local_12c;
        local_11c = local_128;
      }
      if (local_ec != (undefined4 *)0x0) {
        iVar4 = FUN_007300a0("Category");
        if (iVar4 == 0) {
LAB_0056ea80:
          local_fc = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0056ea80;
          local_fc = FUN_008917b4(puVar7);
        }
        iVar4 = FUN_007300a0("Variant");
        if (iVar4 != 0) {
          puVar7 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 != (undefined4 *)0x0) {
            local_100 = FUN_008917b4(puVar7);
            goto LAB_0056eaba;
          }
        }
        local_100 = 0;
      }
LAB_0056eaba:
      if (iVar5 != 0) {
        iVar4 = FUN_007300a0(&DAT_00c06928);
        if (iVar4 == 0) {
LAB_0056eaef:
          iVar4 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0056eaef;
          iVar4 = FUN_008917b4(puVar7);
        }
        iVar5 = FUN_007300a0(&DAT_00c0692c);
        if (iVar5 == 0) {
LAB_0056eb2a:
          iVar5 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_0056eb2a;
          iVar5 = FUN_008917b4(puVar7);
        }
        FUN_0056f730((int)(float)iVar4,(int)(float)iVar5);
        local_f0 = local_124;
        local_108 = local_120;
        iVar4 = FUN_007300a0(&DAT_00c0f680);
        if (bVar2) {
          FUN_004ada90(local_4c);
          local_8._0_1_ = 2;
          uVar9 = FUN_00402a50();
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_00402800(uVar9);
          if (7 < local_54) {
            FUN_0089120c(local_68);
          }
          local_8._0_1_ = 1;
          local_54 = 7;
          local_58 = 0;
          local_68 = local_68 & 0xffff0000;
          if (0xf < local_38) {
LAB_0056ec2c:
            local_8._0_1_ = 1;
            FUN_0089120c(local_4c[0]);
          }
        }
        else {
          if (iVar4 == 0) {
            puVar7 = (undefined4 *)0x0;
          }
          else {
            puVar7 = (undefined4 *)(iVar4 + 0x30);
            if (0xf < *(uint *)(iVar4 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
          }
          uVar9 = FUN_0046e270(puVar7);
          local_8._0_1_ = 4;
          FUN_00402800(uVar9);
          local_8._0_1_ = 1;
          if (7 < local_38) goto LAB_0056ec2c;
        }
      }
      puVar7 = (undefined4 *)FUN_00891268(0x48);
      local_8._0_1_ = 5;
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        pppppppsVar12 = local_30[0];
        if (local_1c < 8) {
          pppppppsVar12 = (short *******)local_30;
        }
        *puVar7 = local_fc;
        puVar7[2] = local_100;
        puVar7[4] = local_f4;
        puVar7[5] = local_11c;
        puVar7[7] = local_f0;
        puVar7[8] = local_108;
        puVar7[1] = 0xffffffff;
        *(undefined1 *)(puVar7 + 3) = 1;
        puVar7[6] = 0;
        puVar7[0xe] = 7;
        puVar7[0xd] = 0;
        *(undefined2 *)(puVar7 + 9) = 0;
        pppppppsVar10 = pppppppsVar12;
        do {
          sVar1 = *(short *)pppppppsVar10;
          pppppppsVar10 = (short *******)((int)pppppppsVar10 + 2);
        } while (sVar1 != 0);
        local_ec = puVar7;
        FUN_00402160(pppppppsVar12,(int)pppppppsVar10 - (int)((int)pppppppsVar12 + 2) >> 1);
        puVar7[0x10] = 0;
        puVar7[0x11] = 0;
      }
      iVar8 = local_e8;
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar4 = *(int *)(local_e8 + 0x54);
      local_ec = puVar7;
      iVar11 = FUN_0074d700(iVar4,*(undefined4 *)(iVar4 + 4),&local_ec);
      iVar5 = *(int *)(iVar8 + 0x58);
      if (iVar5 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("list<T> too long");
      }
      *(int *)(iVar8 + 0x58) = iVar5 + 1;
      *(int *)(iVar4 + 4) = iVar11;
      **(int **)(iVar11 + 4) = iVar11;
      iVar4 = FUN_0072e320("StaticMarker");
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      local_1c = 7;
      local_20 = 0;
      local_30[0] = (short *******)((uint)local_30[0] & 0xffff0000);
    }
    local_8 = 0xffffffff;
    FUN_00407fb0();
  }
LAB_0056ee31:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

