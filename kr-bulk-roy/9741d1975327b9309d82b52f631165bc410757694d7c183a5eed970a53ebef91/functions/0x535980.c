
void FUN_00535980(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1[1];
  if ((in_EAX < puVar3) && (puVar1 = (undefined4 *)*param_1, puVar1 <= in_EAX)) {
    if (puVar3 == (undefined4 *)param_1[2]) {
      FUN_00535a40();
    }
    in_EAX = (undefined4 *)((((int)in_EAX - (int)puVar1) / 0x1f) * 0x1f + *param_1);
  }
  else if (puVar3 == (undefined4 *)param_1[2]) {
    FUN_00535a40();
  }
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)param_1[1];
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *in_EAX;
      in_EAX = in_EAX + 1;
      puVar3 = puVar3 + 1;
    }
    *(undefined2 *)puVar3 = *(undefined2 *)in_EAX;
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)in_EAX + 2);
  }
  param_1[1] = param_1[1] + 0x1f;
  return;
}

