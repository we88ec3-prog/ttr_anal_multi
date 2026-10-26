
int FUN_0074a1c0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x74);
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      return 0;
    }
    if ((*(uint *)(puVar2[2] + 0x28) >> 8 & 1) != 0) break;
    iVar3 = FUN_0074a1c0();
    if (iVar3 != 0) {
      return iVar3;
    }
    puVar2 = (undefined4 *)*puVar2;
  }
  return puVar2[2];
}

