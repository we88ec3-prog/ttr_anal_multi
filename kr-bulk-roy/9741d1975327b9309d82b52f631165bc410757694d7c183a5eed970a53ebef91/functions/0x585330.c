
undefined4 * FUN_00585330(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  int unaff_ESI;
  
  FUN_005740f0(&stack0x00000004);
  if (in_ECX == *(int *)(unaff_ESI + 4)) {
    pcVar1 = (code *)swi(3);
    puVar2 = (undefined4 *)(*pcVar1)();
    return puVar2;
  }
  if (7 < *(uint *)(in_ECX + 0x24)) {
    return *(undefined4 **)(in_ECX + 0x10);
  }
  return (undefined4 *)(in_ECX + 0x10);
}

