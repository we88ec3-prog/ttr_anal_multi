
undefined4 FUN_008b99c0(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  puVar1 = *(undefined1 **)(param_1 + 0x20);
  uVar2 = 0;
  puVar3 = puVar1;
  if (puVar1 + 3 < *(undefined1 **)(param_1 + 0x24)) {
    puVar3 = puVar1 + 4;
    uVar2 = CONCAT31(CONCAT21(CONCAT11(*puVar1,puVar1[1]),puVar1[2]),puVar1[3]);
  }
  *(undefined1 **)(param_1 + 0x20) = puVar3;
  return uVar2;
}

