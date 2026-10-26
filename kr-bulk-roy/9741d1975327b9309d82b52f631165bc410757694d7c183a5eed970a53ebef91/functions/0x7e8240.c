
void FUN_007e8240(undefined4 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  char *pcVar7;
  int *piVar8;
  undefined1 auStack_5c [4];
  int *local_58;
  uint local_54 [4];
  undefined4 local_44;
  uint local_40;
  uint local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00914850;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_5c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  param_2[0xfb3] = param_2[0xfb3] + 1;
  local_58 = param_2;
  piVar6 = param_2 + 0xfac;
  piVar8 = piVar6;
  if (*param_2 == 0) {
    piVar5 = piVar6;
    if (0xf < (uint)param_2[0xfb1]) {
      piVar5 = (int *)*piVar6;
    }
    local_40 = 0xf;
    local_44 = 0;
    local_54[0] = local_54[0] & 0xffffff00;
    piVar4 = piVar5;
    do {
      iVar2 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar2 != '\0');
    FUN_00402a70(piVar5,(int)piVar4 - ((int)piVar5 + 1));
    local_c = 0;
    piVar5 = (int *)FUN_007e86e0(local_54);
    local_c = 0xffffffff;
    if (0xf < local_40) {
      FUN_0089120c(local_54[0],uVar3);
    }
    local_40 = 0xf;
    local_44 = 0;
    local_54[0] = local_54[0] & 0xffffff00;
    if (*piVar5 != 0) goto LAB_007e83f3;
    *piVar5 = 1;
    if (0xf < (uint)param_2[0xfb1]) {
      piVar6 = (int *)*piVar6;
      piVar8 = piVar6;
    }
    do {
      iVar2 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 1);
    } while ((char)iVar2 != '\0');
  }
  else {
    piVar5 = piVar6;
    if (0xf < (uint)param_2[0xfb1]) {
      piVar5 = (int *)*piVar6;
    }
    local_24 = 0xf;
    local_28 = 0;
    local_38[0] = local_38[0] & 0xffffff00;
    pcVar7 = (char *)piVar5;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(piVar5,(int)pcVar7 - (int)((int)piVar5 + 1));
    local_c = 1;
    piVar5 = (int *)FUN_007e86e0(local_38);
    local_c = 0xffffffff;
    if (0xf < local_24) {
      FUN_0089120c(local_38[0]);
    }
    local_24 = 0xf;
    local_28 = 0;
    local_38[0] = local_38[0] & 0xffffff00;
    if (*piVar5 != 0) goto LAB_007e83f3;
    *piVar5 = 1;
    if (0xf < (uint)param_2[0xfb1]) {
      piVar6 = (int *)*piVar6;
      piVar8 = piVar6;
    }
    do {
      iVar2 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 1);
    } while ((char)iVar2 != '\0');
  }
  FUN_00402a70(piVar8,(int)piVar6 - ((int)piVar8 + 1));
LAB_007e83f3:
  FUN_007bb350();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_5c);
  return;
}

