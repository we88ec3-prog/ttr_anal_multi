
void FUN_007048d0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  double *pdVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 auStack_34c [4];
  int local_348;
  char *local_344;
  int local_340;
  int local_33c;
  uint local_338;
  int local_334;
  undefined1 *local_330;
  int local_32c;
  int local_328;
  undefined1 local_324 [512];
  undefined1 local_124 [4];
  undefined1 *local_120;
  undefined1 *local_11c;
  int local_118;
  undefined4 local_114;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_34c;
  local_334 = param_1;
  puVar5 = (undefined1 *)FUN_006f6210(param_1);
  local_344 = (char *)FUN_006f6210(param_1);
  iVar2 = *(int *)(param_1 + 0xc);
  if (((undefined4 *)(iVar2 + 0x20) < *(undefined4 **)(param_1 + 8)) &&
     ((undefined4 *)(iVar2 + 0x20) != &DAT_00c0bfc8)) {
    iVar8 = *(int *)(iVar2 + 0x28);
  }
  else {
    iVar8 = -1;
  }
  local_33c = local_348 + 1;
  if ((((undefined4 *)(iVar2 + 0x30) < *(undefined4 **)(param_1 + 8)) &&
      ((undefined4 *)(iVar2 + 0x30) != &DAT_00c0bfc8)) && (0 < *(int *)(iVar2 + 0x38))) {
    local_33c = FUN_006f6370(param_1,4);
  }
  cVar1 = *local_344;
  if (cVar1 == '^') {
    local_344 = local_344 + 1;
  }
  local_338 = (uint)(cVar1 == '^');
  local_340 = 0;
  if (((iVar8 != 3) && (iVar8 != 4)) && ((iVar8 != 6 && (iVar8 != 5)))) {
    FUN_006f5da0(3);
  }
  local_11c = puVar5 + local_348;
  local_330 = local_324;
  local_328 = param_1;
  local_32c = 0;
  local_118 = param_1;
  puVar6 = puVar5;
  local_120 = puVar5;
  if (local_33c < 1) {
LAB_00704add:
    FUN_006f6c40(puVar6,(int)local_11c - (int)puVar6);
    FUN_006f6af0();
    FUN_006f5bb0();
    pdVar4 = *(double **)(local_334 + 8);
    *pdVar4 = (double)local_340;
    *(undefined4 *)(pdVar4 + 1) = 3;
    *(int *)(local_334 + 8) = *(int *)(local_334 + 8) + 0x10;
    __security_check_cookie(local_c ^ (uint)auStack_34c);
    return;
  }
  do {
    local_114 = 0;
    puVar6 = (undefined1 *)FUN_00703c30(&local_120,puVar5,local_344);
    if (puVar6 == (undefined1 *)0x0) {
LAB_00704a36:
      iVar2 = local_328;
      puVar6 = puVar5;
      if (local_11c <= puVar5) goto LAB_00704add;
      if ((local_124 <= local_330) && (local_348 = (int)local_330 - (int)local_324, local_348 != 0))
      {
        if (*(uint *)(*(int *)(local_328 + 0x10) + 0x40) <=
            *(uint *)(*(int *)(local_328 + 0x10) + 0x44)) {
          FUN_006fb3a0();
        }
        puVar3 = *(undefined4 **)(iVar2 + 8);
        uVar7 = FUN_006fec70(iVar2,local_324,local_348);
        *puVar3 = uVar7;
        puVar3[2] = 4;
        *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 0x10;
        local_32c = local_32c + 1;
        local_330 = local_324;
        FUN_006f6b60(&local_330);
      }
      *local_330 = *puVar5;
      local_330 = local_330 + 1;
      puVar6 = puVar5 + 1;
    }
    else {
      local_340 = local_340 + 1;
      FUN_00704750(&local_330,puVar5,puVar6);
      if (puVar6 <= puVar5) goto LAB_00704a36;
    }
    if ((local_338 != 0) || (puVar5 = puVar6, local_33c <= local_340)) goto LAB_00704add;
  } while( true );
}

