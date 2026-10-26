
void FUN_007d59a0(char *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 ****ppppuVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  char *in_ECX;
  long lVar8;
  uint *puVar9;
  int local_140;
  uint *local_13c;
  char local_135;
  uint *local_134;
  undefined4 local_130;
  undefined1 local_6c;
  uint local_68;
  undefined4 local_58;
  uint local_54;
  undefined4 local_4c;
  uint local_38;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092263b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_8 = 0;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(param_1,(int)pcVar3 - (int)(param_1 + 1));
  local_134 = (uint *)0x0;
  local_130 = 0;
  FUN_0071bc20(uVar2);
  local_6c = 0;
  local_54 = 0xf;
  local_58 = 0;
  local_68 = local_68 & 0xffffff00;
  local_8 = CONCAT31(local_8._1_3_,1);
  ppppuVar4 = (undefined4 ****)local_30[0];
  if (local_1c < 0x10) {
    ppppuVar4 = local_30;
  }
  piVar5 = (int *)FUN_00714770(ppppuVar4,&DAT_00bed1e0);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0x38))();
    uVar6 = (**(code **)(*piVar5 + 0x2c))();
    local_135 = FUN_00499340(uVar6);
    (**(code **)(*piVar5 + 4))();
    if (local_135 != '\0') {
      if (param_1 == (char *)0x0) {
        *(undefined4 *)(param_2 + 0xec) = 0;
      }
      else {
        *(undefined4 *)(param_2 + 0xec) = 1;
        pcVar3 = param_1;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(param_1,(int)pcVar3 - (int)(param_1 + 1));
      }
      local_13c = local_134;
      FUN_00719da0(&local_140);
      FUN_00719da0(&local_13c);
      if (local_13c != (uint *)0x0) {
LAB_007d5b3d:
        lVar8 = 0;
        FUN_0071baa0("Index");
        if (local_140 != 0) {
          if (*(char **)(local_140 + 8) == (char *)0x0) {
            lVar8 = 0;
          }
          else {
            lVar8 = _strtol(*(char **)(local_140 + 8),(char **)0x0,10);
          }
        }
        FUN_00719f10(&local_13c,&DAT_00bf2375);
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_007ef670(lVar8);
        if (local_13c != (uint *)0x0) {
          for (puVar9 = (uint *)local_13c[6]; puVar9 != (uint *)0x0; puVar9 = (uint *)puVar9[6]) {
            if (((char *)puVar9[2] != (char *)0x0) &&
               (iVar7 = __stricmp("Ani",(char *)puVar9[2]), iVar7 == 0)) {
              if (puVar9 == (uint *)0x0) goto LAB_007d5cb0;
              goto LAB_007d5c77;
            }
          }
        }
        goto LAB_007d5be4;
      }
    }
  }
LAB_007d5c0f:
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_54) {
    FUN_0089120c(local_68);
  }
  local_54 = 0xf;
  local_58 = 0;
  local_68 = local_68 & 0xffffff00;
  FUN_0071bc90(&local_134);
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
LAB_007d5c77:
  do {
    if ((*puVar9 & 7) == 1) goto LAB_007d5be6;
    for (puVar9 = (uint *)puVar9[6]; puVar9 != (uint *)0x0; puVar9 = (uint *)puVar9[6]) {
      if (((char *)puVar9[2] != (char *)0x0) &&
         (iVar7 = __stricmp("Ani",(char *)puVar9[2]), iVar7 == 0)) goto LAB_007d5cb2;
    }
LAB_007d5cb0:
    puVar9 = (uint *)0x0;
LAB_007d5cb2:
  } while (puVar9 != (uint *)0x0);
LAB_007d5be4:
  puVar9 = (uint *)0x0;
LAB_007d5be6:
  local_8 = CONCAT31(local_8._1_3_,1);
  local_13c = puVar9;
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
  }
  if (puVar9 == (uint *)0x0) goto LAB_007d5c0f;
  goto LAB_007d5b3d;
}

