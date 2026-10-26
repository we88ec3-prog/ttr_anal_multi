
undefined4 FUN_008b9a00(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  uVar2 = 0;
  puVar3 = puVar1;
  if ((int)puVar1 + 3U < *(uint *)(param_1 + 0x24)) {
    puVar3 = puVar1 + 1;
    uVar2 = *puVar1;
  }
  *(undefined4 **)(param_1 + 0x20) = puVar3;
  return uVar2;
}

