
void FUN_00507b10(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1[1];
  if ((in_EAX < puVar3) && (puVar1 = (undefined4 *)*param_1, puVar1 <= in_EAX)) {
    if (puVar3 == (undefined4 *)param_1[2]) {
      FUN_00507cb0();
    }
    in_EAX = (undefined4 *)((((int)in_EAX - (int)puVar1) / 0x60) * 0x60 + *param_1);
  }
  else if (puVar3 == (undefined4 *)param_1[2]) {
    FUN_00507cb0();
  }
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)param_1[1];
    for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *in_EAX;
      in_EAX = in_EAX + 1;
      puVar3 = puVar3 + 1;
    }
  }
  param_1[1] = param_1[1] + 0x60;
  return;
}

