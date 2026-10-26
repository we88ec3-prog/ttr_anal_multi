
bool FUN_00723110(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  char *_String;
  undefined4 *puVar3;
  undefined8 uVar4;
  char cVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 in_ECX;
  int in_EDX;
  float10 fVar14;
  double dVar15;
  undefined1 local_78 [4];
  int local_74;
  int local_70;
  undefined1 local_68 [4];
  int local_64;
  int local_60;
  int *local_58;
  undefined4 *local_54;
  int local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  undefined4 local_44;
  undefined1 local_40 [8];
  undefined1 local_38 [4];
  int local_34;
  int local_30 [2];
  undefined8 local_28;
  undefined8 local_20;
  char *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911fe8;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  cVar5 = *(char *)(in_EDX + 1);
  cVar6 = *(char *)(param_1 + 1);
  if (cVar5 == '\x01') {
    cVar5 = cVar6;
    if (cVar6 == '\x01') {
      local_4c = (undefined4 *)*param_2;
      local_48 = (undefined4 *)*local_4c;
      local_20 = (double)CONCAT44(local_4c,(char *)local_20);
      local_44 = local_4c[1];
      local_8 = 1;
      ExceptionList = &local_10;
      FUN_0071efc0(local_78,in_ECX,param_2);
      FUN_0071efc0(local_68,in_ECX,param_2);
      local_14 = local_74;
      iVar8 = local_64;
      iVar13 = local_60;
      if (local_74 != local_70) {
        do {
          param_1 = iVar8;
          if (iVar8 != iVar13) {
            do {
              piVar1 = (int *)*param_2;
              puVar12 = (undefined4 *)*piVar1;
              local_50 = piVar1[1];
              local_8._0_1_ = 2;
              local_58 = piVar1;
              local_54 = puVar12;
              uVar9 = FUN_0071c150(local_30,piVar1);
              local_28 = (double)CONCAT44(uVar9,(char *)local_28);
              puVar10 = (undefined4 *)FUN_0071c150(local_40,*param_2);
              iVar11 = __stricmp((char *)*puVar10,(char *)*local_28._4_4_);
              local_8 = CONCAT31(local_8._1_3_,1);
              puVar10 = (undefined4 *)*piVar1;
              puVar2 = local_48;
              uVar4 = local_20;
              iVar8 = local_64;
              iVar13 = local_60;
              if (iVar11 != 0) {
                while (local_48 = puVar2, local_20 = (double)uVar4, puVar10 != puVar12) {
                  puVar2 = (undefined4 *)*puVar10;
                  (*(code *)PTR_FUN_00d63d4c)(puVar10);
                  puVar10 = puVar2;
                  puVar2 = local_48;
                  uVar4 = local_20;
                }
                local_8 = 0xffffffff;
                local_20._4_4_ = (undefined4 *)((ulonglong)uVar4 >> 0x20);
                puVar10 = local_20._4_4_;
                *piVar1 = (int)puVar12;
                piVar1[1] = local_50;
                puVar12 = (undefined4 *)*local_20._4_4_;
                while (puVar12 != puVar2) {
                  puVar3 = (undefined4 *)*puVar12;
                  (*(code *)PTR_FUN_00d63d4c)(puVar12);
                  puVar12 = puVar3;
                }
                *puVar10 = puVar2;
                puVar10[1] = local_44;
                ExceptionList = local_10;
                return true;
              }
              while (local_64 = iVar8, local_60 = iVar13, puVar10 != puVar12) {
                local_28 = (double)CONCAT44(*puVar10,(char *)local_28);
                (*(code *)PTR_FUN_00d63d4c)(puVar10);
                iVar8 = local_64;
                iVar13 = local_60;
                puVar10 = local_28._4_4_;
              }
              piVar1[1] = local_50;
              *piVar1 = (int)puVar12;
              param_1 = param_1 + 8;
            } while (param_1 != iVar13);
          }
          local_14 = local_14 + 8;
        } while (local_14 != local_70);
      }
      puVar10 = local_48;
      local_8 = 0xffffffff;
      puVar2 = local_20._4_4_;
      puVar12 = (undefined4 *)*local_20._4_4_;
      while (puVar12 != puVar10) {
        puVar3 = (undefined4 *)*puVar12;
        (*(code *)PTR_FUN_00d63d4c)(puVar12);
        puVar12 = puVar3;
      }
      puVar2[1] = local_44;
      *puVar2 = puVar10;
      ExceptionList = local_10;
      return false;
    }
  }
  else if (cVar6 != '\x01') {
    if ((cVar5 != '\x04') && (cVar6 != '\x04')) {
      if ((cVar5 != '\x02') && (cVar6 != '\x02')) {
        if ((cVar5 != '\x03') && (cVar6 != '\x03')) {
          return false;
        }
        local_58 = (int *)*param_2;
        local_54 = (undefined4 *)*local_58;
        local_50 = local_58[1];
        local_8 = 0;
        ExceptionList = &local_10;
        FUN_0071e6b0(&local_20,in_ECX,param_2);
        FUN_0071e6b0(&local_28,in_ECX,param_2);
        iVar8 = __stricmp((char *)local_20,(char *)local_28);
        local_8 = 0xffffffff;
        FUN_0071beb0(uVar7);
        ExceptionList = local_10;
        return iVar8 != 0;
      }
      ExceptionList = &local_10;
      fVar14 = (float10)FUN_0071de00(in_ECX,param_2);
      local_28 = (double)fVar14;
      fVar14 = (float10)FUN_0071de00(in_ECX,param_2);
      if ((float10)local_28 != fVar14) {
        ExceptionList = local_10;
        return true;
      }
      ExceptionList = local_10;
      return false;
    }
    goto LAB_0072323a;
  }
  if (cVar5 != '\x04') {
    if (cVar5 == '\x02') {
      local_4c = (undefined4 *)*param_2;
      local_48 = (undefined4 *)*local_4c;
      local_28 = (double)CONCAT44(local_4c,(char *)local_28);
      local_44 = local_4c[1];
      local_8 = 3;
      ExceptionList = &local_10;
      fVar14 = (float10)FUN_0071de00(in_ECX,param_2);
      local_20 = (double)fVar14;
      FUN_0071efc0(local_78,in_ECX,param_2);
      iVar8 = local_74;
      if (local_74 != local_70) {
        do {
          local_58 = (int *)*param_2;
          local_54 = (undefined4 *)*local_58;
          local_50 = local_58[1];
          local_8 = CONCAT31(local_8._1_3_,4);
          puVar12 = (undefined4 *)FUN_0071c150(local_40,local_58);
          _String = (char *)*puVar12;
          cVar5 = FUN_0071c8a0();
          if (cVar5 == '\0') {
            dVar15 = NAN;
          }
          else {
            dVar15 = _atof(_String);
          }
          local_8 = CONCAT31(local_8._1_3_,3);
          if (local_20 != dVar15) goto LAB_0072350e;
          FUN_0071beb0();
          iVar8 = iVar8 + 8;
        } while (iVar8 != local_70);
      }
      puVar10 = local_48;
      local_8 = 0xffffffff;
      puVar2 = local_28._4_4_;
      puVar12 = (undefined4 *)*local_28._4_4_;
      while (puVar12 != puVar10) {
        puVar3 = (undefined4 *)*puVar12;
        (*(code *)PTR_FUN_00d63d4c)(puVar12);
        puVar12 = puVar3;
      }
      puVar2[1] = local_44;
      *puVar2 = puVar10;
      ExceptionList = local_10;
      return false;
    }
    if (cVar5 == '\x03') {
      local_4c = (undefined4 *)*param_2;
      local_48 = (undefined4 *)*local_4c;
      local_44 = local_4c[1];
      local_8 = 5;
      ExceptionList = &local_10;
      FUN_0071e6b0(&local_18,in_ECX,param_2);
      FUN_0071efc0(local_38,in_ECX,param_2);
      iVar8 = local_34;
      if (local_34 != local_30[0]) {
        do {
          local_58 = (int *)*param_2;
          local_54 = (undefined4 *)*local_58;
          local_50 = local_58[1];
          local_8._0_1_ = 6;
          puVar12 = (undefined4 *)FUN_0071c150(local_40,local_58);
          iVar13 = __stricmp(local_18,(char *)*puVar12);
          local_8 = CONCAT31(local_8._1_3_,5);
          if (iVar13 != 0) {
LAB_0072350e:
            FUN_0071beb0();
            local_8 = 0xffffffff;
            FUN_0071beb0();
            ExceptionList = local_10;
            return true;
          }
          FUN_0071beb0();
          iVar8 = iVar8 + 8;
        } while (iVar8 != local_30[0]);
      }
      local_8 = 0xffffffff;
      FUN_0071beb0();
    }
    ExceptionList = local_10;
    return false;
  }
LAB_0072323a:
  ExceptionList = &local_10;
  cVar5 = FUN_0071d8f0(in_ECX,param_2);
  cVar6 = FUN_0071d8f0(in_ECX,param_2);
  ExceptionList = local_10;
  return cVar6 != cVar5;
}

