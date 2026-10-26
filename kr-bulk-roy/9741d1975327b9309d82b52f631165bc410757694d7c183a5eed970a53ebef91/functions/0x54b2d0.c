
undefined4 FUN_0054b2d0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  
  (**(code **)(*param_1 + 0x14))();
  iVar1 = FUN_007300a0("source");
  if (iVar1 == 0) {
LAB_0054b311:
    uVar3 = 0;
  }
  else {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 == (undefined4 *)0x0) goto LAB_0054b311;
    uVar3 = FUN_008917b4(puVar2);
  }
  *(undefined4 *)(in_ECX + 4) = uVar3;
  iVar1 = FUN_007300a0("target");
  if (iVar1 == 0) {
LAB_0054b33d:
    uVar3 = 0;
  }
  else {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 == (undefined4 *)0x0) goto LAB_0054b33d;
    uVar3 = FUN_008917b4(puVar2);
  }
  *(undefined4 *)(in_ECX + 8) = uVar3;
  iVar1 = FUN_007300a0(&DAT_00c0f030);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = FUN_008917b4(puVar2);
      goto LAB_0054b36c;
    }
  }
  uVar3 = 0xffffffff;
LAB_0054b36c:
  *(undefined4 *)(in_ECX + 0xc) = uVar3;
  iVar1 = FUN_007300a0(&DAT_00c0f038);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = FUN_008917b4(puVar2);
      *(undefined4 *)(in_ECX + 0x10) = uVar3;
      return 1;
    }
  }
  *(undefined4 *)(in_ECX + 0x10) = 0;
  return 1;
}

