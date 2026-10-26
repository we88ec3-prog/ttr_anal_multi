
void FUN_00513560(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  uint *_Src;
  undefined4 uVar9;
  int *_Str1;
  int iStack_13c;
  int iStack_138;
  undefined4 *puStack_134;
  int iStack_130;
  int *local_12c;
  undefined4 uStack_128;
  int iStack_124;
  int local_120;
  undefined4 uStack_11c;
  undefined4 *puStack_118;
  uint auStack_10c [4];
  undefined4 uStack_fc;
  uint uStack_f8;
  uint uStack_f0;
  undefined4 uStack_e0;
  uint uStack_dc;
  uint auStack_d4 [4];
  uint uStack_c4;
  uint uStack_c0;
  int iStack_b8;
  uint auStack_b4 [4];
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00923e42;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_13c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffeb8;
  ExceptionList = &local_14;
  local_120 = param_1;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if ((cVar1 != '\0') && (iVar3 = FUN_0072e2e0("PrologSet"), iVar3 != 0)) {
    piVar4 = (int *)FUN_0072e2e0("Prolog");
joined_r0x0051364a:
    local_12c = (int *)0x0;
    if (piVar4 != (int *)0x0) {
      local_12c = piVar4;
      iVar3 = (**(code **)(*piVar4 + 0x14))();
      if (iVar3 != 0) {
        iVar3 = FUN_007300a0(&DAT_00c071fc);
        if (iVar3 == 0) {
LAB_00513696:
          uStack_128 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_00513696;
          uStack_128 = FUN_008917b4(puVar5);
        }
        puStack_134 = (undefined4 *)FUN_00891268(0x10);
        if (puStack_134 == (undefined4 *)0x0) {
          puStack_134 = (undefined4 *)0x0;
        }
        else {
          *puStack_134 = 0;
          puStack_134[1] = 0;
          puStack_134[2] = 0;
        }
        iStack_124 = 0;
        iStack_13c = FUN_0072e360();
        iVar3 = iStack_13c;
        while (iVar3 != 0) {
          uStack_dc = 7;
          uStack_e0 = 0;
          uStack_f0 = uStack_f0 & 0xffff0000;
          uStack_c0 = 0xf;
          uStack_c4 = 0;
          auStack_d4[0] = auStack_d4[0] & 0xffffff00;
          local_c._1_3_ = (uint3)((uint)local_c >> 8);
          local_c = CONCAT31(local_c._1_3_,1);
          iVar3 = FUN_0072e360();
          iStack_130 = 0;
joined_r0x00513729:
          iStack_138 = iVar3;
          if (iStack_138 != 0) {
            if ((*(int **)(iStack_138 + 0x18) != (int *)0x0) &&
               (iVar3 = (**(code **)(**(int **)(iStack_138 + 0x18) + 0x2c))(), iVar3 != 0)) {
              if (iStack_130 != 0) {
                FUN_00440010(1,10);
              }
              pcVar7 = (char *)(iVar3 + 0x20);
              if (0xf < *(uint *)(iVar3 + 0x34)) {
                pcVar7 = *(char **)pcVar7;
              }
              uStack_f8 = 0xf;
              uStack_fc = 0;
              auStack_10c[0] = auStack_10c[0] & 0xffffff00;
              pcVar6 = pcVar7;
              do {
                cVar1 = *pcVar6;
                pcVar6 = pcVar6 + 1;
              } while (cVar1 != '\0');
              FUN_00402a70(pcVar7,(int)pcVar6 - (int)(pcVar7 + 1));
              local_c._0_1_ = 2;
              FUN_004028b0(auStack_10c);
              local_c._0_1_ = 4;
              if (0xf < uStack_f8) {
                FUN_0089120c(auStack_10c[0]);
              }
              uStack_f8 = 0xf;
              uStack_fc = 0;
              auStack_10c[0] = auStack_10c[0] & 0xffffff00;
              FUN_004041f0(auStack_b4,0,0xffffffff);
              local_c = CONCAT31(local_c._1_3_,1);
              if (7 < uStack_a0) {
                FUN_0089120c(auStack_b4[0]);
              }
            }
            if (iStack_130 == 0) {
              iStack_130 = 1;
            }
            for (iVar3 = *(int *)(iStack_138 + 0x40); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x40)) {
              pcVar7 = (char *)(iVar3 + 0x20);
              if (0xf < *(uint *)(iVar3 + 0x34)) {
                pcVar7 = *(char **)pcVar7;
              }
              iVar8 = __stricmp(pcVar7,"Line");
              if (iVar8 == 0) goto joined_r0x00513729;
            }
            iVar3 = 0;
            goto joined_r0x00513729;
          }
          uStack_f8 = 0xf;
          uStack_fc = 0;
          auStack_10c[0] = auStack_10c[0] & 0xffffff00;
          FUN_00402a70("PicturePath",0xb);
          local_c = CONCAT31(local_c._1_3_,5);
          _Src = (uint *)FUN_0072ecf0(&DAT_00bf2375);
          if (auStack_d4 != _Src) {
            if (0xf < uStack_c0) {
              FUN_0089120c(auStack_d4[0]);
            }
            uStack_c0 = 0xf;
            uStack_c4 = 0;
            auStack_d4[0] = auStack_d4[0] & 0xffffff00;
            if (_Src[5] < 0x10) {
              FID_conflict__memcpy(auStack_d4,_Src,_Src[4] + 1);
            }
            else {
              auStack_d4[0] = *_Src;
              *_Src = 0;
            }
            uStack_c4 = _Src[4];
            uStack_c0 = _Src[5];
            _Src[5] = 0xf;
            _Src[4] = 0;
            *(undefined1 *)_Src = 0;
          }
          if (0xf < uStack_a0) {
            FUN_0089120c(auStack_b4[0]);
          }
          local_c._0_1_ = 1;
          uStack_a0 = 0xf;
          uStack_a4 = 0;
          auStack_b4[0] = auStack_b4[0] & 0xffffff00;
          if (0xf < uStack_f8) {
            FUN_0089120c(auStack_10c[0]);
          }
          iStack_b8 = iStack_124;
          iStack_124 = iStack_124 + 1;
          FUN_00513b30(puStack_134);
          iVar3 = FUN_0072e3c0();
          local_c = (uint)local_c._1_3_ << 8;
          iStack_13c = iVar3;
          if (0xf < uStack_c0) {
            FUN_0089120c(auStack_d4[0]);
          }
          uStack_c0 = 0xf;
          uStack_c4 = 0;
          auStack_d4[0] = auStack_d4[0] & 0xffffff00;
          if (7 < uStack_dc) {
            FUN_0089120c(uStack_f0);
          }
        }
        iVar3 = local_120 + 4;
        uStack_11c = uStack_128;
        puStack_118 = puStack_134;
        uVar9 = FUN_0057ef20();
        FUN_0057e850(iVar3,uVar9);
        piVar4 = local_12c;
      }
      for (piVar4 = (int *)piVar4[0x10]; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[0x10]) {
        _Str1 = piVar4 + 8;
        if (0xf < (uint)piVar4[0xd]) {
          _Str1 = (int *)*_Str1;
        }
        iVar3 = __stricmp((char *)_Str1,"Prolog");
        if (iVar3 == 0) goto joined_r0x0051364a;
      }
      piVar4 = (int *)0x0;
      goto joined_r0x0051364a;
    }
  }
  local_98[0] = TiXmlDocument::vftable;
  local_c = 0xffffffff;
  if (0xf < local_38) {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    FUN_0089120c(local_4c,uVar2);
  }
  local_38 = 0xf;
  local_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&iStack_13c);
  return;
}

