
undefined4 FUN_0070b3b0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  FUN_006f6060();
  FUN_006f55b0(FUN_0070a070,0);
  iVar6 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,&DAT_00c42be8,4);
  local_10 = 4;
  FUN_006fb9a0(param_1,iVar6 + -0x20,local_18,*(int *)(param_1 + 8) + -0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  FUN_006f6590("package",&PTR_s_loadlib_00c0b93c);
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = puVar1[-4];
  puVar1[1] = puVar1[-3];
  puVar1[2] = puVar1[-2];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  if (*(int *)(param_1 + 0x14) == *(int *)(param_1 + 0x28)) {
    FUN_006f8b60(param_1,"no calling environment");
  }
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(**(int **)(*(int *)(param_1 + 0x14) + 4) + 0xc);
  *(undefined4 *)(param_1 + 0x60) = 5;
  iVar6 = **(int **)(*(int *)(param_1 + 0x14) + 4);
  *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 8) + -0x10);
  if (((3 < *(int *)(*(int *)(param_1 + 8) + -8)) &&
      (iVar2 = *(int *)(*(int *)(param_1 + 8) + -0x10), (*(byte *)(iVar2 + 5) & 3) != 0)) &&
     ((*(byte *)(iVar6 + 5) & 4) != 0)) {
    FUN_006fb5a0(iVar2);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  uVar3 = FUN_006f99a0(param_1,0,4);
  *puVar1 = uVar3;
  puVar1[2] = 5;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  pcVar4 = FUN_0070a730;
  iVar6 = 0;
  do {
    FUN_006f55b0(pcVar4,0);
    iVar6 = iVar6 + 1;
    FUN_006f5870(iVar6);
    pcVar4 = (code *)(&PTR_FUN_00c0b954)[iVar6];
  } while (pcVar4 != (code *)0x0);
  iVar6 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,"loaders",7);
  local_10 = 4;
  FUN_006fb9a0(param_1,iVar6 + -0x20,local_18,*(int *)(param_1 + 8) + -0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  FUN_0070b2d0(param_1,&DAT_00bfca9c);
  FUN_0070b2d0(param_1,"cpath");
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  uVar3 = FUN_006fec70(param_1,"\\\n;\n?\n!\n-",9);
  *puVar1 = uVar3;
  puVar1[2] = 4;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar6 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,"config",6);
  local_10 = 4;
  FUN_006fb9a0(param_1,iVar6 + -0x20,local_18,*(int *)(param_1 + 8) + -0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  FUN_006f68a0("_LOADED",2);
  iVar6 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,"loaded",6);
  local_10 = 4;
  FUN_006fb9a0(param_1,iVar6 + -0x20,local_18,*(int *)(param_1 + 8) + -0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar5 = (undefined4 *)FUN_00700880(param_1,0,0,0x20);
  iVar6 = *(int *)(param_1 + 0x10);
  *puVar5 = *(undefined4 *)(iVar6 + 0x1c);
  *(undefined4 **)(iVar6 + 0x1c) = puVar5;
  *(byte *)((int)puVar5 + 5) = *(byte *)(iVar6 + 0x14) & 3;
  *(undefined1 *)(puVar5 + 1) = 5;
  puVar5[2] = 0;
  puVar5[3] = 0;
  puVar5[7] = 0;
  *(undefined2 *)((int)puVar5 + 6) = 0xff;
  puVar5[4] = &DAT_00c0bfa8;
  uVar3 = FUN_00700880(param_1,0,0,0);
  puVar5[3] = uVar3;
  if ((int)puVar5[7] < 0) {
    iVar6 = puVar5[7] << 4;
    do {
      iVar6 = iVar6 + 0x10;
      *(undefined4 *)(puVar5[3] + -8 + iVar6) = 0;
    } while (iVar6 < 0);
  }
  puVar5[7] = 0;
  *(undefined1 *)((int)puVar5 + 7) = 0;
  puVar5[4] = &DAT_00c0bfa8;
  puVar5[5] = &DAT_00c0bfa8;
  *puVar1 = puVar5;
  puVar1[2] = 5;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar6 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,"preload",7);
  local_10 = 4;
  FUN_006fb9a0(param_1,iVar6 + -0x20,local_18,*(int *)(param_1 + 8) + -0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = *(undefined4 *)(param_1 + 0x48);
  puVar1[1] = *(undefined4 *)(param_1 + 0x4c);
  puVar1[2] = *(undefined4 *)(param_1 + 0x50);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  FUN_006f6590(0,&PTR_s_module_00c0b9b8);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  return 1;
}

