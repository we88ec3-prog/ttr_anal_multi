
undefined4 FUN_00810300(void)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = (undefined4 *)(in_ECX + 8);
  do {
    iVar1 = FUN_00810170(*puVar2);
    if (iVar1 < 0) {
      return 0;
    }
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 2);
  alSourceQueueBuffers(*(undefined4 *)(in_ECX + 0x10),2,in_ECX + 8);
  FUN_00810080();
  return 1;
}

