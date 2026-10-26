
undefined4 FUN_0054ac90(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  int in_ECX;
  double dVar5;
  float local_8;
  
  (**(code **)(*param_1 + 0x14))();
  iVar1 = FUN_007300a0("source");
  if (iVar1 == 0) {
LAB_0054acd2:
    uVar3 = 0;
  }
  else {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 == (undefined4 *)0x0) goto LAB_0054acd2;
    uVar3 = FUN_008917b4(puVar2);
  }
  *(undefined4 *)(in_ECX + 4) = uVar3;
  iVar1 = FUN_007300a0("target");
  if (iVar1 == 0) {
LAB_0054acfe:
    uVar3 = 0;
  }
  else {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 == (undefined4 *)0x0) goto LAB_0054acfe;
    uVar3 = FUN_008917b4(puVar2);
  }
  *(undefined4 *)(in_ECX + 8) = uVar3;
  iVar1 = FUN_007300a0(&DAT_00c0fb84);
  if (iVar1 == 0) {
LAB_0054ad2d:
    param_1 = (int *)0x0;
  }
  else {
    pcVar4 = (char *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      pcVar4 = *(char **)pcVar4;
    }
    if (pcVar4 == (char *)0x0) goto LAB_0054ad2d;
    dVar5 = _atof(pcVar4);
    param_1 = (int *)(float)dVar5;
  }
  iVar1 = FUN_007300a0(&DAT_00c0fb88);
  if (iVar1 != 0) {
    pcVar4 = (char *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      pcVar4 = *(char **)pcVar4;
    }
    if (pcVar4 != (char *)0x0) {
      dVar5 = _atof(pcVar4);
      local_8 = (float)dVar5;
      goto LAB_0054ad67;
    }
  }
  local_8 = 0.0;
LAB_0054ad67:
  *(float *)(in_ECX + 0xc) = (float)param_1 * (float)param_1;
  *(float *)(in_ECX + 0x10) = local_8 * local_8;
  return 1;
}

