
void FUN_008196d0(void)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  byte *unaff_EDI;
  
  puVar3 = *(undefined4 **)(unaff_ESI + 4);
  if (*(char *)((int)puVar3[1] + 0x19) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(byte *)(puVar1 + 3) < *unaff_EDI) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x19) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(unaff_ESI + 4)) && (*(byte *)(puVar3 + 3) <= *unaff_EDI)) {
    *in_EAX = puVar3;
    return;
  }
  *in_EAX = *(undefined4 **)(unaff_ESI + 4);
  return;
}

