
void FUN_00520800(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  iVar2 = FUN_007300a0("value");
  if (iVar2 != 0) {
    puVar3 = (undefined4 *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    if (puVar3 != (undefined4 *)0x0) {
      uVar1 = FUN_008917b4(puVar3);
      *(undefined2 *)(in_ECX + 0xc) = uVar1;
      return;
    }
  }
  *(undefined2 *)(in_ECX + 0xc) = 0;
  return;
}

