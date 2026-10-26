
void FUN_007dd2a0(long param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 ****ppppuVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint *puVar7;
  undefined4 *puVar8;
  char *in_ECX;
  long lVar9;
  float10 fVar10;
  uint *local_17c;
  float local_178;
  float local_174;
  uint *local_170;
  float local_16c;
  int local_168;
  long local_164;
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  undefined4 ***local_124 [4];
  undefined4 local_114;
  uint local_110;
  int local_108 [50];
  undefined1 local_40;
  uint local_3c;
  undefined4 local_2c;
  uint local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009225ed;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_17c;
  ExceptionList = &local_14;
  local_164 = param_1;
  local_108[0] = 0;
  local_108[1] = 0;
  FUN_0071bc20(DAT_00d61f20 ^ (uint)&stack0xfffffe78);
  local_40 = 0;
  local_28 = 0xf;
  local_2c = 0;
  local_3c = local_3c & 0xffffff00;
  local_c = 0;
  local_110 = 0xf;
  local_114 = 0;
  local_124[0] = (undefined4 ***)((uint)local_124[0] & 0xffffff00);
  pcVar2 = in_ECX;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar2 - (int)(in_ECX + 1));
  local_c = CONCAT31(local_c._1_3_,1);
  ppppuVar3 = (undefined4 ****)local_124[0];
  if (local_110 < 0x10) {
    ppppuVar3 = local_124;
  }
  piVar4 = (int *)FUN_00714770(ppppuVar3,&DAT_00bed1e0);
  if (piVar4 == (int *)0x0) {
    cVar1 = '\0';
  }
  else {
    (**(code **)(*piVar4 + 0x38))();
    uVar5 = (**(code **)(*piVar4 + 0x2c))();
    cVar1 = FUN_00499340(uVar5);
    (**(code **)(*piVar4 + 4))();
  }
  local_c = local_c & 0xffffff00;
  if (0xf < local_110) {
    FUN_0089120c(local_124[0]);
  }
  if (cVar1 == '\0') {
    local_c = 0xffffffff;
    if (0xf < local_28) {
      FUN_0089120c(local_3c);
    }
    local_28 = 0xf;
    local_2c = 0;
    local_3c = local_3c & 0xffffff00;
    FUN_0071bc90(local_108);
  }
  else {
    local_174 = (float)local_108[0];
    piVar4 = (int *)FUN_0071ba40("Effect");
    local_17c = (uint *)*piVar4;
    if (local_17c == (uint *)0x0) {
      local_c = 0xffffffff;
      if (0xf < local_28) {
        FUN_0089120c(local_3c);
      }
      local_28 = 0xf;
      local_2c = 0;
      local_3c = local_3c & 0xffffff00;
      FUN_0071bc90(local_108);
    }
    else {
      FUN_00719da0(&local_170);
      fVar10 = (float10)FUN_00719fe0(&local_170,0);
      local_16c = (float)fVar10;
      FUN_0071baa0("Version");
      if ((local_174 != 0.0) && (*(char **)((int)local_174 + 8) != (char *)0x0)) {
        _strtol(*(char **)((int)local_174 + 8),(char **)0x0,10);
      }
      lVar9 = local_164;
      *(float *)(local_164 + 0x48) = local_16c;
      piVar4 = (int *)FUN_0071ba40("EffectCompositeList");
      local_174 = (float)*piVar4;
      if (local_174 == 0.0) {
        local_c = 0xffffffff;
        FUN_00401000();
      }
      else {
        piVar4 = (int *)FUN_0071ba40("Element");
        local_170 = (uint *)*piVar4;
        if (local_170 != (uint *)0x0) {
          local_168 = lVar9 + 0x4c;
          do {
            if ((local_170 == (uint *)0x0) || (local_17c = local_170, (*local_170 & 7) != 1)) {
              local_17c = (uint *)0x0;
            }
            FUN_0071baa0(&DAT_00c0d66c);
            if (local_140 == 0) {
              pcVar2 = (char *)0x0;
            }
            else {
              pcVar2 = *(char **)(local_140 + 8);
              if (pcVar2 == (char *)0x0) {
                pcVar2 = "";
              }
            }
            local_110 = 0xf;
            local_114 = 0;
            local_124[0] = (undefined4 ***)((uint)local_124[0] & 0xffffff00);
            pcVar6 = pcVar2;
            do {
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            FUN_00402a70(pcVar2,(int)pcVar6 - (int)(pcVar2 + 1));
            local_c = CONCAT31(local_c._1_3_,2);
            local_160 = 0.0;
            local_15c = 0.0;
            local_158 = 0.0;
            local_154 = 0.0;
            local_150 = 0.0;
            local_14c = 0.0;
            local_174 = 0.0;
            FUN_0071baa0("Delay");
            if (local_144 != 0) {
              if (*(int *)(local_144 + 8) == 0) {
                local_178 = 0.0;
              }
              else {
                fVar10 = (float10)FUN_00898a3f(*(int *)(local_144 + 8),0);
                local_178 = (float)fVar10;
              }
              local_174 = local_178;
            }
            local_16c = 0.0;
            FUN_0071baa0("Scale");
            if (local_134 != 0) {
              if (*(int *)(local_134 + 8) == 0) {
                local_178 = 0.0;
              }
              else {
                fVar10 = (float10)FUN_00898a3f(*(int *)(local_134 + 8),0);
                local_178 = (float)fVar10;
              }
              local_16c = local_178;
            }
            local_178 = 0.0;
            FUN_0071baa0("FrameSpeedRatio");
            if (local_148 != 0) {
              if (*(int *)(local_148 + 8) == 0) {
                local_178 = 0.0;
              }
              else {
                fVar10 = (float10)FUN_00898a3f(*(int *)(local_148 + 8),0);
                local_178 = (float)fVar10;
              }
            }
            local_164 = 0;
            FUN_0071baa0("isAttach");
            if (local_13c != 0) {
              if (*(char **)(local_13c + 8) == (char *)0x0) {
                local_164 = 0;
              }
              else {
                local_164 = _strtol(*(char **)(local_13c + 8),(char **)0x0,10);
              }
            }
            lVar9 = 0;
            FUN_0071baa0("RepeatCount");
            if (local_138 != 0) {
              if (*(char **)(local_138 + 8) == (char *)0x0) {
                lVar9 = 0;
              }
              else {
                lVar9 = _strtol(*(char **)(local_138 + 8),(char **)0x0,10);
              }
            }
            puVar7 = (uint *)FUN_0071ba40("Rotation");
            puVar7 = (uint *)*puVar7;
            if (puVar7 != (uint *)0x0) {
              local_17c = (uint *)(~-(uint)((*puVar7 & 7) != 1) & (uint)puVar7);
              fVar10 = (float10)FUN_00719fe0(&local_17c,0);
              local_154 = (float)fVar10;
              fVar10 = (float10)FUN_00719fe0(&local_17c,0);
              local_150 = (float)fVar10;
              fVar10 = (float10)FUN_00719fe0(&local_17c,0);
              local_14c = (float)fVar10;
            }
            puVar7 = (uint *)FUN_0071ba40("Position");
            puVar7 = (uint *)*puVar7;
            if (puVar7 != (uint *)0x0) {
              local_17c = (uint *)(~-(uint)((*puVar7 & 7) != 1) & (uint)puVar7);
              fVar10 = (float10)FUN_00719fe0(&local_17c,0);
              local_160 = (float)fVar10;
              fVar10 = (float10)FUN_00719fe0(&local_17c,0);
              local_15c = (float)fVar10;
              fVar10 = (float10)FUN_00719fe0(&local_17c,0);
              local_158 = (float)fVar10;
            }
            local_17c = (uint *)FUN_00891268(0x68);
            local_c._0_1_ = 3;
            if (local_17c == (uint *)0x0) {
              local_174 = 0.0;
            }
            else {
              ppppuVar3 = (undefined4 ****)local_124[0];
              if (local_110 < 0x10) {
                ppppuVar3 = local_124;
              }
              local_174 = (float)FUN_007d6790(ppppuVar3,local_174,local_16c,local_160,local_15c,
                                              local_158,local_154,local_150,local_14c,local_164,
                                              lVar9,local_178);
            }
            local_c._0_1_ = 2;
            FUN_007bb350();
            if ((DAT_00fe1770 & 1) == 0) {
              DAT_00fe1770 = DAT_00fe1770 | 1;
              local_c._0_1_ = 4;
              FUN_007b7da0();
              _atexit((_func_4879 *)&LAB_00bce790);
              local_c._0_1_ = 2;
            }
            FUN_007dc800(DAT_00fe173c);
            local_c = (uint)local_c._1_3_ << 8;
            if (0xf < local_110) {
              FUN_0089120c(local_124[0]);
            }
            local_110 = 0xf;
            local_114 = 0;
            local_124[0] = (undefined4 ***)((uint)local_124[0] & 0xffffff00);
            puVar8 = (undefined4 *)FUN_0071bb00("Element");
            local_170 = (uint *)*puVar8;
          } while (local_170 != (uint *)0x0);
        }
        local_c = 0xffffffff;
        if (0xf < local_28) {
          FUN_0089120c(local_3c);
        }
        local_28 = 0xf;
        local_2c = 0;
        local_3c = local_3c & 0xffffff00;
        FUN_0071bc90(local_108);
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_17c);
  return;
}

