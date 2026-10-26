
float10 FUN_0071de00(int param_1,int *param_2)

{
  float fVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined1 *in_ECX;
  undefined1 *puVar6;
  int iVar7;
  bool bVar8;
  float10 fVar9;
  double dVar10;
  undefined1 local_80 [16];
  undefined1 local_70 [4];
  int local_6c;
  int local_68;
  undefined4 *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48 [8];
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  double local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f2c0;
  local_10 = ExceptionList;
  switch(*in_ECX) {
  case 8:
    ExceptionList = &local_10;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    local_18 = (double)fVar9;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    ExceptionList = local_10;
    return fVar9 + (float10)local_18;
  case 9:
    ExceptionList = &local_10;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    local_18 = (double)fVar9;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    ExceptionList = local_10;
    return (float10)local_18 - fVar9;
  case 10:
    ExceptionList = &local_10;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    local_18 = (double)fVar9;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    ExceptionList = local_10;
    return fVar9 * (float10)local_18;
  case 0xb:
    ExceptionList = &local_10;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    local_18 = (double)fVar9;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    ExceptionList = local_10;
    return (float10)local_18 / fVar9;
  case 0xc:
    ExceptionList = &local_10;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    local_18 = (double)fVar9;
    FUN_0071de00(param_1,param_2);
    fVar9 = (float10)FUN_008ff95a();
    ExceptionList = local_10;
    return fVar9;
  case 0xd:
    ExceptionList = &local_10;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    ExceptionList = local_10;
    return -fVar9;
  case 0x13:
    return (float10)*(double *)(in_ECX + 0x10);
  case 0x14:
    if (in_ECX[1] == '\x02') {
      if (**(int **)(in_ECX + 0x10) == 2) {
        return (float10)*(double *)(*(int **)(in_ECX + 0x10) + 2);
      }
      return (float10)NAN;
    }
  default:
    cVar3 = in_ECX[1];
    if (cVar3 == '\x01') {
      local_60 = (undefined4 *)*param_2;
      local_5c = *local_60;
      local_58 = local_60[1];
      local_8 = 7;
      puVar6 = local_48;
    }
    else {
      if (cVar3 != '\x03') {
        if (cVar3 != '\x04') {
          return (float10)0;
        }
        ExceptionList = &local_10;
        cVar3 = FUN_0071d8f0(param_1,param_2);
        ExceptionList = local_10;
        return (float10)(cVar3 != '\0');
      }
      local_60 = (undefined4 *)*param_2;
      local_5c = *local_60;
      local_58 = local_60[1];
      local_8 = 6;
      puVar6 = local_40;
    }
    ExceptionList = &local_10;
    puVar5 = (undefined4 *)FUN_0071e6b0(puVar6,param_1,param_2);
    pcVar2 = (char *)*puVar5;
    cVar3 = FUN_0071c8a0();
    if (cVar3 == '\0') {
      fVar1 = NAN;
    }
    else {
      dVar10 = _atof(pcVar2);
      fVar1 = (float)dVar10;
    }
    local_18 = (double)fVar1;
    goto LAB_0071e37d;
  case 0x15:
    if (-1 < *(int *)(param_1 + 0xc)) {
      return (float10)*(int *)(param_1 + 0xc);
    }
    return (float10)*(int *)(param_1 + 0xc) + (float10)4294967296.0;
  case 0x16:
    if (-1 < *(int *)(param_1 + 8)) {
      return (float10)*(int *)(param_1 + 8);
    }
    return (float10)*(int *)(param_1 + 8) + (float10)4294967296.0;
  case 0x17:
    local_54 = (undefined4 *)*param_2;
    local_50 = *local_54;
    local_4c = local_54[1];
    local_8 = 0;
    ExceptionList = &local_10;
    iVar7 = FUN_0071efc0(local_80,param_1,param_2);
    iVar7 = *(int *)(iVar7 + 8) - *(int *)(iVar7 + 4) >> 3;
    local_18 = (double)iVar7;
    bVar8 = iVar7 < 0;
    break;
  case 0x28:
    local_54 = (undefined4 *)*param_2;
    local_50 = *local_54;
    local_4c = local_54[1];
    local_8 = 1;
    ExceptionList = &local_10;
    puVar5 = (undefined4 *)FUN_0071c150(local_20,local_54,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    pcVar4 = (char *)*puVar5;
    pcVar2 = pcVar4 + 1;
    do {
      cVar3 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar3 != '\0');
    bVar8 = (int)pcVar4 - (int)pcVar2 < 0;
    local_18 = (double)((int)pcVar4 - (int)pcVar2);
    break;
  case 0x29:
    local_54 = (undefined4 *)*param_2;
    local_50 = *local_54;
    local_4c = local_54[1];
    local_8 = 2;
    ExceptionList = &local_10;
    puVar5 = (undefined4 *)FUN_0071e6b0(local_28,param_1,param_2);
    pcVar4 = (char *)*puVar5;
    pcVar2 = pcVar4 + 1;
    do {
      cVar3 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar3 != '\0');
    bVar8 = (int)pcVar4 - (int)pcVar2 < 0;
    local_18 = (double)((int)pcVar4 - (int)pcVar2);
    break;
  case 0x32:
    local_54 = (undefined4 *)*param_2;
    local_50 = *local_54;
    local_4c = local_54[1];
    local_8 = 3;
    ExceptionList = &local_10;
    FUN_0071c150(local_30,local_54,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    fVar9 = (float10)FUN_0071c950();
    local_18 = (double)fVar9;
    goto LAB_0071e37d;
  case 0x33:
    ExceptionList = &local_10;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    ExceptionList = local_10;
    return fVar9;
  case 0x34:
    local_60 = (undefined4 *)*param_2;
    local_5c = *local_60;
    local_58 = local_60[1];
    local_8 = 4;
    local_18 = 0.0;
    ExceptionList = &local_10;
    FUN_0071efc0(local_70,param_1,param_2);
    iVar7 = local_6c;
    if (local_6c != local_68) {
      do {
        local_54 = (undefined4 *)*param_2;
        local_50 = *local_54;
        local_4c = local_54[1];
        local_8 = CONCAT31(local_8._1_3_,5);
        puVar5 = (undefined4 *)FUN_0071c150(local_38);
        pcVar2 = (char *)*puVar5;
        cVar3 = FUN_0071c8a0();
        if (cVar3 == '\0') {
          dVar10 = NAN;
        }
        else {
          dVar10 = _atof(pcVar2);
        }
        local_18 = dVar10 + local_18;
        local_8 = CONCAT31(local_8._1_3_,4);
        FUN_0071beb0();
        iVar7 = iVar7 + 8;
      } while (iVar7 != local_68);
    }
    goto LAB_0071e37d;
  case 0x35:
    ExceptionList = &local_10;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    fVar9 = (float10)FUN_008ff2e0((double)fVar9);
    ExceptionList = local_10;
    return fVar9;
  case 0x36:
    ExceptionList = &local_10;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    fVar9 = (float10)FUN_00892d30((double)fVar9);
    ExceptionList = local_10;
    return fVar9;
  case 0x37:
    ExceptionList = &local_10;
    fVar9 = (float10)FUN_0071de00(param_1,param_2);
    fVar9 = (float10)FUN_0071ca30((double)fVar9);
    ExceptionList = local_10;
    return fVar9;
  }
  if (bVar8) {
    local_18 = local_18 + 4294967296.0;
  }
LAB_0071e37d:
  local_8 = 0xffffffff;
  FUN_0071beb0();
  ExceptionList = local_10;
  return (float10)local_18;
}

