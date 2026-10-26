
void FUN_0044af30(void)

{
  char cVar1;
  int *in_EAX;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int unaff_EDI;
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  cVar1 = *(char *)((int)puVar4[1] + 0x15);
  puVar5 = (undefined4 *)puVar4[1];
  while (cVar1 == '\0') {
    if (unaff_EDI < (int)puVar5[3]) {
      puVar2 = (undefined4 *)*puVar5;
      puVar4 = puVar5;
    }
    else {
      puVar2 = (undefined4 *)puVar5[2];
    }
    puVar5 = puVar2;
    cVar1 = *(char *)((int)puVar2 + 0x15);
  }
  puVar5 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar1 = *(char *)((int)puVar5 + 0x15);
  puVar2 = *(undefined4 **)(in_ECX + 4);
  while (cVar1 == '\0') {
    if ((int)puVar5[3] < unaff_EDI) {
      puVar3 = (undefined4 *)puVar5[2];
      puVar5 = puVar2;
    }
    else {
      puVar3 = (undefined4 *)*puVar5;
    }
    puVar2 = puVar5;
    puVar5 = puVar3;
    cVar1 = *(char *)((int)puVar3 + 0x15);
  }
  *in_EAX = (int)puVar2;
  in_EAX[1] = (int)puVar4;
  return;
}

