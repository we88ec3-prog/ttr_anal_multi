
void FUN_008ed160(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  uint *in_ECX;
  undefined4 *puVar5;
  int unaff_EDI;
  
  uVar2 = *(uint *)(unaff_EDI + 0x18c);
  uVar3 = *in_ECX;
  puVar5 = *(undefined4 **)(unaff_EDI + 0x194);
  puVar1 = puVar5 + uVar2 * 6;
  for (; (puVar5 < puVar1 && (puVar5[3] != uVar3)); puVar5 = puVar5 + 6) {
  }
  if (puVar5 == puVar1) {
    if (*(uint *)(unaff_EDI + 400) <= uVar2) goto LAB_008ed198;
    *(uint *)(unaff_EDI + 0x18c) = uVar2 + 1;
  }
  if (uVar3 < 0x10000) {
    *puVar5 = *(undefined4 *)(unaff_EDI + 0x160);
    puVar5[3] = uVar3 & 0xffff;
    puVar5[1] = *(int *)(unaff_EDI + 0x168) + 1;
    *(undefined2 *)(puVar5 + 4) = 1;
    puVar5[5] = 0;
    if (*(uint *)(unaff_EDI + 0x1a4) < uVar3) {
      *(uint *)(unaff_EDI + 0x1a4) = uVar3 & 0xffff;
    }
    cVar4 = FUN_008ed050();
    if (cVar4 == '\0') {
      while (cVar4 = *(char *)(unaff_EDI + 0x170), cVar4 != ',') {
        if (cVar4 == '-') {
          puVar5[2] = *(undefined4 *)(unaff_EDI + 0x168);
          return;
        }
        if (cVar4 == -0x77) break;
        cVar4 = FUN_008ed050();
        if (cVar4 != '\0') {
          return;
        }
      }
      *(undefined4 *)(unaff_EDI + 0xc) = 0x89;
    }
    return;
  }
LAB_008ed198:
  *(undefined4 *)(unaff_EDI + 0xc) = 0x8c;
  return;
}

