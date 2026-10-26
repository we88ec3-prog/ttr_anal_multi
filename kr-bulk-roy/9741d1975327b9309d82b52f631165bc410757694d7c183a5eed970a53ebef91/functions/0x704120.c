
void FUN_00704120(int param_1)

{
  char cVar1;
  double *pdVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  char *pcVar7;
  int unaff_ESI;
  int iVar8;
  uint uVar9;
  undefined1 auStack_130 [4];
  uint local_12c;
  uint local_128;
  char *local_124;
  int local_120;
  uint local_11c;
  
  uVar3 = DAT_00d61f20 ^ (uint)auStack_130;
  iVar4 = FUN_006f6210();
  local_124 = (char *)FUN_006f6210();
  puVar5 = (undefined4 *)(*(int *)(unaff_ESI + 0xc) + 0x20);
  if (((puVar5 < *(undefined4 **)(unaff_ESI + 8)) && (puVar5 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(unaff_ESI + 0xc) + 0x28))) {
    iVar8 = FUN_006f6370();
    if (iVar8 < 0) {
      iVar8 = iVar8 + 1 + local_128;
    }
  }
  else {
    iVar8 = 1;
  }
  uVar9 = iVar8 - 1;
  if ((int)uVar9 < 0) {
    uVar9 = 0;
  }
  else if (local_128 < uVar9) {
    uVar9 = local_128;
  }
  if (param_1 != 0) {
    piVar6 = (int *)(*(int *)(unaff_ESI + 0xc) + 0x30);
    if (*(int **)(unaff_ESI + 8) <= piVar6) {
      piVar6 = &DAT_00c0bfc8;
    }
    if (((piVar6[2] != 0) && ((piVar6[2] != 1 || (*piVar6 != 0)))) ||
       (pcVar7 = _strpbrk(local_124,"^$*+?.([%-"), pcVar7 == (char *)0x0)) {
      iVar8 = FUN_00703f20(uVar9 + iVar4,local_128 - uVar9,local_124,local_12c);
      if (iVar8 != 0) {
        pdVar2 = *(double **)(unaff_ESI + 8);
        local_128 = (iVar8 - iVar4) + 1;
        local_12c = (iVar8 - iVar4) + local_12c;
        *(undefined4 *)(pdVar2 + 1) = 3;
        *pdVar2 = (double)(int)local_128;
        *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
        pdVar2 = *(double **)(unaff_ESI + 8);
        *(undefined4 *)(pdVar2 + 1) = 3;
        *pdVar2 = (double)(int)local_12c;
        *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
        __security_check_cookie(uVar3 ^ (uint)auStack_130);
        return;
      }
      goto LAB_007042cf;
    }
  }
  cVar1 = *local_124;
  if (cVar1 == '^') {
    local_124 = local_124 + 1;
  }
  local_12c = (uint)(cVar1 == '^');
  local_11c = local_128 + iVar4;
  uVar9 = uVar9 + iVar4;
  local_120 = iVar4;
  do {
    iVar8 = FUN_00703c30(&local_120,uVar9,local_124);
    if (iVar8 != 0) {
      if (param_1 == 0) {
        FUN_007040b0(&local_120,uVar9,iVar8);
        __security_check_cookie(uVar3 ^ (uint)auStack_130);
        return;
      }
      pdVar2 = *(double **)(unaff_ESI + 8);
      local_12c = iVar8 - iVar4;
      *pdVar2 = (double)(int)((uVar9 - iVar4) + 1);
      *(undefined4 *)(pdVar2 + 1) = 3;
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
      pdVar2 = *(double **)(unaff_ESI + 8);
      *(undefined4 *)(pdVar2 + 1) = 3;
      *pdVar2 = (double)(int)local_12c;
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
      FUN_007040b0(&local_120,0,0);
      __security_check_cookie(uVar3 ^ (uint)auStack_130);
      return;
    }
  } while ((uVar9 < local_11c) && (uVar9 = uVar9 + 1, local_12c == 0));
LAB_007042cf:
  *(undefined4 *)(*(int *)(unaff_ESI + 8) + 8) = 0;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  __security_check_cookie(uVar3 ^ (uint)auStack_130);
  return;
}

