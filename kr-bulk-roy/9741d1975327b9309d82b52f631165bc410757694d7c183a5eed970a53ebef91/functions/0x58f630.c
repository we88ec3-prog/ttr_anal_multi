
undefined4 * FUN_0058f630(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_EAX;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *unaff_EDI;
  
  puVar5 = (undefined4 *)(*(undefined4 **)(in_EAX + 4))[1];
  cVar1 = *(char *)((int)puVar5 + 0x3d);
  puVar2 = *(undefined4 **)(in_EAX + 4);
  while (cVar1 == '\0') {
    puVar3 = unaff_EDI;
    if (7 < (uint)unaff_EDI[5]) {
      puVar3 = (undefined4 *)*unaff_EDI;
    }
    iVar4 = FUN_0044df20(0,puVar3,unaff_EDI[4]);
    if (iVar4 < 0) {
      puVar3 = (undefined4 *)puVar5[2];
      puVar5 = puVar2;
    }
    else {
      puVar3 = (undefined4 *)*puVar5;
    }
    puVar2 = puVar5;
    puVar5 = puVar3;
    cVar1 = *(char *)((int)puVar3 + 0x3d);
  }
  return puVar2;
}

