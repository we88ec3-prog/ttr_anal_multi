
void FUN_006f7860(int param_1)

{
  double *pdVar1;
  int *piVar2;
  char cVar3;
  undefined4 *puVar4;
  double *pdVar5;
  char *pcVar6;
  undefined4 uVar7;
  char *pcVar8;
  int in_ECX;
  char *in_EDX;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_40;
  char local_34 [4];
  int local_30;
  int local_2c;
  undefined4 *local_28;
  char local_24 [24];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_30 = param_1;
  iVar9 = 1;
  local_40 = 1;
  FUN_006f7800();
  pcVar6 = _strchr(in_EDX,0x25);
  if (pcVar6 != (char *)0x0) {
    local_28 = (undefined4 *)(local_30 + -4);
    local_2c = local_30 + -8;
    do {
      puVar4 = *(undefined4 **)(in_ECX + 8);
      uVar7 = FUN_006fec70();
      *puVar4 = uVar7;
      puVar4[2] = 4;
      if (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 8) < 0x11) {
        iVar9 = *(int *)(in_ECX + 0x2c);
        local_30 = *(int *)(in_ECX + 0x20);
        if (iVar9 < 1) {
          iVar11 = iVar9 + 1;
          iVar10 = iVar9 + 7;
          if (0xfffffff < iVar9 + 8U) goto LAB_006f7940;
          iVar9 = FUN_00700880();
        }
        else {
          iVar11 = iVar9 * 2;
          iVar10 = iVar11 + 6;
          if (iVar11 + 7U < 0x10000000) {
            iVar9 = FUN_00700880();
          }
          else {
LAB_006f7940:
            iVar9 = FUN_00700860();
          }
        }
        *(int *)(in_ECX + 0x20) = iVar9;
        *(int *)(in_ECX + 0x2c) = iVar10;
        *(int *)(in_ECX + 0x1c) = iVar11 * 0x10 + iVar9;
        FUN_006fdc30();
      }
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 0x10;
      pdVar5 = *(double **)(in_ECX + 8);
      switch(pcVar6[1]) {
      case '%':
        FUN_006f7800();
        break;
      default:
        local_34[1] = pcVar6[1];
        pcVar8 = local_34;
        local_34[0] = '%';
        local_34[2] = 0;
        do {
          cVar3 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar3 != '\0');
        uVar7 = FUN_006fec70();
        *(undefined4 *)pdVar5 = uVar7;
        *(undefined4 *)(pdVar5 + 1) = 4;
        if (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 8) < 0x11) {
          iVar9 = *(int *)(in_ECX + 0x2c);
          local_30 = *(int *)(in_ECX + 0x20);
          if (iVar9 < 1) {
            iVar11 = iVar9 + 1;
            iVar10 = iVar9 + 7;
            if (0xfffffff < iVar9 + 8U) goto LAB_006f7b31;
            iVar9 = FUN_00700880();
          }
          else {
            iVar11 = iVar9 * 2;
            iVar10 = iVar11 + 6;
            if (iVar11 + 7U < 0x10000000) {
              iVar9 = FUN_00700880();
            }
            else {
LAB_006f7b31:
              iVar9 = FUN_00700860();
            }
          }
          *(int *)(in_ECX + 0x20) = iVar9;
          *(int *)(in_ECX + 0x2c) = iVar10;
          *(int *)(in_ECX + 0x1c) = iVar11 * 0x10 + iVar9;
          FUN_006fdc30();
        }
        goto LAB_006f7b52;
      case 'c':
        local_2c = local_2c + 4;
        local_28 = local_28 + 1;
        FUN_006f7800();
        break;
      case 'd':
        piVar2 = local_28 + 1;
        local_2c = local_2c + 4;
        local_28 = local_28 + 1;
        *pdVar5 = (double)*piVar2;
        *(undefined4 *)(pdVar5 + 1) = 3;
        if (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 8) < 0x11) {
          if (*(int *)(in_ECX + 0x2c) < 1) {
LAB_006f7a0f:
            FUN_006fdcb0();
          }
          else {
            FUN_006fdcb0();
          }
        }
        goto LAB_006f7b52;
      case 'f':
        pdVar1 = (double *)(local_2c + 8);
        local_28 = local_28 + 2;
        local_2c = local_2c + 8;
        *pdVar5 = *pdVar1;
        *(undefined4 *)(pdVar5 + 1) = 3;
        if (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 8) < 0x11) {
          if (*(int *)(in_ECX + 0x2c) < 1) goto LAB_006f7a0f;
          FUN_006fdcb0();
        }
LAB_006f7b52:
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 0x10;
        break;
      case 'p':
        local_2c = local_2c + 4;
        local_28 = local_28 + 1;
        _sprintf(local_24,"%p",*local_28);
        FUN_006f7800();
        break;
      case 's':
        local_2c = local_2c + 4;
        local_28 = local_28 + 1;
        FUN_006f7800();
      }
      iVar9 = local_40 + 2;
      pcVar6 = _strchr(pcVar6 + 2,0x25);
      local_40 = iVar9;
    } while (pcVar6 != (char *)0x0);
  }
  FUN_006f7800();
  FUN_006fc080();
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar9 * -0x10;
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

