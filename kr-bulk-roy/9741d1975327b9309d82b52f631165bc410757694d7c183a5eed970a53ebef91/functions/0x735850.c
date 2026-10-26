
undefined4 FUN_00735850(int param_1,undefined4 param_2)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_64 [24];
  
  (**(code **)(**(int **)(param_1 + 8) + 0x28))(param_2);
  puVar3 = auStack_64;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *in_EAX;
    in_EAX = in_EAX + 1;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_00736800();
  FUN_00736560(param_1 + 0xc,uVar1);
  return param_2;
}

