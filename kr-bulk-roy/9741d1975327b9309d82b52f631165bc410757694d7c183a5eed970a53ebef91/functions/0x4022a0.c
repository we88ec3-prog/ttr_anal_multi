
undefined4 * FUN_004022a0(undefined4 *param_1,undefined2 param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_3 != 0) {
    puVar2 = param_1;
    for (uVar1 = param_3 >> 1; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = CONCAT22(param_2,param_2);
      puVar2 = puVar2 + 1;
    }
    for (uVar1 = (uint)((param_3 & 1) != 0); uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined2 *)puVar2 = param_2;
      puVar2 = (undefined4 *)((int)puVar2 + 2);
    }
    return param_1;
  }
  return param_1;
}

