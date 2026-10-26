
void FUN_0066dac0(undefined4 *param_1)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 *in_EDX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  while (in_EDX != param_1) {
    puVar3 = in_EDX + 0x18;
    puVar1 = in_EAX + 0x18;
    puVar4 = in_EDX;
    puVar5 = in_EAX;
    for (iVar2 = 0x18; in_EDX = puVar3, in_EAX = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}

