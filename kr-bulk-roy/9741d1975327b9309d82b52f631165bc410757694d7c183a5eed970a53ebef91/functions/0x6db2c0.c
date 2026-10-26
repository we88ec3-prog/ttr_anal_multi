
undefined4 * FUN_006db2c0(int param_1,short *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  if (*(char *)((int)puVar3[1] + 0x31) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(short *)(puVar1 + 4) < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x31) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(param_1 + 4)) && (*(short *)(puVar3 + 4) <= *param_2)) {
    return puVar3 + 6;
  }
  param_2 = (short *)puVar3;
  FUN_006dbb50();
  FUN_006db7d0(&param_1,param_2);
  return (undefined4 *)(param_1 + 0x18);
}

