
undefined4 FUN_007054c0(int param_1)

{
  double *pdVar1;
  double dVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  int iVar5;
  ulong uVar6;
  float10 fVar7;
  byte *local_18;
  byte *local_14;
  int local_10;
  
  puVar4 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if ((((puVar4 < *(undefined4 **)(param_1 + 8)) && (puVar4 != &DAT_00c0bfc8)) &&
      (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x18))) &&
     (iVar5 = FUN_006f6370(param_1,2), local_10 = iVar5, iVar5 != 10)) {
    local_14 = (byte *)FUN_006f6210(param_1);
    if ((iVar5 < 2) || (0x24 < iVar5)) {
      FUN_006f5da0(2);
      iVar5 = local_10;
    }
    pbVar3 = local_14;
    uVar6 = _strtoul((char *)local_14,(char **)&local_18,iVar5);
    if (pbVar3 != local_18) {
      iVar5 = _isspace((uint)*local_18);
      while (iVar5 != 0) {
        local_18 = local_18 + 1;
        iVar5 = _isspace((uint)*local_18);
      }
      if (*local_18 == 0) {
        pdVar1 = *(double **)(param_1 + 8);
        dVar2 = (double)(int)uVar6;
        if ((int)uVar6 < 0) {
          dVar2 = dVar2 + 4294967296.0;
        }
        *pdVar1 = dVar2;
        *(undefined4 *)(pdVar1 + 1) = 3;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        return 1;
      }
    }
  }
  else {
    puVar4 = *(undefined4 **)(param_1 + 0xc);
    if (((*(undefined4 **)(param_1 + 8) <= puVar4) || (puVar4 == &DAT_00c0bfc8)) ||
       (puVar4[2] == -1)) {
      FUN_006f5da0(1);
    }
    puVar4 = *(undefined4 **)(param_1 + 0xc);
    if (*(undefined4 **)(param_1 + 8) <= puVar4) {
      puVar4 = &DAT_00c0bfc8;
    }
    if ((puVar4[2] == 3) || ((puVar4[2] == 4 && (iVar5 = FUN_006f7760(), iVar5 != 0)))) {
      fVar7 = (float10)FUN_006f5320();
      pdVar1 = *(double **)(param_1 + 8);
      *pdVar1 = (double)fVar7;
      *(undefined4 *)(pdVar1 + 1) = 3;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      return 1;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

