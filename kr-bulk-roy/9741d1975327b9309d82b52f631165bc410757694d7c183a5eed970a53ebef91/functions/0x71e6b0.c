
undefined4 * FUN_0071e6b0(undefined4 *param_1,undefined8 *param_2,uint *param_3)

{
  double dVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *puVar6;
  char **ppcVar7;
  undefined1 *in_ECX;
  char *pcVar8;
  undefined1 *puVar9;
  float10 fVar10;
  uint uVar11;
  undefined4 local_84;
  int local_80;
  int local_7c;
  char *local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 local_68 [16];
  undefined1 local_58 [8];
  undefined1 local_50 [16];
  undefined8 local_40;
  char *local_38;
  uint local_34;
  undefined4 local_30 [2];
  undefined8 local_28;
  undefined8 local_20;
  char *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f258;
  local_10 = ExceptionList;
  switch(*in_ECX) {
  case 0x12:
    *param_1 = *(undefined4 *)(in_ECX + 0x10);
    *(undefined1 *)(param_1 + 1) = 0;
    return param_1;
  default:
    goto switchD_0071e6e9_caseD_13;
  case 0x14:
    if (in_ECX[1] == '\x03') {
      if ((**(int **)(in_ECX + 0x10) != 3) ||
         (puVar9 = (undefined1 *)(*(int **)(in_ECX + 0x10))[2], puVar9 == (undefined1 *)0x0)) {
        puVar9 = &DAT_00bf2375;
      }
      *param_1 = puVar9;
      *(undefined1 *)(param_1 + 1) = 0;
      return param_1;
    }
    goto switchD_0071e6e9_caseD_13;
  case 0x19:
    local_20 = (double)*param_2;
    ExceptionList = &local_10;
    uVar3 = FUN_0071cab0();
    *param_1 = uVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return param_1;
  case 0x1a:
    local_74 = (char *)*param_3;
    local_70 = *(undefined4 *)local_74;
    local_6c = *(undefined4 *)(local_74 + 4);
    local_8 = 0;
    ExceptionList = &local_10;
    FUN_0071efc0(local_30,param_2,param_3);
    FUN_0071cf20(local_30[0]);
    uVar3 = FUN_0071cab0();
    *param_1 = uVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    break;
  case 0x1b:
    local_20 = (double)*param_2;
    ExceptionList = &local_10;
    uVar3 = FUN_0071ccd0();
    *param_1 = uVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return param_1;
  case 0x1c:
    local_74 = (char *)*param_3;
    local_70 = *(undefined4 *)local_74;
    local_6c = *(undefined4 *)(local_74 + 4);
    local_8 = 2;
    ExceptionList = &local_10;
    FUN_0071efc0(local_30,param_2,param_3);
    FUN_0071cf20(local_30[0]);
    uVar3 = FUN_0071ccd0();
    *param_1 = uVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    break;
  case 0x1d:
    local_20 = (double)*param_2;
    ExceptionList = &local_10;
    uVar3 = FUN_0071ca80();
    *param_1 = uVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    ExceptionList = local_10;
    return param_1;
  case 0x1e:
    local_74 = (char *)*param_3;
    local_70 = *(undefined4 *)local_74;
    local_6c = *(undefined4 *)(local_74 + 4);
    local_8 = 1;
    ExceptionList = &local_10;
    FUN_0071efc0(local_30,param_2,param_3);
    FUN_0071cf20(local_30[0]);
    uVar3 = FUN_0071ca80();
    *param_1 = uVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    break;
  case 0x1f:
    ExceptionList = &local_10;
    FUN_0071c150(param_1,*param_3,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    ExceptionList = local_10;
    return param_1;
  case 0x20:
    ExceptionList = &local_10;
    FUN_0071e6b0(param_1,param_2,param_3);
    ExceptionList = local_10;
    return param_1;
  case 0x21:
    ExceptionList = &local_10;
    FUN_0071e420(param_1,param_3);
    ExceptionList = local_10;
    return param_1;
  case 0x24:
    local_74 = (char *)param_3[1];
    local_70 = *(undefined4 *)local_74;
    local_6c = *(undefined4 *)(local_74 + 4);
    local_8 = 3;
    local_14 = *param_3;
    ExceptionList = &local_10;
    local_18 = local_74;
    FUN_0071e6b0(&local_20,param_2,&local_18);
    FUN_0071e6b0(&local_38,param_2,&local_18);
    pcVar8 = _strstr((char *)local_20,local_38);
    if (pcVar8 == (char *)0x0) {
      local_28 = (double)CONCAT35(local_28._5_3_,0xbf2375);
      ppcVar7 = (char **)&local_28;
    }
    else {
      ppcVar7 = (char **)FUN_0071c000();
    }
    goto LAB_0071ef18;
  case 0x25:
    local_74 = (char *)param_3[1];
    local_70 = *(undefined4 *)local_74;
    local_6c = *(undefined4 *)(local_74 + 4);
    local_8 = 4;
    local_14 = *param_3;
    ExceptionList = &local_10;
    local_18 = local_74;
    FUN_0071e6b0(&local_20,param_2,&local_18);
    FUN_0071e6b0(&local_28,param_2,&local_18);
    pcVar8 = _strstr((char *)local_20,(char *)local_28);
    if (pcVar8 == (char *)0x0) goto LAB_0071ec2d;
    pcVar5 = (char *)local_28;
    do {
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    if (local_20._4_1_ == '\0') {
      local_34 = local_34 & 0xffffff00;
      ppcVar7 = &local_38;
      local_38 = pcVar8 + ((int)pcVar5 - (int)((char *)local_28 + 1));
    }
    else {
      ppcVar7 = (char **)FUN_0071bfa0(local_50,*param_3);
    }
LAB_0071ef18:
    *param_1 = *ppcVar7;
    pcVar8 = ppcVar7[1];
LAB_0071ef22:
    param_1[1] = pcVar8;
    break;
  case 0x26:
    local_74 = (char *)param_3[1];
    local_70 = *(undefined4 *)local_74;
    local_6c = *(undefined4 *)(local_74 + 4);
    local_8 = 5;
    local_34 = *param_3;
    ExceptionList = &local_10;
    local_38 = local_74;
    FUN_0071e6b0(&local_18,param_2,&local_38);
    pcVar8 = local_18 + 1;
    pcVar5 = local_18;
    do {
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    fVar10 = (float10)FUN_0071de00(param_2,param_3);
    fVar10 = (float10)FUN_008ff2e0((double)(fVar10 + (float10)0.5));
    local_40 = (double)fVar10;
    cVar2 = FUN_0071c640((double)fVar10);
    if (cVar2 == '\0') {
      dVar1 = (double)(int)(pcVar5 + (1 - (int)pcVar8));
      if ((int)(pcVar5 + (1 - (int)pcVar8)) < 0) {
        dVar1 = dVar1 + 4294967296.0;
      }
      if (local_40 < dVar1) {
        if (1.0 <= local_40) {
          local_40 = (double)(longlong)ROUND(local_40);
          iVar4 = (int)(char *)local_40;
        }
        else {
          iVar4 = 1;
        }
        if ((char)local_14 == '\0') {
          local_28._0_5_ = ZEXT45(local_18 + iVar4 + -1);
          *param_1 = local_18 + iVar4 + -1;
          param_1[1] = local_28._4_4_;
        }
        else {
          puVar6 = (undefined4 *)FUN_0071bfa0(local_58,*param_3);
          *param_1 = *puVar6;
          param_1[1] = puVar6[1];
        }
        break;
      }
    }
    goto LAB_0071ec2d;
  case 0x27:
    local_74 = (char *)param_3[1];
    local_70 = *(undefined4 *)local_74;
    local_6c = *(undefined4 *)(local_74 + 4);
    local_8 = 6;
    local_34 = *param_3;
    ExceptionList = &local_10;
    local_38 = local_74;
    FUN_0071e6b0(&local_18,param_2,&local_38);
    pcVar8 = local_18 + 1;
    pcVar5 = local_18;
    do {
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    fVar10 = (float10)FUN_0071de00(param_2,param_3);
    fVar10 = (float10)FUN_008ff2e0((double)(fVar10 + (float10)0.5));
    local_28 = (double)fVar10;
    fVar10 = (float10)FUN_0071de00(param_2,param_3);
    fVar10 = (float10)FUN_008ff2e0((double)(fVar10 + (float10)0.5));
    local_20 = (double)(fVar10 + (float10)local_28);
    cVar2 = FUN_0071c640(SUB84(local_28,0),(int)((ulonglong)local_28 >> 0x20));
    if ((cVar2 == '\0') &&
       (cVar2 = FUN_0071c640(SUB84(local_20,0),(int)((ulonglong)local_20 >> 0x20)), cVar2 == '\0'))
    {
      pcVar5 = pcVar5 + (1 - (int)pcVar8);
      dVar1 = (double)(int)pcVar5;
      if ((int)pcVar5 < 0) {
        dVar1 = dVar1 + 4294967296.0;
      }
      if (((local_28 < dVar1) && (local_20 < local_28 == (local_20 == local_28))) &&
         (1.0 <= local_20)) {
        if (1.0 <= local_28) {
          local_40 = (double)(longlong)ROUND(local_28);
          iVar4 = (int)(char *)local_40;
        }
        else {
          iVar4 = 1;
        }
        pcVar8 = pcVar5;
        if (local_20 < dVar1) {
          local_40 = (double)(longlong)ROUND(local_20);
          pcVar8 = (char *)local_40;
        }
        if ((pcVar8 == pcVar5) && ((char)local_14 == '\0')) {
          local_28._0_5_ = ZEXT45(local_18 + iVar4 + -1);
          *param_1 = local_18 + iVar4 + -1;
          param_1[1] = local_28._4_4_;
        }
        else {
          puVar6 = (undefined4 *)FUN_0071c000();
          *param_1 = *puVar6;
          param_1[1] = puVar6[1];
        }
        break;
      }
    }
LAB_0071ec2d:
    *param_1 = &DAT_00bf2375;
    *(undefined1 *)(param_1 + 1) = 0;
    break;
  case 0x2a:
    ExceptionList = &local_10;
    FUN_0071c150(&local_18,*param_3,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    uVar11 = *param_3;
    goto LAB_0071ed10;
  case 0x2b:
    ExceptionList = &local_10;
    FUN_0071e6b0(&local_18,param_2,param_3);
    uVar11 = *param_3;
LAB_0071ed10:
    FUN_0071c0f0(uVar11);
    FUN_0071cd10();
    *param_1 = local_18;
    param_1[1] = local_14;
    ExceptionList = local_10;
    return param_1;
  case 0x2c:
    local_74 = (char *)param_3[1];
    local_70 = *(undefined4 *)local_74;
    local_6c = *(undefined4 *)(local_74 + 4);
    local_8 = 7;
    local_14 = *param_3;
    ExceptionList = &local_10;
    local_18 = local_74;
    FUN_0071e6b0(&local_20,param_2,param_3);
    FUN_0071e6b0(&local_28,param_2,&local_18);
    FUN_0071e6b0(&local_38,param_2,&local_18);
    pcVar8 = (char *)local_28;
    pcVar5 = local_38;
    FUN_0071c0f0(*param_3);
    FUN_0071cd80(pcVar8,pcVar5);
    *param_1 = (char *)local_20;
    pcVar8 = local_20._4_4_;
    goto LAB_0071ef22;
  }
  local_8 = 0xffffffff;
  FUN_0071beb0();
  ExceptionList = local_10;
  return param_1;
switchD_0071e6e9_caseD_13:
  cVar2 = in_ECX[1];
  if (cVar2 != '\x01') {
    if (cVar2 == '\x02') {
      uVar11 = *param_3;
      ExceptionList = &local_10;
      fVar10 = (float10)FUN_0071de00(param_2,param_3);
      FUN_0071c770((double)fVar10,uVar11);
      ExceptionList = local_10;
      return param_1;
    }
    if (cVar2 == '\x04') {
      ExceptionList = &local_10;
      cVar2 = FUN_0071d8f0(param_2,param_3);
      pcVar8 = "true";
      if (cVar2 == '\0') {
        pcVar8 = "false";
      }
      *param_1 = pcVar8;
      *(undefined1 *)(param_1 + 1) = 0;
      ExceptionList = local_10;
      return param_1;
    }
    *param_1 = &DAT_00bf2375;
    *(undefined1 *)(param_1 + 1) = 0;
    return param_1;
  }
  local_74 = (char *)param_3[1];
  local_70 = *(undefined4 *)local_74;
  local_6c = *(undefined4 *)(local_74 + 4);
  local_8 = 8;
  local_40 = (double)CONCAT44(*param_3,local_74);
  ExceptionList = &local_10;
  FUN_0071efc0(&local_84,param_2,&local_40);
  if (local_80 == local_7c) {
    local_38 = "";
    local_34 = local_34 & 0xffffff00;
    ppcVar7 = &local_38;
  }
  else {
    FUN_0071cf20(local_84);
    ppcVar7 = (char **)FUN_0071c150(local_68,*param_3);
  }
  goto LAB_0071ef18;
}

