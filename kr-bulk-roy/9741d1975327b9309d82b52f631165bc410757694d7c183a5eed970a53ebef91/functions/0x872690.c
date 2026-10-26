
undefined4 FUN_00872690(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 0x184);
  puVar1 = *(undefined4 **)(in_ECX + 0x188);
  while( true ) {
    if (puVar3 == puVar1) {
      return *(undefined4 *)(in_ECX + 0x24);
    }
    iVar2 = (**(code **)(*(int *)*puVar3 + 8))();
    if (iVar2 == 0) break;
    puVar3 = puVar3 + 1;
  }
  return 0;
}

