
undefined4 FUN_008dcc90(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(*(int *)(*param_1 + 0x60) + 4);
  *param_2 = 0;
  param_2[1] = 0;
  if (((undefined *)param_1[3] != &DAT_00bea118) && ((undefined *)param_1[3] != &DAT_00bea140)) {
    uVar1 = FUN_008b8f30(uVar1,&DAT_00bd7d94);
    puVar2 = (undefined4 *)FUN_008b8ff0(uVar1,"tt-cmaps");
    if ((puVar2 != (undefined4 *)0x0) && ((code *)*puVar2 != (code *)0x0)) {
      uVar1 = (*(code *)*puVar2)(param_1,param_2);
      return uVar1;
    }
  }
  return 0;
}

