
void FUN_00520780(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar1 = FUN_007300a0(&DAT_00c0e844);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = FUN_008917b4(puVar2);
      *(undefined4 *)(in_ECX + 0xc) = uVar3;
      return;
    }
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

