
void FUN_00750240(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  puVar1 = *(undefined4 **)(unaff_EDI + 0x1438);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if (*(int *)(puVar2[2] + 0xc) == unaff_ESI) {
      *(undefined4 *)(puVar2[2] + 0xc) = 0;
    }
  }
  puVar1 = *(undefined4 **)(unaff_EDI + 0x142c);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if (*(int *)(puVar2[2] + 0xc) == unaff_ESI) {
      *(undefined4 *)(puVar2[2] + 0xc) = 0;
    }
  }
  return;
}

