
undefined4 FUN_0073fa20(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_EAX;
  int *in_EDX;
  
  puVar2 = (undefined4 *)**(undefined4 **)(in_EAX + 4);
  while( true ) {
    if (puVar2 == *(undefined4 **)(in_EAX + 4)) {
      return 0;
    }
    if ((((puVar2[3] != 0) && (iVar3 = puVar2[4], *in_EDX == *(int *)(iVar3 + 8))) &&
        (in_EDX[1] == *(int *)(iVar3 + 0xc))) &&
       (((int)(char)in_EDX[2] == *(int *)(iVar3 + 0x10) && (in_EDX[3] == *(int *)(iVar3 + 0x14)))))
    break;
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar2 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar2 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x15);
        puVar5 = (undefined4 *)puVar2[1];
        puVar4 = puVar2;
        while ((puVar2 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar5 = (undefined4 *)puVar2[1];
          puVar4 = puVar2;
        }
      }
    }
  }
  return puVar2[3];
}

