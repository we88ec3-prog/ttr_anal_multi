
undefined4 FUN_007235f0(int param_1,undefined4 *param_2,int *param_3)

{
  float fVar1;
  int *piVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char cVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 in_ECX;
  undefined4 *puVar11;
  float10 fVar12;
  double dVar13;
  undefined1 local_7c [4];
  int local_78;
  int local_74;
  undefined1 local_6c [4];
  int local_68;
  int local_64;
  int *local_5c;
  char *local_58;
  int local_54;
  undefined4 *local_50;
  undefined4 *local_4c;
  undefined4 local_48;
  undefined1 local_44 [4];
  undefined4 *local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  undefined1 local_34 [8];
  undefined1 local_2c [8];
  double local_24;
  char *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911f88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)(param_1 + 1) == '\x01') {
    puVar9 = (undefined4 *)*param_3;
    local_50 = puVar9;
    if (*(char *)((int)param_2 + 1) == '\x01') {
      local_4c = (undefined4 *)*puVar9;
      local_48 = puVar9[1];
      local_8 = 0;
      local_18 = puVar9;
      FUN_0071efc0(local_7c,in_ECX,param_3);
      FUN_0071efc0(local_6c,in_ECX,param_3);
      param_1 = local_78;
      if (local_78 != local_74) {
        do {
          puVar10 = (undefined4 *)*param_3;
          puVar11 = (undefined4 *)*puVar10;
          local_38 = puVar10[1];
          local_8._0_1_ = 1;
          local_40 = puVar10;
          local_3c = puVar11;
          local_14 = puVar10;
          puVar9 = (undefined4 *)FUN_0071c150(local_2c,puVar10);
          pcVar5 = (char *)*puVar9;
          cVar8 = FUN_0071c8a0();
          if (cVar8 == '\0') {
            fVar1 = NAN;
          }
          else {
            dVar13 = _atof(pcVar5);
            fVar1 = (float)dVar13;
          }
          local_24 = (double)fVar1;
          param_2 = (undefined4 *)local_68;
          if (local_68 != local_64) {
            do {
              piVar2 = (int *)*param_3;
              pcVar5 = (char *)*piVar2;
              local_54 = piVar2[1];
              local_8 = CONCAT31(local_8._1_3_,2);
              local_5c = piVar2;
              local_58 = pcVar5;
              puVar9 = (undefined4 *)FUN_0071c150(local_34,piVar2);
              local_1c = (char *)*puVar9;
              cVar8 = FUN_0071c8a0();
              if (cVar8 == '\0') {
                local_1c = (char *)0x7fc00000;
                dVar13 = NAN;
              }
              else {
                dVar13 = _atof(local_1c);
              }
              local_8._0_1_ = 1;
              pcVar3 = (char *)*piVar2;
              puVar9 = local_3c;
              puVar10 = local_14;
              puVar11 = local_3c;
              if (local_24 < dVar13) {
                while (local_3c = puVar9, local_14 = puVar10, pcVar3 != pcVar5) {
                  pcVar4 = *(char **)pcVar3;
                  (*(code *)PTR_FUN_00d63d4c)(pcVar3);
                  pcVar3 = pcVar4;
                  puVar9 = local_3c;
                  puVar10 = local_14;
                }
                *piVar2 = (int)pcVar5;
                local_8 = (uint)local_8._1_3_ << 8;
                piVar2[1] = local_54;
                puVar11 = (undefined4 *)*puVar10;
                puVar6 = local_4c;
                puVar7 = local_18;
                while (local_4c = puVar6, local_18 = puVar7, puVar11 != puVar9) {
                  puVar6 = (undefined4 *)*puVar11;
                  (*(code *)PTR_FUN_00d63d4c)(puVar11);
                  puVar11 = puVar6;
                  puVar6 = local_4c;
                  puVar7 = local_18;
                }
                *puVar10 = puVar9;
                puVar10[1] = local_38;
                local_8 = 0xffffffff;
                puVar9 = (undefined4 *)*puVar7;
                while (puVar9 != puVar6) {
                  puVar10 = (undefined4 *)*puVar9;
                  (*(code *)PTR_FUN_00d63d4c)(puVar9);
                  puVar9 = puVar10;
                }
                *puVar7 = puVar6;
                puVar7[1] = local_48;
                ExceptionList = local_10;
                return 1;
              }
              while (local_3c = puVar11, local_14 = puVar10, pcVar3 != pcVar5) {
                local_1c = *(char **)pcVar3;
                (*(code *)PTR_FUN_00d63d4c)(pcVar3);
                pcVar3 = local_1c;
                puVar11 = local_3c;
                puVar10 = local_14;
              }
              piVar2[1] = local_54;
              param_2 = (undefined4 *)((int)param_2 + 8);
              *piVar2 = (int)pcVar5;
            } while (param_2 != (undefined4 *)local_64);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          puVar6 = (undefined4 *)*puVar10;
          puVar9 = local_18;
          while (local_18 = puVar9, puVar6 != puVar11) {
            puVar9 = (undefined4 *)*puVar6;
            (*(code *)PTR_FUN_00d63d4c)(puVar6);
            puVar6 = puVar9;
            puVar9 = local_18;
          }
          param_1 = param_1 + 8;
          *puVar10 = puVar11;
          puVar10[1] = local_38;
        } while (param_1 != local_74);
      }
      puVar11 = local_4c;
      local_8 = 0xffffffff;
      puVar10 = (undefined4 *)*puVar9;
      while (puVar10 != puVar11) {
        puVar6 = (undefined4 *)*puVar10;
        (*(code *)PTR_FUN_00d63d4c)(puVar10);
        puVar10 = puVar6;
      }
      puVar9[1] = local_48;
    }
    else {
      local_4c = (undefined4 *)*puVar9;
      local_48 = puVar9[1];
      local_8 = 5;
      FUN_0071efc0(local_44,in_ECX,param_3);
      fVar12 = (float10)FUN_0071de00(in_ECX,param_3);
      local_24 = (double)fVar12;
      param_2 = local_40;
      if (local_40 != local_3c) {
        do {
          local_5c = (int *)*param_3;
          local_58 = (char *)*local_5c;
          local_54 = local_5c[1];
          local_8 = CONCAT31(local_8._1_3_,6);
          puVar10 = (undefined4 *)FUN_0071c150(local_34,local_5c);
          pcVar5 = (char *)*puVar10;
          cVar8 = FUN_0071c8a0();
          if (cVar8 == '\0') {
            dVar13 = NAN;
          }
          else {
            dVar13 = _atof(pcVar5);
          }
          local_8 = CONCAT31(local_8._1_3_,5);
          if (dVar13 < local_24) goto LAB_0072398f;
          FUN_0071beb0();
          param_2 = param_2 + 2;
        } while (param_2 != local_3c);
      }
      puVar11 = local_4c;
      local_8 = 0xffffffff;
      puVar10 = (undefined4 *)*puVar9;
      while (puVar10 != puVar11) {
        puVar6 = (undefined4 *)*puVar10;
        (*(code *)PTR_FUN_00d63d4c)(puVar10);
        puVar10 = puVar6;
      }
      puVar9[1] = local_48;
    }
  }
  else {
    if (*(char *)((int)param_2 + 1) != '\x01') {
      fVar12 = (float10)FUN_0071de00(in_ECX,param_3);
      local_24 = (double)fVar12;
      fVar12 = (float10)FUN_0071de00(in_ECX,param_3);
      if ((float10)local_24 <= fVar12) {
        ExceptionList = local_10;
        return 0;
      }
      ExceptionList = local_10;
      return 1;
    }
    puVar9 = (undefined4 *)*param_3;
    local_4c = (undefined4 *)*puVar9;
    local_48 = puVar9[1];
    local_8 = 3;
    local_50 = puVar9;
    fVar12 = (float10)FUN_0071de00(in_ECX,param_3);
    local_24 = (double)fVar12;
    FUN_0071efc0(local_7c,in_ECX,param_3);
    param_2 = (undefined4 *)local_78;
    if (local_78 != local_74) {
      do {
        local_5c = (int *)*param_3;
        local_58 = (char *)*local_5c;
        local_54 = local_5c[1];
        local_8 = CONCAT31(local_8._1_3_,4);
        puVar10 = (undefined4 *)FUN_0071c150(local_34,local_5c);
        pcVar5 = (char *)*puVar10;
        cVar8 = FUN_0071c8a0();
        if (cVar8 == '\0') {
          dVar13 = NAN;
        }
        else {
          dVar13 = _atof(pcVar5);
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        if (local_24 < dVar13) {
LAB_0072398f:
          FUN_0071beb0();
          local_8 = 0xffffffff;
          FUN_0071beb0();
          ExceptionList = local_10;
          return 1;
        }
        FUN_0071beb0();
        param_2 = (undefined4 *)((int)param_2 + 8);
      } while (param_2 != (undefined4 *)local_74);
    }
    puVar11 = local_4c;
    local_8 = 0xffffffff;
    puVar10 = (undefined4 *)*puVar9;
    while (puVar10 != puVar11) {
      puVar6 = (undefined4 *)*puVar10;
      (*(code *)PTR_FUN_00d63d4c)(puVar10);
      puVar10 = puVar6;
    }
    puVar9[1] = local_48;
  }
  *puVar9 = puVar11;
  ExceptionList = local_10;
  return 0;
}

