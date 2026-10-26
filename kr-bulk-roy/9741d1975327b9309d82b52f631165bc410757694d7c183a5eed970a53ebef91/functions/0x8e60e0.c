
undefined4 FUN_008e60e0(uint param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(param_1 + 0x210);
  uVar2 = 6;
  if (puVar1 != (undefined4 *)0x0) {
    *param_2 = puVar1[1];
    param_2[1] = *puVar1;
    param_1 = 0;
    if (puVar1[1] != 0) {
      puVar4 = puVar1 + 2;
      param_2 = param_2 + 4;
      piVar3 = puVar1 + 0x17;
      do {
        param_2[-2] = *puVar4;
        param_2[-1] = *(undefined4 *)*piVar3;
        *param_2 = *(undefined4 *)(*piVar3 + -4 + (uint)*(byte *)(piVar3 + -1) * 4);
        param_1 = param_1 + 1;
        puVar4 = puVar4 + 1;
        param_2 = param_2 + 3;
        piVar3 = piVar3 + 3;
      } while (param_1 < (uint)puVar1[1]);
    }
    uVar2 = 0;
  }
  return uVar2;
}

