
void FUN_007b16d0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1[1];
  if ((in_EAX < puVar3) && (puVar1 = (undefined4 *)*param_1, puVar1 <= in_EAX)) {
    if (puVar3 == (undefined4 *)param_1[2]) {
      FUN_007b1b90();
    }
    in_EAX = (undefined4 *)((((int)in_EAX - (int)puVar1) / 0x68) * 0x68 + *param_1);
  }
  else if (puVar3 == (undefined4 *)param_1[2]) {
    FUN_007b1b90();
  }
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)param_1[1];
    for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *in_EAX;
      in_EAX = in_EAX + 1;
      puVar3 = puVar3 + 1;
    }
  }
  param_1[1] = param_1[1] + 0x68;
  return;
}

