
void FUN_0053dc90(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  
  puVar4 = *(undefined4 **)(unaff_EDI + 0x10);
  if (puVar4 != *(undefined4 **)(unaff_EDI + 0x14)) {
    do {
      if (*(short *)(puVar4 + 5) == param_1) {
        puVar1 = *(undefined4 **)(unaff_EDI + 0x14);
        puVar3 = puVar4;
        puVar2 = puVar4;
        while (puVar2 = puVar2 + 6, puVar2 != puVar1) {
          *puVar3 = *puVar2;
          puVar3[1] = puVar2[1];
          puVar3[2] = puVar2[2];
          puVar3[3] = puVar2[3];
          puVar3[4] = puVar2[4];
          puVar3[5] = puVar2[5];
          puVar3 = puVar3 + 6;
        }
        *(int *)(unaff_EDI + 0x14) = *(int *)(unaff_EDI + 0x14) + -0x18;
      }
      else {
        puVar4 = puVar4 + 6;
      }
    } while (puVar4 != *(undefined4 **)(unaff_EDI + 0x14));
  }
  return;
}

