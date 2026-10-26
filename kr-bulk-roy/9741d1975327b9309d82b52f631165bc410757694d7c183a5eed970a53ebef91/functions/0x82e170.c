
void FUN_0082e170(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_EAX;
  undefined4 *puVar5;
  undefined1 local_8 [4];
  
  puVar2 = (undefined4 *)**(undefined4 **)(in_EAX + 0x28);
  puVar5 = puVar2;
  while (puVar2 != *(undefined4 **)(in_EAX + 0x28)) {
    if (*(uint *)(puVar2[4] + 8) < *(uint *)(puVar5[4] + 8)) {
      puVar5 = puVar2;
    }
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
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  if (puVar5[4] != 0) {
    FUN_0089120c(puVar5[4]);
    puVar5[4] = 0;
  }
  FUN_007b6890(in_EAX + 0x24,local_8,puVar5);
  return;
}

