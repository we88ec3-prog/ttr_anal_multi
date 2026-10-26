
void FUN_008ed420(void)

{
  undefined4 *puVar1;
  uint uVar2;
  char cVar3;
  undefined4 *puVar4;
  int unaff_ESI;
  uint *unaff_EDI;
  
  uVar2 = *(uint *)(unaff_ESI + 0x198);
  puVar4 = *(undefined4 **)(unaff_ESI + 0x1a0);
  puVar1 = puVar4 + uVar2 * 6;
  if (puVar4 < puVar1) {
    do {
      if (puVar4[3] == *unaff_EDI) break;
      puVar4 = puVar4 + 6;
    } while (puVar4 < puVar1);
  }
  if (puVar4 == puVar1) {
    if (*(uint *)(unaff_ESI + 0x19c) <= uVar2) goto LAB_008ed4d8;
    *(uint *)(unaff_ESI + 0x198) = uVar2 + 1;
  }
  uVar2 = *unaff_EDI;
  if ((-1 < (int)uVar2) && ((int)uVar2 < 0x100)) {
    puVar4[3] = uVar2 & 0xff;
    puVar4[1] = *(int *)(unaff_ESI + 0x168) + 1;
    *puVar4 = *(undefined4 *)(unaff_ESI + 0x160);
    *(undefined1 *)(puVar4 + 4) = 1;
    if (*(uint *)(unaff_ESI + 0x1a8) < *unaff_EDI) {
      *(uint *)(unaff_ESI + 0x1a8) = *unaff_EDI & 0xff;
    }
    cVar3 = FUN_008ed050();
    if (cVar3 != '\0') {
      return;
    }
    while (cVar3 = *(char *)(unaff_ESI + 0x170), cVar3 != ',') {
      if (cVar3 == '-') {
        return;
      }
      if (cVar3 == -0x77) break;
      cVar3 = FUN_008ed050();
      if (cVar3 != '\0') {
        return;
      }
    }
    *(undefined4 *)(unaff_ESI + 0xc) = 0x89;
    return;
  }
LAB_008ed4d8:
  *(undefined4 *)(unaff_ESI + 0xc) = 0x8d;
  return;
}

