
undefined4 * FUN_007c0140(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_EAX;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint *in_EDX;
  undefined4 *puVar5;
  int local_8;
  
  puVar5 = (undefined4 *)(*(undefined4 **)(in_EAX + 4))[1];
  cVar1 = *(char *)((int)puVar5 + 0x21);
  puVar2 = *(undefined4 **)(in_EAX + 4);
  while (cVar1 == '\0') {
    if (((int)in_EDX[1] < (int)puVar5[5]) ||
       (((int)in_EDX[1] <= (int)puVar5[5] && (*in_EDX <= (uint)puVar5[4])))) {
      puVar3 = (undefined4 *)*puVar5;
    }
    else {
      puVar3 = (undefined4 *)puVar5[2];
      puVar5 = puVar2;
    }
    puVar2 = puVar5;
    puVar5 = puVar3;
    cVar1 = *(char *)((int)puVar3 + 0x21);
  }
  if (puVar2 != *(undefined4 **)(in_EAX + 4)) {
    if (((int)puVar2[5] < (int)in_EDX[1]) ||
       (((int)puVar2[5] <= (int)in_EDX[1] && ((uint)puVar2[4] <= *in_EDX)))) {
      return puVar2 + 6;
    }
  }
  uVar4 = FUN_007c1af0();
  FUN_007c0f40(&local_8,puVar2,uVar4);
  return (undefined4 *)(local_8 + 0x18);
}

