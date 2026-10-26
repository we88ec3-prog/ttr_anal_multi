
void FUN_0079c4b0(undefined4 *param_1)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 *in_EDX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (in_EDX != param_1) {
    puVar1 = in_EAX;
    puVar3 = in_EDX;
    do {
      puVar4 = puVar3;
      puVar5 = puVar1;
      for (iVar2 = 0x1e; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar1[0x1f] = *(undefined4 *)((int)in_EDX + (0x7c - (int)in_EAX) + (int)puVar1);
      puVar1[0x1e] = puVar3[0x1e];
      puVar3 = puVar3 + 0x20;
      puVar1 = puVar1 + 0x20;
    } while (puVar3 != param_1);
  }
  return;
}

