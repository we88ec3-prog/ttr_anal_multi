
undefined4 FUN_00816ea0(char *param_1)

{
  int iVar1;
  char *pcVar2;
  uint in_stack_00000018;
  
  pcVar2 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar2 = (char *)&param_1;
  }
  iVar1 = __stricmp(pcVar2,"Skill_Prepare");
  if (iVar1 == 0) {
    if (0xf < in_stack_00000018) {
      FUN_0089120c(param_1);
    }
    return 1;
  }
  pcVar2 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar2 = (char *)&param_1;
  }
  iVar1 = __stricmp(pcVar2,"On_Skill_Success");
  if (iVar1 == 0) {
    if (0xf < in_stack_00000018) {
      FUN_0089120c(param_1);
    }
    return 2;
  }
  pcVar2 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar2 = (char *)&param_1;
  }
  iVar1 = __stricmp(pcVar2,"Pre_Attack");
  if (iVar1 == 0) {
    if (0xf < in_stack_00000018) {
      FUN_0089120c(param_1);
    }
    return 3;
  }
  pcVar2 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar2 = (char *)&param_1;
  }
  iVar1 = __stricmp(pcVar2,"On_Attack_Failed");
  if (iVar1 == 0) {
    FUN_00402c50();
    return 4;
  }
  pcVar2 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar2 = (char *)&param_1;
  }
  iVar1 = __stricmp(pcVar2,"On_Attack_Evaded");
  if (iVar1 == 0) {
    FUN_00402c50();
    return 5;
  }
  pcVar2 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar2 = (char *)&param_1;
  }
  iVar1 = __stricmp(pcVar2,"On_Attack_Success");
  if (iVar1 == 0) {
    FUN_00402c50();
    return 6;
  }
  pcVar2 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar2 = (char *)&param_1;
  }
  iVar1 = __stricmp(pcVar2,"On_Attacked");
  if (iVar1 == 0) {
    FUN_00402c50();
    return 7;
  }
  pcVar2 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar2 = (char *)&param_1;
  }
  iVar1 = __stricmp(pcVar2,"On_Kill");
  if (iVar1 == 0) {
    FUN_00402c50();
    return 8;
  }
  pcVar2 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar2 = (char *)&param_1;
  }
  iVar1 = __stricmp(pcVar2,"On_Buff_Casts");
  if (iVar1 == 0) {
    FUN_00402c50();
    return 0xb;
  }
  pcVar2 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar2 = (char *)&param_1;
  }
  iVar1 = __stricmp(pcVar2,"On_Buff_Received");
  if (iVar1 == 0) {
    FUN_00402c50();
    return 0xc;
  }
  pcVar2 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar2 = (char *)&param_1;
  }
  iVar1 = __stricmp(pcVar2,"Pre_Heal");
  if (iVar1 == 0) {
    FUN_00402c50();
    return 10;
  }
  FUN_00402c50();
  return 0;
}

