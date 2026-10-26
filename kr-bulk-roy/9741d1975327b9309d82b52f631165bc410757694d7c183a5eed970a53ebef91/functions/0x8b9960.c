
undefined2 FUN_008b9960(int param_1)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined1 *puVar4;
  
  puVar4 = *(undefined1 **)(param_1 + 0x20);
  uVar3 = 0;
  if (puVar4 + 1 < *(undefined1 **)(param_1 + 0x24)) {
    uVar2 = *puVar4;
    puVar1 = puVar4 + 1;
    puVar4 = puVar4 + 2;
    uVar3 = CONCAT11(uVar2,*puVar1);
  }
  *(undefined1 **)(param_1 + 0x20) = puVar4;
  return uVar3;
}

