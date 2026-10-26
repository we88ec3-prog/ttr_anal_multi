
void FUN_005080b0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (; param_1 != param_2; param_1 = param_1 + 0x18) {
    if (in_EAX != (undefined4 *)0x0) {
      puVar2 = param_1;
      puVar3 = in_EAX;
      for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    in_EAX = in_EAX + 0x18;
  }
  return;
}

