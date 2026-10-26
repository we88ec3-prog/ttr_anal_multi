
void FUN_007e3860(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 in_ECX;
  double dVar7;
  undefined1 local_124 [12];
  undefined1 local_118 [12];
  undefined1 local_10c [12];
  int local_100;
  float local_fc;
  undefined **local_f8 [19];
  uint local_ac;
  undefined4 local_9c;
  uint local_98;
  uint local_7c;
  undefined4 local_6c;
  uint local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ba29;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_100 = param_1;
  if ((DAT_00fe1df8 & 1) == 0) {
    DAT_00fe1df8 = DAT_00fe1df8 | 1;
    local_8 = 0;
    FUN_00716be0(local_18);
    _atexit((_func_4879 *)&LAB_00bcf1a0);
  }
  local_8 = 0xffffffff;
  iVar2 = FUN_00716740(in_ECX);
  if (iVar2 != 0) {
    FUN_0079c590();
    local_8 = 1;
    FUN_0072ee30(local_f8);
    local_8 = CONCAT31(local_8._1_3_,3);
    if (0xf < local_68) {
      FUN_0089120c(local_7c);
    }
    local_68 = 0xf;
    local_6c = 0;
    local_7c = local_7c & 0xffffff00;
    cVar1 = FUN_0072f110(0);
    if (cVar1 == '\0') {
      local_8 = 0xffffffff;
      local_f8[0] = TiXmlDocument::vftable;
      if (0xf < local_98) {
        FUN_0089120c(local_ac);
      }
      local_98 = 0xf;
      local_9c = 0;
      local_ac = local_ac & 0xffffff00;
      FUN_0072e040();
    }
    else {
      FUN_0072e360();
      iVar2 = FUN_0072e360();
      while (iVar2 != 0) {
        local_24 = 0xf;
        local_28 = 0;
        local_38 = local_38 & 0xffffff00;
        local_60 = 0;
        local_5c = 0;
        local_58 = 0;
        local_54 = 0;
        local_50 = 0;
        local_4c = 0;
        local_48 = 0x3f800000;
        local_44 = 0x3f800000;
        local_40 = 0x3f800000;
        local_3c = 1.0;
        local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
        local_8 = CONCAT31(local_8._1_3_,4);
        iVar2 = FUN_0072e360();
        iVar3 = FUN_007300a0(&DAT_00c0d66c);
        if (iVar3 == 0) {
          pcVar6 = (char *)0x0;
        }
        else if (*(uint *)(iVar3 + 0x44) < 0x10) {
          pcVar6 = (char *)(iVar3 + 0x30);
        }
        else {
          pcVar6 = *(char **)(iVar3 + 0x30);
        }
        pcVar4 = pcVar6;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar6,(int)pcVar4 - (int)(pcVar6 + 1));
        if (iVar2 != 0) {
          FUN_00401fc0(&DAT_00c504d0,1);
          iVar2 = FUN_007300a0(&DAT_00c0d66c);
          if (iVar2 == 0) {
            pcVar6 = (char *)0x0;
          }
          else {
            pcVar6 = (char *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              pcVar6 = *(char **)pcVar6;
            }
          }
          pcVar4 = pcVar6;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          FUN_00401fc0(pcVar6,(int)pcVar4 - (int)(pcVar6 + 1));
        }
        FUN_0072e360();
        puVar5 = (undefined4 *)FUN_007e3f30(local_124);
        local_60 = *puVar5;
        local_5c = puVar5[1];
        local_58 = puVar5[2];
        FUN_0072e360();
        puVar5 = (undefined4 *)FUN_007e3f30(local_10c);
        local_54 = *puVar5;
        local_50 = puVar5[1];
        local_4c = puVar5[2];
        FUN_0072e360();
        puVar5 = (undefined4 *)FUN_007e3f30(local_118);
        local_48 = *puVar5;
        local_44 = puVar5[1];
        local_40 = puVar5[2];
        iVar2 = FUN_007300a0("Speed");
        if (iVar2 == 0) {
LAB_007e3b5c:
          local_fc = 1.0;
        }
        else {
          pcVar6 = (char *)(iVar2 + 0x30);
          if (0xf < *(uint *)(iVar2 + 0x44)) {
            pcVar6 = *(char **)pcVar6;
          }
          if (pcVar6 == (char *)0x0) goto LAB_007e3b5c;
          dVar7 = _atof(pcVar6);
          local_fc = (float)dVar7;
        }
        local_3c = local_fc;
        FUN_007e3d00(&local_60);
        iVar2 = FUN_0072e3c0();
        FUN_007e2130(*(undefined4 *)(local_100 + 0x1c));
        if (0xf < local_24) {
          FUN_0089120c(local_38);
        }
        local_24 = 0xf;
        local_28 = 0;
        local_38 = local_38 & 0xffffff00;
      }
      local_8 = 0xffffffff;
      local_f8[0] = TiXmlDocument::vftable;
      if (0xf < local_98) {
        FUN_0089120c(local_ac);
      }
      local_98 = 0xf;
      local_9c = 0;
      local_ac = local_ac & 0xffffff00;
      FUN_0072e040();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

