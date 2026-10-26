
undefined4 FUN_006f48a0(int param_1)

{
  double *pdVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  size_t sVar5;
  void *_Src;
  uint uVar6;
  size_t _Size;
  char *local_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  code *pcStack_14;
  char **ppcStack_10;
  int iStack_c;
  
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(iVar3 + -8) == 4) {
LAB_006f48e0:
    iVar3 = *(int *)(iVar3 + -0x10) + 0x10;
  }
  else {
    iVar3 = FUN_006fb5d0();
    if (iVar3 != 0) {
      if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44))
      {
        FUN_006fb3a0();
      }
      iVar3 = *(int *)(param_1 + 8);
      goto LAB_006f48e0;
    }
    iVar3 = 0;
  }
  local_24 = (char *)0x1;
  piVar4 = (int *)FUN_00714770(iVar3,&DAT_00bed1e0);
  if (piVar4 == (int *)0x0) goto LAB_006f4a30;
  sVar5 = (**(code **)(*piVar4 + 0x2c))();
  local_24 = (char *)FUN_0087dc3d(sVar5 + 1);
  _Size = sVar5;
  _Src = (void *)(**(code **)(*piVar4 + 0x38))();
  FID_conflict__memcpy(local_24,_Src,_Size);
  local_24[sVar5] = '\0';
  uVar6 = (**(code **)(*piVar4 + 0x2c))();
  pcVar2 = local_24;
  if ((((uVar6 < 3) || (*local_24 != -0x11)) || (local_24[1] != -0x45)) || (local_24[2] != -0x41)) {
    ppcStack_10 = &local_24;
    uStack_1c = 0;
    uStack_18 = 0;
    iStack_c = param_1;
    pcStack_14 = FUN_006f70e0;
    uStack_20 = uVar6;
    iVar3 = FUN_006fe990(param_1);
    if (iVar3 == 0) {
      local_24 = (char *)(*(int *)(param_1 + 8) + -0x10);
      iVar3 = (int)local_24 - *(int *)(param_1 + 0x20);
      goto LAB_006f49e3;
    }
LAB_006f4a16:
    local_24 = (char *)0x1;
  }
  else {
    iVar3 = FUN_006f7110(local_24 + 3,uVar6 - 3);
    if (iVar3 != 0) goto LAB_006f4a16;
    local_24 = (char *)(*(int *)(param_1 + 8) + -0x10);
    iVar3 = (int)local_24 - *(int *)(param_1 + 0x20);
LAB_006f49e3:
    uStack_20 = 0xffffffff;
    iVar3 = FUN_006fe770(FUN_006f5a50,&local_24,iVar3);
    if (*(uint *)(*(int *)(param_1 + 0x14) + 8) <= *(uint *)(param_1 + 8)) {
      *(uint *)(*(int *)(param_1 + 0x14) + 8) = *(uint *)(param_1 + 8);
    }
    local_24 = (char *)0x0;
    if (iVar3 != 0) goto LAB_006f4a16;
  }
  (**(code **)(*piVar4 + 4))();
  FUN_00891d3d(pcVar2);
LAB_006f4a30:
  pdVar1 = *(double **)(param_1 + 8);
  *(undefined4 *)(pdVar1 + 1) = 3;
  *pdVar1 = (double)(int)local_24;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

