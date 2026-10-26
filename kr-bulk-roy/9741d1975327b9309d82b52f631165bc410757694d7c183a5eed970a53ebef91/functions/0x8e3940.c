
void FUN_008e3940(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  FUN_008e3640();
  *(undefined4 *)(param_1 + 0x2dd8) = param_2;
  *(undefined4 *)(param_1 + 0x2dc8) = param_2;
  *(undefined4 *)(param_1 + 0x2ddc) = param_3;
  *(undefined4 *)(param_1 + 0x2dcc) = param_3;
  *(undefined1 *)(param_1 + 0x2d93) = 1;
  cVar1 = FUN_008e0f70();
  if (cVar1 != '\0') {
    cVar1 = FUN_008e1cf0();
    if (cVar1 == '\0') goto LAB_008e39b8;
  }
  FUN_008e2ff0((undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x2d94),
               *(undefined4 *)(param_1 + 0x2d98),*(undefined4 *)(param_1 + 0x2d9c),
               *(undefined4 *)(param_1 + 0x2da0),0);
LAB_008e39b8:
  puVar3 = (undefined4 *)(param_1 + 8);
  puVar4 = (undefined4 *)(param_1 + 0xf24);
  for (iVar2 = 0x3c7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}

