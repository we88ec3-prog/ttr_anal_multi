
undefined2 * FUN_0053a960(void)

{
  undefined4 in_EAX;
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  
  puVar1 = (undefined2 *)FUN_0053a9d0(in_EAX);
  if (puVar1 == (undefined2 *)0x0) {
    puVar2 = (undefined2 *)FUN_00891268(0x38);
    puVar1 = (undefined2 *)0x0;
    if (puVar2 != (undefined2 *)0x0) {
      *puVar2 = (short)in_EAX;
      *(undefined4 *)(puVar2 + 10) = 0;
      *(undefined4 *)(puVar2 + 0xc) = 7;
      puVar2[2] = 0;
      *(undefined4 *)(puVar2 + 0x14) = 0;
      *(undefined4 *)(puVar2 + 0x16) = 0;
      *(undefined4 *)(puVar2 + 0x18) = 0;
      puVar1 = puVar2;
    }
    uVar3 = FUN_004ca670();
    FUN_008262f0(in_ECX + 0x5ec8,uVar3);
  }
  return puVar1;
}

