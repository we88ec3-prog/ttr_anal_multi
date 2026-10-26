
undefined1 FUN_0071d8f0(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  int iVar7;
  byte bVar8;
  undefined1 *in_ECX;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  float10 fVar12;
  undefined1 local_4c [16];
  undefined4 *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [8];
  byte *local_28 [2];
  undefined4 *local_20;
  char *local_1c;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009120d8;
  local_10 = ExceptionList;
  switch(*in_ECX) {
  case 0:
    ExceptionList = &local_10;
    cVar2 = FUN_0071d8f0(param_1,param_2);
    if (cVar2 != '\0') {
      ExceptionList = local_10;
      return true;
    }
    cVar2 = FUN_0071d8f0(param_1,piVar1);
    break;
  case 1:
    ExceptionList = &local_10;
    cVar2 = FUN_0071d8f0(param_1,param_2);
    if (cVar2 == '\0') {
      ExceptionList = local_10;
      return false;
    }
    cVar2 = FUN_0071d8f0(param_1,piVar1);
    break;
  case 2:
    ExceptionList = &local_10;
    uVar4 = FUN_00722c30(*(undefined4 *)(in_ECX + 8),param_2);
    ExceptionList = local_10;
    return uVar4;
  case 3:
    ExceptionList = &local_10;
    uVar4 = FUN_00723110(*(undefined4 *)(in_ECX + 8),param_2);
    ExceptionList = local_10;
    return uVar4;
  case 4:
    ExceptionList = &local_10;
    uVar4 = FUN_007235f0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),param_2);
    ExceptionList = local_10;
    return uVar4;
  case 5:
    ExceptionList = &local_10;
    uVar4 = FUN_007235f0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 4),param_2);
    ExceptionList = local_10;
    return uVar4;
  case 6:
    ExceptionList = &local_10;
    uVar4 = FUN_00723aa0(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),param_2,
                         DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    ExceptionList = local_10;
    return uVar4;
  case 7:
    ExceptionList = &local_10;
    uVar4 = FUN_00723aa0(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 4),param_2,
                         DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    ExceptionList = local_10;
    return uVar4;
  case 0x14:
    if (in_ECX[1] == '\x04') {
      if (**(int **)(in_ECX + 0x10) != 4) {
        return false;
      }
      return (char)(*(int **)(in_ECX + 0x10))[2];
    }
  default:
    cVar2 = in_ECX[1];
    if (cVar2 == '\x01') {
      local_3c = (undefined4 *)*param_2;
      local_38 = *local_3c;
      local_34 = local_3c[1];
      local_8 = 4;
      ExceptionList = &local_10;
      iVar7 = FUN_0071efc0(local_4c,param_1,param_2);
      bVar11 = *(int *)(iVar7 + 4) == *(int *)(iVar7 + 8);
    }
    else {
      if (cVar2 == '\x02') {
        ExceptionList = &local_10;
        fVar12 = (float10)FUN_0071de00(param_1,param_2);
        uVar4 = FUN_0071c6d0((double)fVar12);
        ExceptionList = local_10;
        return uVar4;
      }
      if (cVar2 != '\x03') {
switchD_0071d932_caseD_30:
        ExceptionList = local_10;
        return false;
      }
      local_3c = (undefined4 *)*param_2;
      local_38 = *local_3c;
      local_34 = local_3c[1];
      local_8 = 3;
      ExceptionList = &local_10;
      puVar6 = (undefined4 *)FUN_0071e6b0(local_30,param_1,param_2);
      bVar11 = *(char *)*puVar6 == '\0';
    }
LAB_0071dd60:
    uVar4 = !bVar11;
LAB_0071dd66:
    local_8 = 0xffffffff;
    FUN_0071beb0();
    ExceptionList = local_10;
    return uVar4;
  case 0x22:
    local_3c = (undefined4 *)*param_2;
    local_38 = *local_3c;
    local_34 = local_3c[1];
    local_8 = 0;
    ExceptionList = &local_10;
    FUN_0071e6b0(local_28,param_1,param_2);
    FUN_0071e6b0(&local_1c,param_1,piVar1);
    uVar4 = FUN_0071c130();
    goto LAB_0071dd66;
  case 0x23:
    local_3c = (undefined4 *)*param_2;
    local_38 = *local_3c;
    local_34 = local_3c[1];
    local_8 = 1;
    ExceptionList = &local_10;
    FUN_0071e6b0(&local_1c,param_1,param_2);
    FUN_0071e6b0(local_28,param_1,piVar1);
    pcVar5 = _strstr(local_1c,(char *)local_28[0]);
    bVar11 = pcVar5 == (char *)0x0;
    goto LAB_0071dd60;
  case 0x2d:
    ExceptionList = &local_10;
    uVar4 = FUN_0071d8f0(param_1,param_2);
    ExceptionList = local_10;
    return uVar4;
  case 0x2e:
    ExceptionList = &local_10;
    cVar2 = FUN_0071d8f0(param_1,param_2);
    ExceptionList = local_10;
    return cVar2 == '\0';
  case 0x2f:
    return true;
  case 0x30:
    goto switchD_0071d932_caseD_30;
  case 0x31:
    uVar4 = 0;
    if (param_1[1] == 0) {
      local_20 = (undefined4 *)*param_2;
      local_1c = (char *)*local_20;
      local_18 = local_20[1];
      local_8 = 2;
      ExceptionList = &local_10;
      FUN_0071e6b0(local_28,param_1,param_2);
      puVar6 = param_1;
      if (param_1[1] != 0) {
        param_2 = (int *)0x0;
        puVar6 = &param_2;
      }
      param_2 = (int *)*puVar6;
      while (param_2 != (int *)0x0) {
        FUN_0071baa0();
        if (param_1 != (undefined4 *)0x0) {
          pbVar9 = (byte *)param_1[2];
          if (pbVar9 == (byte *)0x0) {
            pbVar9 = &DAT_00bf2375;
          }
          bVar3 = *local_28[0];
          pbVar10 = pbVar9;
          if (bVar3 == 0) goto LAB_0071dc89;
          goto LAB_0071dc5f;
        }
        puVar6 = (undefined4 *)FUN_0071bb60();
        param_2 = (int *)*puVar6;
      }
LAB_0071dc1f:
      local_8 = 0xffffffff;
      FUN_0071beb0();
    }
    goto switchD_0071d932_caseD_30;
  }
  if (cVar2 != '\0') {
    ExceptionList = local_10;
    return true;
  }
  ExceptionList = local_10;
  return false;
  while( true ) {
    bVar3 = pbVar10[(int)(local_28[0] + (1 - (int)pbVar9))];
    pbVar10 = pbVar10 + 1;
    if (bVar3 == 0) break;
LAB_0071dc5f:
    if ((int)(char)bVar3 - 0x41U < 0x1a) {
      bVar3 = bVar3 | 0x20;
    }
    bVar8 = *pbVar10;
    if ((int)(char)bVar8 - 0x41U < 0x1a) {
      bVar8 = bVar8 | 0x20;
    }
    if (bVar3 != bVar8) goto LAB_0071dc1f;
  }
LAB_0071dc89:
  if ((*pbVar10 == 0) || (*pbVar10 == 0x2d)) {
    uVar4 = 1;
  }
  goto LAB_0071dd66;
}

