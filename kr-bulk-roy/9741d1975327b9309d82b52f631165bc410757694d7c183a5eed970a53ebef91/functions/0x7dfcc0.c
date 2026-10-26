
void FUN_007dfcc0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_3 != param_4) {
    puVar1 = *(undefined4 **)(param_1 + 4);
    puVar2 = param_3;
    for (; param_4 != puVar1; param_4 = param_4 + 5) {
      *puVar2 = *param_4;
      FUN_007e02b0(param_4 + 1);
      puVar2 = puVar2 + 5;
    }
    FUN_007e0170(*(undefined4 *)(param_1 + 4),param_1);
    *(undefined4 **)(param_1 + 4) = puVar2;
  }
  *param_2 = param_3;
  return;
}

