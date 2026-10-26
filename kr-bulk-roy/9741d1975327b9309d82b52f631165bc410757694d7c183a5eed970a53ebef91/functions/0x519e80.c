
void FUN_00519e80(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  char *_Str1;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined1 auStack_194 [4];
  int *local_190 [2];
  int local_188;
  undefined1 *local_184;
  int **local_180;
  int **local_17c;
  int **local_178;
  undefined1 local_170 [4];
  undefined4 *local_16c;
  undefined4 local_168;
  undefined1 local_160 [16];
  undefined1 auStack_150 [16];
  undefined4 uStack_140;
  char *local_134;
  undefined1 local_130;
  int local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined **local_114 [3];
  undefined4 local_108;
  int local_104 [4];
  int iStack_f4;
  undefined4 *puStack_f0;
  int aiStack_e4 [4];
  undefined1 auStack_d4 [16];
  undefined4 uStack_c4;
  undefined1 local_c0 [8];
  undefined1 auStack_b8 [16];
  int local_a8;
  undefined **local_98 [17];
  char local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00923c82;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_194;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffe60;
  ExceptionList = &local_14;
  FUN_0072ed80(local_98);
  local_c = 0;
  FUN_0072f110(0);
  if (local_54 == '\0') {
    iVar3 = FUN_0072e2e0("ITEMEXPERTNPC");
    if ((iVar3 != 0) && (local_188 = FUN_0072e360(uVar2), local_188 != 0)) {
      do {
        iVar3 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar3 == 0) {
LAB_0051a013:
          local_190[1] = (int *)0x0;
        }
        else {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 == (undefined4 *)0x0) goto LAB_0051a013;
          local_190[1] = (int *)FUN_008917b4(puVar4);
        }
        local_184 = (undefined1 *)local_190[1];
        local_180 = (int **)0x0;
        local_17c = (int **)0x0;
        local_178 = (int **)0x0;
        local_c._0_1_ = 1;
        local_168 = 0;
        puVar4 = (undefined4 *)FUN_00891268(0x28);
        if (puVar4 == (undefined4 *)0x0) {
          local_134 = (char *)0x0;
          std::exception::exception((exception *)local_114,&local_134);
          local_114[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_114,&DAT_00c857a8);
        }
        *puVar4 = puVar4;
        puVar4[1] = puVar4;
        puVar4[2] = puVar4;
        *(undefined1 *)(puVar4 + 9) = 1;
        *(undefined1 *)((int)puVar4 + 0x25) = 1;
        local_c._0_1_ = 2;
        local_16c = puVar4;
        FUN_00537140(local_160);
        local_c._0_1_ = 3;
        iVar3 = FUN_0072e360();
        while (iVar3 != 0) {
          for (iVar1 = *(int *)(iVar3 + 0x94); iVar1 != iVar3 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)
              ) {
            _Str1 = (char *)(iVar1 + 0x14);
            if (0xf < *(uint *)(iVar1 + 0x28)) {
              _Str1 = *(char **)_Str1;
            }
            iVar5 = __stricmp(_Str1,"ID");
            if (iVar5 == 0) {
              if (iVar1 != 0) {
                puVar4 = (undefined4 *)(iVar1 + 0x30);
                if (0xf < *(uint *)(iVar1 + 0x44)) {
                  puVar4 = (undefined4 *)*puVar4;
                }
                if (puVar4 != (undefined4 *)0x0) {
                  piVar7 = (int *)FUN_008917b4(puVar4);
                  goto LAB_0051a0d6;
                }
              }
              break;
            }
          }
          piVar7 = (int *)0x0;
LAB_0051a0d6:
          local_190[0] = piVar7;
          if ((local_190 < local_17c) && (local_180 <= local_190)) {
            iVar3 = (int)local_190 - (int)local_180;
            if (local_17c == local_178) {
              FUN_006d6240();
            }
            if (local_17c != (int **)0x0) {
              *local_17c = local_180[iVar3 >> 2];
            }
          }
          else {
            if (local_17c == local_178) {
              FUN_006d6240();
            }
            if (local_17c != (int **)0x0) {
              *local_17c = piVar7;
            }
          }
          local_17c = local_17c + 1;
          iVar3 = FUN_0072e3c0();
        }
        if (local_180 != local_17c) {
          local_12c = 0;
          local_128 = 0;
          local_124 = 0;
          local_c._0_1_ = 4;
          local_130 = 1;
          FUN_004738a0(&local_180);
          local_190[0] = (int *)0x0;
          uVar6 = FUN_0051b650();
          local_c = CONCAT31(local_c._1_3_,5);
          FUN_0051bb30(uVar6);
          FUN_0047eb20(local_170,local_c0);
          if (local_a8 != 0) {
            FUN_0089120c(local_a8);
          }
          local_c._0_1_ = 3;
          if (local_12c != 0) {
            FUN_0089120c(local_12c);
          }
        }
        local_108 = local_190[1];
        local_190[1] = local_104;
        FUN_007e8a90(local_104,&local_180);
        local_c._0_1_ = 6;
        FUN_0051aca0(&iStack_f4,local_170);
        local_190[0] = aiStack_e4;
        local_c._0_1_ = 7;
        FUN_0051abd0(local_190[0],local_160);
        local_c._0_1_ = 8;
        FUN_0051ab00(auStack_d4,auStack_150);
        uStack_c4 = uStack_140;
        local_c._0_1_ = 9;
        uVar6 = FUN_0051bc10();
        FUN_0051b750(auStack_b8,uVar6);
        local_190[1] = local_104;
        local_c._0_1_ = 0xb;
        FUN_00537240(aiStack_e4);
        local_190[0] = &iStack_f4;
        local_c._0_1_ = 0xc;
        FUN_00825810(*puStack_f0,puStack_f0);
        FUN_0089120c(puStack_f0);
        local_c._0_1_ = 3;
        if (local_104[0] != 0) {
          FUN_0089120c(local_104[0]);
        }
        FUN_0072e360();
        iVar3 = FUN_0051a570();
        FUN_00538320(iVar3 + 0x20);
        local_c._0_1_ = 0xe;
        FUN_00537240(local_160);
        local_184 = local_170;
        local_c._0_1_ = 0xf;
        FUN_00825810(*local_16c,local_16c);
        FUN_0089120c(local_16c);
        local_c = (uint)local_c._1_3_ << 8;
        if (local_180 != (int **)0x0) {
          FUN_0089120c(local_180);
        }
        local_180 = (int **)0x0;
        local_17c = (int **)0x0;
        local_178 = (int **)0x0;
        local_188 = FUN_0072e3c0();
      } while (local_188 != 0);
      local_188 = 0;
    }
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  else {
    FUN_006edb60(&DAT_00c0e578);
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  local_4c = local_4c & 0xffffff00;
  local_38 = 0xf;
  local_3c = 0;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_194);
  return;
}

