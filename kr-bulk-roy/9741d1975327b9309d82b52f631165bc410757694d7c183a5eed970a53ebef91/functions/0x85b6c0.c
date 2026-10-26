
void FUN_0085b6c0(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *in_ECX;
  byte *pbVar6;
  int in_EDX;
  bool bVar7;
  undefined1 local_1cc [4];
  char *local_1c8;
  undefined1 local_1a0 [4];
  int *local_19c;
  int *local_198;
  undefined4 local_168;
  int local_164;
  int local_160;
  undefined4 local_15c;
  int *local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined1 local_128 [4];
  int local_124;
  int *local_120;
  int local_11c;
  undefined4 *local_118;
  byte local_114 [256];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091811c;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_11c = in_EDX;
  local_118 = in_ECX;
  (**(code **)(**(int **)(in_EDX + 4) + 0x10))(*(int **)(in_EDX + 4),*in_ECX,local_1cc,local_14);
  if (local_1c8 != (char *)0x0) {
    _memset(local_114,0,0xff);
    pcVar4 = local_1c8;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FID_conflict__memcpy(local_114,local_1c8,(int)pcVar4 - (int)(local_1c8 + 1));
    __strupr((char *)local_114);
    local_124 = FUN_00858b10();
    puVar3 = local_118;
    pbVar6 = local_114;
    pcVar4 = "CUSTOMPARAM";
    do {
      bVar2 = *pcVar4;
      bVar7 = bVar2 < *pbVar6;
      if (bVar2 != *pbVar6) {
LAB_0085b7a7:
        iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_0085b7ac;
      }
      if (bVar2 == 0) break;
      bVar2 = pcVar4[1];
      bVar7 = bVar2 < pbVar6[1];
      if (bVar2 != pbVar6[1]) goto LAB_0085b7a7;
      pcVar4 = pcVar4 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar2 != 0);
    iVar5 = 0;
LAB_0085b7ac:
    if (iVar5 == 0) {
      FUN_0085b2e0(in_EDX,local_118);
    }
    else {
      pbVar6 = local_114;
      pcVar4 = "RENDERCOLORTARGET";
      do {
        bVar2 = *pcVar4;
        bVar7 = bVar2 < *pbVar6;
        if (bVar2 != *pbVar6) {
LAB_0085b7f0:
          iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0085b7f5;
        }
        if (bVar2 == 0) break;
        bVar2 = pcVar4[1];
        bVar7 = bVar2 < pbVar6[1];
        if (bVar2 != pbVar6[1]) goto LAB_0085b7f0;
        pcVar4 = pcVar4 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_0085b7f5:
      if (iVar5 == 0) {
        if (local_124 != 0xb) goto LAB_0085b83a;
        local_120 = (int *)0x0;
        (**(code **)(**(int **)(in_EDX + 4) + 0xd4))(*(int **)(in_EDX + 4),*local_118,&local_120);
        if (local_120 != (int *)0x0) {
          (**(code **)(*local_120 + 8))(local_120);
          goto LAB_0085b83a;
        }
        FUN_00864f30();
        local_8 = 0;
        iVar5 = FUN_0085d290(*puVar3);
        if (iVar5 != 0) {
          FUN_0085f590(local_1a0);
          local_8._0_1_ = 1;
          FUN_0085fad0();
          FUN_0085f650(local_11c + 0x30,local_128);
          local_8 = (uint)local_8._1_3_ << 8;
          if (local_19c != (int *)0x0) {
            (**(code **)(*local_19c + 8))(local_19c);
          }
          (**(code **)(**(int **)(local_11c + 4) + 0xd0))
                    (*(int **)(local_11c + 4),*local_118,local_15c);
          local_8 = 0xffffffff;
          FUN_00865720();
          goto LAB_0085b83a;
        }
        local_8 = 0xffffffff;
        FUN_00865720();
      }
      pbVar6 = local_114;
      pcVar4 = "RENDERDEPTHSTENCILTARGET";
      do {
        bVar2 = *pcVar4;
        bVar7 = bVar2 < *pbVar6;
        if (bVar2 != *pbVar6) {
LAB_0085b950:
          iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0085b955;
        }
        if (bVar2 == 0) break;
        bVar2 = pcVar4[1];
        bVar7 = bVar2 < pbVar6[1];
        if (bVar2 != pbVar6[1]) goto LAB_0085b950;
        pcVar4 = pcVar4 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_0085b955:
      if (iVar5 == 0) {
        if (local_124 != 0xb) goto LAB_0085b83a;
        local_130 = 0;
        local_158 = (int *)0x0;
        local_12c = 0;
        local_154 = 0;
        local_150 = 2;
        local_14c = 0;
        local_148 = 0;
        local_144 = 0x4b;
        local_140 = 0;
        local_13c = 0;
        local_134 = 0;
        local_138 = 0;
        local_8 = 2;
        iVar5 = FUN_0085dab0(&local_158);
        if (iVar5 != 0) {
          FUN_0085f5c0(&local_19c);
          local_8._0_1_ = 3;
          FUN_0085fba0();
          FUN_0085f710(local_11c + 0x40,local_128);
          local_8 = CONCAT31(local_8._1_3_,2);
          if (local_198 != (int *)0x0) {
            (**(code **)(*local_198 + 8))(local_198);
          }
          local_8 = 0xffffffff;
          if (local_158 != (int *)0x0) {
            (**(code **)(*local_158 + 8))(local_158);
          }
          goto LAB_0085b83a;
        }
        local_8 = 0xffffffff;
        if (local_158 != (int *)0x0) {
          (**(code **)(*local_158 + 8))(local_158);
        }
      }
      FUN_0085df80();
      iVar5 = FUN_00870f10();
      if (iVar5 != 0) {
        local_168 = *local_118;
        local_164 = local_124;
        local_160 = iVar5;
        FUN_0085df00();
      }
    }
  }
LAB_0085b83a:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

