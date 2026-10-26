
void FUN_00849f90(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1[1];
  if ((in_EAX < puVar3) && (puVar1 = (undefined4 *)*param_1, puVar1 <= in_EAX)) {
    if (puVar3 == (undefined4 *)param_1[2]) {
      FUN_0084a0e0();
    }
    in_EAX = (undefined4 *)(*param_1 + (((int)in_EAX - (int)puVar1) / 0x24) * 0x24);
  }
  else if (puVar3 == (undefined4 *)param_1[2]) {
    FUN_0084a0e0();
  }
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)param_1[1];
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *in_EAX;
      in_EAX = in_EAX + 1;
      puVar3 = puVar3 + 1;
    }
  }
  param_1[1] = param_1[1] + 0x24;
  return;
}

