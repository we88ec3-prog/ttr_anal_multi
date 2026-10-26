
undefined4 FUN_004e35c0(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  if (param_2 < 2) {
    param_2 = 0;
  }
  else {
    param_2 = param_2 - 2 >> 2;
  }
  if (param_2 != 0) {
    puVar3 = (undefined4 *)(param_1 + 2);
    do {
      puVar1 = *(undefined4 **)(in_ECX + 0x6900);
      if ((puVar3 < puVar1) && (puVar2 = *(undefined4 **)(in_ECX + 0x68fc), puVar2 <= puVar3)) {
        if (puVar1 == *(undefined4 **)(in_ECX + 0x6904)) {
          FUN_006d6240();
        }
        if (*(undefined4 **)(in_ECX + 0x6900) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0x6900) =
               *(undefined4 *)(*(uint *)(in_ECX + 0x68fc) + ((int)puVar3 - (int)puVar2 >> 2) * 4);
        }
      }
      else {
        if (puVar1 == *(undefined4 **)(in_ECX + 0x6904)) {
          FUN_006d6240();
        }
        if (*(undefined4 **)(in_ECX + 0x6900) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0x6900) = *puVar3;
        }
      }
      *(int *)(in_ECX + 0x6900) = *(int *)(in_ECX + 0x6900) + 4;
      puVar3 = puVar3 + 1;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  return 0;
}

