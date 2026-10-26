
void FUN_00520850(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  iVar2 = FUN_007300a0("object");
  if (iVar2 != 0) {
    puVar3 = (undefined4 *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    if (puVar3 != (undefined4 *)0x0) {
      uVar1 = FUN_008917b4(puVar3);
      goto LAB_00520887;
    }
  }
  uVar1 = 0;
LAB_00520887:
  *(undefined2 *)(in_ECX + 0xc) = uVar1;
  iVar2 = FUN_007300a0("duration");
  if (iVar2 != 0) {
    puVar3 = (undefined4 *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    if (puVar3 != (undefined4 *)0x0) {
      uVar1 = FUN_008917b4(puVar3);
      *(undefined2 *)(in_ECX + 0xe) = uVar1;
      return;
    }
  }
  *(undefined2 *)(in_ECX + 0xe) = 0;
  return;
}

