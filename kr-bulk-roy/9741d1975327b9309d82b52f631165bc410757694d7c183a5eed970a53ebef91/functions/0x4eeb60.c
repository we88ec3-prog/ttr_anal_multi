
void FUN_004eeb60(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int unaff_EDI;
  undefined1 local_8 [4];
  
  puVar2 = *(undefined4 **)(unaff_EDI + 4);
  puVar5 = (undefined4 *)*puVar2;
  while (puVar5 != puVar2) {
    *(short *)(puVar5 + 4) = *(short *)(puVar5 + 4) + 1;
    if (*(ushort *)(puVar5 + 4) < *(ushort *)((int)puVar5 + 0xe)) {
      if (*(char *)((int)puVar5 + 0x13) == '\0') {
        puVar3 = (undefined4 *)puVar5[2];
        if (*(char *)((int)puVar3 + 0x13) == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x13);
          puVar5 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar3 + 0x13);
            puVar5 = puVar3;
            puVar3 = (undefined4 *)*puVar3;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar5[1] + 0x13);
          puVar4 = (undefined4 *)puVar5[1];
          puVar3 = puVar5;
          while ((puVar5 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar5[2]))) {
            cVar1 = *(char *)((int)puVar5[1] + 0x13);
            puVar4 = (undefined4 *)puVar5[1];
            puVar3 = puVar5;
          }
        }
      }
    }
    else {
      puVar5 = (undefined4 *)FUN_00516d40(unaff_EDI,local_8,puVar5);
      puVar5 = (undefined4 *)*puVar5;
    }
  }
  return;
}

