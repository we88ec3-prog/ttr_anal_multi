
void FUN_007fdbd0(int *param_1)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1[1];
  if ((in_EAX < puVar3) && (puVar1 = (undefined4 *)*param_1, puVar1 <= in_EAX)) {
    if (puVar3 == (undefined4 *)param_1[2]) {
      FUN_007fdc70();
    }
    puVar3 = (undefined4 *)param_1[1];
    puVar1 = (undefined4 *)((((int)in_EAX - (int)puVar1) / 0x30) * 0x30 + *param_1);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = *puVar1;
      iVar2 = 0xb;
      while( true ) {
        puVar3 = puVar3 + 1;
        puVar1 = puVar1 + 1;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        *puVar3 = *puVar1;
      }
      param_1[1] = param_1[1] + 0x30;
      return;
    }
  }
  else {
    if (puVar3 == (undefined4 *)param_1[2]) {
      FUN_007fdc70();
    }
    puVar3 = (undefined4 *)param_1[1];
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = *in_EAX;
      iVar2 = 0xb;
      while( true ) {
        puVar3 = puVar3 + 1;
        in_EAX = in_EAX + 1;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        *puVar3 = *in_EAX;
      }
    }
  }
  param_1[1] = param_1[1] + 0x30;
  return;
}

