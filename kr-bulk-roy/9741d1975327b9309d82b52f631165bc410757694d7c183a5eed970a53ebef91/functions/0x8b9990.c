
undefined2 FUN_008b9990(int param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  
  puVar2 = *(undefined2 **)(param_1 + 0x20);
  uVar1 = 0;
  if ((int)puVar2 + 1U < *(uint *)(param_1 + 0x24)) {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 **)(param_1 + 0x20) = puVar2;
  return uVar1;
}

