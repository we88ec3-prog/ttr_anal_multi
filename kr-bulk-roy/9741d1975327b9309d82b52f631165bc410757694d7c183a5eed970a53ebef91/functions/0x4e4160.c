
undefined4 FUN_004e4160(undefined2 *param_1,uint param_2)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int in_ECX;
  
  if (param_2 < 2) {
    param_2 = 0;
  }
  else {
    param_2 = param_2 - 2 >> 1;
  }
  if (param_2 != 0) {
    do {
      param_1 = param_1 + 1;
      puVar1 = *(undefined2 **)(in_ECX + 0x693c);
      if ((param_1 < puVar1) && (puVar2 = *(undefined2 **)(in_ECX + 0x6938), puVar2 <= param_1)) {
        if (puVar1 == *(undefined2 **)(in_ECX + 0x6940)) {
          FUN_0044b5b0();
        }
        if (*(undefined2 **)(in_ECX + 0x693c) != (undefined2 *)0x0) {
          **(undefined2 **)(in_ECX + 0x693c) =
               *(undefined2 *)(*(int *)(in_ECX + 0x6938) + ((int)param_1 - (int)puVar2 >> 1) * 2);
        }
      }
      else {
        if (puVar1 == *(undefined2 **)(in_ECX + 0x6940)) {
          FUN_0044b5b0();
        }
        if (*(undefined2 **)(in_ECX + 0x693c) != (undefined2 *)0x0) {
          **(undefined2 **)(in_ECX + 0x693c) = *param_1;
        }
      }
      *(int *)(in_ECX + 0x693c) = *(int *)(in_ECX + 0x693c) + 2;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  return 0;
}

