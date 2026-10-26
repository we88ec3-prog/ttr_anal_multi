
void FUN_005206b0(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  
  iVar3 = FUN_007300a0("skill");
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    if (puVar4 != (undefined4 *)0x0) {
      uVar2 = FUN_008917b4(puVar4);
      goto LAB_005206e7;
    }
  }
  uVar2 = 0;
LAB_005206e7:
  *(undefined2 *)(in_ECX + 0xc) = uVar2;
  iVar3 = FUN_007300a0("level");
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    if (puVar4 != (undefined4 *)0x0) {
      uVar1 = FUN_008917b4(puVar4);
      *(undefined1 *)(in_ECX + 0xe) = uVar1;
      return;
    }
  }
  *(undefined1 *)(in_ECX + 0xe) = 0;
  return;
}

