
void FUN_00866b80(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *puVar4;
  int in_ECX;
  undefined1 *unaff_EBX;
  int iVar5;
  undefined4 uStack_64;
  undefined4 *puStack_60;
  int *piStack_5c;
  char **ppcStack_58;
  uint uStack_54;
  undefined4 uStack_44;
  char *local_40;
  uint uStack_3c;
  uint local_38;
  void *pvStack_34;
  undefined4 local_28;
  undefined4 local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009203e8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_44;
  uStack_54 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  ppcStack_58 = (char **)param_1;
  piStack_5c = (int *)0x866bc2;
  FUN_008447d0();
  piStack_5c = (int *)(in_ECX + 0x16c);
  local_40 = (char *)0x0;
  if (*piStack_5c != 0) {
    ppcStack_58 = &local_40;
    puStack_60 = (undefined4 *)0x866be8;
    (**(code **)(**(int **)(param_1 + 0x90) + 0x80))();
  }
  local_24 = 0xf;
  local_28 = 0;
  local_38 = local_38 & 0xffffff00;
  pcVar3 = local_40;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  ppcStack_58 = (char **)((int)pcVar3 - (int)(local_40 + 1));
  puStack_60 = (undefined4 *)0x866c1a;
  piStack_5c = (int *)local_40;
  FUN_00402a70();
  ppcStack_58 = (char **)0x0;
  uStack_c = 0;
  uStack_64 = *(undefined4 *)(param_1 + 0x88);
  piStack_5c = (int *)0x4;
  puStack_60 = &uStack_44;
  uStack_44 = local_28;
  FUN_00721910();
  puVar4 = unaff_EBX;
  if (pvStack_34 < 0x10) {
    puVar4 = &stack0xffffffb8;
  }
  if ((puVar4 != (undefined1 *)0x0) && (uStack_54 != 0)) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),puVar4,uStack_54,0);
  }
  local_1c = 0xffffffff;
  if (0xf < pvStack_34) {
    FUN_0089120c(unaff_EBX);
  }
  pvStack_34 = (void *)0xf;
  local_38 = 0;
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),&stack0xffffffb4,4,0);
  iVar2 = *(int *)(in_ECX + 0x188);
  for (iVar5 = *(int *)(in_ECX + 0x184); iVar5 != iVar2; iVar5 = iVar5 + 0x10) {
    FUN_00868160(param_1);
  }
  ExceptionList = pvStack_34;
  __security_check_cookie(uStack_3c ^ (uint)&uStack_64);
  return;
}

