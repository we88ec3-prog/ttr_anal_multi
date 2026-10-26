
int FUN_00749db0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_EAX;
  int in_ECX;
  undefined1 local_8 [4];
  
  puVar2 = (undefined4 *)**(undefined4 **)(in_ECX + 0x50);
  while( true ) {
    if (puVar2 == *(undefined4 **)(in_ECX + 0x50)) {
      return 0;
    }
    if (puVar2[4] == in_EAX) break;
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x15);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x15);
        puVar5 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar5, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar5 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  iVar4 = puVar2[4];
  *(undefined4 *)(iVar4 + 0x44) = 0;
  *(undefined4 *)(puVar2[4] + 0x48) = 0xffffffff;
  FUN_007b6890(in_ECX + 0x4c,local_8,puVar2);
  return iVar4;
}

