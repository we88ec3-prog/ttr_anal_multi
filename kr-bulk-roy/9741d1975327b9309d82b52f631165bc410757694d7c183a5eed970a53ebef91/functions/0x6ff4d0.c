
void FUN_006ff4d0(uint *param_1,undefined4 param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  byte *pbVar8;
  uint uVar9;
  
  puVar4 = param_1;
  do {
    FUN_006fef80(*puVar4);
    iVar6 = *(int *)puVar4[0xe];
    *(int *)puVar4[0xe] = iVar6 + -1;
    if (iVar6 == 0) {
      piVar2 = (int *)puVar4[0xe];
      pbVar8 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&param_1);
      if ((pbVar8 == (byte *)0x0) || (param_1 == (uint *)0x0)) {
        uVar9 = 0xffffffff;
      }
      else {
        piVar2[1] = (int)pbVar8;
        *piVar2 = (int)param_1 + -1;
        uVar9 = (uint)*pbVar8;
        piVar2[1] = (int)(pbVar8 + 1);
      }
    }
    else {
      pbVar8 = *(byte **)(puVar4[0xe] + 4);
      uVar9 = (uint)*pbVar8;
      *(byte **)(puVar4[0xe] + 4) = pbVar8 + 1;
    }
    *puVar4 = uVar9;
    iVar6 = _isdigit(uVar9);
  } while ((iVar6 != 0) || (*puVar4 == 0x2e));
  pcVar7 = _strchr("Ee",*puVar4);
  if ((pcVar7 != (char *)0x0) &&
     ((iVar6 = FUN_006ff3a0(), iVar6 != 0 && (pcVar7 = _strchr("+-",*puVar4), pcVar7 != (char *)0x0)
      ))) {
    FUN_006ff3a0();
  }
  while ((iVar6 = _isalnum(*puVar4), iVar6 != 0 || (*puVar4 == 0x5f))) {
    FUN_006fef80(*puVar4);
    iVar6 = *(int *)puVar4[0xe];
    *(int *)puVar4[0xe] = iVar6 + -1;
    if (iVar6 == 0) {
      piVar2 = (int *)puVar4[0xe];
      pbVar8 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&param_1);
      if ((pbVar8 == (byte *)0x0) || (param_1 == (uint *)0x0)) {
        *puVar4 = 0xffffffff;
      }
      else {
        piVar2[1] = (int)pbVar8;
        *piVar2 = (int)param_1 + -1;
        bVar1 = *pbVar8;
        piVar2[1] = (int)(pbVar8 + 1);
        *puVar4 = (uint)bVar1;
      }
    }
    else {
      pbVar8 = *(byte **)(puVar4[0xe] + 4);
      bVar1 = *pbVar8;
      *(byte **)(puVar4[0xe] + 4) = pbVar8 + 1;
      *puVar4 = (uint)bVar1;
    }
  }
  FUN_006fef80(0);
  uVar5 = param_2;
  iVar6 = ((int *)puVar4[0xf])[1];
  uVar9 = puVar4[0x11];
  iVar3 = *(int *)puVar4[0xf];
  while (iVar6 != 0) {
    iVar6 = iVar6 + -1;
    if (*(char *)(iVar3 + iVar6) == '.') {
      *(char *)(iVar3 + iVar6) = (char)uVar9;
    }
  }
  iVar6 = FUN_006f7760();
  if (iVar6 == 0) {
    FUN_006ff430(puVar4,uVar5);
  }
  return;
}

